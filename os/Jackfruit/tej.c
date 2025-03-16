#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/delay.h>
#include <linux/sched/signal.h>
#include <linux/mm.h>
#include <linux/mmap_lock.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>

#define NUM_CHILDREN 3

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Tejas");
MODULE_DESCRIPTION("Kernel module");
MODULE_VERSION("1.1");

static struct task_struct *child_threads[NUM_CHILDREN];
static struct proc_dir_entry *proc_entry;

static int show_memory_map(struct seq_file *m, void *v) {
    struct vm_area_struct *vma;
    struct vma_iterator vmi;
    unsigned long total_size = 0;

    seq_printf(m, "PID: %d - Memory Map\n", current->pid);
    seq_printf(m, "Address   Kbytes Mode  Offset   Device    Mapping\n");

    if (!current->mm) {
        seq_printf(m, "[No user-space memory map available for kernel thread]\n");
        return 0;
    }

    mmap_read_lock(current->mm);

    vma_iter_init(&vmi, current->mm, 0);
    for_each_vma(vmi, vma) {
        unsigned long size = (vma->vm_end - vma->vm_start) >> 10;
        const char *name = vma->vm_file ? vma->vm_file->f_path.dentry->d_name.name : "[anonymous]";
        char mode[5];

        mode[0] = (vma->vm_flags & VM_READ) ? 'r' : '-';
        mode[1] = (vma->vm_flags & VM_WRITE) ? 'w' : '-';
        mode[2] = (vma->vm_flags & VM_EXEC) ? 'x' : '-';
        mode[3] = (vma->vm_flags & VM_SHARED) ? 's' : 'p';
        mode[4] = '\0';

        seq_printf(m, "%08lx %7lu %s %08lx %02x:%02x %s\n",
                   vma->vm_start,
                   size,
                   mode,
                   vma->vm_pgoff << PAGE_SHIFT,
                   MAJOR(vma->vm_file ? vma->vm_file->f_inode->i_sb->s_dev : 0),
                   MINOR(vma->vm_file ? vma->vm_file->f_inode->i_sb->s_dev : 0),
                   name);

        total_size += size;
    }

    mmap_read_unlock(current->mm);

    seq_printf(m, "Total: %lu KB\n", total_size);

    return 0;
}

static int proc_open(struct inode *inode, struct file *file) {
    return single_open(file, show_memory_map, NULL);
}

static const struct proc_ops proc_fops = {
    .proc_open = proc_open,
    .proc_read = seq_read,
    .proc_lseek = seq_lseek,
    .proc_release = single_release,
};

static int child_fn(void *data) {
    int id = *(int *)data;
    printk(KERN_INFO "   |--Kernel Child %d (PID: %d) started\n", id, current->pid);

    int *dmem = kmalloc(10 * sizeof(int), GFP_KERNEL);
    if (!dmem) {
        printk(KERN_ERR "      |--Memory allocation failed for child %d\n", id);
        return -ENOMEM;
    }
    printk(KERN_INFO "      |--Child %d allocated memory at: %p\n", id, dmem);

    msleep(5000);

    kfree(dmem);
    printk(KERN_INFO "      |--Child %d exiting\n", id);
    return 0;
}

static int __init kernel_sim_init(void) {
    int i;
    printk(KERN_INFO "Parent (Kernel Thread) PID: %d\n", current->pid);

    for (i = 0; i < NUM_CHILDREN; i++) {
        int *child_id = kmalloc(sizeof(int), GFP_KERNEL);
        if (!child_id) {
            printk(KERN_ERR "Failed to allocate memory for child ID\n");
            return -ENOMEM;
        }
        *child_id = i;

        child_threads[i] = kthread_run(child_fn, child_id, "child_thread_%d", i);
        if (IS_ERR(child_threads[i])) {
            printk(KERN_ERR "Failed to create child thread %d\n", i);
            kfree(child_id);
            return PTR_ERR(child_threads[i]);
        }
    }

    proc_entry = proc_create("memory_map", 0, NULL, &proc_fops);
    if (!proc_entry) {
        printk(KERN_ERR "Failed to create proc entry\n");
        return -ENOMEM;
    }

    printk(KERN_INFO "Module initialized. Check /proc/memory_map for memory map.\n");
    return 0;
}

static void __exit kernel_sim_exit(void) {
    int i;
    for (i = 0; i < NUM_CHILDREN; i++) {
        if (child_threads[i] && !IS_ERR(child_threads[i])) {
            kthread_stop(child_threads[i]);
            printk(KERN_INFO "Stopped child thread %d\n", i);
        }
    }
    proc_remove(proc_entry);
    printk(KERN_INFO "Goodbye from kernel module!\n");
}

module_init(kernel_sim_init);
module_exit(kernel_sim_exit);

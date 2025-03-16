#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/sched.h>

struct mem_allocation {
    void *mem_ptr; 
    size_t size;   
};

static int kthread_function(void *data) {
    int level = *(int *)data;
    struct mem_allocation *allocations;
    int i;

    printk(KERN_INFO "|%*s--Thread PID: %d\n", level * 4, "", current->pid);

    allocations = kmalloc(sizeof(struct mem_allocation) * 3, GFP_KERNEL);
    if (!allocations) {
        printk(KERN_INFO "|%*s  Failed to allocate memory for allocation array\n", level * 4, "");
        return -ENOMEM;
    }

    allocations[0].size = 128;
    allocations[1].size = 256;
    allocations[2].size = 512;

    for (i = 0; i < 3; i++) {
        allocations[i].mem_ptr = kmalloc(allocations[i].size, GFP_KERNEL);
        if (allocations[i].mem_ptr) {
            printk(KERN_INFO "|%*s  |--Allocated memory: %zu bytes at %px\n",
                   level * 4, "", allocations[i].size, allocations[i].mem_ptr);
        } else {
            printk(KERN_INFO "|%*s  |--Failed to allocate %zu bytes\n", level * 4, "", allocations[i].size);
        }
    }

    msleep(100); 

    for (i = 0; i < 3; i++) {
        if (allocations[i].mem_ptr) {
            kfree(allocations[i].mem_ptr);
            printk(KERN_INFO "|%*s  |--Freed memory: %zu bytes at %px\n",
                   level * 4, "", allocations[i].size, allocations[i].mem_ptr);
        }
    }
    kfree(allocations);

    printk(KERN_INFO "|%*s--Thread PID: %d exiting\n", level * 4, "", current->pid);
    return 0;
}

static int create_thread_tree(void) {
    struct task_struct *threads[2]; 
    int levels[2] = {1, 1};         
    int threads_per_level = 2;
    int i;

    printk(KERN_INFO "Creating top-level threads\n");

    for (i = 0; i < threads_per_level; i++) {
        threads[i] = kthread_run(kthread_function, &levels[i], "kthread_top_%d", i);
        if (IS_ERR(threads[i])) {
            printk(KERN_INFO "Failed to create top-level thread %d: %ld\n", i, PTR_ERR(threads[i]));
            threads[i] = NULL;
        } else {
            printk(KERN_INFO "|--Created top-level thread %d with PID %d\n", i, threads[i]->pid);
        }
    }

    for (i = 0; i < threads_per_level; i++) {
        if (threads[i] && !IS_ERR(threads[i])) {
            int ret = kthread_stop(threads[i]);
            printk(KERN_INFO "|--Stopped top-level thread %d with return code %d\n", i, ret);
        }
    }

    return 0;
}

static int __init tree_init(void) {
    printk(KERN_INFO "Loading Kernel Module: Process Tree with Memory Allocation\n");

    if (create_thread_tree() != 0) {
        printk(KERN_INFO "Failed to create thread tree\n");
        return -EFAULT;
    }

    return 0;
}

static void __exit tree_exit(void) {
    printk(KERN_INFO "Removing Kernel Module\n");
}

module_init(tree_init);
module_exit(tree_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Kernel Module for Process Tree with Dynamic Memory Allocation");
MODULE_AUTHOR("Suchitra");

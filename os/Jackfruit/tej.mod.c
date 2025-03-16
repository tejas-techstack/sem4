#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

#ifdef CONFIG_UNWINDER_ORC
#include <asm/orc_header.h>
ORC_HEADER;
#endif

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_MITIGATION_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif



static const char ____versions[]
__used __section("__versions") =
	"\x1c\x00\x00\x00\x63\xa5\x03\x4c"
	"random_kmalloc_seed\0"
	"\x18\x00\x00\x00\x1d\x07\x60\x20"
	"kmalloc_caches\0\0"
	"\x20\x00\x00\x00\xee\xfb\xb4\x10"
	"__kmalloc_cache_noprof\0\0"
	"\x10\x00\x00\x00\xf9\x82\xa4\xf9"
	"msleep\0\0"
	"\x10\x00\x00\x00\xba\x0c\x7a\x03"
	"kfree\0\0\0"
	"\x20\x00\x00\x00\xfa\xea\x96\x1a"
	"kthread_create_on_node\0\0"
	"\x18\x00\x00\x00\x3e\xf2\xdc\x1e"
	"wake_up_process\0"
	"\x14\x00\x00\x00\x2b\x3a\x21\x7f"
	"proc_create\0"
	"\x28\x00\x00\x00\xb3\x1c\xa2\x87"
	"__ubsan_handle_out_of_bounds\0\0\0\0"
	"\x18\x00\x00\x00\x55\xc6\x6d\xcc"
	"kthread_stop\0\0\0\0"
	"\x14\x00\x00\x00\x65\xc9\xf2\x1d"
	"proc_remove\0"
	"\x14\x00\x00\x00\x69\xb6\x98\xa4"
	"seq_printf\0\0"
	"\x30\x00\x00\x00\xff\xe6\x0d\x77"
	"__tracepoint_mmap_lock_start_locking\0\0\0\0"
	"\x14\x00\x00\x00\xa1\x19\x8b\x66"
	"down_read\0\0\0"
	"\x30\x00\x00\x00\x84\x64\x5a\xce"
	"__tracepoint_mmap_lock_acquire_returned\0"
	"\x14\x00\x00\x00\x34\x00\xb3\x87"
	"mas_find\0\0\0\0"
	"\x28\x00\x00\x00\x31\x55\xa8\x49"
	"__tracepoint_mmap_lock_released\0"
	"\x10\x00\x00\x00\xa2\x54\xb9\x53"
	"up_read\0"
	"\x28\x00\x00\x00\x88\xae\x1a\x3a"
	"__mmap_lock_do_trace_released\0\0\0"
	"\x30\x00\x00\x00\xb5\xc2\x92\xf1"
	"__mmap_lock_do_trace_acquire_returned\0\0\0"
	"\x2c\x00\x00\x00\x7b\xc5\x92\x32"
	"__mmap_lock_do_trace_start_locking\0\0"
	"\x1c\x00\x00\x00\xcb\xf6\xfd\xf0"
	"__stack_chk_fail\0\0\0\0"
	"\x14\x00\x00\x00\x0e\xd8\xd5\xd9"
	"seq_read\0\0\0\0"
	"\x14\x00\x00\x00\xe5\x41\x2a\xae"
	"seq_lseek\0\0\0"
	"\x18\x00\x00\x00\x0a\x8d\x36\x7f"
	"single_release\0\0"
	"\x14\x00\x00\x00\xbb\x6d\xfb\xbd"
	"__fentry__\0\0"
	"\x14\x00\x00\x00\xb7\x6f\x70\xe6"
	"single_open\0"
	"\x1c\x00\x00\x00\xca\x39\x82\x5b"
	"__x86_return_thunk\0\0"
	"\x18\x00\x00\x00\xe3\xb8\xcb\x0d"
	"const_pcpu_hot\0\0"
	"\x10\x00\x00\x00\x7e\x3a\x2c\x12"
	"_printk\0"
	"\x18\x00\x00\x00\xde\x9f\x8a\x25"
	"module_layout\0\0\0"
	"\x00\x00\x00\x00\x00\x00\x00\x00";

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "417E3BA56EF1D7D88A89247");

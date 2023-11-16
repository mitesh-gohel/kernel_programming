#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

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

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif


static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x122c3a7e, "_printk" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xb7f7a7b2, "alloc_pages" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xca1deb1d, "pcpu_hot" },
	{ 0x72d79d83, "pgdir_shift" },
	{ 0xf5b00aab, "boot_cpu_data" },
	{ 0xf7901fc5, "__free_pages" },
	{ 0xdad13544, "ptrs_per_p4d" },
	{ 0x2bd36bdd, "pv_ops" },
	{ 0x1d19f77b, "physical_mask" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x4ddb9e0e, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "A27DCB24DC35D78766D1746");

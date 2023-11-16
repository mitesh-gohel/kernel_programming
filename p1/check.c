//Sample module
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>

static __init int entry_fun(void)
{
	printk("Loading... mod\n");
	return 0;
}

static __exit void exit_fun(void)
{
	printk("Unloading... mod\n");
}


module_init(entry_fun);
module_exit(exit_fun);

MODULE_LICENSE("GPL");

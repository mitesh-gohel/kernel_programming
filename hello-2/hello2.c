#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>

static int __init m_init_module(void)
{
	printk(KERN_INFO "hello world 1 \n");
	return 0;
}

static void __exit m_cleanup_module(void)
{
	printk(KERN_INFO "Good  by world 1 \n");
}

module_init(m_init_module);
module_exit(m_cleanup_module);

#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/moduleparam.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mitesh Gohel");
MODULE_DESCRIPTION("To learn command line argument in module programming");

static int arg_var = 10;
module_param(arg_var, int , 0);
static int __init start(void)
{
	printk(KERN_INFO "Starting module %d", arg_var);
	return 0;
}

static void __exit end(void)
{
	printk(KERN_INFO "Exiting from module");
}

module_init(start);
module_exit(end);

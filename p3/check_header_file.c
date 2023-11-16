//Check : which header files are required for simple kernel module
//#include<linux/kernel.h>	//not needed
#include<linux/module.h>
//#include<linux/init.h>	//not needed

MODULE_LICENSE("GPL");

static __init int entry_fun(void)
{
	printk("Entering ....\n");
	pr_info("Enter\n");
	printk(KERN_INFO "print KERN_INFO macro\n");
	return 0;
}

static __exit void exit_fun(void)
{
	printk("Exiting ... \n");
	pr_info("Exit\n");
}

module_init(entry_fun);
module_exit(exit_fun);

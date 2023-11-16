#include<linux/module.h>
#include<linux/kernel.h>

int init_module()
{
	printk(KERN_INFO "hello world 1 \n");
	return 0;
}

void cleanup_module()
{
	printk(KERN_INFO "Good  by world 1 \n");
}

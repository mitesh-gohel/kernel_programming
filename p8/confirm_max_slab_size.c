//To confirm that max 4MB of memory can be allocate by slab allocator

#include<linux/module.h>
#include<linux/mm.h>

MODULE_LICENSE("GPL");

static int entry_fun(void)
{
	int size = 4;
	void *p=NULL;
	printk("Entering....\n");
	while(1)
	{
		p = kmalloc(size, GFP_KERNEL);
		if(p == NULL)
		{
			printk("Allocatioon of %d bytes faild\n", size);
			return -ENOMEM; 
		}
		printk("%d bytes allocated\n", size);
		kfree(p);
		p = NULL;
		size += 500;
	}
	return 0;
}

static void exit_fun(void)
{
	printk("Exiting....\n");
}

module_init(entry_fun);
module_exit(exit_fun);


/*
Conclusion :
	Slab allocator can allocate upto 4MB of memory
*/

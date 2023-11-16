//To check memory waste by slab allocator

#include<linux/module.h>
#include<linux/mm.h>

MODULE_LICENSE("GPL");

static int entry_fun(void)
{
	int size = 5, actual_alloc = 0;
	void *p = NULL;
	while(size < 80000)
	{
		p = kmalloc(size, GFP_KERNEL);
		if(p == NULL)
		{
			printk("%s : Memory allocation failed for %d bytes\n", __func__, size);
			return -ENOMEM;
		}
		actual_alloc = ksize(p); 	/* ksize() gives alllocted memory size */
		printk("%s : Requested = %d, Allocated = %d, Wasted = %d\n", __func__, size, actual_alloc, actual_alloc - size);
		kfree(p);
		p = NULL;
		size += 10;
	}
	return 0;
}

static void exit_fun(void)
{
	printk("%s : Exiting...\n", __func__);
}

module_init(entry_fun);
module_exit(exit_fun);

//Try to allocate all pages
#include<linux/module.h>

MODULE_LICENSE("GPL");

static int entry_fun(void)
{
	struct page *pg;
	unsigned int n=1;
	while(1)
	{
		printk("Allocting 2^%d pages ....\n", n);
		pg = alloc_pages(GFP_KERNEL, n);
		if(!pg)
		{
			printk("page allocation failed\n");
			return -ENOMEM;
		}
		printk("page allocated successfully\n");
		__free_pages(pg, n);
		++n;
	}
	return 0;
}

static void exit_fun(void)
{
	printk("Exiting ....\n");
}

module_init(entry_fun);
module_exit(exit_fun);

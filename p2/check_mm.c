//Find total phycial memmory
#include<linux/module.h>
#include<linux/mm.h>


static int entry_fun(void)
{
	unsigned int total_mem = 0;
	printk("No. of pages = %ld\n",get_num_physpages());
	printk("Size of one frame, which is paged by page  =  %ld bytes\n", PAGE_SIZE);
	total_mem = (unsigned int)((get_num_physpages() * PAGE_SIZE) / (1024 * 1024));
	printk("Total physical memmory =  %d MB\n", total_mem);
	return 0;
}

static void exit_fun(void)
{
	printk("Exiting...\n");
}

module_init(entry_fun);
module_exit(exit_fun);

MODULE_LICENSE("GPL");

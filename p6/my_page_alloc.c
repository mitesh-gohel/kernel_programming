//How to allocate page using __get_free_page()
#include<linux/module.h>
#include<linux/slab.h>

MODULE_LICENSE("GPL");

static int entry_fun(void)
{
	unsigned long ptr1=0, ptr2=0;
	ptr1 = __get_free_page(GFP_KERNEL);		//__get_free_page() - allocates 1  page in form of linear address of page
	ptr2 = __get_free_pages(GFP_KERNEL, 1);		//__get_free_pages() - allocates 2^n (here 2^1) page in form of linear address of page

	printk("Linear address of page = %ld\n", ptr1);
	
	free_page((unsigned long)ptr1);
	free_pages((unsigned long)ptr2, 1);
	return 0;
}

static void exit_fun(void)
{
	printk("Exiting.....\n");
}

module_init(entry_fun);
module_exit(exit_fun);

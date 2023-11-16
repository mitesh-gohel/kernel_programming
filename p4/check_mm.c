//How to get physical address of page
#include<linux/module.h>
#include<linux/slab.h>	//for kmallloc

MODULE_LICENSE("GPL");

static char *ptr=NULL;
static struct page *pg=NULL;

static int my_init_module(void)
{
	ptr = kmalloc(GFP_KERNEL, PAGE_SIZE);    //This will return kernel linear address
	pg = (struct page *)__pa(ptr);	//__pa will give physical address of page.   physical address is (Frame no. + Offset)    
	printk("Linear address = %p\n", ptr);
	printk("physical address (frame no. + offset) = %p\n", pg);

	strcpy(ptr, "Hello world !");
	printk("After doing strcpy in ptr\n");
	//strcpy(pg, "This will fail"); 	// This will give error because this pg is not kernel linear address, It is physical address
	kfree(ptr);
	ptr = NULL;
	return 0;
}

void my_exit_module(void)
{
	printk("Exiting.... \n");
}

module_init(my_init_module);
module_exit(my_exit_module);

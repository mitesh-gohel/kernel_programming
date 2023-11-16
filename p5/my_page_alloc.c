//How to allocate page using alloc_page()
#include<linux/module.h>
#include<linux/mm.h> 	//for page_address()

MODULE_LICENSE("GPL");

static int entry_fun(void)
{
	struct page *pg1=NULL;
	struct page *pg2=NULL;
	char *ptr1=NULL;
	char *ptr2=NULL;

	pg1 = alloc_page(GFP_KERNEL); 	//alloc_page() - to allocate 1 page, which returns page descriptor
	pg2 = alloc_pages(GFP_KERNEL, 3);	//alloc_pages - to allocate 2^n pages (here 2^3 pages), which returns page descriiptor
	
	ptr1 = page_address(pg1);	//page_address - to get linear address from address of page desciiptor
	ptr2 = page_address(pg2);

	printk("Page descriptor address = %p\n", pg1);
	printk("Linear address of page = %p\n", ptr1);
	printk("Frame no. = %ld\n", page_to_pfn(pg1));			//page_to_pfn() - to find frame no. of given page descriptor
	printk("Page no. = %p\n", pfn_to_page(page_to_pfn(pg1)));	//pfn_to_page - to find page descriptor address of given page no.

	free_page((unsigned long int)ptr1);	//free_page() - to deallocate 1 page based on given linear address of page
	free_pages((unsigned long int)ptr2, 3);		//free_pages() - to deallocate 2^n pages (here 2^3 pages) based on given linear address of page
	/*
	we can use below API also
	void __free_page(struct page *page);
	void __free_pages(struct page *page, unsigned int order);
	*/
	return 0;
}

static void exit_fun(void)
{
	printk("Exiting ..... \n");
}

module_init(entry_fun);
module_exit(exit_fun);

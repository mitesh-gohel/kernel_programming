/* To understand page translation concepts */

#include<linux/module.h>
#include<linux/mm.h>
#include<linux/delay.h>

static void debug_addr(unsigned long l_addr)
{
	pgd_t *pgd;
	p4d_t *p4d;
	pud_t *pud;
	pmd_t *pmd;
	pte_t *pte;
	struct page *pg_desc;
	
	pr_info("Process = %s,    PID = %d\n", current->comm, current->pid);

	pgd = pgd_offset(current->mm, l_addr);
	if(pgd_none(*pgd))
	{
		printk("Not mapped in pgd\n");
		return;
	}

	p4d = p4d_offset(pgd, l_addr);
	if(p4d_none(*p4d))
	{
		printk("Not mapped in p4d\n");
		return;
	}

	pud = pud_offset(p4d, l_addr);
	if(pud_none(*pud))
	{
		printk("Not mapped in pud\n");
		return;
	}

	pmd = pmd_offset(pud, l_addr);
	if(pmd_none(*pmd))
	{
		printk("Not mapped in pmd\n");
		return;
	}

	pte = pte_offset_map(pmd, l_addr);
	if(pte_none(*pte))
	{
		printk("Not mapped in pgd\n");
		return;
	}

	printk("%s : Physical address(Frame no. + offset) = %p\n", __func__, pte);


	pg_desc = pte_page(*pte);		/* get mapped page describtor of given physical location */
	printk("%s : page describtor = %p\n", __func__, pg_desc);

	printk("%s : Linear address from page describtor = %p\n", __func__, page_address(pg_desc));

	pte_unmap(pte);   /* Unmap page : reverse operation of pte_page() */
}

static int init_my_page(void)
{
	void *l_addr=NULL; 	/* kernel linear address */
	void *phy_addr=NULL;
	struct page *pg_desc=NULL;
	unsigned long f_num=0; 		/* frame number */
	pg_desc = alloc_page(GFP_KERNEL);  /* allocate 1 page */
	if(pg_desc == NULL)
	{
		pr_err("page allocation failed\n");
		return -ENOMEM;
	}
	l_addr = page_address(pg_desc);
	phy_addr = __pa(l_addr);
	pr_info("page describtor address = %p\n", pg_desc);
	pr_info("kernel linear address = %p\n", l_addr);	
	pr_info("Physical address = %p\n", phy_addr);
	f_num = page_to_pfn(pg_desc);
	pr_info("Frame no. = %ld\n", f_num);

	debug_addr((unsigned long)l_addr);

	__free_page(pg_desc);
	pg_desc = NULL;
	l_addr = NULL;
	/*
	msleep(60000);
	*/

	return 0;
}

static void exit_my_page(void)
{
	pr_info("Exiting....\n");
}

module_init(init_my_page);
module_exit(exit_my_page);
MODULE_LICENSE("GPL");

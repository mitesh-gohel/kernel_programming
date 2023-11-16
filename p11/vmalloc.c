/* Fragment allocator - vmalloc()*/

#include<linux/module.h>
#include<linux/vmalloc.h>

MODULE_LICENSE("GPL");

void *p=NULL;

static int entry_fun(void)
{
	pr_info("%s : Entering\n", __func__);
	p = vmalloc(9000 * 1024); /*allocate 9MB*/
	if(p == NULL)
	{
		pr_info("%s : Allocation failed\n", __func__);
		return -ENOMEM;
	}
	pr_info("%s : Allocation done\n", __func__);
	strcpy(p, "Fragment allocator\n");
	return 0;
}

static void exit_fun(void)
{
	pr_info("%s : info in buffer : %s\n", __func__, (char *)p);
	vfree(p);
	p = NULL;
	pr_info("%s : Exiting\n", __func__);
}

module_init(entry_fun);
module_exit(exit_fun);

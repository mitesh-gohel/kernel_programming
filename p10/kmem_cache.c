//Private cache

#include<linux/module.h>
#include<linux/mm.h>

MODULE_LICENSE("GPL");

struct kmem_cache *my_cache=NULL;
void *p=NULL;

void test_fun(void)
{
	printk("%s : Test function called\n", __func__);
}

void construct_fun(void *data)	//Constructor function will be called for each obj of slab
{
	static int i=0;
	printk("%s : Constructor function called %d times\n", __func__ , ++i);
}

static int entry_fun(void)
{
	
	my_cache = kmem_cache_create("my_private_cache", 50, 0, SLAB_RED_ZONE, construct_fun);
	test_fun();
	printk("%s : cache size = %d\n", __func__, kmem_cache_size(my_cache));
	p = kmem_cache_alloc(my_cache, GFP_KERNEL);
	if(p == NULL)
	{
		printk("%s : Memeory allocation failed\n", __func__);
		return -ENOMEM;
	}
	printk("%s : Memory allocation done\n", __func__);
	printk("%s : Allocated memory size = %ld\n", __func__ , ksize(p));
	return 0;
}

static void exit_fun(void)
{
	kmem_cache_free(my_cache, p);
	p = NULL;
	printk("%s : Memory is freed up\n", __func__);
	kmem_cache_destroy(my_cache);
	printk("%s : Private cache is destroyed\n", __func__);
}

module_init(entry_fun);
module_exit(exit_fun);

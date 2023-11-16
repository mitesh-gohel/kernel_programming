/* Demo code of DMA allocation using consistent API*/

#include<linux/module.h>
#include<linux/mm.h>
#include<linux/dma-mapping.h>

static struct device *dev;
static int size=4096;
static void *k_ptr=NULL;
static dma_addr_t my_var;
static dma_addr_t *dma_ptr = &my_var;

static void dev_release_fun(struct device *dev)
{
	pr_info("%s : Virtual device is released\n", __func__);
}

static int entry_fun(void)
{
	unsigned int phy_addr = 0;
	static const u64 dmamask = DMA_BIT_MASK(32);
	pr_info("%s : Entering...\n", __func__);
	dev = kmalloc(sizeof(struct device), GFP_KERNEL);
	dev_set_name(dev, "dma_for_test");
	dev->dma_mask = (u64 *)&dmamask;
	dev->coherent_dma_mask = DMA_BIT_MASK(32);	
	dev->release = dev_release_fun;
	device_register(dev);
	
	k_ptr = dma_alloc_coherent(dev, size, dma_ptr, GFP_KERNEL | GFP_DMA32);
	if(k_ptr == NULL || dma_ptr == NULL)
	{
		pr_info("%s : Memory is not available for DMA\n", __func__);
		return -ENOMEM;
	}
	pr_info("%s : k_ptr (Virtual address )= %p, dma_ptr = %p\n", __func__, k_ptr, dma_ptr);
	strcpy(k_ptr , "DMA operation\n");
	phy_addr = __pa(k_ptr);
	pr_info("%s : Phyical address of allocated memory : %p\n", __func__, phy_addr);
	return 0;
}

static void exit_fun(void)
{
	pr_info("%s : Exiting...\n", __func__);
	pr_info("%s : DMA data : %s\n", __func__, (char *)k_ptr);
	dma_free_coherent(dev, size, k_ptr, *dma_ptr);
k_ptr = NULL;
	dma_ptr = NULL;
	device_unregister(dev);
	dev = NULL;
}

module_init(entry_fun);
module_exit(exit_fun);

MODULE_LICENSE("GPL");

obj-m := hello1.o

KDIR ?= /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

build :
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean :
	$(MAKE) -C $(KDIR) M=$(PWD) clean

obj-m := mm_page.o

all :
	make -C /usr/lib/modules/$(shell uname -r)/build/ M=$(shell pwd) modules
clean :
	make -C /usr/lib/modules/$(shell uname -r)/build/ M=$(shell pwd) clean


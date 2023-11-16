obj-m := alloc_all_page.o

all :
	make -C "/lib/modules/$(shell uname -r)/build" M="$(shell pwd)" modules
clean :
	make -C "/lib/modules/$(shell uname -r)/build" M="$(shell pwd)" clean

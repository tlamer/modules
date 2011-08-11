obj-m := test1.o
obj-m += test2.o
obj-m += test3.o
obj-m += chardev.o
obj-m += procfs1.o
obj-m += procfsd2.o
obj-m += procfs2.o

EXTRA_CFLAGS := -I$(PWD) -I/usr/include -I/usr/realtime/include

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

obj-m := test1.o
obj-m += test2.o
obj-m += test3.o

#EXTRA_CFLAGS := -I$(PWD)/../include -I/usr/include -I/usr/realtime/include

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

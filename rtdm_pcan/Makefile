obj-m := rtcan.o

EXTRA_CFLAGS := -I$(PWD) -I/usr/include -I/usr/realtime/include 

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

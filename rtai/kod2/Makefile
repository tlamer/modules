obj-m := hello.o
obj-m += new.o

hello-objs := prvy.o
hello-objs += druhy.o
hello-objs += funkcia.o

new-objs := novy.o
new-objs += pridavok.o

EXTRA_CFLAGS := -I$(PWD)/../include -I/usr/include -I/usr/realtime/include

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	sudo cp *.ko /lib/modules/$(shell uname -r)/misc
	sudo depmod
	#make -C /lib/modules/2.6.35.9RTAI/build M=$(PWD) modules

clean:
	make -C /lib/modules/2.6.35.9RTAI/build M=$(PWD) clean

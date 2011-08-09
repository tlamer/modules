obj-m := hello.o
obj-m += novy.o
#hello-objs := prvy.o
#hello-objs += druhy.o


all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

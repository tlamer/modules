obj-m := hello.o
obj-m += new.o

hello-objs := prvy.o
hello-objs += druhy.o

new-objs := novy.o
new-objs += pridavok.o

EXTRA_CFLAGS := -I$(PWD)
#EXTRA_CFLAGS := -I.

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
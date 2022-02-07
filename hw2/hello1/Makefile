
obj-m += hello1.o

all:
	make -C /usr/src/kernels/$(shell uname -r) M=$(PWD) modules

clean: 
	make -C /usr/src/kernels/$(shell uname -r) M=$(PWD) clean

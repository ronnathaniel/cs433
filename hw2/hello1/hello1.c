
/*
 * Filename: hello1.c
 * Author: Ron Nathaniel
 */

# include <linux/module.h>
# include <linux/kernel.h>

MODULE_LICENSE();

int init_module(void) {
	printk(KERN_INFO "Hello, World!\n");
	return 0;
}

void cleanup_module(void) {
	printk(KERN_INFO "Goodbye, World...\n");
}

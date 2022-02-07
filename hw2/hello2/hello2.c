
/*
 * Filename: hello2.c
 * Author: Ron Nathaniel
 */


# include <linux/module.h>
# include <linux/kernel.h>
# include <linux/init.h>

MODULE_LICENSE();

static int hello2_init_modnum __initdata = 2;

static int __init hello_2_init (void) {
	printk(KERN_INFO "Ron Nathaniel: Loading Hello2 module - Hello World 2\n");
	printk(KERN_INFO "__initdata: modnum=[%d]", hello2_init_modnum);
	return 0;
}


static void __exit hello_2_exit (void) {
	printk(KERN_INFO "Ron Nathaniel: Exiting Hello2 module - Goodbye World 2\n");
}

module_init(hello_2_init);
module_exit(hello_2_exit);


/* 
 * Filename: hello3.c
 * Author: Ron Nathaniel
 */

# include <linux/module.h>
# include <linux/kernel.h>
# include <linux/init.h>

static char *weather = "snowing";
static char *zipcode = "90210";

module_param(weather, charp, 000);
MODULE_PARM_DESC(weather, "The current weather");

module_param(zipcode, charp, 000);
MODULE_PARM_DESC(zipcode, "Location of said weather.");

MODULE_LICENSE("MIT");
MODULE_AUTHOR("Ron Nathaniel");

static int __init hello_3_init (void) {
	printk(KERN_INFO "Ron Nathaniel: Loading Hello3 module - Hello World 3\n");
	return 0;
}


static void __exit hello_3_exit (void) {
	printk(KERN_INFO "Ron Nathaniel: Exiting Hello3 module - Goodbye World 3\n");
}

module_init(hello_3_init);
module_exit(hello_3_exit);

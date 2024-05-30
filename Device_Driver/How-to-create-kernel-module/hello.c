
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rabie");
MODULE_DESCRIPTION("HELLo world device deriver");



static int __init hellodriver_init(void){
    printk(KERN_INFO,"hello world");
    return 0;

}

static void __exit hellodriver_exit(void){
    printk(KERN_INFO,"Good bye,");

}
module_init(hellodriver_init);
module_exit(hellodriver_exit);

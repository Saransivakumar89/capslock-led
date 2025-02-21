#include<linux/module.h>
#include<linux/kernel.h>


#undef pr_fmt
#define pr_fmt(fmt) "%s :" fmt,__func__

    
static int __init led_init(void)
{
    pr_info("Caps led module loaded\n");
    return 0;
}

static void __exit led_exit(void)
{
    pr_info("caps led module unloaded\n");
}

module_init(led_init);
module_exit(led_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Saran sivakumar");
MODULE_DESCRIPTION("Capslock key led blink module");

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/init.h>
#include <linux/tty.h>
#include <linux/console.h>
#include <linux/vt_kern.h>
#include <linux/workqueue.h>

#define BLINK_COUNT 10   /* Number of LED blinks */
#define DELAY 500        /* Delay for LED ON/OFF in milliseconds */

#undef pr_fmt
#define pr_fmt(fmt) "%s :" fmt,__func__

static struct work_struct capsled_work;  /* Workqueue task */

/* Function to control LED */
static void set_leds(int state)
{
    struct tty_struct *tty;

    tty = vc_cons[fg_console].d->port.tty;
    if (tty && tty->ops->ioctl)
        tty->ops->ioctl(tty, KDSETLED, state);
}

/* Function to blink the LED */
static void blink_led(struct work_struct *work)
{
    int i;
    for (i = 0; i < BLINK_COUNT; i++) 
    {
        set_leds(0x04);  /* Caps Lock ON */
        msleep(DELAY);
        set_leds(0x00);  /* Caps Lock OFF */
        msleep(DELAY);
    }
}

/* Module Init */
static int __init led_init(void)
{
    pr_info("Caps LED module loaded\n");
    INIT_WORK(&capsled_work, blink_led);
    schedule_work(&capsled_work);
    return 0;
}

/* Module Exit */
static void __exit led_exit(void)
{
    
    cancel_work_sync(&capsled_work);
    pr_info("Caps LED module unloaded\n");
}

module_init(led_init);
module_exit(led_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Saran Sivakumar");
MODULE_DESCRIPTION("Simple Caps Lock LED blink module");



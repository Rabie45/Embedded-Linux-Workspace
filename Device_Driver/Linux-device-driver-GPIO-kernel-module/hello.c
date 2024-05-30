#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <linux/gpio.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rabie");
MODULE_DESCRIPTION("Hello world device driver");
#define SIZE 15
#define LED_PIN 21
static struct cdev st_character_device;
static dev_t device_number;
static struct class *myclass;
static struct device *mydevice;
static unsigned char buffer[SIZE] = "";
static int number = 0;
module_param(number, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(number, "major number");
// echo hello /dev/test_file
ssize_t driver_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *off)
{

    // adjust count
    // cop from user to kernel
    // addjust offset
    // return suceflly count
    int not_copied;

    printk(KERN_INFO "%sThe Count %ld\n", __FUNCTION__, count);
    printk(KERN_INFO "%s the offset %lld\n", __FUNCTION__, *off);
    if (count + *off > SIZE)
    {
        count = SIZE - *off;
    }
    if (!count)
    {
        printk(KERN_INFO "%s No space left\n", __FUNCTION__);
    }
    not_copied = copy_from_user(&buffer[*off], user_buffer, count);
    switch (buffer[0])
    {
    case '1':
        gpio_set_value(LED_PIN, 1);
        break;
    case '0':
        gpio_set_value(LED_PIN, 0);
        break;
    default:
        break;
    }
    if (not_copied < 0)
    {
        return -1;
    }
    *off = count;
    printk(KERN_INFO "%s not_copied %d\n", __func__, not_copied);
    printk(KERN_INFO "%s The user_buffer %s \n", __func__, buffer);
    return count;
}
static ssize_t driver_read(struct file *file, char __user *user_buffer, size_t count, loff_t *off)
{
    int not_copied;

    printk(KERN_INFO "%sThe Count %ld\n", __FUNCTION__, count);
    printk(KERN_INFO "%s the offset %lld\n", __FUNCTION__, *off);
    if (count + *off > SIZE)
    {
        count = SIZE - *off;
    }
    not_copied = copy_to_user(user_buffer, &buffer[*off], count);
    if (not_copied < 0)
    {
        return -1;
    }
    *off = count;
    printk(KERN_INFO "%s not_copied %d\n", __func__, not_copied);
    printk(KERN_INFO "%s The user_buffer %s \n", __func__, buffer);
    return count;
}

static int driver_open(struct inode *device_file, struct file *instance)
{
    printk(KERN_INFO "%s device open was called\n", __FUNCTION__);
    return 0;
}

static int driver_close(struct inode *device_file, struct file *instance)
{
    printk(KERN_INFO "%s device close was called\n", __FUNCTION__);
    return 0;
}

static const struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = driver_open,
    .release = driver_close,
    .read = driver_read,
    .write = driver_write};

static int __init hellodriver_init(void)
{
    int retval;

    printk(KERN_INFO "Hello world\n");

    // Allocate device number
    retval = alloc_chrdev_region(&device_number, 0, 1, "test_devicenumber");
    if (retval != 0)
    {
        printk(KERN_ERR "Failed to register device number\n");
        return retval;
    }
    printk(KERN_INFO "%s registered device number major:%d, minor:%d\n", __FUNCTION__, MAJOR(device_number), MINOR(device_number));

    // Initialize character device
    cdev_init(&st_character_device, &fops);
    retval = cdev_add(&st_character_device, device_number, 1);
    if (retval != 0)
    {
        printk(KERN_ERR "Failed to add character device\n");
        goto CHARACTER_ERROR;
        return retval;
    }

    // Create device class
    myclass = class_create(THIS_MODULE, "test_class");
    if (IS_ERR(myclass))
    {
        printk(KERN_ERR "Failed to create device class\n");
        goto CLASS_ERROR;

        return PTR_ERR(myclass);
    }

    // Create device file
    mydevice = device_create(myclass, NULL, device_number, NULL, "test_file");
    if (mydevice == NULL)
    {
        printk(KERN_ERR "Failed to create device file\n");
        goto DEVICE_ERROR;
    }

    printk(KERN_INFO "Device driver created successfully\n");
    retval=gpio_request(LED_PIN, "rpi_gpio_21");
    if (retval<0)
    {
        printk(KERN_INFO "Can not allocate for GPIO rpi_gpio_21%d \n",retval);
        goto GPIO_REQUEST_ERROR;
    }
    if (gpio_direction_output(LED_PIN, 0))
    {
        printk(KERN_INFO "Can not set the pin to be output \n");
        goto GPIO_DIR_ERROR;
    }
    return 0;
GPIO_DIR_ERROR:
    gpio_free(LED_PIN);
GPIO_REQUEST_ERROR:
    device_destroy(myclass, device_number);
DEVICE_ERROR:
    class_destroy(myclass);

CLASS_ERROR:
    cdev_del(&st_character_device);

CHARACTER_ERROR:
    unregister_chrdev_region(device_number, 1);
    return -1;
}

static void __exit hellodriver_exit(void)
{
    gpio_set_value(LED_PIN, 0);
    gpio_free(LED_PIN);

    device_destroy(myclass, device_number);
    class_destroy(myclass);
    cdev_del(&st_character_device);
    unregister_chrdev_region(device_number, 1);
    printk(KERN_INFO "Goodbye\n");
}

module_init(hellodriver_init);
module_exit(hellodriver_exit);

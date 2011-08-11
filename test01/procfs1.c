/*
 *  procfs1.c -  create a "file" in /proc
 *
 */

#include <linux/module.h>	/* Specifically, a module */
#include <linux/kernel.h>	/* We're doing kernel work */
#include <linux/proc_fs.h>	/* Necessary bcause we use the proc fs */
#include <asm/uaccess.h>
#include <procfs1.h>

#define PROCFS_NAME "helloworld"
#define	BUF_LEN 80

MODULE_LICENSE("GPL");

/**
 * This structure hold information about the /proc file
 *
 */
static struct proc_dir_entry *Our_Proc_File;
static struct file_operations proc_fops = {
	.read = procfile_read,
	.open = procfile_open,
	.release = procfile_release
};

static char msg[BUF_LEN];
static char *msg_ptr;
static int Device_Open = 0;

/* Put data into the proc fs file.
 * 
 * Arguments
 * =========
 * 1. The buffer where the data is to be inserted, if
 *    you decide to use it.
 * 2. A pointer to a pointer to characters. This is
 *    useful if you don't want to use the buffer
 *    allocated by the kernel.
 * 3. The current position in the file
 * 4. The size of the buffer in the first argument.
 * 5. Write a "1" here to indicate EOF.
 * 6. A pointer to data (useful in case one common 
 *    read for multiple /proc/... entries)
 *
 * Usage and Return Value
 * ======================
 * A return value of zero means you have no further
 * information at this time (end of file). A negative
 * return value is an error condition.
 *
 * For More Information
 * ====================
 * The way I discovered what to do with this function
 * wasn't by reading documentation, but by reading the
 * code which used it. I just looked to see what uses
 * the get_info field of proc_dir_entry struct (I used a
 * combination of find and grep, if you're interested),
 * and I saw that  it is used in <kernel source
 * directory>/fs/proc/array.c.
 *
 * If something is unknown about the kernel, this is
 * usually the way to go. In Linux we have the great
 * advantage of having the kernel source code for
 * free - use it.
 */
//static int
//procfile_read(char *buffer,
//	      char **buffer_location,
//	      off_t offset, int buffer_length, int *eof, void *data)
//{
//	int ret;
//	
//	printk(KERN_INFO "[procfs1] procfile_read (/proc/%s) called\n", PROCFS_NAME);
//	
//	/* 
//	 * We give all of our information in one go, so if the
//	 * user asks us if we have more information the
//	 * answer should always be no.
//	 *
//	 * This is important because the standard read
//	 * function from the library would continue to issue
//	 * the read system call until the kernel replies
//	 * that it has no more information, or until its
//	 * buffer is filled.
//	 */
//	if (offset > 0) {
//		/* we have finished to read, return 0 */
//		ret  = 0;
//	} else {
//		/* fill the buffer, return the buffer size */
//		ret = sprintf(buffer, "HelloWorld!\n");
//	}
//
//	return ret;
//}

static int procfile_open(struct inode *inode, struct file *file){
	
	if (Device_Open)
		return -EBUSY;

	Device_Open++;
	sprintf(msg, "Hello World!\n");
	msg_ptr = msg;
	try_module_get(THIS_MODULE);

	return 0;
}

static int procfile_release(struct inode *inode, struct file *file)
{
	Device_Open--;
	module_put(THIS_MODULE);
	return 0;
}

static ssize_t procfile_read(struct file *filp,
		char *buffer,
		size_t length,
		loff_t *offset)
{
	int bytes_read = 0;
	if (*msg_ptr == 0)
		return 0;

	while (length && *msg_ptr){
		put_user(*(msg_ptr++),buffer++);

		length--;
		bytes_read++;
	}
	return bytes_read;
}

int init_module()
{
	Our_Proc_File = proc_create(PROCFS_NAME, S_IFREG | S_IRUGO, NULL, &proc_fops);
	
	if (Our_Proc_File == NULL) {
		remove_proc_entry(PROCFS_NAME, NULL);
		printk(KERN_ALERT "[procfs1] Error: Could not initialize /proc/%s\n",
		       PROCFS_NAME);
		return -ENOMEM;
	}

	Our_Proc_File->uid 	 = 0;
	Our_Proc_File->gid 	 = 0;
	Our_Proc_File->size 	 = 37;

	sprintf(msg, "Hello World!\n");
	msg_ptr = msg;

	printk(KERN_INFO "[procfs1] /proc/%s created\n", PROCFS_NAME);	
	return 0;	/* everything is ok */
}

void cleanup_module()
{
	remove_proc_entry(PROCFS_NAME, NULL);
	printk(KERN_INFO "[procfs1] /proc/%s removed\n", PROCFS_NAME);
}

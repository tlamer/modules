/* 
 * Copyright (C) 2011  Peter Kotvan <peter.kotvan@gmail.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <linux/module.h>	/* Specifically, a module */
#include <linux/kernel.h>	/* We're doing kernel work */
#include <linux/proc_fs.h>	/* Necessary because we use the proc fs */
#include <asm/uaccess.h>	/* for copy_from_user */
#include <procfs2.h>

#define PROCFS_MAX_SIZE		1024
#define PROCFS_NAME 		"buffer1k"

/**
 * This structure hold information about the /proc file
 *
 */
static struct proc_dir_entry *Our_Proc_File;
static struct file_operations proc_fops = {
	.read = procfile_read,
	.write = procfile_write,
	.open = procfile_open,
	.release = procfile_release
};

/**
 * The buffer used to store character for this module
 *
 */
static char procfs_buffer[PROCFS_MAX_SIZE];
static unsigned long procfs_buffer_size = 0;
static int Device_Open = 0;

static int procfile_open(struct inode *inode, struct file *file){
	
	if (Device_Open)
		return -EBUSY;

	Device_Open++;
//	sprintf(msg, "Hello World!\n");
//	msg_ptr = msg;
	try_module_get(THIS_MODULE);

	return 0;
}

static int procfile_release(struct inode *inode, struct file *file)
{
	Device_Open--;
	module_put(THIS_MODULE);
	return 0;
}

//int 
//procfile_read(char *buffer,
//	      char **buffer_location,
//	      off_t offset, int buffer_length, int *eof, void *data)
//{
//	int ret;
//	
//	printk(KERN_INFO "[procfs2] procfile_read (/proc/%s) called\n", PROCFS_NAME);
//	
//	if (offset > 0) {
//		/* we have finished to read, return 0 */
//		ret  = 0;
//	} else {
//		/* fill the buffer, return the buffer size */
//		memcpy(buffer, procfs_buffer, procfs_buffer_size);
//		ret = procfs_buffer_size;
//	}
//
//	return ret;
//}

static ssize_t procfile_read(struct file *filp,
		char *buffer,
		size_t length,
		loff_t *offset)
{
//	int bytes_read = 0;
//	if (*msg_ptr == 0)
//		return 0;
//
//	while (length && *msg_ptr){
//		put_user(*(msg_ptr++),buffer++);
//
//		length--;
//		bytes_read++;
//	}
//	return bytes_read;
	return 0;
}
/**
 * This function is called with the /proc file is written
 *
 */
//int procfile_write(struct file *file, const char *buffer, unsigned long count,
//		   void *data)
//{
//	/* get buffer size */
//	procfs_buffer_size = count;
//	if (procfs_buffer_size > PROCFS_MAX_SIZE ) {
//		procfs_buffer_size = PROCFS_MAX_SIZE;
//	}
//	
//	/* write data to the buffer */
//	if ( copy_from_user(procfs_buffer, buffer, procfs_buffer_size) ) {
//		return -EFAULT;
//	}
//	
//	return procfs_buffer_size;
//}
static ssize_t
procfile_write(struct file *filp, const char *buff, size_t len, loff_t * off)
{
//	printk(KERN_ALERT "[procfs2] Sorry, this operation isn't supported.\n");
//	return -EINVAL;

	procfs_buffer_size = len;
	if (procfs_buffer_size > PROCFS_MAX_SIZE ) {
		procfs_buffer_size = PROCFS_MAX_SIZE;
	}
	
	/* write data to the buffer */
	if ( copy_from_user(procfs_buffer, buff, procfs_buffer_size) ) {
		return -EFAULT;
	}

	printk(KERN_INFO "[procfs2] %s",procfs_buffer);
	
	return procfs_buffer_size;
}


/**
 *This function is called when the module is loaded
 *
 */
int init_module()
{
	/* create the /proc file */
	Our_Proc_File = proc_create(PROCFS_NAME, S_IFREG | S_IRUGO, NULL, &proc_fops);
	
	if (Our_Proc_File == NULL) {
		remove_proc_entry(PROCFS_NAME, NULL);
		printk(KERN_ALERT "[procfs2] Error: Could not initialize /proc/%s\n",
			PROCFS_NAME);
		return -ENOMEM;
	}

	Our_Proc_File->uid 	  = 0;
	Our_Proc_File->gid 	  = 0;
	Our_Proc_File->size 	  = 37;

	printk(KERN_INFO "[procfs2] /proc/%s created\n", PROCFS_NAME);	
	return 0;	/* everything is ok */
}

/**
 *This function is called when the module is unloaded
 *
 */
void cleanup_module()
{
	remove_proc_entry(PROCFS_NAME, NULL);
	printk(KERN_INFO "[procfs2] /proc/%s removed\n", PROCFS_NAME);
}

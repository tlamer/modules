/* 
 * Pcan communication driver
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


#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/stat.h>
#include <rtdm/rtdm.h>

int pcan_fd0;
int pcan_fd1;
static int __init rtcan_init(void)
{
	const char device0[] = "pcan0"; 
	const char device1[] = "pcan1"; 
	pcan_fd0 = rt_dev_open(device0, 0);
	pcan_fd1 = rt_dev_open(device1, 0);
	printk(KERN_INFO "[rtcan] pcan0 file descriptor: %i\n",pcan_fd0);
	printk(KERN_INFO "[rtcan] pcan1 file descriptor: %i\n",pcan_fd1);
	printk(KERN_INFO "[rtcan] succesfully loaded\n");

	return 0;
}

static void __exit rtcan_exit(void)
{
	int retval0;
	int retval1;
	retval0 = rt_dev_close(pcan_fd0);	
	retval1 = rt_dev_close(pcan_fd1);	
	printk(KERN_INFO "[rtcan] pcan0 closed with exit code: %i\n",retval0);
	printk(KERN_INFO "[rtcan] pcan0 closed with exit code: %i\n",retval1);
	printk(KERN_INFO "[rtcan] succesfully unloaded\n");
}

module_init(rtcan_init);
module_exit(rtcan_exit);

MODULE_AUTHOR("Peter Kotvan");
MODULE_LICENSE("GPL");

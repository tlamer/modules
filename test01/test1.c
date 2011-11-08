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

#include <linux/module.h>
#include <linux/kernel.h>


int init_module(void)
{
    printk("sizeof(int): %d\n",sizeof(int));
//	printk(KERN_INFO "[test1] loading\n");
//	printk(KERN_DEBUG "[test1] debug msg\n");
//	printk(KERN_INFO "[test1] info msg\n");
//	printk(KERN_NOTICE "[test1] notice msg\n");
//	printk(KERN_WARNING "[test1] warning msg\n");
//	printk(KERN_ERR "[test1] error msg\n");
//	printk(KERN_CRIT "[test1] critical msg\n");
//	printk(KERN_ALERT "[test1] alert msg\n");
//	printk(KERN_EMERG "[test1] emergency msg\n");
	return 0;
	//return -1;
}

void cleanup_module(void)
{
	printk(KERN_INFO "[test1] unloading\n");
}

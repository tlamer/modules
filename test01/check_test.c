/* 
 * check_region and check_mem_region test
 * Copyright (C) 2011  Peter Kotvan <peter.kotvan@gmail.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 of the License.
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
#include <linux/fs.h>
#include <linux/ioport.h>
#include <linux/pci.h>

#define ADLINK_PCI_VENDOR_ID 0x144A
#define ADLINK_PCI_DEVICE_ID 0x7841

#define ADLINK_PCI_CONFIG_PORT_SIZE    0x007f
#define ADLINK_PCI_PORT_SIZE           0x00ff

#define PEAK_PCI_VENDOR_ID 0x001C
#define PEAK_PCI_DEVICE_ID 0x0001

#define PEAK_PCI_CONFIG_PORT_SIZE    0x1000
#define PEAK_PCI_PORT_SIZE           0x0400

static int __init check_init(void)
{
    int i,j,k,l;
    struct pci_dev *adlinkDev;
    struct pci_dev *peakDev;
    adlinkDev = pci_get_device (ADLINK_PCI_VENDOR_ID, ADLINK_PCI_DEVICE_ID, NULL);
    peakDev = pci_get_device (PEAK_PCI_VENDOR_ID, PEAK_PCI_DEVICE_ID, NULL);
//    printk (KERN_INFO "adlinkDev->resource[1] length: %p\n", -(adlinkDev->resource[1].start)+adlinkDev->resource[1].end );
//    printk (KERN_INFO "adlinkDev->resource[2] length: %p\n", -(adlinkDev->resource[2].start)+adlinkDev->resource[2].end );
//    printk (KERN_INFO "adlinkDev->resource[3] length: %p\n", -(adlinkDev->resource[2].start)+adlinkDev->resource[2].end );
//
//    printk (KERN_INFO "peakDev->resource[0] length: %p\n", -(peakDev->resource[0].start)+peakDev->resource[0].end );
//    printk (KERN_INFO "peakDev->resource[1] length: %p\n", -(peakDev->resource[1].start)+peakDev->resource[1].end );

    printk (KERN_INFO "adlinkDev->resource[0].start: %p\n", adlinkDev->resource[0].start);
    printk (KERN_INFO "adlinkDev->resource[1].start: %p\n", adlinkDev->resource[1].start);
    printk (KERN_INFO "adlinkDev->resource[2].start: %p\n", adlinkDev->resource[2].start);
    printk (KERN_INFO "adlinkDev->resource[3].start: %p\n", adlinkDev->resource[3].start);
//    printk (KERN_INFO "peakDev->resource[0].start: %p\n", peakDev->resource[0].start);
//    printk (KERN_INFO "peakDev->resource[1].start: %p\n", peakDev->resource[1].start);
//    printk (KERN_INFO "peakDev->resource[2].start: %p\n", peakDev->resource[2].start);
//    printk (KERN_INFO "peakDev->resource[3].start: %p\n", peakDev->resource[3].start);

//    i = check_mem_region(adlinkDev->resource[1].start, ADLINK_PCI_CONFIG_PORT_SIZE);
//    printk(KERN_INFO "check_mem_region adlink resource[1] return value: %i\n",i);
    i = check_region(adlinkDev->resource[1].start, ADLINK_PCI_CONFIG_PORT_SIZE);
    printk(KERN_INFO "check_region adlink resource[1] return value: %i\n",i);
//
//    j = check_mem_region(adlinkDev->resource[2].start, ADLINK_PCI_CONFIG_PORT_SIZE);
//    printk(KERN_INFO "check_mem_region adlink resource[2] return value: %i\n",j);
    j = check_region(adlinkDev->resource[2].start, ADLINK_PCI_PORT_SIZE);
    printk(KERN_INFO "check_region adlink resource[2] return value: %i\n",j);
//
//    k = check_mem_region(peakDev->resource[0].start, PEAK_PCI_CONFIG_PORT_SIZE);
//    printk(KERN_INFO "check_mem_region adlink resource[0] return value: %i\n",k);
//    k = check_region(peakDev->resource[0].start, PEAK_PCI_CONFIG_PORT_SIZE);
//    printk(KERN_INFO "check_region adlink resource[2] return value: %i\n",k);
//
//    l = check_mem_region(peakDev->resource[1].start, PEAK_PCI_CONFIG_PORT_SIZE);
//    printk(KERN_INFO "check_mem_region adlink resource[0] return value: %i\n",l);
//    l = check_region(peakDev->resource[1].start, PEAK_PCI_PORT_SIZE);
//    printk(KERN_INFO "check_region adlink resource[2] return value: %i\n",l);


    return 0;
}

static void __exit check_exit(void)
{

}

module_init(check_init);
module_exit(check_exit);

MODULE_LICENSE("GPL");

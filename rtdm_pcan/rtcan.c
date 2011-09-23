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
#include <linux/slab.h>
#include <linux/stat.h>
#include <rtdm/rtdm.h>
#include <rtcan.h>

#define DEVICE_PATH "/dev/pcan"   // + Minor = real device path
#define LOCAL_STRING_LEN 64

typedef struct
{
	char szVersionString[LOCAL_STRING_LEN];
	char szDevicePath[LOCAL_STRING_LEN];
	int nFileNo;
}PCAN_DESCRIPTOR;

//----------------------------------------------------------------------------
// merge a device file path
static char *szDeviceName(int nMinor)
{
  static char path[LOCAL_STRING_LEN];
  
  path[0] = 0;
  
  if (nMinor > 64)
    return path;
    
  sprintf(path, "%s%d", DEVICE_PATH, nMinor);
  
  return path;
} 

//----------------------------------------------------------------------------
// do a unix like open of the device
HANDLE LINUX_CAN_Open(const char *szDeviceName, int nFlag)
{
	PCAN_DESCRIPTOR *desc = NULL;
	char DeviceName[15];

	//  if ((desc = (PCAN_DESCRIPTOR *)malloc(sizeof(*desc))) == NULL)
	desc = (PCAN_DESCRIPTOR *) kmalloc(sizeof(*desc), GFP_KERNEL);
	if (!desc)
		goto fail;

	desc->szVersionString[0] = 0;
	desc->szDevicePath[0]    = 0;

  	sscanf(szDeviceName, "/dev/%s", DeviceName);
	printk(KERN_INFO "%s",DeviceName);
	if ((desc->nFileNo = rt_dev_open(DeviceName, nFlag)) == -1)
		goto fail;

	strncpy(desc->szDevicePath, DeviceName, LOCAL_STRING_LEN);

	return (HANDLE)desc;

fail:
	if (desc)
	{
		if (desc->nFileNo > -1)
			rt_dev_close(desc->nFileNo);
		kfree(desc);
	}

	return NULL;
}

//----------------------------------------------------------------------------
// do a close of the device
DWORD CAN_Close(HANDLE hHandle)
{
	PCAN_DESCRIPTOR *desc = (PCAN_DESCRIPTOR *)hHandle;

	if (desc)
	{
		{
			rt_dev_close(desc->nFileNo);
			desc->nFileNo = -1;
		}
		kfree(desc);
	}
	return 0;;
}

//----------------------------------------------------------------------------
// init the CAN chip of this device
DWORD CAN_Init(HANDLE hHandle, WORD wBTR0BTR1, int nCANMsgType)
{
  PCAN_DESCRIPTOR *desc = (PCAN_DESCRIPTOR *)hHandle;
  int err = EBADF;
  
  if (desc)
  {
    TPCANInit init;
    
    init.wBTR0BTR1    = wBTR0BTR1;    // combined BTR0 and BTR1 register of the SJA100
    init.ucCANMsgType = (nCANMsgType) ? MSGTYPE_EXTENDED : MSGTYPE_STANDARD;  // 11 or 29 bits
    init.ucListenOnly = 0;            // listen only mode when != 0
    
    if ((err = rt_dev_ioctl(desc->nFileNo, PCAN_INIT, &init)) < 0)
      return err;
  }
  
  return err;
}
        
HANDLE fd0;

static int __init rtcan_init(void)
{
	int err;

	fd0 = LINUX_CAN_Open(szDeviceName(0), O_RDWR);
//	err = CAN_Init(fd0,CAN_BAUD_1M,CAN_INIT_TYPE_ST);

	if(fd0)
	{
		printk(KERN_INFO "[rtcan] pcan0 was succesfully opened\n");
//		printk(KERN_INFO "[rtcan] pcan0 was initialised with status: %i\n",err);
		printk(KERN_INFO "[rtcan] succesfully loaded\n");
	}
	else
		printk(KERN_INFO "[rtcan] error\n");

	return 0;
}

static void __exit rtcan_exit(void)
{
	CAN_Close(fd0);
	printk(KERN_INFO "[rtcan] succesfully unloaded\n");
}

module_init(rtcan_init);
module_exit(rtcan_exit);

MODULE_AUTHOR("Peter Kotvan");
MODULE_LICENSE("GPL");

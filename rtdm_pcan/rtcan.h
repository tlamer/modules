/* 
 * Pcan
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

//****************************************************************************
// INCLUDES
#include <pcan.h>

//****************************************************************************
// compatibilty defines
#if defined(LPSTR) || defined(HANDLE)
#error "double define for LPSTR, HANDLE found"
#endif

#define LPSTR  char *
#define HANDLE void *

//****************************************************************************
// for CAN_Open(...)

//****************************************************************************
// for CAN_Init(...)

// parameter wBTR0BTR1
// bitrate codes of BTR0/BTR1 registers
#define CAN_BAUD_1M     0x0014  //   1 MBit/s
#define CAN_BAUD_500K   0x001C  // 500 kBit/s
#define CAN_BAUD_250K   0x011C  // 250 kBit/s
#define CAN_BAUD_125K   0x031C  // 125 kBit/s
#define CAN_BAUD_100K   0x432F  // 100 kBit/s
#define CAN_BAUD_50K    0x472F  //  50 kBit/s
#define CAN_BAUD_20K    0x532F  //  20 kBit/s
#define CAN_BAUD_10K    0x672F  //  10 kBit/s
#define CAN_BAUD_5K     0x7F7F  //   5 kBit/s

// parameter nCANMsgType
#define CAN_INIT_TYPE_EX		0x01	//Extended Frame
#define CAN_INIT_TYPE_ST		0x00	//Standart Frame

//****************************************************************************
// error codes are defined in pcan.h
#define CAN_ERR_ANYBUSERR (CAN_ERR_BUSLIGHT | CAN_ERR_BUSHEAVY | CAN_ERR_BUSOFF)

//****************************************************************************
//  CAN_Open()
//  creates a path to a CAN port
//
//  for PCAN-Dongle call:             CAN_Open(HW_DONGLE_.., DWORD dwPort, WORD wIrq);
//  for PCAN-ISA or PCAN-PC/104 call: CAN_Open(HW_ISA_SJA, DWORD dwPort, WORD wIrq);
//  for PCAN-PCI call:                CAN_Open(HW_PCI, int nPort); .. enumerate nPort 1..8.
//
//  if ((dwPort == 0) && (wIrq == 0)) CAN_Open() takes the 1st default ISA or DONGLE port.
//  if (nPort == 0) CAN_Open() takes the 1st default PCI port.
//  returns NULL when open failes.
//
//  The first CAN_Open() to a CAN hardware initializes the hardware to default
//  parameter 500 kbit/sec and acceptance of extended frames.
//
HANDLE CAN_Open(WORD wHardwareType, ...);

//****************************************************************************
//  CAN_Init()
//  initializes the CAN hardware with the BTR0 + BTR1 constant "CAN_BAUD_...".
//  nCANMsgType must be filled with "CAN_INIT_TYPE_..".
//  The default initialisation, e.g. CAN_Init is not called,
//  is 500 kbit/sec and extended frames.
//
DWORD CAN_Init(HANDLE hHandle, WORD wBTR0BTR1, int nCANMsgType);

//****************************************************************************
//  CAN_Close()
//  closes the path to the CAN hardware.
//  The last close on the hardware put the chip into passive state.
DWORD CAN_Close(HANDLE hHandle);


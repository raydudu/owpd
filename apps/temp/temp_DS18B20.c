//---------------------------------------------------------------------------
// Copyright (C) 2000 Dallas Semiconductor Corporation, All Rights Reserved.
//
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY,  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL DALLAS SEMICONDUCTOR BE LIABLE FOR ANY CLAIM, DAMAGES
// OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.
//
// Except as contained in this notice, the name of Dallas Semiconductor
// shall not be used except as stated in the Dallas Semiconductor
// Branding Policy.
//---------------------------------------------------------------------------
//
//  temp.c -   Application to find and read the 1-Wire Net
//             DS18B20 - temperature measurement.
//
//             This application uses the files from the 'Public Domain'
//             1-Wire Net libraries ('general' and 'userial').
//
//
//  Version: 2.00
//

#include <stdlib.h>
#include <stdio.h>
#include "ownet.h"
#include "findtype.h"

//----------------------------------------------------------------------
// Read the temperature of a DS18B20
//
// 'portnum'     - number 0 to MAX_PORTNUM-1.  This number was provided to
//                 OpenCOM to indicate the port number.
// 'SerialNum'   - Serial Number of DS18B20 to read temperature from
// 'Temp '       - pointer to variable where that temperature will be
//                 returned
//
// Returns: TRUE(1)  temperature has been read and verified
//          FALSE(0) could not read the temperature, perhaps device is not
//                   in contact
//
static int DS18B20_ReadTempInC(int portnum, uchar *SerialNum, float *Temp)
{
    uchar rt=FALSE;
    uchar send_block[30],lastcrc8;
    int send_cnt, i, loop;

    // set the device serial number to the counter device
    owSerialNum(portnum,SerialNum,FALSE);

    for (loop = 0; loop < 2; loop ++)
    {
        // access the device
        if (owAccess(portnum))
        {
            // send the convert command and start power delivery
            if (!owWriteBytePower(portnum,0x44))
                return FALSE;

            // sleep for 800 ms
            msDelay(800);

            // turn off the 1-Wire Net strong pull-up
            if (owLevel(portnum,MODE_NORMAL) != MODE_NORMAL)
                return FALSE;

            // access the device
            if (owAccess(portnum))
            {
                // create a block to send that reads the temperature
                // read scratchpad command
                send_cnt = 0;
                send_block[send_cnt++] = 0xBE;
                // now add the read bytes for data bytes and crc8
                for (i = 0; i < 9; i++)
                    send_block[send_cnt++] = 0xFF;

                // now send the block
                if (owBlock(portnum,FALSE,send_block,send_cnt))
                {
                    // initialize the CRC8
                    setcrc8(portnum,0);
                    // perform the CRC8 on the last 8 bytes of packet
                    for (i = send_cnt - 9; i < send_cnt; i++)
                        lastcrc8 = docrc8(portnum,send_block[i]);

                    // verify CRC8 is correct
                    if (lastcrc8 == 0x00)
                    {
                        int16_t temp = send_block[2];
                        temp <<=8;
                        temp |= send_block[1];

                        *Temp = temp;
                        *Temp /= 16.0f;

                        // success
                        rt = TRUE;
                        break;
                    }
                }
            }
        }

    }

    // return the result flag rt
    return rt;
}


// defines
#define MAXDEVICES         20

// global serial numbers
uchar FamilySN[MAXDEVICES][8];

int main(int argc, char **argv)
{
   float current_temp;
   int i = 0;
   int NumDevices=0;
   int portnum = 0;

   //----------------------------------------
   // Introduction header
   printf("\n/---------------------------------------------\n");
   printf("  Temperature application DS18B20 - Version 1.00 \n");

   printf("  Press any CTRL-C to stop this program.\n\n");
   printf("  Output [Serial Number(s) ........ Temp1(F)] \n\n");

   // check for required port name
   if (argc != 2)
   {
      printf("1-Wire Net name required on command line!\n"
             " (example: \"COM1\" (Win32 DS2480),\"/dev/cua0\" "
             "(Linux DS2480),\"{1,5}\" (Win32 TMEX), DS2490-1 (DS2490 USB)\n");
      exit(1);
   }


   // attempt to acquire the 1-Wire Net
   if((portnum = owAcquireEx(argv[1])) < 0)
   {
      OWERROR_DUMP(stdout);
      exit(1);
   }

   // success
   printf("Port opened: %s\n",argv[1]);

   // Find the device(s)
   NumDevices = FindDevices(portnum, &FamilySN[0], 0x28, MAXDEVICES);
   if (NumDevices>0)
   {
      printf("\n");
      printf("Device(s) Found: \n");
      for (i = 0; i < NumDevices; i++)
      {
         PrintSerialNum(FamilySN[i]);
         printf("\n");
      }
      printf("\n\n");

      // (stops on CTRL-C)
      do
      {
         // read the temperature and print serial number and temperature
         for (i = 0; i < NumDevices; i++)
         {

            if (DS18B20_ReadTempInC(portnum, FamilySN[i], &current_temp))
            {
               PrintSerialNum(FamilySN[i]);
               printf("     %5.1f °C\n", current_temp);
              // converting temperature from Celsius to Fahrenheit
            }
            else
               printf("     Error reading temperature, verify device present:%d\n",
                       (int)owVerify(portnum, FALSE));
         }
         printf("\n");
      }
      while (!key_abort());
   }
   else
      printf("\n\n\nERROR, device DS18B20 not found!\n");

   // release the 1-Wire Net
   owRelease(portnum);
   printf("Closing port %s.\n", argv[1]);

   return 0;
}


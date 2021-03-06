//*****************************************************************************
// Copyright (c) 2014 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
//   Redistribution and use in source and binary forms, with or without
//   modification, are permitted provided that the following conditions
//   are met:
// 
//   Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the  
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// This file was automatically generated by the Tiva C Series PinMux Utility
// Version: 1.0.4
//
//*****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include "toggle_PinMux.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/gpio.h"

#define 	RED_MASK 		0x08

//*****************************************************************************
//
//!
//! A very simple example that toggles the on-board blue LED using PinMux for 
//! port initialization and functions in Peripheral Driver Library for port access
//
//*****************************************************************************
void
PortFunctionInit(void)
{
    //
    // Enable Peripheral Clocks 
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    //
    // Enable pin PF1 for GPIOOutput
    //
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3);
}

int main(void)
{
    uint8_t LED_data;
	
		//initialize the GPIO ports	
		PortFunctionInit();
	
    // Turn on the LED.
    LED_data= 0x02;
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, LED_data);
    
    //
    // Loop forever.
    //
    while(1)
    {
        // Delay for a bit.
				SysCtlDelay(10000000);	

        // Toggle the LED.
        LED_data^=RED_MASK;	//toggle red LED (PF1)
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, LED_data);
    }
}

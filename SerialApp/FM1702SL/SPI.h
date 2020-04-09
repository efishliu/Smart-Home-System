/**************************************************************************************************
  Filename:       sb_main.h
  Revised:        $Date: 2010-03-10 20:36:55 -0800 (Wed, 10 Mar 2010) $
  Revision:       $Revision: 21890 $

  Description:    Serial Bootloader Main functionality.

  Copyright 2010 Texas Instruments Incorporated. All rights reserved.

  IMPORTANT: Your use of this Software is limited to those specific rights
  granted under the terms of a software license agreement between the user
  who downloaded the software, his/her employer (which must be your employer)
  and Texas Instruments Incorporated (the "License").  You may not use this
  Software unless you agree to abide by the terms of the License. The License
  limits your use, and you acknowledge, that the Software may not be modified,
  copied or distributed unless embedded on a Texas Instruments microcontroller
  or used solely and exclusively in conjunction with a Texas Instruments radio
  frequency transceiver, which is integrated into your product.  Other than for
  the foregoing purpose, you may not use, reproduce, copy, prepare derivative
  works of, modify, distribute, perform, display or sell this Software and/or
  its documentation for any purpose.

  YOU FURTHER ACKNOWLEDGE AND AGREE THAT THE SOFTWARE AND DOCUMENTATION ARE
  PROVIDED �AS IS?WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
  INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE, 
  NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL
  TEXAS INSTRUMENTS OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT,
  NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER
  LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
  INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE
  OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT
  OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
  (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

  Should you have any questions regarding your right to use this Software,
  contact Texas Instruments Incorporated at www.TI.com. 
**************************************************************************************************/
#ifndef SB_MAIN_H
#define SB_MAIN_H

/* ------------------------------------------------------------------------------------------------
 *                                          Includes
 * ------------------------------------------------------------------------------------------------
 */

#include "hal_types.h"

/* ------------------------------------------------------------------------------------------------
 *                                           Macros
 * ------------------------------------------------------------------------------------------------
 */

#define HAL_UART_SPI_RX_AVAIL() \
  (spiCfg.rxTail >= spiCfg.rxHead) ? \
  (spiCfg.rxTail - spiCfg.rxHead) : \
  (HAL_UART_SPI_RX_MAX - spiCfg.rxHead + spiCfg.rxTail)

#define HAL_UART_SPI_TX_AVAIL() \
  (spiCfg.txHead > spiCfg.txTail) ? \
  (spiCfg.txHead - spiCfg.txTail - 1) : \
  (HAL_UART_SPI_TX_MAX - spiCfg.txTail + spiCfg.txHead - 1)

/*********************************************************************
 * CONSTANTS
 */


// UxCSR - USART Control and Status Register.
#define CSR_MODE                   0x80
#define CSR_RE                     0x40
#define CSR_SLAVE                  0x20
#define CSR_FE                     0x10
#define CSR_ERR                    0x08
#define CSR_RX_BYTE                0x04
#define CSR_TX_BYTE                0x02
#define CSR_ACTIVE                 0x01

// UxUCR - USART UART Control Register.
#define UCR_FLUSH                  0x80
#define UCR_FLOW                   0x40
#define UCR_D9                     0x20
#define UCR_BIT9                   0x10
#define UCR_PARITY                 0x08
#define UCR_SPB                    0x04
#define UCR_STOP                   0x02
#define UCR_START                  0x01

#define UTX0IE                     0x04
#define UTX1IE                     0x08

#define P2DIR_PRIPO                0xC0

#define HAL_UART_PERCFG_BIT        0x02         // USART1 on P1, Alt-2; so set this bit.

#if !defined HAL_UART_SPI_RX_MAX
#define HAL_UART_SPI_RX_MAX        128
#endif
#if !defined HAL_UART_SPI_TX_MAX
#define HAL_UART_SPI_TX_MAX        128
#endif

#define  cs  P1_4
#define  si  P1_6
#define  sck P1_5
#define  so  P1_7
 
/*********************************************************************
 * TYPEDEFS
 */

typedef struct
{
  uint8 rxBuf[HAL_UART_SPI_RX_MAX]; //����buf
  uint8 rxHead;
  volatile uint8 rxTail;
  uint8 txBuf[HAL_UART_SPI_TX_MAX]; //����buf
  volatile uint8 txHead;
  uint8 txTail;
} uartSPICfg_t;

/* ------------------------------------------------------------------------------------------------
 *                                       Global Functions
 * ------------------------------------------------------------------------------------------------
 */
extern void HalUARTInitSPI(void);
extern int8  SPIOneByte(int8 x);

#endif

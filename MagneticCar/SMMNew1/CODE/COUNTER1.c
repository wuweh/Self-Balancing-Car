/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : COUNTER1.C
**     Project   : SMMNew1
**     Processor : 56F8013VFAE
**     Component : EventCntr16
**     Version   : Component 02.135, Driver 02.04, CPU db: 2.87.097
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 2012-2-3, 17:35
**     Abstract  :
**         This bean "EventCntr16" implements an 16-bit event counter.
**         It counts the external events (specified edges of the external
**         signal). It uses a hardware timer counter.
**         The counter width is extended or taperred to 16 bits.
**     Settings  :
**         Timer name                  : TMR0 [16-bit]
**
**         Counting mode               : Simple counter
**
**         Used input pin              : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       19            |  GPIOB4_T0_CLKO
**             ----------------------------------------------------
**
**         Initialization:
**              Timer                  : Enabled
**              Events                 : Enabled
**
**         Timer registers
**         Counter register            : TMR0_CNTR [61445]
**         Mode register               : TMR0_CTRL [61446]
**         Run register                : TMR0_CTRL [61446]
**     Contents  :
**         Reset        - byte COUNTER1_Reset(void);
**         GetNumEvents - byte COUNTER1_GetNumEvents(word *Value);
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE COUNTER1. */

#include "COUNTER1.h"

volatile static bool Overflow;         /* Internal overflow flag */

/*
** ===================================================================
**     Method      :  COUNTER1_Reset (component EventCntr16)
**
**     Description :
**         This method resets the external event counter (sets it to
**         zero).
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
** ===================================================================
*/
byte COUNTER1_Reset(void)
{
  setReg(TMR0_CNTR,0);                 /* Set counter register */
  Overflow = FALSE;                    /* Clear internal overflow flag */
  return ERR_OK;                       /* Return OK */
}

/*
** ===================================================================
**     Method      :  COUNTER1_GetNumEvents (component EventCntr16)
**
**     Description :
**         This method returns the number of the external events.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Value           - A pointer to the returned number of
**                           the external events
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_OVERFLOW - Timer overflow
** ===================================================================
*/
byte COUNTER1_GetNumEvents(word *Value)
{
  *Value = getReg(TMR0_CNTR);          /* Get number of events */
  if (Overflow)                        /* If an overflow of the counter occured */
    return ERR_OVERFLOW;               /* Return overflow error */
  return ERR_OK;                       /* Return OK */
}


/*
** ===================================================================
**     Method      :  COUNTER1_Interrupt (component EventCntr16)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes the beans event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
#pragma interrupt alignsp saveall
void COUNTER1_Interrupt(void)
{
  clrRegBit(TMR0_SCR,TOF);             /* Clear overflow interrupt flag */
  Overflow = TRUE;                     /* Set an internal overflow flag */
}

/*
** ===================================================================
**     Method      :  COUNTER1_Init (component EventCntr16)
**
**     Description :
**         Initializes the associated peripheral(s) and the beans 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void COUNTER1_Init(void)
{
  /* TMR0_CTRL: CM=0,PCS=0,SCS=0,ONCE=0,LENGTH=0,DIR=0,Co_INIT=0,OM=0 */
  setReg(TMR0_CTRL,0);                 /* Stop all functions of the timer */
  /* TMR0_SCR: TCF=0,TCFIE=0,TOF=0,TOFIE=1,IEF=0,IEFIE=0,IPS=0,INPUT=0,Capture_Mode=0,MSTR=0,EEOF=0,VAL=0,FORCE=0,OPS=0,OEN=0 */
  setReg(TMR0_SCR,4096);               /* Enable interrupt on overflow, select input edge polarity */
  /* TMR0_COMSCR: DBG_EN=0,??=0,??=0,??=0,??=0,??=0,??=0,TCF2EN=0,TCF1EN=0,TCF2=0,TCF1=0,CL2=0,CL1=0 */
  setReg(TMR0_COMSCR,0);               /* Disable interrupt on compare, disable compare preload */
  setReg(TMR0_CNTR,0);                 /* Initialize counter register */
  /* TMR0_CTRL: CM=1,PCS=0,SCS=0,ONCE=0,LENGTH=0,DIR=0,Co_INIT=0,OM=0 */
  setReg(TMR0_CTRL,8192);              /* Initialize timer control register */
}

/* END COUNTER1. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/
/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : PWMC1.C
**     Project   : SMMNew1
**     Processor : 56F8013VFAE
**     Component : PWMMC
**     Version   : Component 01.703, Driver 01.31, CPU db: 2.87.097
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 2012-2-11, 17:22
**     Abstract  :
**         This bean "PWMMC" implements 6-channel center-aligned or 
**         edge-aligned pulse-width modulator for AC motor control, which 
**         is presented on chip. The device is capable of controlling most 
**         motor types: AC induction motors (ACIM), both brushless (BLDC) 
**         and brush DC motors (BDC), switched (SRM) and variable reluctance  
**         motors (VRM),and stepper motors.
**         Another possibility of using this bean is as a pulse-width modulation 
**         generator that generates 6 signals with variable duty and fixed cycle.
**     Settings  :
**          Component name                                 : PWMC1
**          Device                                         : PWM_Timer
**          Align                                          : center-aligned mode
**          Mode of PWM Pair 0                             : independent
**          Mode of PWM Pair 1                             : independent
**          Mode of PWM Pair 2                             : complementary
**          Top-Side PWM Pair 0 Polarity                   : Positive
**          Top-Side PWM Pair 1 Polarity                   : Positive
**          Top-Side PWM Pair 2 Polarity                   : Positive
**          Bottom-Side PWM Pair 0 Polarity                : Positive
**          Bottom-Side PWM Pair 1 Polarity                : Positive
**          Bottom-Side PWM Pair 2 Polarity                : Positive
**          Write Protect                                  : no
**          Output pads                                    : Enabled
**          Enable in Wait mode                            : no
**          Enable in EnOnCE mode                          : no
**          Reload                                         : 1
**          Half cycle reload                              : no
**          Hardware acceleration                          : Disabled
**          Frequency/period                               : 5 kHz
**          Output Frequency                               : 2.5 kHz
**          Same frequency in modes                        : no
**          Dead-time                                      : 0 �s
**          Dead-time 1                                    : 0 �s
**          Correction                                     : Enabled
**            Correction                                   : method 1
**            Internal correction logic                    : Disabled
**            PWM pairs                                    : PWM Pair 0, 1, 2
**              PWM Pair 0                                 : top
**              PWM Pair 1                                 : top
**              PWM Pair 2                                 : top
**          Interrupt service/event                        : Disabled
**          Channel 0                                      : 
**            Channel                                      : PWMod0
**            PWM pin                                      : GPIOA0_PWM0
**            PWM pin signal                               : 
**            Duty                                         : 0 %
**            Pin PWM0 active                              : no
**            Output software control                      : no
**            PWM compare invert                           : no
**            Mask channel                                 : no
**            Mask fault 0                                 : yes
**            Mask fault 1                                 : yes
**            Mask fault 2                                 : yes
**            Mask fault 3                                 : yes
**          Channel 1                                      : Enabled
**            Channel                                      : PWMod1
**            PWM pin                                      : GPIOA1_PWM1
**            PWM pin signal                               : 
**            Duty                                         : 0 %
**            Pin PWM1 active                              : no
**            Output software control                      : no
**            PWM compare invert                           : no
**            Mask channel                                 : no
**            Mask fault 0                                 : yes
**            Mask fault 1                                 : yes
**            Mask fault 2                                 : yes
**            Mask fault 3                                 : yes
**          Channel 2                                      : Enabled
**            Channel                                      : PWMod2
**            PWM pin                                      : GPIOA2_PWM2
**            PWM pin signal                               : 
**            Duty                                         : 0 %
**            Pin PWM2 active                              : no
**            Output software control                      : no
**            PWM compare invert                           : no
**            Mask channel                                 : no
**            Mask fault 0                                 : yes
**            Mask fault 1                                 : yes
**            Mask fault 2                                 : yes
**            Mask fault 3                                 : yes
**          Channel 3                                      : Enabled
**            Channel                                      : PWMod3
**            PWM pin                                      : GPIOA3_PWM3
**            PWM pin signal                               : 
**            Duty                                         : 0 %
**            Pin PWM3 active                              : no
**            Output software control                      : no
**            PWM compare invert                           : no
**            Mask channel                                 : no
**            Mask fault 0                                 : yes
**            Mask fault 1                                 : yes
**            Mask fault 2                                 : yes
**            Mask fault 3                                 : yes
**          Channel 4                                      : Disabled
**          Channel 5                                      : Disabled
**          Fault protection                               : controlled by this component
**            Fault 0                                      : Disabled
**            Fault 1                                      : Disabled
**            Fault 2                                      : Enabled
**              Fault pin                                  : GPIOA5_PWM5_FAULT2_T3
**              Fault pin signal                           : 
**              Fault clearing mode                        : automatic
**            Fault 3                                      : Disabled
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Events enabled in init.                      : yes
**          CPU clock/speed selection                      : 
**            High speed mode                              : This component enabled
**            Low speed mode                               : This component disabled
**            Slow speed mode                              : This component disabled
**          Simulation output mode                         : PWM
**          High output value                              : 1.0
**          Low output value                               : 0.0
**     Contents  :
**         SetDuty          - byte PWMC1_SetDuty(byte Channel, PWMC1_TPWMMC_Duty Duty);
**         Load             - void PWMC1_Load(void);
**         SetRatio16       - byte PWMC1_SetRatio16(byte Channel, word Ratio);
**         SetRatio15       - byte PWMC1_SetRatio15(byte Channel, int16_t Ratio);
**         OutputPadEnable  - void PWMC1_OutputPadEnable(void);
**         OutputPadDisable - void PWMC1_OutputPadDisable(void);
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/


/* MODULE PWMC1. */

#include "PWMC1.h"


/*
** ===================================================================
**     Method      :  PWMC1_Init (component PWMMC)
**
**     Description :
**         Initializes the associated peripheral(s) and the bean internal 
**         variables. The method is called automatically as a part of the 
**         application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void PWMC1_Init(void)
{
  /* PWM_PMCTL: LDFQ=0,HALF=0,IPOL2=0,IPOL1=0,IPOL0=0,PRSC=0,PWMRIE=0,PWMF=0,??=0,??=0,LDOK=0,PWMEN=0 */
  setReg16(PWM_PMCTL, 0U);             /* Set up PWM control register */ 
  /* PWM_PMFCTL: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,FIE3=0,FMODE3=0,FIE2=0,FMODE2=1,FIE1=0,FMODE1=0,FIE0=0,FMODE0=0 */
  setReg16(PWM_PMFCTL, 16U);           /* Set up Fault Control Register */ 
  /* PWM_PMICCR: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,ICC2=0,ICC1=0,ICC0=0 */
  setReg16(PWM_PMICCR, 0U);            /* Set up Internal Correction Control Register */ 
  /* PWM_PMDISMAP1: DISMAP=0 */
  setReg16(PWM_PMDISMAP1, 0U);          
  /* PWM_PMDISMAP2: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,DISMAP=0 */
  setReg16(PWM_PMDISMAP2, 0U);          
  /* PWM_PMOUT: PAD_EN=1,??=0,OUTCTL=0,??=0,??=0,OUT=0 */
  setReg16(PWM_PMOUT, 32768U);          
  /* PWM_PMCCR: ENHA=0,nBX=0,MSK=0,??=0,??=0,VLMODE=0,??=0,SWP45=0,SWP23=0,SWP01=0 */
  setReg16(PWM_PMCCR, 0U);              
  /* PWM_PMSRC: ??=0,??=0,CINV5=0,CINV4=0,CINV3=0,CINV2=0,CINV1=0,CINV0=0,SRC2=0,SRC1=0,SRC0=0 */
  setReg16(PWM_PMSRC, 0U);              
  /* PWM_PMDEADTM0: ??=0,??=0,??=0,??=0,PWMDT0=0 */
  setReg16(PWM_PMDEADTM0, 0U);          
  /* PWM_PMDEADTM1: ??=0,??=0,??=0,??=0,PWMDT1=0 */
  setReg16(PWM_PMDEADTM1, 0U);          
  /* PWM_PWMVAL0: VAL=0 */
  setReg16(PWM_PWMVAL0, 0U);            
  /* PWM_PWMVAL1: VAL=0 */
  setReg16(PWM_PWMVAL1, 0U);            
  /* PWM_PWMVAL2: VAL=0 */
  setReg16(PWM_PWMVAL2, 0U);            
  /* PWM_PWMVAL3: VAL=0 */
  setReg16(PWM_PWMVAL3, 0U);            
  /* PWM_PWMCM: ??=0,CM=6400 */
  setReg16(PWM_PWMCM, 6400U);           
  /* PWM_PMCFG: ??=0,DBG_EN=0,WAIT_EN=0,EDG=0,??=0,TOPNEG45=0,TOPNEG23=0,TOPNEG01=0,??=0,BOTNEG45=0,BOTNEG23=0,BOTNEG01=0,INDEP45=0,INDEP23=1,INDEP01=1,WP=0 */
  setReg16(PWM_PMCFG, 6U);             /* Set up PWM configure register */ 
  /* PWM_PMCTL: LDOK=1 */
  setReg16Bits(PWM_PMCTL, 2U);         /* Load counter and modulo registers into buffers */ 
  /* PWM_PMCTL: PWMEN=1 */
  setReg16Bits(PWM_PMCTL, 1U);         /* Run counter */ 
  /* PWM_PMCTL: PWMF=1 */
  setReg16Bits(PWM_PMCTL, 16U);        /* Clear reload flag made by PWMEN bit */ 

}

/*
** ===================================================================
**     Method      :  PWMC1_SetDuty (component PWMMC)
**
**     Description :
**         Setting duty (value) register(s) of selected channel. The
**         value is loaded after calling <Load> method.
**         
**         Version specific information for Freescale 56800/E and HC08
**         and HCS12 and HCS12X derivatives ] 
**         Setting is valid for actual speed mode only, initial value
**         is restored after speed mode change.
**         
**         Version specific information for Freescale 56800/E
**         derivatives - eFlexPWM device ] 
**         Duty register(s) value is not affected during speed mode
**         change. It should be handled by the user code.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Channel         - Channel number (0 - 5). The number
**                           corresponds to the logical channel number
**                           assigned in the component settings, which
**                           may not correspond to channel number of the
**                           peripheral.
**         Duty            - Duty value for selected channel.
**                           
**                           Writing a number less than or equal to 0
**                           causes the PWM to be off for the entire PWM
**                           period. Writing a number greater than or
**                           equal to the 15 bit (12-bit on HC08MR32 CPU)
**                           modulus causes the PWM to be on for the
**                           entire PWM period.
**                           
**                           Version specific information for Freescale
**                           56800/E derivatives - eFlexPWM device ] 
**                           Parameter duty is an unsigned value. 
**                           - _edge-aligned mode:_ parameter value is
**                           written into PWM clear-edge
**                           (eFlexPWM_SMn_FRACVALx) register; PWM
**                           set-edge (eFlexPWM_SMn_FRACVALx) register
**                           is not affected (zero value assumed); where
**                           x = 2, 4. 
**                           - _center-aligned mode:_ parameter value is
**                           split between PWM set-edge
**                           (eFlexPWM_SMn_FRACVALx) and PWM clear-edge
**                           (eFlexPWM_SMn_FRACVAL(x+1)) registers;
**                           where x = 2, 4.
**     Returns     :
**         ---             - Error code, possible codes: 
**                           - ERR_OK - OK 
**                           - ERR_NOTAVAIL - Channel is disabled 
**                           - ERR_RANGE - Parameter Channel is out of
**                           range
** ===================================================================
*/
byte PWMC1_SetDuty(byte Channel,PWMC1_TPWMMC_Duty Duty)
{
  switch (Channel) {
  case 0 :
      setReg(PWM_PWMVAL0,Duty);        /* Store value to the duty-compare register 0 */
      break;
  case 1 :
      setReg(PWM_PWMVAL1,Duty);        /* Store value to the duty-compare register 1 */
      break;
  case 2 :
      setReg(PWM_PWMVAL2,Duty);        /* Store value to the duty-compare register 2 */
      break;
  case 3 :
      setReg(PWM_PWMVAL3,Duty);        /* Store value to the duty-compare register 3 */
      break;
  case 4 :
      return ERR_NOTAVAIL;
  case 5 :
      return ERR_NOTAVAIL;
  default: return ERR_RANGE;
  }
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  PWMC1_Load (component PWMMC)
**
**     Description :
**         Apply last setting of the methods <SetDuty>, <SetDutyPercent>,
**         both <SetRatio*>, <SetPeriod> and <SetPrescaler>.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void PWMC1_Load(void)

**  This method is implemented as a macro. See PWMC1.h file.  **

*/

/*
** ===================================================================
**     Method      :  PWMC1_OutputPadEnable (component PWMMC)
**
**     Description :
**         Method enables output pads.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void PWMC1_OutputPadEnable(void)

**  This method is implemented as a macro. See PWMC1.h file.  **

*/

/*
** ===================================================================
**     Method      :  PWMC1_OutputPadDisable (component PWMMC)
**
**     Description :
**         Method disables output pads.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void PWMC1_OutputPadDisable(void)

**  This method is implemented as a macro. See PWMC1.h file.  **

*/

/*
** ===================================================================
**     Method      :  PWMC1_SetRatio16 (component PWMMC)
**
**     Description :
**         This method sets a new duty-cycle ratio for selected channel.
**         The value is loaded after calling <Load> method.
**         
**         Version specific information for Freescale 56800/E and HC08
**         and HCS12 and HCS12X derivatives ] 
**         Setting is valid for actual speed mode only, initial value
**         is restored after speed mode change.
**         
**         Version specific information for Freescale 56800/E
**         derivatives - eFlexPWM device ] 
**         Settings is not affected during speed mode change. It should
**         be handled by the user code.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Channel         - channel number (0 - 5). The number
**                           corresponds to the logical channel number
**                           assigned in the component settings, which
**                           may not correspond to channel number of the
**                           peripheral.
**         Ratio           - Ratio is expressed as an 16-bit
**                           unsigned integer number. 0 - 65535 value is
**                           proportional to ratio 0 - 100%.
**                           
**                           Version specific information for Freescale
**                           56800/E derivatives - eFlexPWM device ] 
**                           - _edge-aligned mode:_ value computed from
**                           parameter is written into PWM clear-edge
**                           (eFlexPWM_SMn_FRACVALx) register; PWM
**                           set-edge (eFlexPWM_SMn_FRACVALx) register
**                           is not affected (zero value assumed); where
**                           x = 2, 4. 
**                           - _center-aligned mode:_ value computed
**                           from parameter value is split between PWM
**                           set-edge (eFlexPWM_SMn_FRACVALx) and PWM
**                           clear-edge (eFlexPWM_SMn_FRACVAL(x+1))
**                           registers; where x = 2, 4.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_NOTAVAIL - Channel is disabled
**                           ERR_RANGE - Parameter Channel is out of
**                           range
** ===================================================================
*/
byte PWMC1_SetRatio16(byte Channel,word Ratio)
{
  register word dutyreg;

  dutyreg = (word)((dword)getReg(PWM_PWMCM)*Ratio/65535); /* Calculate real duty */
  switch (Channel) {
  case 0 :
      setReg(PWM_PWMVAL0,dutyreg);     /* Store ratio value to the duty-compare register 0 */
      break;
  case 1 :
      setReg(PWM_PWMVAL1,dutyreg);     /* Store ratio value to the duty-compare register 1 */
      break;
  case 2 :
      setReg(PWM_PWMVAL2,dutyreg);     /* Store ratio value to the duty-compare register 2 */
      break;
  case 3 :
      setReg(PWM_PWMVAL3,dutyreg);     /* Store ratio value to the duty-compare register 3 */
      break;
  case 4 :
      return ERR_NOTAVAIL;
  case 5 :
      return ERR_NOTAVAIL;
  default: return ERR_RANGE;
  }
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  PWMC1_SetRatio15 (component PWMMC)
**
**     Description :
**         This method sets a new duty-cycle ratio for selected channel.
**         The value is loaded after calling <Load> method.
**         
**         Version specific information for Freescale 56800/E and HC08
**         and HCS12 and HCS12X derivatives ] 
**         Setting is valid for actual speed mode only, initial value
**         is restored after speed mode change.
**         
**         Version specific information for Freescale 56800/E
**         derivatives - eFlexPWM device ] 
**         Settings is not affected during speed mode change. It should
**         be handled by the user code.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Channel         - channel number (0 - 5). The number
**                           corresponds to the logical channel number
**                           assigned in the component settings, which
**                           may not correspond to channel number of the
**                           peripheral.
**         Ratio           - Ratio is expressed as an 16-bit signed
**                           integer number. 0 - 32767 value is
**                           proportional to ratio 0 - 100%. Value
**                           under 0 corresponds to 0% ratio.
**                           
**                           Version specific information for Freescale
**                           56800/E derivatives - eFlexPWM device ] 
**                           - _edge-aligned mode:_ value computed from
**                           parameter is written into PWM clear-edge
**                           (eFlexPWM_SMn_FRACVALx) register; PWM
**                           set-edge (eFlexPWM_SMn_FRACVALx) register
**                           is not affected (zero value assumed); where
**                           x = 2, 4. 
**                           - _center-aligned mode:_ value computed
**                           from parameter value is split between PWM
**                           set-edge (eFlexPWM_SMn_FRACVALx) and PWM
**                           clear-edge (eFlexPWM_SMn_FRACVAL(x+1))
**                           registers; where x = 2, 4.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_NOTAVAIL - Channel is disabled
**                           ERR_RANGE - Parameter Channel or Ratio is
**                           out of range
** ===================================================================
*/
byte PWMC1_SetRatio15(byte Channel,int Ratio)
{
  register word dutyreg;

  dutyreg = (word)((dword)getReg(PWM_PWMCM)*Ratio/32767); /* Calculate real duty from percent value */
  switch (Channel) {
  case 0 :
      setReg(PWM_PWMVAL0,dutyreg);     /* Store ratio value to the duty-compare register 0 */
      break;
  case 1 :
      setReg(PWM_PWMVAL1,dutyreg);     /* Store ratio value to the duty-compare register 1 */
      break;
  case 2 :
      setReg(PWM_PWMVAL2,dutyreg);     /* Store ratio value to the duty-compare register 2 */
      break;
  case 3 :
      setReg(PWM_PWMVAL3,dutyreg);     /* Store ratio value to the duty-compare register 3 */
      break;
  case 4 :
      return ERR_NOTAVAIL;
  case 5 :
      return ERR_NOTAVAIL;
  default: return ERR_RANGE;
  }
  return ERR_OK;
}

/* END PWMC1. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/

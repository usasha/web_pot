/*******************************************************************************
**  DAVE App Name : RTC       App Version: 4.0.1               
**  This file is generated by DAVE, User modification to this file will be    **
**  overwritten at the next code generation.                                  **
*******************************************************************************/


/*******************************************************************************
 Copyright (c) 2015, Infineon Technologies AG                                 **
 All rights reserved.                                                         **
																			  **
 Redistribution and use in source and binary forms, with or without           **
 modification,are permitted provided that the following conditions are met:   **
																			  **
 *Redistributions of source code must retain the above copyright notice,      **
 this list of conditions and the following disclaimer.                        **
 *Redistributions in binary form must reproduce the above copyright notice,   **
 this list of conditions and the following disclaimer in the documentation    **
 and/or other materials provided with the distribution.                       **
 *Neither the name of the copyright holders nor the names of its contributors **
 may be used to endorse or promote products derived from this software without**
 specific prior written permission.                                           **
																			  **
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  **
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    **
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   **
 ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   **
 LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         **
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         **
 SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    **
 INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      **
 CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)       **
 ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   **
 POSSIBILITY OF SUCH DAMAGE.                                                  **
																			  **
 To improve the quality of the software, users are encouraged to share        **
 modifications, enhancements or bug fixes with Infineon Technologies AG       **
 dave@infineon.com).                                                          **
																			  **
********************************************************************************
**                                                                            **
**                                                                            **
** PLATFORM : Infineon XMC4000/XMC1000 Series                                 **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR   : APP Developer                                                   **
**                                                                            **
** NOTE     : Any Changes made to this file will be overwritten during Code   **
**            Generation                                                      **
**                                                                            **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
** Version History:                                                           **
********************************************************************************
** v4.0.0    16 Feb 2015  Initial version									  **
*******************************************************************************/

/**
 *******************************************************************************
 *
 * @file rtc_conf.c
 *
 
 *
 * @brief Handle definitions based on UI configuration for RTC APP
 *        Instances.
*/

/*******************************************************************************
 ** Include Files:                                                            **
 ******************************************************************************/
#include "rtc.h"
	

const RTC_CONFIG_t RTC_0_config  = 
{

  /* RTC start at Initialization */
  .start = RTC_START_ENABLE,

  /* Event trigger to SCU interrupt enabled */
  .eventtrig_timer = RTC_EVENTTRIGSCU_TIMER_ENABLE,

  /* Timer Periodic seconds interrupt disabled */
  .periodic_sec_intr = RTC_PERIODICSECINT_DISABLE,

  /* Timer Periodic minutes interrupt disabled */
  .periodic_min_intr = RTC_PERIODICMININT_DISABLE,

  /* Timer Periodic hours interrupt enabled */
  .periodic_hour_intr = RTC_PERIODICHOURINT_ENABLE,

  /* Timer Periodic days interrupt disabled */
  .periodic_day_intr = RTC_PERIODICDAYINT_DISABLE,

  /* Timer Periodic months interrupt disabled */
  .periodic_month_intr = RTC_PERIODICMONTHINT_DISABLE,

  /* Timer Periodic years interrupt disabled */
  .periodic_year_intr = RTC_PERIODICYEARINT_DISABLE,

  /* Alarm interrupt disabled */
  .alarm_intr = RTC_ALARMINT_DISABLE,

  /* Event trigger to SCU interrupt enabled */
  .eventtrig_alarm = RTC_EVENTTRIGSCU_ALARM_ENABLE,

   /* Event: Periodic Interrupt */ 
  .pi_listener = IRQ_HourPassed,

  /* Event: Alarm Interrupt */  
  .ai_listener = NULL

};
const XMC_RTC_CONFIG_t RTC_0_time_alarm_config =
{
{
  .seconds = 0U,
  .minutes = 47U,
  .hours = 16U,
  /* To be in sync with RTC hardware, day of month entered in UI is subtracted by 1 */
  .days = 27U,
  .daysofweek = XMC_RTC_WEEKDAY_TUESDAY,
  /* To be in sync with RTC hardware, month entered in UI is subtracted by 1 */
  .month = XMC_RTC_MONTH_APRIL,
  .year = 2015U
},
{
  .seconds = 0U,
  .minutes = 1U,
  .hours = 0U,
  /* To be in sync with RTC hardware, day of month entered in UI is subtracted by 1 */
  .days = 0U,
/* To be in sync with RTC hardware, month entered in UI is subtracted by 1 */
  .month = XMC_RTC_MONTH_JANUARY,
  .year = 1970U
},
.prescaler = DEFAULT_DIVIDERVALUE
};
RTC_t RTC_0 =
{
  .time_alarm_config = &RTC_0_time_alarm_config,
  .config = &RTC_0_config,
  .initialized = false
};


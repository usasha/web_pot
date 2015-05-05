/******************************************************************************
 Copyright (c) 2015, Infineon Technologies AG                                **
 All rights reserved.                                                        **
																			 **
 Redistribution and use in source and binary forms, with or without          **
 modification,are permitted provided that the following conditions are met:  **
																			 **
 *Redistributions of source code must retain the above copyright notice,     **
 this list of conditions and the following disclaimer.                       **
 *Redistributions in binary form must reproduce the above copyright notice,  **
 this list of conditions and the following disclaimer in the documentation   **
 and/or other materials provided with the distribution.                      **
 *Neither the name of the copyright holders nor the names of its             **
 contributors may be used to endorse or promote products derived from this   **
 software without specific prior written permission.                         **
																			 **
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" **
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   **
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  **
 ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE  **
 LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR        **
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF        **
 SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS   **
 INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN     **
 CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)      **
 ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  **
 POSSIBILITY OF SUCH DAMAGE.                                                 **
																			 **
 To improve the quality of the software, users are encouraged to share       **
 modifications, enhancements or bug fixes with Infineon Technologies AG      **
 dave@infineon.com).                                                         **
																			 **
*******************************************************************************
**                                                                           **
**                                                                           **
** PLATFORM : Infineon XMC4000/ XMC1000 Series                               **
**                                                                           **
** COMPILER : Compiler Independent                                           **
**                                                                           **
** AUTHOR   : APP Developer                                                  **
**                                                                           **
** MAY BE CHANGED BY USER [yes/no]: Yes                                      **
**                                                                           **
**                                                                           **
******************************************************************************/
/*************** Revision History **********************************************
Version        Date          Description

  4.0.0       16-Feb-2015   Initial version for DAVEv4
*******************************************************************************/

/**
 * @file PWM.h
 * @brief  This file contains Enumerations, Function prototypes & Structure
 * definitions of PWM App.
 */

#ifndef PWM_H_
#define PWM_H_

#ifdef __cplusplus
extern "C" {
#endif
/*******************************************************************************
**                      Include Files                                         **
*******************************************************************************/
#include <xmc_gpio.h>
#include "pwm_conf.h"
#include <DAVE_common.h>

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

#define PWM_MAX_TIMER_COUNT  (65535U) /**< Max Timer count value */

/*******************************************************************************
 *                                ENUMERATIONS                                **
 ******************************************************************************/
 /**
  * @ingroup PWM_enumerations
  * @{
  */
/**
 *   @brief The type identifies the CCU4 or CCU8 timer selected.
 */
typedef enum PWM_TIMER_TYPE
{
  PWM_TIMER_SLICE_CCU4 = 0U,
  PWM_TIMER_SLICE_CCU8
} PWM_TIMER_TYPE_t;

/**
 *   @brief The type identifies the timer status.
 */
typedef enum PWM_TIMER_STATUS
{
  PWM_TIMER_IDLE = 0U,
  PWM_TIMER_RUNNING
} PWM_TIMER_STATUS_t;

/**
 *   @brief The type identifies the timer interrupts.
 */
typedef enum PWM_InterruptType
{
  PWM_PERIODMATCH_INTERRUPT 	 = 0U,		/**< Period match interrupt while counting up */
  PWM_COMPAREMATCH_INTERRUPT	 = 2U    	/**< Compare match interrupt while counting up */
} PWM_InterruptType_t;

/**
 *   @brief The type identifies the timer interrupts.
 */
typedef enum PWM_OutputPassiveLevelType
{
  PWM_OUTPUT_PASSIVE_LEVEL_LOW  = 0, /**< Passive level = Low */
  PWM_OUTPUT_PASSIVE_LEVEL_HIGH    , /**< Passive level = High */
  PWM_OUTPUT_PASSIVE_LEVEL_MAX
} PWM_OutputPassiveLevelType_t;

/**
 * @brief The type identifies App state.
 */
typedef enum PWM_STATUS
{
  PWM_STATUS_SUCCESS = 0,    /**< APP is initialized as per selected parameters */
  PWM_STATUS_FAILURE,   	     /**< APP initialization function failure */
  PWM_STATUS_UNINITIALIZED,      /**< default state after power on reset */
  PWM_STATUS_RUNNING,            /**< CCU slice is running in PWM mode */
  PWM_STATUS_STOPPED,            /**< CCU slice timer is stopped */
} PWM_STATUS_t;

/**
 * @brief The type identifies the App Error Codes.
 */
typedef enum PWM_ERROR_CODES
{
  PWM_OPER_NOT_ALLOWED_ERROR = 1,  /**< if the current API operation is not possible in the given state */
  PWM_INVALID_PARAM_ERROR          /**< the parameters passed to an API are invalid */
} PWM_ERROR_CODES_t;

/**
 * @}
 */

/*******************************************************************************
 *                             STRUCTURES                                     **
 ******************************************************************************/
/**
  * @ingroup PWM_datastructures
  * @{
  */
/**
 * @brief Configuration values of the PWM signal.
 */
typedef struct PWM_Dynamic_type
{
	uint32_t compare_value;        /**< Value that is pushed into the compare register*/

	uint32_t period_value;         /**< Value that is pushed into the period register*/

	uint32_t duty_cycle;            /**< Value of duty cycle that is scaled with a factor 100*/
}PWM_Dynamic_t;

/**
 * @brief Configuration parameters of the PWM APP
 */
typedef struct PWM_ConfigType
{
	const bool                             start_control;        /**<Enable/disable start of PWM after initialization*/

	PWM_Dynamic_t                         *const config_value;  /**< This holds the pointer to the dynamic handle of PWM*/

	const bool                             period_match_enable;  /**< Enable/Disable Period match interrupt*/

	const bool                             compare_match_enable; /**< Enable/Disable Compare match interrupt*/

#ifdef  PWM_SLICE_USED_CCU4
	XMC_CCU4_MODULE_t                      *const ccu4_kernel_ptr;        /**< Pointer to CCU4 kernel*/

	XMC_CCU4_SLICE_t                       *const ccu4_slice_ptr;         /**< Pointer to CCU4 slice*/

	const uint8_t                          ccu4_kernel_number;               /**< Indicates the CCU4 kernel number*/

	const uint8_t                          ccu4_slice_number;             /**< Indicates the CCU4 slice number */

	const XMC_CCU4_SLICE_COMPARE_CONFIG_t *const ccu4_slice_config_ptr;   /**< Pointer to CCU4 configuration handle*/

	const XMC_CCU4_SLICE_SR_ID_t           ccu4_slice_period_match_node;  /**< SR node line for period match */

	const XMC_CCU4_SLICE_SR_ID_t           ccu4_slice_compare_match_node; /**< SR node line for compare match*/
#endif
#ifdef  PWM_SLICE_USED_CCU8
	XMC_CCU8_MODULE_t                     *const ccu8_kernel_ptr;         /**< Pointer to CCU8 kernel */

	XMC_CCU8_SLICE_t                      *const ccu8_slice_ptr;          /**< Pointer to CCU8 slice*/

	const uint8_t                          ccu8_kernel_number;               /**< Indicates the CCU8 kernel number*/

	const uint8_t                          ccu8_slice_number;             /**< Indicates the CCU8 slice number */

	const XMC_CCU8_SLICE_COMPARE_CONFIG_t *const ccu8_slice_config_ptr;   /**< Pointer to CCU8 configuration handle*/

	const XMC_CCU8_SLICE_SR_ID_t           ccu8_slice_period_match_node;  /**< SR node line for period match */

	const XMC_CCU8_SLICE_SR_ID_t           ccu8_slice_compare_match_node; /**< SR node line for compare match*/
#endif
	XMC_GPIO_PORT_t			              *const  gpio_out_port;    /**< Holds the port number for the PWM output*/

	const uint8_t                          gpio_out_pin;            /**< Holds the pin number for the PWM output*/

	const XMC_GPIO_CONFIG_t               *const  gpio_out_config;  /**< Holds the pin configuration for the PWM output*/
} PWM_ConfigType_t;

/**
 * @brief Initialization parameters of the PWM App
 */
typedef struct PWM_HandleType
{
  const PWM_TIMER_TYPE_t    timer_type;  /**< Type of CCU selected for the PWM generation */

  PWM_STATUS_t              state;  /**< The current state of the PWM App instance*/
#ifdef  PWM_SLICE_USED_CCU4
  GLOBAL_CCU4_t              *const GLOBAL_CCU4_handle;  /**< GLOBAL_CCU4 App handle */
#endif
#ifdef  PWM_SLICE_USED_CCU8
  GLOBAL_CCU8_t              *const GLOBAL_CCU8_handle;  /**< GLOBAL_CCU8 App handle*/
#endif
  const PWM_ConfigType_t    *const  config_ptr; /**< PWM App instance, configuration handle*/
} PWM_t;

/**
 * @}
 */

/**
 * @ingroup PWM_apidoc
 * @{
 */
/*******************************************************************************
 **FUNCTION PROTOTYPES                                                        **
*******************************************************************************/
/**
 * @brief Get PWM APP version
 * @return DAVE_APP_VERSION_t APP version information (major, minor and patch number)
 *
 * \par<b>Description: </b><br>
 * The function can be used to check application software compatibility with a
 * specific version of the APP.
 *
 * Example Usage:
 *
 * @code
 * #include <DAVE.h>
 *
 * int main(void) {
 *   DAVE_STATUS_t init_status;
 *   DAVE_APP_VERSION_t version;
 *
 *   // Initialize PWM APP:
 *   // PWM_Init() is called from within DAVE_Init().
 *   init_status = DAVE_Init();
 *
 *   version = PWM_GetAppVersion();
 *   if (version.major != 1U) {
 *     // Probably, not the right version.
 *   }
 *
 *   // More code here
 *   while(1) {
 *
 *   }
 *   return (0);
 * }
 * @endcode
 */
DAVE_APP_VERSION_t PWM_GetAppVersion(void);

/**
 * @brief Initializes the PWM APP.
 * @param   handle_ptr Constant pointer to the handle structure ::PWM_t
 * @return  PWM_STATUS_t status of the initialization.
 *
 *
 * \par<b>Description:</b><br>
 * Initializes the PWM APP. This initializes the CCUx slice to compare mode of operation. Configures
 * required events, GPIO pin as output. It will configure CCU4 or CCU8 slice registers with the selected PWM parameters.
 * If PWM generation is set to start after initialization then after the CCUx related initialization is completed
 * the PWM output will start.
 *
 * @code
  #include <DAVE.h>

  int main(void)
  {
   DAVE_Init(); //PWM_Init() is called by DAVE_Init().
    while(1);
    return 0;
  }
 * @endcode
 */
PWM_STATUS_t PWM_Init(PWM_t *const handle_ptr);

/**
 * @brief Starts the PWM generation.
 * @param   handle_ptr Constant pointer to the handle structure ::PWM_t
 * @return void\n
 *
 * \par<b>Description:</b><br>
 * Start the selected PWM generation. It is needed to be called if "Start after initialization" is
 * unchecked in the UI. Enables the clock for the CCUx slice and also starts the timer operation.
 * Invoke this API only after initialization and when the timer is not running. If invoked outside
 * these conditions, the API will have no effect.
 *
 * @code
  #include <DAVE.h>

  int main(void)
  {
   DAVE_Init();
   //This needs to be called if "Start after initialization" is unchecked
   if(!PWM_GetTimerStatus(&PWM_0))
   {
     PWM_Start(&PWM_0);
   }
   while(1);
   return 0;
  }
 * @endcode
*/
void PWM_Start(PWM_t *const handle_ptr);

/**
 * @brief Stops the PWM generation.
 * @param   handle_ptr Constant pointer to the handle structure ::PWM_t
 * @return void\n
 *
 * \par<b>Description:</b><br>
 * Stop the selected PWM generation. Disables the clock for the CCUx slice and also
 * stops the timer operation. Invoke this API only after initialization and when the timer is running. If invoked outside
 * these conditions, the API will have no effect.
 *
 * @code
   #include <DAVE.h>

  int main(void)
  {
   DAVE_Init();

   if(PWM_GetTimerStatus(&PWM_0))
   {
     PWM_Stop(&PWM_0);
   }
   while(1);
   return 0;
  }
 * @endcode
*/
void PWM_Stop(PWM_t *const handle_ptr);

/**
 * @brief  Configures the PWM Frequency.
 * @param   handle_ptr Constant pointer to the handle structure ::PWM_t
 * @param   PwmFreqHz Frequency value in Hz.<BR>
 *                    Range: [1(d) to 60000000(d)]
 * @return  PWM_STATUS_t Would return PWM_STATUS_FAILURE if the \b PwmFreqHz exceeded the maximum frequency achievable.
 *
 * \par<b>Description:</b><br>
 * Configures the frequency of the PWM signal. The PWM duty cycle remains unchanged. Calculates the
 * least possible resolution(Prescaler) of the CCUx Timer. Using this Prescaler it would calculate the value for the
 * period register and the compare register. Adjusts the compare match value according to the frequency
 * and the existing duty cycle.
 *
 * @code
  #include <DAVE.h>

  int main(void)
  {
     PWM_STATUS_t pwm_setfreq_status;
     uint32_t Counter;

     DAVE_Init();

     // Change duty cycle value to 20%.
	 PWM_SetDutyCycle(&PWM_0, 2000);

    // Change PWM frequency to 100kHz
    pwm_setfreq_status = PWM_SetFreq(&PWM_0,100000);
    if(PWM_STATUS_FAILURE == pwm_setfreq_status)
    {
    	// frequency couldn't be set
    	while(1);
    }

    // Wait to observe the waveform
    for(Counter = 0;Counter <=0xFFFF;Counter++);

	// Change duty cycle value to 60%.
    PWM_SetDutyCycle(&PWM_0, 6000);


    while(1);
    return 0;
  }
* @endcode
*/
PWM_STATUS_t PWM_SetFreq(PWM_t *const handle_ptr, uint32_t PwmFreqHz);

/**
 * @brief  Configures the PWM Frequency and duty cycle.
 * @param   handle_ptr Constant pointer to the handle structure ::PWM_t
 * @param   PwmFreqHz Frequency value in Hz.<BR>
 *                    Range: [1(d) to 60000000(d)]
 * @param   duty_cycle Duty cycle in percentage.<BR>
 *                    The values are scaled by a factor of 100.<BR>
 *                    Range: [0(d) to 10000(d)]
 *                    Where 1(d) represents 0.01% duty cycle <BR>
 *                          10000(d) represents 100% duty cycle <BR>
 *
 * @return  	Return PWM_STATUS_FAILURE if the PwmFreqHz exceeded the maximum frequency achievable.
 *
 * \par<b>Description:</b><br>
 * Configures the frequency and duty cycle together. Calculates the
 * least possible resolution(Prescaler) of the CCUx Timer. Using this Prescaler it would calculate the value for the
 * period register. Using the \b duty_cycle the compare register values would be calculated.
 *
 * \par<b>Note:</b><br>
 *  <LI>This is a fixed point implementation for duty cycle. It is expected that there are resolution losses due to
 *  scaling of the duty cycle in the API. At higher frequencies it may not be possible to achieve the required
 *  duty cycle due to the hardware limitation. </LI>
 *  <LI>If the input frequency to the API is very high (> 30MHz) due to integer divisions, the desired frequency
 *  might not be set.</LI>
 *
 * @code
  #include <DAVE.h>

  int main(void)
  {
     PWM_STATUS_t pwm_setfreq_status;
     uint32_t Counter;

     DAVE_Init();

	// Change duty cycle value to 90.90%.
    PWM_SetDutyCycle(&PWM_0, 9090);

	// Wait to observe the waveform
    for(Counter = 0;Counter <=0xFFFF;Counter++);

    // Change PWM frequency to 100kHz and duty to 20%
    pwm_setfreq_status = PWM_SetFreqAndDutyCycle(&PWM_0,100000,2000);
    if(PWM_STATUS_FAILURE == pwm_setfreq_status)
    {
    	// frequency couldn't be set
    	while(1);
    }

    while(1);
    return 0;
}
* @endcode
*/
PWM_STATUS_t PWM_SetFreqAndDutyCycle(PWM_t *const handle_ptr, uint32_t pwm_freq_hz, uint32_t duty_cycle);

/**
 * @brief   Clears the PWM related interrupt.
 * @param   handle_ptr Constant pointer to the handle structure ::PWM_t
 * @param   pwm_interrupt Interrupt to acknowledge.
 * @return void\n
 *
 * \par<b>Description:</b><br>
 * Clears the CCUx related interrupt. When an interrupt occurs it must be acknowledged by clearing the
 * respective flag in the hardware. Clears the interrupt type ::PWM_InterruptType_t.
 *
 *
 * @code
 *
   // Drag 2 INTERRUPT APPs into the project. In the PWM APPs UI editor enable compare match event and period
   // match event. Goto the Signal connectivity window and connect the event_compare_match and event_period_match to
   // the 2 different INTERRUPT APPs. Give the handler for the compare match interrupt as PWM_compare_match_interrupt
   // and the handler for the period match interrupt as PWM_period_match_interrupt
   #include <DAVE.h>
   uint32_t period_count;

   void PWM_period_match_interrupt(void)
   {
     static uint32_t frequency = 1000; //start frequency 1Khz
     PWM_AcknowledgeInterrupt(&PWM_0, PWM_PERIODMATCH_INTERRUPT);
     period_count++;

     if(period_count == 35000) // wait to get 40K pwm cycles then increment the frequency by 2kHz
     {
       frequency += 2000;
       PWM_SetFreq(&PWM_0,frequency);
       period_count = 0;
       if(frequency > 30000000)
         frequency = 1000;
     }
   }

   void PWM_compare_match_interrupt(void)
   {
     PWM_AcknowledgeInterrupt(&PWM_0, PWM_COMPAREMATCH_INTERRUPT);
   }

   int main(void)
   {

     DAVE_Init();

     PWM_Start(&PWM_0);
     while(1);
     return 0;
   }
* @endcode
*/
void PWM_AcknowledgeInterrupt(PWM_t *const handle_ptr, PWM_InterruptType_t pwm_interrupt);

/**
 * @brief  Gets the corresponding interrupt status.
 * @param   handle_ptr Constant pointer to the handle structure ::PWM_t
 * @param   pwm_interrupt Interrupt to get status.
 * @return bool returns true if the \b pwm_interrupt has occured else returns false.
 *
 * \par<b>Description:</b><br>
 * Returns the status of the corresponding interrupt. Reads the appropriate flag and would return
 * true if the event was asserted.
 *
 * @code
   // Drag 1 INTERRUPT APP into the project. In the PWM APPs UI editor enable compare match event and period
   // match event. Goto the Signal connectivity window and connect the event_compare_match and event_period_match to
   // the same INTERRUPT APP and give the handler as PWM_compare_period_match_interrupt.
   #include <DAVE.h>
   uint32_t period_count;

   void PWM_compare_period_match_interrupt(void)
   {
     if(PWM_GetInterruptStatus(&PWM_0, PWM_PERIODMATCH_INTERRUPT))
     {
    	 PWM_Stop(&PWM_0); // A single shot PWM generated
     }
     PWM_AcknowledgeInterrupt(&PWM_0, PWM_COMPAREMATCH_INTERRUPT);
   }

   int main(void)
   {

     DAVE_Init();

     PWM_Start(&PWM_0);
     while(1);
     return 0;
   }

* @endcode
*/
bool PWM_GetInterruptStatus(PWM_t *const handle_ptr, PWM_InterruptType_t pwm_interrupt);

/**
 * @brief  Gets the corresponding timer status.
 * @param   handle_ptr Constant pointer to the handle structure ::PWM_t
 * @return bool\n returns true if timer is running , false if the timer is idle.
 *
 * \par<b>Description:</b><br>
 * Returns the state of the timer. Would return a false if the timer is not running. A call to this API results
 * in invalid outputs if invoked before PWM_Init().
 *
 * @code
   #include <DAVE.h>

  int main(void)
  {
   DAVE_Init();

   if(PWM_GetTimerStatus(&PWM_0))
   {
     PWM_Stop(&PWM_0);
   }
   while(1);
   return 0;
  }
* @endcode
*/
bool PWM_GetTimerStatus(PWM_t *const handle_ptr);

/**
 * @brief  Configure the PWM duty cycle.
 * @param   handle_ptr Constant pointer to the handle structure ::PWM_t
 * @param   duty_cycle Duty cycle in percentage.<BR>
 *                    The values are scaled by a factor of 100.<BR>
 *                    Range: [0(d) to 10000(d)]
 *                    Where 1(d) represents 0.01% duty cycle <BR>
 *                          10000(d) represents 100% duty cycle <BR>
 *
 * @return  Returns PWM_STATUS_FAILURE if the duty_cycle exceeds the valid range.
 *
 * \par<b>Description:</b><br>
 * Configure the PWM duty cycle by changing the compare match values. The API would configure the duty cycle for the
 * given frequency. The \b duty_cycle is a scaled parameter where a single value change would result in a 0.01% change.
 *
 * \par<b>Note:</b><br>
 *  <LI>This is a fixed point implementation. It is expected that there are resolution losses due to scaling in the API.
 *  At higher frequencies it may not be possible to achieve the required duty cycle due to the hardware limitation. </LI>
 *
 * @code
 * #include <DAVE.h>
 *
 * int main(void)
 * {

    uint32_t Counter;

    DAVE_Init();

    for(Counter = 0;Counter <=0xFFFF;Counter++);

    // Change duty cycle value to 60.00%
    if(PWM_SetDutyCycle(&PWM_0,6000))
    {
      while(1);
    }

    // Wait to observe the waveform
    for(Counter = 0;Counter <=0xFFFF;Counter++);

    // Change duty cycle value to 54.26%
    if(PWM_SetDutyCycle(&PWM_0,5426))
    {
      while(1);
    }

    // Wait to observe the waveform
    for(Counter = 0;Counter <=0xFFFF;Counter++);

    // Change duty cycle value to an invalid duty 100.26%
    if(PWM_SetDutyCycle(&PWM_0,10026))
    {
      while(1);
    }
    while(1);
    return 0;
}
* @endcode
*/
PWM_STATUS_t PWM_SetDutyCycle(PWM_t *const handle_ptr, uint32_t duty_cycle);


/**
 * @brief  Configure the passive level of the PWM output waveform.
 * @param   handle_ptr Constant pointer to the handle structure ::PWM_t
 * @param   pwm_output_passive_level Passive level LOW or HIGH.
 * @return void\n
 *
 * \par<b>Description:</b><br>
 *  Configure the passive level for the PWM signal. If ::PWM_OutputPassiveLevelType::PWM_OUTPUT_PASSIVE_LEVEL_HIGH
 *  is selected the output of the PWM will be high before the compare match occurs after that it would be set to low.
 *  If ::PWM_OutputPassiveLevelType::PWM_OUTPUT_PASSIVE_LEVEL_LOW is selected the output of the PWM will be
 *  low before the compare match occurs after that it would be set to high.
 *
 * @code
   #include <DAVE.h>

   int main(void)
   {

    uint32_t Counter;

    DAVE_Init();

    for(Counter = 0;Counter <=0xFFFF;Counter++);

    PWM_SetPassiveLevel(&PWM_0, PWM_OUTPUT_PASSIVE_LEVEL_HIGH);
    for(Counter = 0;Counter <=0xFFFF;Counter++);
    PWM_SetPassiveLevel(&PWM_0, PWM_OUTPUT_PASSIVE_LEVEL_LOW);
    for(Counter = 0;Counter <=0xFFFF;Counter++);

    while(1);
    return 0;
   }
* @endcode
*/
void PWM_SetPassiveLevel(PWM_t *const handle_ptr, PWM_OutputPassiveLevelType_t pwm_output_passive_level);

#include "PWM_Extern.h"

/**
 * @}
 */
#ifdef __cplusplus
}
#endif

#endif /* PWM_H_ */

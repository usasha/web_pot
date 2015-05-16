/*******************************************************************************
**  DAVE App Name : ADC_MEASUREMENT       App Version: 4.0.1               
**  This file is generated by DAVE, User modification to this file will be    **
**  overwritten at the next code generation.                                  **
*******************************************************************************/


/*CODE_BLOCK_BEGIN[ADC_MEASUREMENT_Conf.c]*/
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
  4.0.1       19-Feb-2015   Added GetResult APIs for XMC1100 devices.
*******************************************************************************/

/**
 * @file   adc_measurement_conf.c
 *
 * @brief  Configuration file generated based on UI settings
 *         of ADC_MEASUREMENT App
 */

/*******************************************************************************
 ** INCLUDE FILES                                                             **
 ******************************************************************************/

#include "adc_measurement.h"

/* Global iclass0 configuration*/
const  XMC_VADC_GLOBAL_CLASS_t global_iclass_config =
{
  .conversion_mode_standard  = (uint32_t) XMC_VADC_CONVMODE_12BIT,
  .sample_time_std_conv	     = (uint32_t) 0,
};

/******************************* CHANNEL CONFIG *******************************/

/*********************** Channel_A Configurations ************************************/


/*Channel_A ADC Channel configuration structure*/
XMC_VADC_CHANNEL_CONFIG_t  Channel_A_ch_config =
{
  .input_class                = (uint32_t) XMC_VADC_CHANNEL_CONV_GLOBAL_CLASS0,  /* Global ICLASS 0 selected */
  .lower_boundary_select 	  = (uint32_t) XMC_VADC_CHANNEL_BOUNDARY_GROUP_BOUND0,
  .upper_boundary_select 	  = (uint32_t) XMC_VADC_CHANNEL_BOUNDARY_GROUP_BOUND0,
  .event_gen_criteria         = (uint32_t) XMC_VADC_CHANNEL_EVGEN_NEVER, /*Channel Event disabled */
  .sync_conversion  		  = (uint32_t) 0,                            /* Sync feature disabled*/
  .alternate_reference        = (uint32_t) XMC_VADC_CHANNEL_REF_INTREF,  /* Internal reference selected */
  .result_reg_number          = (uint32_t) 15,                           /* GxRES[15] selected */
  .use_global_result          = (uint32_t) 0, 				             /* Use Group result register*/
  .result_alignment           = (uint32_t) XMC_VADC_RESULT_ALIGN_RIGHT,  /* Result alignment - Right Aligned*/
  .broken_wire_detect_channel = (uint32_t) XMC_VADC_CHANNEL_BWDCH_VAGND, /* No Broken wire mode select*/
  .broken_wire_detect		  = (uint32_t) 0,    		                 /* No Broken wire detection*/
  .bfl                        = (uint32_t) 0,                            /* No Boundary flag */
  .channel_priority           = (uint32_t) 0,                   		 /* Lowest Priority 0 selected*/
  .alias_channel              = (int8_t) -1,                         /* ALIAS is Disabled*/
};

/*Channel_A Result configuration structure*/
XMC_VADC_RESULT_CONFIG_t Channel_A_res_config =
{
  .data_reduction_control  = (uint8_t) 0,  /* No Accumulation */
  .post_processing_mode    = (uint32_t) XMC_VADC_DMM_REDUCTION_MODE,
  .wait_for_read_mode  	   = (uint32_t) 0,  /* Disabled */
  .part_of_fifo       	   = (uint32_t) 0 , /* No FIFO */
  .event_gen_enable   	   = (uint32_t) 0   /* Disable Result event */
};

/* Channel_A ADC channel Handle */
ADC_MEASUREMENT_channel_t ADC_MEASUREMENT_Channel_A_handle =
{
  .ch_num        = (uint8_t) 0,
  .group_handle  = (VADC_G_TypeDef*)(void*) VADC_G0,
  .group_index	 = (uint8_t) 0,
  .ch_handle	 = (XMC_VADC_CHANNEL_CONFIG_t*) &Channel_A_ch_config,
  .res_handle	 = (XMC_VADC_RESULT_CONFIG_t*) &Channel_A_res_config,
};


/*********************** Channel_B Configurations ************************************/


/*Channel_B ADC Channel configuration structure*/
XMC_VADC_CHANNEL_CONFIG_t  Channel_B_ch_config =
{
  .input_class                = (uint32_t) XMC_VADC_CHANNEL_CONV_GLOBAL_CLASS0,  /* Global ICLASS 0 selected */
  .lower_boundary_select 	  = (uint32_t) XMC_VADC_CHANNEL_BOUNDARY_GROUP_BOUND0,
  .upper_boundary_select 	  = (uint32_t) XMC_VADC_CHANNEL_BOUNDARY_GROUP_BOUND0,
  .event_gen_criteria         = (uint32_t) XMC_VADC_CHANNEL_EVGEN_NEVER, /*Channel Event disabled */
  .sync_conversion  		  = (uint32_t) 0,                            /* Sync feature disabled*/
  .alternate_reference        = (uint32_t) XMC_VADC_CHANNEL_REF_INTREF,  /* Internal reference selected */
  .result_reg_number          = (uint32_t) 4,                           /* GxRES[4] selected */
  .use_global_result          = (uint32_t) 0, 				             /* Use Group result register*/
  .result_alignment           = (uint32_t) XMC_VADC_RESULT_ALIGN_RIGHT,  /* Result alignment - Right Aligned*/
  .broken_wire_detect_channel = (uint32_t) XMC_VADC_CHANNEL_BWDCH_VAGND, /* No Broken wire mode select*/
  .broken_wire_detect		  = (uint32_t) 0,    		                 /* No Broken wire detection*/
  .bfl                        = (uint32_t) 0,                            /* No Boundary flag */
  .channel_priority           = (uint32_t) 0,                   		 /* Lowest Priority 0 selected*/
  .alias_channel              = (int8_t) -1,                         /* ALIAS is Disabled*/
};

/*Channel_B Result configuration structure*/
XMC_VADC_RESULT_CONFIG_t Channel_B_res_config =
{
  .data_reduction_control  = (uint8_t) 0,  /* No Accumulation */
  .post_processing_mode    = (uint32_t) XMC_VADC_DMM_REDUCTION_MODE,
  .wait_for_read_mode  	   = (uint32_t) 0,  /* Disabled */
  .part_of_fifo       	   = (uint32_t) 0 , /* No FIFO */
  .event_gen_enable   	   = (uint32_t) 0   /* Disable Result event */
};

/* Channel_B ADC channel Handle */
ADC_MEASUREMENT_channel_t ADC_MEASUREMENT_Channel_B_handle =
{
  .ch_num        = (uint8_t) 1,
  .group_handle  = (VADC_G_TypeDef*)(void*) VADC_G0,
  .group_index	 = (uint8_t) 0,
  .ch_handle	 = (XMC_VADC_CHANNEL_CONFIG_t*) &Channel_B_ch_config,
  .res_handle	 = (XMC_VADC_RESULT_CONFIG_t*) &Channel_B_res_config,
};


/*********************** Channel_C Configurations ************************************/


/*Channel_C ADC Channel configuration structure*/
XMC_VADC_CHANNEL_CONFIG_t  Channel_C_ch_config =
{
  .input_class                = (uint32_t) XMC_VADC_CHANNEL_CONV_GLOBAL_CLASS0,  /* Global ICLASS 0 selected */
  .lower_boundary_select 	  = (uint32_t) XMC_VADC_CHANNEL_BOUNDARY_GROUP_BOUND0,
  .upper_boundary_select 	  = (uint32_t) XMC_VADC_CHANNEL_BOUNDARY_GROUP_BOUND0,
  .event_gen_criteria         = (uint32_t) XMC_VADC_CHANNEL_EVGEN_NEVER, /*Channel Event disabled */
  .sync_conversion  		  = (uint32_t) 0,                            /* Sync feature disabled*/
  .alternate_reference        = (uint32_t) XMC_VADC_CHANNEL_REF_INTREF,  /* Internal reference selected */
  .result_reg_number          = (uint32_t) 0,                           /* GxRES[0] selected */
  .use_global_result          = (uint32_t) 0, 				             /* Use Group result register*/
  .result_alignment           = (uint32_t) XMC_VADC_RESULT_ALIGN_RIGHT,  /* Result alignment - Right Aligned*/
  .broken_wire_detect_channel = (uint32_t) XMC_VADC_CHANNEL_BWDCH_VAGND, /* No Broken wire mode select*/
  .broken_wire_detect		  = (uint32_t) 0,    		                 /* No Broken wire detection*/
  .bfl                        = (uint32_t) 0,                            /* No Boundary flag */
  .channel_priority           = (uint32_t) 0,                   		 /* Lowest Priority 0 selected*/
  .alias_channel              = (int8_t) -1,                         /* ALIAS is Disabled*/
};

/*Channel_C Result configuration structure*/
XMC_VADC_RESULT_CONFIG_t Channel_C_res_config =
{
  .data_reduction_control  = (uint8_t) 0,  /* No Accumulation */
  .post_processing_mode    = (uint32_t) XMC_VADC_DMM_REDUCTION_MODE,
  .wait_for_read_mode  	   = (uint32_t) 0,  /* Disabled */
  .part_of_fifo       	   = (uint32_t) 0 , /* No FIFO */
  .event_gen_enable   	   = (uint32_t) 0   /* Disable Result event */
};

/* Channel_C ADC channel Handle */
ADC_MEASUREMENT_channel_t ADC_MEASUREMENT_Channel_C_handle =
{
  .ch_num        = (uint8_t) 2,
  .group_handle  = (VADC_G_TypeDef*)(void*) VADC_G2,
  .group_index	 = (uint8_t) 2,
  .ch_handle	 = (XMC_VADC_CHANNEL_CONFIG_t*) &Channel_C_ch_config,
  .res_handle	 = (XMC_VADC_RESULT_CONFIG_t*) &Channel_C_res_config,
};


/* ADC_MEASUREMENT channel handles */
ADC_MEASUREMENT_channel_array_t ADC_MEASUREMENT_channel_array=
{
  .channel_array =
	{
	  (ADC_MEASUREMENT_channel_t *)&ADC_MEASUREMENT_Channel_A_handle,
	  (ADC_MEASUREMENT_channel_t *)&ADC_MEASUREMENT_Channel_B_handle,
	  (ADC_MEASUREMENT_channel_t *)&ADC_MEASUREMENT_Channel_C_handle,
	}
};


/* LLD Background Scan Init Structure */
const XMC_VADC_BACKGROUND_CONFIG_t backgnd_config =
{
  .conv_start_mode   = (uint32_t) XMC_VADC_STARTMODE_CIR, 		/* Conversion start mode selected as cancel inject repeat*/
  .req_src_priority  = (uint32_t) XMC_VADC_GROUP_RS_PRIORITY_1, /* Priority of the Background request source in the VADC module*/
  .trigger_signal    = (uint32_t) XMC_VADC_REQ_TR_A,            /*If Trigger needed then this denotes the Trigger signal*/
  .trigger_edge      = (uint32_t) XMC_VADC_TRIGGER_EDGE_NONE,   /*If Trigger needed then this denotes Trigger edge selected*/
  .gate_signal    	 = (uint32_t) XMC_VADC_REQ_GT_A,			 /*If Gating needed then this denotes the Gating signal*/
  .timer_mode        = (uint32_t) 0,							 /*Timer Mode Disabled */
  .external_trigger  = (uint32_t) 0,                               /*Trigger is Disabled*/
  .req_src_interrupt = (uint32_t) 0,                              /*Background Request source interrupt Disabled*/
  .enable_auto_scan  = (uint32_t) 0,
  .load_mode         = (uint32_t) XMC_VADC_SCAN_LOAD_OVERWRITE
};

ADC_MEASUREMENT_t ADC_MEASUREMENT_0=
{
  .array		 	     = (ADC_MEASUREMENT_channel_array_t*) &ADC_MEASUREMENT_channel_array,
  .backgnd_config_handle = (XMC_VADC_BACKGROUND_CONFIG_t*) &backgnd_config,
  .req_src_intr_handle	 = (ADC_MEASUREMENT_ISR_t *) NULL,
  .iclass_config_handle  = ( XMC_VADC_GLOBAL_CLASS_t *) &global_iclass_config,
  .srv_req_node          = XMC_VADC_SR_SHARED_SR0,
  .global_handle    	 = (GLOBAL_ADC_t *) &GLOBAL_ADC_0, 
  .start_conversion		 = (bool) true,
  .mux_config			 = NULL,
  .init_state 			 = ADC_MEASUREMENT_STATUS_UNINITIALIZED
};



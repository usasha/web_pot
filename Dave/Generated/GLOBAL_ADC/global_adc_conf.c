/*******************************************************************************
**  DAVE App Name : GLOBAL_ADC       App Version: 4.0.0               
**  This file is generated by DAVE, User modification to this file will be    **
**  overwritten at the next code generation.                                  **
*******************************************************************************/


/*CODE_BLOCK_BEGIN[GLOBAL_ADC_Conf.c]*/
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
**                                                                            **
** PLATFORM : Infineon XMC4000/XMC1000 Series                                 **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR   : APP Developer                                                   **
**                                                                            **
** MAY BE CHANGED BY USER [yes/no]: Yes                                       **
**                                                                            **
** NOTE     : Any Changes made to this file will be overwritten during Code   **
**            Generation                                                      **
**                                                                            **
******************************************************************************/
/*************** Revision History **********************************************
Version        Date          Description 

  4.0.0       16-Feb-2015   Initial version for DAVEv4
*******************************************************************************/

/**
 * @file global_adc_conf.c
 * @brief This file contains the configuration parameters for the instances of
 * the GLOBAL_ADC App
 */
/******************************************************************************
 ** INCLUDE FILES                                                            **
 *****************************************************************************/
#include "global_adc.h"

/**
 * @ingroup GLOBAL_ADC_datastructures
 * @{
 */

/**
 * This structure contains the group 0 Configuration.
 */
const XMC_VADC_GROUP_CONFIG_t group_init_handle0 =
{
  .emux_config	= { 
					.stce_usage                = (uint32_t) 0, 					 /*Use STCE when the setting changes*/
					.emux_mode                 = XMC_VADC_GROUP_EMUXMODE_SWCTRL, /* Mode for Emux conversion*/
					.emux_coding               = XMC_VADC_GROUP_EMUXCODE_BINARY, /*Channel progression - binary format*/
					.starting_external_channel = (uint32_t) 0,                   /* Channel starts at 0 for EMUX*/
					.connected_channel         = (uint32_t) 0                    /* Channel connected to EMUX*/
				   },
  .class0 		= {
             	    .sample_time_std_conv            = (uint32_t) 0,                /*The Sample time is (2*tadci)*/
             	    .conversion_mode_standard        = XMC_VADC_CONVMODE_12BIT,     /* 12bit conversion Selected*/
             	    .sampling_phase_emux_channel     = (uint32_t) 0,                /*The Sample time is (2*tadci)*/
					.conversion_mode_emux            = XMC_VADC_CONVMODE_12BIT      /* 12bit conversion Selected*/
		    	  },  /* !<ICLASS-0 */
  .class1   	= {	
             	    .sample_time_std_conv = (uint32_t) 0,                /*The Sample time is (2*tadci)*/
             	    .conversion_mode_standard        = XMC_VADC_CONVMODE_12BIT,     /* 12bit conversion Selected*/
             	    .sampling_phase_emux_channel     = (uint32_t) 0,                /*The Sample time is (2*tadci)*/
					.conversion_mode_emux            = XMC_VADC_CONVMODE_12BIT      /* 12bit conversion Selected*/
             	  }, /* !< ICLASS-1 */
  .boundary0    = (uint32_t) 0,  /* Lower boundary value for Normal comparison mode*/  
  .boundary1	= (uint32_t) 0,  /* Upper boundary value for Normal comparison mode*/
  .arbitration_round_length = (uint32_t) 0,  /* 4 arbitration slots per round selected (tarb = 4*tadcd) */
  .arbiter_mode             = (uint32_t) XMC_VADC_GROUP_ARBMODE_ALWAYS,	/*Determines when the arbiter should run.*/		
};

/**
 * This structure contains the group 1 Configuration.
 */
const XMC_VADC_GROUP_CONFIG_t group_init_handle1 =
{
  .emux_config	= { 
					.stce_usage                = (uint32_t) 0, 					 /*Use STCE when the setting changes*/
					.emux_mode                 = XMC_VADC_GROUP_EMUXMODE_SWCTRL, /* Mode for Emux conversion*/
					.emux_coding               = XMC_VADC_GROUP_EMUXCODE_BINARY, /*Channel progression - binary format*/
					.starting_external_channel = (uint32_t) 0,                   /* Channel starts at 0 for EMUX*/
					.connected_channel         = (uint32_t) 0                    /* Channel connected to EMUX*/
				   },
  .class0 		= {
             	    .sample_time_std_conv            = (uint32_t) 0,                /*The Sample time is (2*tadci)*/
             	    .conversion_mode_standard        = XMC_VADC_CONVMODE_12BIT,     /* 12bit conversion Selected*/
             	    .sampling_phase_emux_channel     = (uint32_t) 0,                /*The Sample time is (2*tadci)*/
					.conversion_mode_emux            = XMC_VADC_CONVMODE_12BIT      /* 12bit conversion Selected*/
		    	  },  /* !<ICLASS-0 */
  .class1   	= {	
             	    .sample_time_std_conv = (uint32_t) 0,                /*The Sample time is (2*tadci)*/
             	    .conversion_mode_standard        = XMC_VADC_CONVMODE_12BIT,     /* 12bit conversion Selected*/
             	    .sampling_phase_emux_channel     = (uint32_t) 0,                /*The Sample time is (2*tadci)*/
					.conversion_mode_emux            = XMC_VADC_CONVMODE_12BIT      /* 12bit conversion Selected*/
             	  }, /* !< ICLASS-1 */
  .boundary0    = (uint32_t) 0,  /* Lower boundary value for Normal comparison mode*/  
  .boundary1	= (uint32_t) 0,  /* Upper boundary value for Normal comparison mode*/
  .arbitration_round_length = (uint32_t) 0,  /* 4 arbitration slots per round selected (tarb = 4*tadcd) */
  .arbiter_mode             = (uint32_t) XMC_VADC_GROUP_ARBMODE_ALWAYS,	/*Determines when the arbiter should run.*/		
};

/**
 * This structure contains the group 2 Configuration.
 */
const XMC_VADC_GROUP_CONFIG_t group_init_handle2 =
{
  .emux_config	= { 
					.stce_usage                = (uint32_t) 0, 					 /*Use STCE when the setting changes*/
					.emux_mode                 = XMC_VADC_GROUP_EMUXMODE_SWCTRL, /* Mode for Emux conversion*/
					.emux_coding               = XMC_VADC_GROUP_EMUXCODE_BINARY, /*Channel progression - binary format*/
					.starting_external_channel = (uint32_t) 0,                   /* Channel starts at 0 for EMUX*/
					.connected_channel         = (uint32_t) 0                    /* Channel connected to EMUX*/
				   },
  .class0 		= {
             	    .sample_time_std_conv            = (uint32_t) 0,                /*The Sample time is (2*tadci)*/
             	    .conversion_mode_standard        = XMC_VADC_CONVMODE_12BIT,     /* 12bit conversion Selected*/
             	    .sampling_phase_emux_channel     = (uint32_t) 0,                /*The Sample time is (2*tadci)*/
					.conversion_mode_emux            = XMC_VADC_CONVMODE_12BIT      /* 12bit conversion Selected*/
		    	  },  /* !<ICLASS-0 */
  .class1   	= {	
             	    .sample_time_std_conv = (uint32_t) 0,                /*The Sample time is (2*tadci)*/
             	    .conversion_mode_standard        = XMC_VADC_CONVMODE_12BIT,     /* 12bit conversion Selected*/
             	    .sampling_phase_emux_channel     = (uint32_t) 0,                /*The Sample time is (2*tadci)*/
					.conversion_mode_emux            = XMC_VADC_CONVMODE_12BIT      /* 12bit conversion Selected*/
             	  }, /* !< ICLASS-1 */
  .boundary0    = (uint32_t) 0,  /* Lower boundary value for Normal comparison mode*/  
  .boundary1	= (uint32_t) 0,  /* Upper boundary value for Normal comparison mode*/
  .arbitration_round_length = (uint32_t) 0,  /* 4 arbitration slots per round selected (tarb = 4*tadcd) */
  .arbiter_mode             = (uint32_t) XMC_VADC_GROUP_ARBMODE_ALWAYS,	/*Determines when the arbiter should run.*/		
};

/**
 * This structure contains the group 3 Configuration.
 */
const XMC_VADC_GROUP_CONFIG_t group_init_handle3 =
{
  .emux_config	= { 
					.stce_usage                = (uint32_t) 0, 					 /*Use STCE when the setting changes*/
					.emux_mode                 = XMC_VADC_GROUP_EMUXMODE_SWCTRL, /* Mode for Emux conversion*/
					.emux_coding               = XMC_VADC_GROUP_EMUXCODE_BINARY, /*Channel progression - binary format*/
					.starting_external_channel = (uint32_t) 0,                   /* Channel starts at 0 for EMUX*/
					.connected_channel         = (uint32_t) 0                    /* Channel connected to EMUX*/
				   },
  .class0 		= {
             	    .sample_time_std_conv            = (uint32_t) 0,                /*The Sample time is (2*tadci)*/
             	    .conversion_mode_standard        = XMC_VADC_CONVMODE_12BIT,     /* 12bit conversion Selected*/
             	    .sampling_phase_emux_channel     = (uint32_t) 0,                /*The Sample time is (2*tadci)*/
					.conversion_mode_emux            = XMC_VADC_CONVMODE_12BIT      /* 12bit conversion Selected*/
		    	  },  /* !<ICLASS-0 */
  .class1   	= {	
             	    .sample_time_std_conv = (uint32_t) 0,                /*The Sample time is (2*tadci)*/
             	    .conversion_mode_standard        = XMC_VADC_CONVMODE_12BIT,     /* 12bit conversion Selected*/
             	    .sampling_phase_emux_channel     = (uint32_t) 0,                /*The Sample time is (2*tadci)*/
					.conversion_mode_emux            = XMC_VADC_CONVMODE_12BIT      /* 12bit conversion Selected*/
             	  }, /* !< ICLASS-1 */
  .boundary0    = (uint32_t) 0,  /* Lower boundary value for Normal comparison mode*/  
  .boundary1	= (uint32_t) 0,  /* Upper boundary value for Normal comparison mode*/
  .arbitration_round_length = (uint32_t) 0,  /* 4 arbitration slots per round selected (tarb = 4*tadcd) */
  .arbiter_mode             = (uint32_t) XMC_VADC_GROUP_ARBMODE_ALWAYS,	/*Determines when the arbiter should run.*/		
};

/**
 * This structure contains the Global related Configuration.
 */
const XMC_VADC_GLOBAL_CONFIG_t global_config =
{  
  .boundary0    = (uint32_t) 0, /* Lower boundary value for Normal comparison mode*/
  .boundary1    = (uint32_t) 0, /* Upper boundary value for Normal comparison mode*/

  .clock_config = { 

	                .analog_clock_divider  = (uint32_t) 3, /*Divider Factor for the Analog Internal Clock*/
	                .arbiter_clock_divider = (uint32_t) 1, /*Divider Factor for the Arbiter Clock*/
	                .msb_conversion_clock  = (uint32_t) 0, /*Double Clock for the MSB Conversion */
	              },
	                
  .class0 = {
     	      .sample_time_std_conv            = (uint32_t) 0,  		  /*The Sample time is (2*tadci)*/
     	      .conversion_mode_standard        = XMC_VADC_CONVMODE_12BIT, /* 12bit conversion Selected*/

     	      .sampling_phase_emux_channel     = (uint32_t) 0,			  /*The Sample time is (2*tadci)*/
			  .conversion_mode_emux            = XMC_VADC_CONVMODE_12BIT, /* 12bit conversion Selected*/

		    },  /* !<ICLASS-0 */
  .class1 = {	
     	      .sample_time_std_conv = (uint32_t) 0,			  /*The Sample time is (2*tadci)*/
     	      .conversion_mode_standard        = XMC_VADC_CONVMODE_12BIT, /* 12bit conversion Selected*/

     	      .sampling_phase_emux_channel     = (uint32_t) 0,			  /*The Sample time is (2*tadci)*/
			  .conversion_mode_emux            = XMC_VADC_CONVMODE_12BIT, /* 12bit conversion Selected*/

            }, /* !< ICLASS-1 */

  .data_reduction_control         = (uint32_t) 0, /* Data Reduction disabled*/
  .wait_for_read_mode             = (uint32_t) 0, /* GLOBRES Register will not be overwriten untill the previous value is read*/
  .event_gen_enable               = (uint32_t) 0, /* Result Event from GLOBRES is disabled*/
  .disable_sleep_mode_control     = (uint32_t) 0  /* Sleep mode is enabled*/
};	


/**
 * This structure contains the group LLD Config Structure with Group ptr and Group Index of Group 0
 */
GLOBAL_ADC_group_t group_0_config = 
{
  .group_handle	       = (XMC_VADC_GROUP_t *) (void*) VADC_G0,  			 /*Holds the hardware group pointer*/
  .group_config_handle = (XMC_VADC_GROUP_CONFIG_t *) &group_init_handle0, /*Holds the group config structure */
  .post_calibration    = (bool) true, /* Enable or disable the post calibration*/
  .state               = GLOBAL_ADC_UNINITIALIZED       /*The status of the ADC group */
};

/**
 * This structure contains the group LLD Config Structure with Group ptr and Group Index of Group 1
 */
GLOBAL_ADC_group_t group_1_config = 
{
  .group_handle	       = (XMC_VADC_GROUP_t *) (void*) VADC_G1,  			 /*Holds the hardware group pointer*/
  .group_config_handle = (XMC_VADC_GROUP_CONFIG_t *) &group_init_handle1, /*Holds the group config structure */
  .post_calibration    = (bool) true, /* Enable or disable the post calibration*/
  .state               = GLOBAL_ADC_UNINITIALIZED       /*The status of the ADC group */
};

/**
 * This structure contains the group LLD Config Structure with Group ptr and Group Index of Group 2
 */
GLOBAL_ADC_group_t group_2_config = 
{
  .group_handle	       = (XMC_VADC_GROUP_t *) (void*) VADC_G2,  			 /*Holds the hardware group pointer*/
  .group_config_handle = (XMC_VADC_GROUP_CONFIG_t *) &group_init_handle2, /*Holds the group config structure */
  .post_calibration    = (bool) true, /* Enable or disable the post calibration*/
  .state               = GLOBAL_ADC_UNINITIALIZED       /*The status of the ADC group */
};

/**
 * This structure contains the group LLD Config Structure with Group ptr and Group Index of Group 3
 */
GLOBAL_ADC_group_t group_3_config = 
{
  .group_handle	       = (XMC_VADC_GROUP_t *) (void*) VADC_G3,  			 /*Holds the hardware group pointer*/
  .group_config_handle = (XMC_VADC_GROUP_CONFIG_t *) &group_init_handle3, /*Holds the group config structure */
  .post_calibration    = (bool) true, /* Enable or disable the post calibration*/
  .state               = GLOBAL_ADC_UNINITIALIZED       /*The status of the ADC group */
};

/**
 * This structure contains the all the Global Related Structures and also GLOBAL_ADC_group_t Structures
 */
GLOBAL_ADC_t GLOBAL_ADC_0 =
{
  .group_ptrs_array		      = { (GLOBAL_ADC_group_t*) &group_0_config,
						          (GLOBAL_ADC_group_t*) &group_1_config,
						          (GLOBAL_ADC_group_t*) &group_2_config,
						          (GLOBAL_ADC_group_t*) &group_3_config
                                },
  .global_config_handle	      = (XMC_VADC_GLOBAL_CONFIG_t*) &global_config, /*Holds the global config structure */
  .module_ptr			      = (XMC_VADC_GLOBAL_t*)(void*) VADC,    /*Holds the hardware module pointer*/
  .init_state                 = GLOBAL_ADC_UNINITIALIZED, 			   /*The status of the GLOBAL_ADC App */
  .enable_startup_calibration = (uint32_t) true /* Enable Start up calibration*/
};



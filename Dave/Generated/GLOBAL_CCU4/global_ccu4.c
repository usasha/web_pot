/***********************************************************************************************************************
 Copyright (c) 2015, Infineon Technologies AG                                                                         **
 All rights reserved.                                                                                                 **
                                                                                                                      **
 Redistribution and use in source and binary forms, with or without modification,are permitted provided that the      **
 following conditions are met:                                                                                        **
                                                                                                                      **
 *Redistributions of source code must retain the above copyright notice, this list of conditions and the following    **
  disclaimer.                                                                                                         **
 *Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following **
  disclaimer in the documentation and/or other materials provided with the distribution.                              **
 *Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote       **
  products derived from this software without specific prior written permission.                                      **
                                                                                                                      **
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  AND ANY EXPRESS OR IMPLIED WARRANTIES,  **
 INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE    **
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,  **
 SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR      **
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,    **
 WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  **
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                                                 **
                                                                                                                      **
 To improve the quality of the software, users are encouraged to share modifications, enhancements or bug fixes with  **
 Infineon Technologies AG dave@infineon.com).                                                                         **
                                                                                                                      **
************************************************************************************************************************
**                                                                                                                    **
** PLATFORM : Infineon XMC4000/XMC1000 Series                                                                         **
**                                                                                                                    **
** COMPILER : Compiler Independent                                                                                    **
**                                                                                                                    **
** AUTHOR   : APP Developer                                                                                           **
**                                                                                                                    **
** NOTE     : Any Changes made to this file will be overwritten during Code Generation                                **
**                                                                                                                    **
***********************************************************************************************************************/
/**
 * @file global_ccu4.c
 * @date 16 Feb, 2015
 * @version 4.0.0
 *
 * @brief Application code for CCU4 Global Register initialization.
 *
 * <b>Detailed description of the file:</b><br>
 * APIs for the functional blocks of CCU4 have been defined:<br>
 *
 * History<br>
 *
 * v4.0.0   16/02/2015   Initial version<br>
 */

/***********************************************************************************************************************
 **                 Header file inclusion                                                                             **
 **********************************************************************************************************************/

#include "global_ccu4.h"

/***********************************************************************************************************************
 **                 External variables                                                                                **
 **********************************************************************************************************************/

/***********************************************************************************************************************
 **                 Local constants                                                                                   **
 **********************************************************************************************************************/

/**
 * @cond INTERNAL_DOCS
 */

/* Returns the version of the GLOBAL_CCU4 APP. */
DAVE_APP_VERSION_t GLOBAL_CCU4_GetAppVersion(void)
{
  DAVE_APP_VERSION_t version;

  version.major = GLOBAL_CCU4_MAJOR_VERSION;
  version.minor = GLOBAL_CCU4_MINOR_VERSION;
  version.patch = GLOBAL_CCU4_PATCH_VERSION;

  return version;
}

/* Initializes the slice with the generated configuration */
GLOBAL_CCU4_STATUS_t GLOBAL_CCU4_Init(GLOBAL_CCU4_t* handle)
{
  XMC_ASSERT("GLOBAL_CCU4_Init:NULL handler", (NULL != handle));

  if (false == handle->is_initialized)
  {
	/* Enable CCU4 module */
	XMC_CCU4_Init(handle->module_ptr,handle->mcs_action);
	/* Start the prescaler */
	XMC_CCU4_StartPrescaler(handle->module_ptr);
    /* Restricts multiple initializations */
	handle->is_initialized = true;
  }

  return (GLOBAL_CCU4_STATUS_SUCCESS);
}

/**
 * @endcond
 */


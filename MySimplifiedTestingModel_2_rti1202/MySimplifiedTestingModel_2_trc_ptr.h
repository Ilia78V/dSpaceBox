/*********************** dSPACE target specific file *************************

   Header file MySimplifiedTestingModel_2_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1202 23.1 (02-May-2023)
   Thu Feb 19 09:49:32 2026

   Copyright 2026, dSPACE GmbH. All rights reserved.

 *****************************************************************************/
#ifndef RTI_HEADER_MySimplifiedTestingModel_2_trc_ptr_h_
#define RTI_HEADER_MySimplifiedTestingModel_2_trc_ptr_h_

/* Include the model header file. */
#include "MySimplifiedTestingModel_2.h"
#include "MySimplifiedTestingModel_2_private.h"
#ifdef EXTERN_C
#undef EXTERN_C
#endif

#ifdef __cplusplus
#define EXTERN_C                       extern "C"
#else
#define EXTERN_C                       extern
#endif

/*
 *  Declare the global TRC pointers
 */
EXTERN_C volatile real_T *p_0_MySimplifiedTestingModel_2_real_T_0;
EXTERN_C volatile uint32_T *p_0_MySimplifiedTestingModel_2_uint32_T_1;
EXTERN_C volatile int32_T *p_0_MySimplifiedTestingModel_2_int32_T_2;
EXTERN_C volatile uint16_T *p_0_MySimplifiedTestingModel_2_uint16_T_3;
EXTERN_C volatile uint8_T *p_0_MySimplifiedTestingModel_2_uint8_T_4;
EXTERN_C volatile boolean_T *p_0_MySimplifiedTestingModel_2_boolean_T_5;
EXTERN_C volatile real_T *p_1_MySimplifiedTestingModel_2_real_T_0;
EXTERN_C volatile int32_T *p_1_MySimplifiedTestingModel_2_int32_T_1;
EXTERN_C volatile uint32_T *p_1_MySimplifiedTestingModel_2_uint32_T_2;
EXTERN_C volatile boolean_T *p_1_MySimplifiedTestingModel_2_boolean_T_3;
EXTERN_C volatile uint8_T *p_1_MySimplifiedTestingModel_2_uint8_T_4;
EXTERN_C volatile uint16_T *p_2_MySimplifiedTestingModel_2_uint16_T_0;
EXTERN_C volatile uint8_T *p_2_MySimplifiedTestingModel_2_uint8_T_1;
EXTERN_C volatile boolean_T *p_2_MySimplifiedTestingModel_2_boolean_T_2;

/*
 *  Declare the general function for TRC pointer initialization
 */
EXTERN_C void MySimplifiedTestingModel_2_rti_init_trc_pointers(void);

#endif                    /* RTI_HEADER_MySimplifiedTestingModel_2_trc_ptr_h_ */

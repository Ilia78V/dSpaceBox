/*********************** dSPACE target specific file *************************

   Header file MySimplifiedTestingModel_20x2810x29_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1202 23.1 (02-May-2023)
   Mon Dec  8 11:32:08 2025

   Copyright 2025, dSPACE GmbH. All rights reserved.

 *****************************************************************************/
#ifndef RTI_HEADER_MySimplifiedTestingModel_20x2810x29_trc_ptr_h_
#define RTI_HEADER_MySimplifiedTestingModel_20x2810x29_trc_ptr_h_

/* Include the model header file. */
#include "MySimplifiedTestingModel_20x2810x29.h"
#include "MySimplifiedTestingModel_20x2810x29_private.h"
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
EXTERN_C volatile real_T *p_0_MySimplifiedTestingModel_20x2810x29_real_T_0;
EXTERN_C volatile uint8_T *p_0_MySimplifiedTestingModel_20x2810x29_uint8_T_1;
EXTERN_C volatile boolean_T *p_0_MySimplifiedTestingModel_20x2810x29_boolean_T_2;
EXTERN_C volatile real_T *p_1_MySimplifiedTestingModel_20x2810x29_real_T_0;
EXTERN_C volatile boolean_T *p_1_MySimplifiedTestingModel_20x2810x29_boolean_T_1;
EXTERN_C volatile uint8_T *p_1_MySimplifiedTestingModel_20x2810x29_uint8_T_2;
EXTERN_C volatile uint16_T *p_2_MySimplifiedTestingModel_20x2810x29_uint16_T_0;
EXTERN_C volatile uint8_T *p_2_MySimplifiedTestingModel_20x2810x29_uint8_T_1;
EXTERN_C volatile boolean_T *p_2_MySimplifiedTestingModel_20x2810x29_boolean_T_2;

/*
 *  Declare the general function for TRC pointer initialization
 */
EXTERN_C void MySimplifiedTestingModel_20x2810x29_rti_init_trc_pointers(void);

#endif           /* RTI_HEADER_MySimplifiedTestingModel_20x2810x29_trc_ptr_h_ */

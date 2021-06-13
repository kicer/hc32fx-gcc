#ifndef __HC32Fx_H
#define __HC32Fx_H

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */


#if !defined  (HC32Fx)
#define HC32Fx
#endif /* HC32Fx */


/** @brief CMSIS Device version number V2.3.3 */
#define __HC32Fx_DEVICE_VERSION_MAIN   (0x02) /*!< [31:24] main version */
#define __HC32Fx_DEVICE_VERSION_SUB1   (0x03) /*!< [23:16] sub1 version */
#define __HC32Fx_DEVICE_VERSION_SUB2   (0x03) /*!< [15:8]  sub2 version */
#define __HC32Fx_DEVICE_VERSION_RC     (0x00) /*!< [7:0]  release candidate */ 
#define __HC32Fx_DEVICE_VERSION        ((__HC32F0_DEVICE_VERSION_MAIN << 24)\
                                        |(__HC32F0_DEVICE_VERSION_SUB1 << 16)\
                                        |(__HC32F0_DEVICE_VERSION_SUB2 << 8 )\
                                        |(__HC32F0_DEVICE_VERSION_RC))


#if defined(HC32F003x4) || defined(hc32f003x4)
  #include "hc32f003x4.h"
#elif defined(HC32F005x6) || defined(hc32f005x6)
  #include "hc32f005x6.h"
#else
 #error "Please select the target HC32Fx device used in your application"
#endif


typedef enum 
{
  RESET = 0, 
  SET = !RESET
} FlagStatus, ITStatus;

typedef enum 
{
  DISABLE = 0, 
  ENABLE = !DISABLE
} FunctionalState;
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

#ifndef ERROR
typedef enum 
{
  ERROR = 0, 
  SUCCESS = !ERROR
} ErrorStatus;
#endif /* ERROR defined in hc32fx.h */


#define SET_BIT(REG, BIT)     ((REG) |= (BIT))
#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))
#define READ_BIT(REG, BIT)    ((REG) & (BIT))
#define CLEAR_REG(REG)        ((REG) = (0x0))
#define WRITE_REG(REG, VAL)   ((REG) = (VAL))
#define READ_REG(REG)         ((REG))
#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __HC32Fx_H */

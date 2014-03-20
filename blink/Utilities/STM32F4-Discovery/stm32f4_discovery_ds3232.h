/**
  ******************************************************************************
  * @file    stm32f4_discovery_ds3232.h
  * @author  Anthony Paterson
  * @version V0.0.0
  * @date    04-March-2014
  * @brief
  ******************************************************************************
  * @attention
  *
  *>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STM32F4_DISCOVERY_DS3232_H_
#define STM32F4_DISCOVERY_DS3232_H_

#ifdef __cplusplus
 extern "C" {
#endif

 /* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "i2c.h"

 /** @addtogroup Utilities
   * @{
   */

 /** @addtogroup STM32F4_DISCOVERY
   * @{
   */


 /** @addtogroup STM32F4_DISCOVERY_DS3232
   * @{
   */

 /** @defgroup STM32F4_DISCOVERY_DS3232_Exported_Types
   * @{
   */

 /**
  * \struct DS3232_InitTypeDef
  */
 typedef struct
 {

	 uint8_t Sample_Rate_Divider;


 }DS3232_InitTypeDef;

 /**
   * @}
   */

 /** @defgroup STM32F4_DISCOVERY_DS3232_Exported_Constants
   * @{
   */

 /** @brief DS3232 i2c device id constant
   *
   */
//#define DS3232_I2C_DEVID				0x??

 /** @brief DS3232 Default I2C Addresses
   * \attention
   *
   */
#define	DS3232_I2C_7BIT_ADDRESS        (uint8_t)0x68 // 0b1101000

 /**
 * @defgroup DS3232_I2C_Interface_Pins
 */

#define DS3232_I2C_INT_PIN            	GPIO_Pin_6
#define DS3232_I2C_INT_GPIO_PORT      	GPIOD
#define DS3232_I2C_INT_GPIO_CLK       	RCC_AHB1Periph_GPIOD
#define DS3232_I2C_INT_EXTI_LINE      	EXTI_Line6
#define DS3232_I2C_INT_EXTI_PORT_SOURCE 	EXTI_PortSourceGPIOD
#define DS3232_I2C_INT_EXTI_PIN_SOURCE  	EXTI_PinSource6
#define DS3232_I2C_INT_EXTI_IRQn        	EXTI0_IRQn

 /**
 * @defgroup DS3232_Registers
 */

 /**
  * \def DS3232_WHO_AM_I_REG_ADDR
  * 		DEVID Register: Device Identification Register.
  * 		Read only.
  * 		Default value:.
  * 		Fixed value.
   */
//#define DS3232_WHO_AM_I_REG_ADDR				((uint8_t)	0x00)	// Read/Write. Yes. You can change the ID of this device. Power on Reset value is 0bx110100x


 /********************************************************************************/
#define DS3232_SECONDS_REG_ADDR         ((uint8_t)      0x00) // READ/WRITE

 ///BIT7         0
 ///BIT6:4       10 Seconds, BCD Format
 ///BIT3:0       Seconds, BCD Format

 /********************************************************************************/
#define DS3232_MINUTES_REG_ADDR         ((uint8_t)      0x01)

 ///BIT7         0
 ///BIT6:4       10 Minutes, BCD Format
 ///BIT3:0       Minutes, BCD Format

 /********************************************************************************/
#define DS3232_HOURS_REG_ADDR           ((uint8_t)      0x02)

 ///BIT7         0
 ///BIT6         12 / !24
 ///BIT5         !AM / PM or 20 Hour, BCD Format
 ///BIT4         10 Hour, BCD Format
 ///BIT3:0       Hour, BCD Format

 /********************************************************************************/
#define DS3232_DAY_REG_ADDR             ((uint8_t)      0x03)

 ///BIT7:3       00000
 ///BIT2:0       Day, BCD Format

 /********************************************************************************/
#define DS3232_DATE_REG_ADDR            ((uint8_t)      0x04)

 ///BIT7         0
 ///BIT6         0
 ///BIT5:4       10 Date, BCD Format
 ///BIT3:0       Date, BCD Format

 /********************************************************************************/
#define DS3232_MONTH_CENTURY_REG_ADDR   ((uint8_t)      0x05)

 ///BIT7         Century
 ///BIT6         0
 ///BIT5         0
 ///BIT4         10 Month, BCD Format
 ///BIT3:0       Month, BCD Format

 /********************************************************************************/
#define DS3232_YEAR_REG_ADDR            ((uint8_t)      0x06)

 ///BIT7:4       10 Year, BCD Format
 ///BIT3:0       Year, BCD Format

 /********************************************************************************/
#define DS3232_ALARM1_SECONDS_REG_ADDR  ((uint8_t)      0x07)

 ///BIT7         A1M1
 ///BIT6:4       10 Seconds, BCD Format
 ///BIT3:0       Seconds, BCD Format

 /********************************************************************************/
#define DS3232_ALARM1_MINUTES_REG_ADDR  ((uint8_t)      0x08)

 ///BIT7         A1M2
 ///BIT6:4       10 Minutes, BCD Format
 ///BIT3:0       Minutes, BCD Format

 /********************************************************************************/
#define DS3232_ALARM1_HOURS_REG_ADDR    ((uint8_t)      0x09)

 ///BIT7        A1M3
 ///BIT6        12 / !24
 ///BIT5        !AM / PM or 20 Hour
 ///BIT4        10 Hour
 ///BIT3:0      Hour, BCD Format

 /********************************************************************************/
#define DS3232_ALARM1_DAY_DATE_REG_ADDR ((uint8_t)      0x0A)

 ///BIT7        A1M4
 ///BIT6        DY / !DT
 ///BIT5:4      10 Date, BCD Format
 ///BIT3:0      Day or Date, BCD Format

 /********************************************************************************/
#define DS3232_ALARM2_MINUTES_REG_ADDR  ((uint8_t)      0x0B)

 ///BIT7         A2M2
 ///BIT6:4       10 Minutes, BCD Format
 ///BIT3:0       Minutes, BCD Format

 /********************************************************************************/
#define DS3232_ALARM2_HOURS_REG_ADDR    ((uint8_t)      0x0C)

 ///BIT7        A2M3
 ///BIT6        12 / !24
 ///BIT5        !AM / PM or 20 Hour
 ///BIT4        10 Hour
 ///BIT3:0      Hour, BCD Format

 /********************************************************************************/
#define DS3232_ALARM2_DAY_DATE_REG_ADDR ((uint8_t)      0x0D)

 ///BIT7        A2M4
 ///BIT6        DY / !DT
 ///BIT5:4      10 Date, BCD Format
 ///BIT3:0      Day or Date, BCD Format


 /********************************************************************************/
#define DS3232_CONTROL_REG_ADDR         ((uint8_t) 0x0E)

#define DS3232_CONTROL_ENABLEOSC        ((uint8_t) 0x80)     ///BIT7        !EOSC       Set to 1 and on battery power disable oscillator.               \
                                                                                        Power on default 0.
#define DS3232_CONTROL_BBSQENABLE       ((uint8_t) 0x40)     ///BIT6        BBSQW       BBSQW = 1 and INTCN = 0 and Vcc = 0 => Enable square wave.      \
                                                                                        BBSQW = 0 => !INT/SQW pin goes high impedance when Vcc < Vpf    \
                                                                                        Power on default = 0.
#define DS3232_CONTROL_ENABLEOSC        ((uint8_t) 0x20)     ///BIT5        CONV        Set to 1 triggers temp conversion and compensation algorithm    \
                                                                                        which updates capacitance array to oscillator.                                 \
                                                                                        Check BSY to ensure periodic conversion not already taking place\
                                                                                        Does not interfere with normal 64 second compensation interval  \
                                                                                        Does not update the BSY pin for 2ms, use CONV to monitor user   \
                                                                                        initiated conversions. CONV and BSY remain 1 during conversion
#define DS3232_CONTROL_ENABLEOSC        ((uint8_t) 0x10)     ///BIT4        RS2         Rate Select:    RS1= 0      RS2= 0      1Hz
#define DS3232_CONTROL_ENABLEOSC        ((uint8_t) 0x08)     ///BIT3        RS1                         RS1= 0      RS2= 1      1.024kHz                \
                                                                                                        RS1= 1      RS2= 0      4.096kHz                \
                                                                                                        RS1= 1      RS2= 1      8.192kHz
#define DS3232_CONTROL_ENABLEOSC        ((uint8_t) 0x04)     ///BIT2        INTCN       Set to 0 => !INT/SQW pin outputs square wave.                   \
                                                                                        Set to 1 => !INT/SQW pin outputs interrupts.
#define DS3232_CONTROL_ENABLEOSC        ((uint8_t) 0x02)     ///BIT1        A2IE        Alarm 2 Interrupt Enable,                                       \
                                                                                        when INTCN = 1, permits Alarm 2 Flag A2F to assert !INT/SQW pin.\
                                                                                        Power on default = 0
#define DS3232_CONTROL_ENABLEOSC        ((uint8_t) 0x01)     ///BIT0        A1IE        Alarm 1 Interrupt Enable,                                       \
                                                                                        when INTCN = 1, permits Alarm 1 Flag A1F to assert !INT/SQW pin.\
                                                                                        Power on default = 0



 /********************************************************************************/
#define DS3232_CTRL_STATUS_REG_ADDR     ((uint8_t)      0x0F)

/**
 * Bit 7: Oscillator Stop Flag (OSF).
 * A logic 1 in this bit indicates that the oscillator either is stopped or was
 * stopped for some period and may be used to judge the validity of the
 * time keeping data. This bit is set to logic 1 any time that the oscillator
 * stops. The following are examples of conditions that can cause the OSF bit to
 * be set:
 *      1) The first time power is applied.
 *      2) The voltages present on both VCC and VBAT are
 *         insufficient to support oscillation.
 *      3) The EOSC bit is turned off in battery-backed mode.
 *      4) External influences on the crystal (i.e., noise, leakage,
 *         etc.).
 * This bit remains at logic 1 until written to logic 0.
 *
 * @param DS3232_InitStruct
 */
 #define DS3232_CTRL_STATUS_OSC_STOP_F   ((uint8_t)      0x80)

/**
 * Bit 6: Battery-Backed 32kHz Output (BB32kHz).
 * This bit enables the 32kHz output when powered from VBAT
 * (provided EN32kHz is enabled). If BB32kHz = 0, the
 * 32kHz output is low when the part is powered by VBAT.
 *
 * @param DS3232_InitStruct
 */
 #define DS3232_CTRL_STATUS_BB32kHz_ENABLE   ((uint8_t)      0x40)

/**
 * Bits 5 and 4: Conversion Rate (CRATE1 and
 * CRATE0). These two bits control the sample rate of the
 * TCXO. The sample rate determines how often the temperature
 * sensor makes a conversion and applies compensation
 * to the oscillator. Decreasing the sample rate
 * decreases the overall power consumption by decreasing
 * the frequency at which the temperature sensor
 * operates. However, significant temperature changes
 * that occur between samples may not be completely
 * compensated for, which reduce overall accuracy.
 * When a new conversion rate is written to the register, it
 * may take up to the new conversion rate time before the
 * conversions occur at the new rate.
 *
 * @param DS3232_InitStruct
 */
#define DS3232_CTRL_STATUS_CRATE_512    ((uint8_t)      0x30)
#define DS3232_CTRL_STATUS_CRATE_256    ((uint8_t)      0x20)
#define DS3232_CTRL_STATUS_CRATE_128    ((uint8_t)      0x10)
#define DS3232_CTRL_STATUS_CRATE_64     ((uint8_t)      0x00)

/**
 * Bit 3: Enable 32kHz Output (EN32kHz).
 * This bit indicates
 * the status of the 32kHz pin. When set to logic 1,
 * the 32kHz pin is enabled and outputs a 32.768kHz
 * square-wave signal. When set to logic 0, the 32kHz pin
 * goes low. The initial power-up state of this bit is logic 1,
 * and a 32.768kHz square-wave signal appears at the
 * 32kHz pin after a power source is applied to the DS3232
 * (if the oscillator is running).
 * **/
#define DS3232_CTRL_STATUS_32kHz_ENABLE ((uint8_t)      0x04

 /**
  * Bit 2: Busy (BSY).
  * This bit indicates the device is busy
  * executing TCXO functions. It goes to logic 1 when the
  * conversion signal to the temperature sensor is asserted
  * and then is cleared when the conversion is complete.
  *
  * @param DS3232_InitStruct
  */
 #define DS3232_CTRL_STATUS_BSY_F

 /**
  * Bit 1: Alarm 2 Flag (A2F).
  * A logic 1 in the alarm 2 flag
  * bit indicates that the time matched the alarm 2 registers.
  * If the A2IE bit is logic 1 and the INTCN bit is set to
  * logic 1, the INT/SQW pin is also asserted. A2F is
  * cleared when written to logic 0. This bit can only be
  * written to logic 0. Attempting to write to logic 1 leaves
  * the value unchanged.
  *
  * @param DS3232_InitStruct
  */
#define DS3232_CTRL_STATUS_Alarm2_F

 /**
  * Bit 0: Alarm 1 Flag (A1F).
  * A logic 1 in the alarm 1 flag
  * bit indicates that the time matched the alarm 1 registers.
  * If the A1IE bit is logic 1 and the INTCN bit is set to
  * logic 1, the INT/SQW pin is also asserted. A1F is
  * cleared when written to logic 0. This bit can only be
  * written to logic 0. Attempting to write to logic 1 leaves
  * the value unchanged.
  *
  * @param DS3232_InitStruct
  */
#define DS3232_CTRL_STATUS_Alarm1_F///BIT0        A1F

 /********************************************************************************/
#define DS3232_AGING_OFFSET_REG_ADDR    ((uint8_t)      0x10)

 ///BIT7:0      SIGNED DATA, Two's Comp Format

 /********************************************************************************/
#define DS3232_TEMP_MSB_REG_ADDR        ((uint8_t)      0x11)

 ///BIT7:0      SIGNED DATA, Two's Comp Format, MSB

 /********************************************************************************/
#define DS3232_TEMP_LSB_REG_ADDR        ((uint8_t)      0x12)

 ///BIT7:6      SIGNED DATA, Two's Comp Format, LSBits
 ///BIT5:0      000000

 /********************************************************************************/
 ///ADDR 0x13 RESERVED FOR TEST
 ///ALL BITS 0

 /********************************************************************************/
#define DS3232_SRAM_START_ADDR          ((uint8_t)      0x14)
#define DS3232_SRAM_END_ADDR            0x0FF


 /**
   * @}
   */

 /** @defgroup STM32F4_DISCOVERY_DS3232_Exported_Macros
   * @{
   */

 /**
   * @}
   */

 /** @defgroup STM32F4_DISCOVERY_DS3232_Exported_Functions
   * @{
   */
 void DS3232_Init(DS3232_InitTypeDef *DS3232_InitStruct);

 uint8_t DS3232_ReadReg(uint8_t DS3232_Reg);
 void DS3232_WriteReg(uint8_t DS3232_Reg, uint16_t DS3232_RegValue);


 /**
   * @}
   */

 /**
  * @brief Uncomment the line below if you want to use user defined Delay function
  *        (for precise timing), otherwise default _delay_ function defined within
  *         this driver is used (less precise timing).
  */
  /* #define USE_Delay */

  #ifdef USE_Delay
  #include "main.h"
  #define _delay_     Delay  /* !< User can provide more timing precise _delay_ function
  								(with 10ms time base), using SysTick for example */
  #else
  #define _delay_     delay      /* !< Default _delay_ function with less precise timing */
  #endif

  /**
    * @}
    */

#ifdef __cplusplus
}
#endif

#endif /* STM32F4_DISCOVERY_DS3232_H_ */

 /**
   * @}
   */

 /**
   * @}
   */

 /**
   * @}
   */


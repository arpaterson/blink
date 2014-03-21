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
   //Modes
   uint8_t DS3232_CONTROL_SQW_RATE;

   //Values
   uint8_t Current_Date_BCD;
   uint8_t Current_Time_BCD;

 }DS3232_InitTypeDef;

 /**
   * @}
   */

 /** @defgroup STM32F4_DISCOVERY_DS3232_Exported_Constants
   * @{
   */

 /** @brief DS3232 Default I2C Addresses
  * 0b1101000
  *
  * \attention
  *
  */
#define	DS3232_I2C_7BIT_ADDRESS                 ((uint8_t) 0x68)

 /**
 * @defgroup DS3232_I2C_Interface_Pins
 * @{
 */

#define DS3232_I2C_INT_PIN            	        GPIO_Pin_6
#define DS3232_I2C_INT_GPIO_PORT      	        GPIOD
#define DS3232_I2C_INT_GPIO_CLK       	        RCC_AHB1Periph_GPIOD
#define DS3232_I2C_INT_EXTI_LINE      	        EXTI_Line6
#define DS3232_I2C_INT_EXTI_PORT_SOURCE 	EXTI_PortSourceGPIOD
#define DS3232_I2C_INT_EXTI_PIN_SOURCE  	EXTI_PinSource6
#define DS3232_I2C_INT_EXTI_IRQn        	EXTI0_IRQn

 /**
  * @}
  */

 /**
 * @defgroup DS3232_Registers
 * @{
 */

 /********************************************************************************/

 /**
  * \def DS3232_SECONDS_REG_ADDR
  *
  * BIT7         0
  * BIT6:4       10 Seconds, BCD Format
  * BIT3:0       Seconds, BCD Format
  *
  * @param DS3232_InitStruct
  */
#define DS3232_SECONDS_REG_ADDR                 ((uint8_t) 0x00)

 ///BIT7         0
 ///BIT6:4       10 Seconds, BCD Format
 ///BIT3:0       Seconds, BCD Format

 /********************************************************************************/

 /**
  * \def DS3232_MINUTES_REG_ADDR
  *
  * @param DS3232_InitStruct
  */

#define DS3232_MINUTES_REG_ADDR                 ((uint8_t) 0x01)

 ///BIT7         0
 ///BIT6:4       10 Minutes, BCD Format
 ///BIT3:0       Minutes, BCD Format

 /********************************************************************************/

 /**
  * \def DS3232_HOURS_REG_ADDR
  *
  * @param DS3232_InitStruct
  */
#define DS3232_HOURS_REG_ADDR                   ((uint8_t) 0x02)

 ///BIT7         0
 ///BIT6         12 / !24
 ///BIT5         !AM / PM or 20 Hour, BCD Format
 ///BIT4         10 Hour, BCD Format
 ///BIT3:0       Hour, BCD Format

 /********************************************************************************/

 /**
  * \def DS3232_DAY_REG_ADDR
  *
  * @param DS3232_InitStruct
  */
#define DS3232_DAY_REG_ADDR                     ((uint8_t) 0x03)

 ///BIT7:3       00000
 ///BIT2:0       Day, BCD Format

 /********************************************************************************/

 /**
  * \def DS3232_DATE_REG_ADDR
  *
  * @param DS3232_InitStruct
  */
#define DS3232_DATE_REG_ADDR                    ((uint8_t) 0x04)

 ///BIT7         0
 ///BIT6         0
 ///BIT5:4       10 Date, BCD Format
 ///BIT3:0       Date, BCD Format

 /********************************************************************************/

 /**
  * \def DS3232_MONTH_CENTURY_REG_ADDR
  *
  * @param DS3232_InitStruct
  */
#define DS3232_MONTH_CENTURY_REG_ADDR           ((uint8_t) 0x05)

 ///BIT7         Century
 ///BIT6         0
 ///BIT5         0
 ///BIT4         10 Month, BCD Format
 ///BIT3:0       Month, BCD Format

 /********************************************************************************/

 /**
  * \def DS3232_YEAR_REG_ADDR
  *
  * @param DS3232_InitStruct
  */
#define DS3232_YEAR_REG_ADDR                    ((uint8_t) 0x06)

 ///BIT7:4       10 Year, BCD Format
 ///BIT3:0       Year, BCD Format

 /********************************************************************************/

 /**
  * \def DS3232_ALARM1_SECONDS_REG_ADDR
  *
  * @param DS3232_InitStruct
  */
#define DS3232_ALARM1_SECONDS_REG_ADDR          ((uint8_t) 0x07)

 ///BIT7         A1M1
 ///BIT6:4       10 Seconds, BCD Format
 ///BIT3:0       Seconds, BCD Format

 /********************************************************************************/

 /**
  * \def DS3232_ALARM1_MINUTES_REG_ADDR
  *
  * @param DS3232_InitStruct
  */
#define DS3232_ALARM1_MINUTES_REG_ADDR          ((uint8_t) 0x08)

 ///BIT7         A1M2
 ///BIT6:4       10 Minutes, BCD Format
 ///BIT3:0       Minutes, BCD Format

 /********************************************************************************/

 /**
  * \def DS3232_ALARM1_HOURS_REG_ADDR
  *
  * @param DS3232_InitStruct
  */
#define DS3232_ALARM1_HOURS_REG_ADDR            ((uint8_t) 0x09)

 ///BIT7        A1M3
 ///BIT6        12 / !24
 ///BIT5        !AM / PM or 20 Hour
 ///BIT4        10 Hour
 ///BIT3:0      Hour, BCD Format

 /********************************************************************************/

 /**
  * \def DS3232_ALARM1_DAY_DATE_REG_ADDR
  *
  * @param DS3232_InitStruct
  */
#define DS3232_ALARM1_DAY_DATE_REG_ADDR         ((uint8_t) 0x0A)

 ///BIT7        A1M4
 ///BIT6        DY / !DT
 ///BIT5:4      10 Date, BCD Format
 ///BIT3:0      Day or Date, BCD Format

 /********************************************************************************/

 /**
  * \def DS3232_ALARM2_MINUTES_REG_ADDR
  *
  * @param DS3232_InitStruct
  */
#define DS3232_ALARM2_MINUTES_REG_ADDR          ((uint8_t) 0x0B)

 ///BIT7         A2M2
 ///BIT6:4       10 Minutes, BCD Format
 ///BIT3:0       Minutes, BCD Format

 /********************************************************************************/

 /**
  * \def DS3232_ALARM2_HOURS_REG_ADDR
  *
  * @param DS3232_InitStruct
  */
#define DS3232_ALARM2_HOURS_REG_ADDR            ((uint8_t) 0x0C)

 ///BIT7        A2M3
 ///BIT6        12 / !24
 ///BIT5        !AM / PM or 20 Hour
 ///BIT4        10 Hour
 ///BIT3:0      Hour, BCD Format

 /********************************************************************************/

 /**
  * \def DS3232_ALARM2_DAY_DATE_REG_ADDR
  *
  * @param DS3232_InitStruct
  */
#define DS3232_ALARM2_DAY_DATE_REG_ADDR         ((uint8_t) 0x0D)

 ///BIT7        A2M4
 ///BIT6        DY / !DT
 ///BIT5:4      10 Date, BCD Format
 ///BIT3:0      Day or Date, BCD Format

 /********************************************************************************/

 /**
  * \def DS3232_CONTROL_REG_ADDR
  *
  * @param DS3232_InitStruct
  */
#define DS3232_CONTROL_REG_ADDR                 ((uint8_t) 0x0E)

/**
 * Bit 7: Enable Oscillator (!EOSC).
 * When set to logic 0, the oscillator is started. When set to logic 1, the oscillator
 * is stopped when the DS3232 switches to battery
 * power. This bit is clear (logic 0) when power is first
 * applied. When the DS3232 is powered by VCC, the
 * oscillator is always on regardless of the status of the
 * !EOSC bit. When !EOSC is disabled, all register data is
 * static.
 *
 * @param DS3232_InitStruct
 */
#define DS3232_CONTROL_ENABLEOSC                ((uint8_t) 0x80)

/**
 * Bit 6: Battery-Backed Square-Wave Enable (BBSQW).
 * When set to logic 1 with INTCN = 0 and VCC
 * < VPF, this bit enables the square wave. When BBSQW
 * is logic 0, the !INT/SQW pin goes high impedance when
 * VCC < VPF. This bit is disabled (logic 0) when power is
 * first applied.
 *
 * @param DS3232_InitStruct
 */
#define DS3232_CONTROL_BBSQENABLE               ((uint8_t) 0x40)

/**
 * Bit 5: Convert Temperature (CONV).
 * Setting this bit to 1 forces the temperature sensor to convert the temperature
 * into digital code and execute the TCXO algorithm
 * to update the capacitance array to the oscillator. This
 * can only happen when a conversion is not already in
 * progress. The user should check the status bit BSY
 * before forcing the controller to start a new TCXO execution.
 * A user-initiated temperature conversion does
 * not affect the internal 64-second (default interval)
 * update cycle.
 * A user-initiated temperature conversion does not affect
 * the BSY bit for approximately 2ms. The CONV bit
 * remains at a 1 from the time it is written until the conversion
 * is finished, at which time both CONV and BSY go
 * to 0. The CONV bit should be used when monitoring
 * the status of a user-initiated conversion.
 *
 * @param DS3232_InitStruct
 */
#define DS3232_CONTROL_CONV                     ((uint8_t) 0x20)

 /**
 * Bits 4 and 3: Rate Select (RS2 and RS1).
 * These bits control the frequency of the square-wave output when
 * the square wave has been enabled. The following table
 * shows the square-wave frequencies that can be selected
 * with the RS bits. These bits are both set to logic 1
 * (8.192kHz) when power is first applied.
 *
 * @param DS3232_InitStruct
 */
#define DS3232_CONTROL_SQW_RATE_8192Hz          ((uint8_t) 0x18)
#define DS3232_CONTROL_SQW_RATE_4096Hz          ((uint8_t) 0x10)
#define DS3232_CONTROL_SQW_RATE_1024Hz          ((uint8_t) 0x08)
#define DS3232_CONTROL_SQW_RATE_1Hz             ((uint8_t) 0x00)


/**
 * Bit 2: Interrupt Control (INTCN).
 * This bit controls the INT/SQW signal. When the INTCN bit is set to logic 0, a
 * square wave is output on the !INT/SQW pin. When the
 * INTCN bit is set to logic 1, a match between the timekeeping
 * registers and either of the alarm registers activates
 * the !INT/SQW (if the alarm is also enabled). The
 * corresponding alarm flag is always set regardless of
 * the state of the INTCN bit. The INTCN bit is set to logic
 * 1 when power is first applied.
 *
 * @param DS3232_InitStruct
 */
#define DS3232_CONTROL_INT_CTRL                 ((uint8_t) 0x04)

/**
 * Bit 1: Alarm 2 Interrupt Enable (A2IE).
 * When set to logic 1, this bit permits the alarm 2 flag (A2F) bit in the
 * status register to assert !INT/SQW (when INTCN = 1).
 * When the A2IE bit is set to logic 0 or INTCN is set to
 * logic 0, the A2F bit does not initiate an interrupt signal.
 * The A2IE bit is disabled (logic 0) when power is first
 * applied.
 *
 * @param DS3232_InitStruct
 */
#define DS3232_CONTROL_ALARM2_INT_ENABLE        ((uint8_t) 0x02)

/**
 * Bit 0: Alarm 1 Interrupt Enable (A1IE).
 * When set to logic 1, this bit permits the alarm 1 flag (A1F) bit in the
 * status register to assert INT/SQW (when INTCN = 1).
 * When the A1IE bit is set to logic 0 or INTCN is set to
 * logic 0, the A1F bit does not initiate the !INT/SQW signal.
 * The A1IE bit is disabled (logic 0) when power is
 * first applied.
 *
 * @param DS3232_InitStruct
 */
#define DS3232_CONTROL_ALARM1_INT_ENABLE        ((uint8_t) 0x01)


 /********************************************************************************/


 /**
  * Control / Status Register
  *
  * @param DS3232_InitStruct
  */
#define DS3232_CTRL_STATUS_REG_ADDR             ((uint8_t) 0x0F)

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
#define DS3232_CTRL_STATUS_OSC_STOP_F           ((uint8_t) 0x80))

/**
 * Bit 6: Battery-Backed 32kHz Output (BB32kHz).
 * This bit enables the 32kHz output when powered from VBAT
 * (provided EN32kHz is enabled). If BB32kHz = 0, the
 * 32kHz output is low when the part is powered by VBAT.
 *
 * @param DS3232_InitStruct
 */
#define DS3232_CTRL_STATUS_BB32kHz_ENABLE       ((uint8_t) 0x40)

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
#define DS3232_CTRL_STATUS_CRATE_512            ((uint8_t) 0x30)
#define DS3232_CTRL_STATUS_CRATE_256            ((uint8_t) 0x20)
#define DS3232_CTRL_STATUS_CRATE_128            ((uint8_t) 0x10)
#define DS3232_CTRL_STATUS_CRATE_64             ((uint8_t) 0x00)

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
#define DS3232_CTRL_STATUS_32kHz_ENABLE         ((uint8_t) 0x08)

 /**
  * Bit 2: Busy (BSY).
  * This bit indicates the device is busy
  * executing TCXO functions. It goes to logic 1 when the
  * conversion signal to the temperature sensor is asserted
  * and then is cleared when the conversion is complete.
  *
  * @param DS3232_InitStruct
  */
#define DS3232_CTRL_STATUS_BSY_F                ((uint8_t) 0x04)

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
#define DS3232_CTRL_STATUS_Alarm2_F             ((uint8_t) 0x02)

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
#define DS3232_CTRL_STATUS_Alarm1_F             ((uint8_t) 0x01)

 /********************************************************************************/

 /**
  * \def DS3232_AGING_OFFSET_REG_ADDR
  * @param DS3232_InitStruct
  */
#define DS3232_AGING_OFFSET_REG_ADDR            ((uint8_t) 0x10)

 ///BIT7:0      SIGNED DATA, Two's Comp Format

 /********************************************************************************/

 /**
  * \def DS3232_TEMP_MSB_REG_ADDR
  * @param DS3232_InitStruct
  */
#define DS3232_TEMP_MSB_REG_ADDR                ((uint8_t) 0x11)

 ///BIT7:0      SIGNED DATA, Two's Comp Format, MSB

 /********************************************************************************/

 /**
  * \def DS3232_TEMP_LSB_REG_ADDR
  * @param DS3232_InitStruct
  */
#define DS3232_TEMP_LSB_REG_ADDR                ((uint8_t) 0x12)

 ///BIT7:6      SIGNED DATA, Two's Comp Format, LSBits
 ///BIT5:0      000000

 /********************************************************************************/

 ///ADDR 0x13 RESERVED FOR TEST
 ///ALL BITS 0

 /********************************************************************************/

 /**
  * \def DS3232_SRAM_START_ADDR
  * @param DS3232_InitStruct
  */
#define DS3232_SRAM_START_ADDR                  ((uint8_t) 0x14)

 /**
  * \def DS3232_SRAM_END_ADDR
  * @param DS3232_InitStruct
  */
#define DS3232_SRAM_END_ADDR                    0x0FF

 /********************************************************************************/

 /**
  * @}
  */


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


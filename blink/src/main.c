/**
  ******************************************************************************
  * @file    main.c 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    19-September-2011
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup STM32F4-Discovery_Demo
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/



/**
  * @brief  Main program.
  * @param
  * @retval
  */
int main(void){

  /*!< At this stage the microcontroller clock setting is already configured,
	   this is done through SystemInit() function which is called from startup
	   file (startup_stm32f4xx.s) before to branch to application main.
	   To reconfigure the default setting of SystemInit() function, refer to
	   system_stm32f4xx.c file
	 */


	STM32f4_Discovery_LCD_Init();
	LCD_RGB_Test();

	STM32f4_Discovery_Debug_Init();
	/* Output a message on Hyperterminal using printf function */
	printf("\n\rUSART Printf Example: retarget the C library printf function to the USART\n\r");

	ADXL345_InitTypeDef ADXL345_InitStruct;
	//ADXL345_InitStruct.Output_Data_Rate = 	ADXL345_BW_RATE_400;
	ADXL345_InitStruct.Data_Format =		(	ADXL345_DATAFORMAT_Range_PLUS_MINUS_16g | \
												ADXL345_DATAFORMAT_FULL_RES_ENABLE
												);
	ADXL345_InitStruct.Power_Mode = 		(ADXL345_POWER_CTL_Measure_ENABLE | ADXL345_POWER_CTL_Wakeup_1Hz);
	ADXL345_InitStruct.Interrupt_Enable = 	(ADXL345_INT_ENABLE_DATA_READY_ENABLE);
	ADXL345_Init(&ADXL345_InitStruct);

	uint8_t devid;
	uint16_t datax;
	uint8_t datax1; //high byte
	uint8_t datax0; //low byte

	uint8_t datay1; //high byte
	uint8_t datay0; //low byte

	uint8_t dataz1; //high byte
	uint8_t dataz0; //low byte

	while (1)
	{
		devid = ADXL345_ReadReg(ADXL345_DEVID_REG_ADDR);
		//printf("DEVID : %s ", devid);

		// these must be a multi byte read for coherency. todo: implement
		//	and in an ISR triggered by a pin interupt connected to INT1 or INT2 pins of ADXL345.
		datax0 = ADXL345_ReadReg(ADXL345_DATAX0_REG_ADDR);
		datax1 = ADXL345_ReadReg(ADXL345_DATAX1_REG_ADDR);
		printf("%i	", datax1*4); //full res mode maintains 4mg/LSB. range bits set range.
		printf("%i	", datax0*4); //full res mode maintains 4mg/LSB. range bits set range.

		// these must be a multi byte read for coherency. todo: implement
		//	and in an ISR triggered by a pin interupt connected to INT1 or INT2 pins of ADXL345.
		datay0 = ADXL345_ReadReg(ADXL345_DATAY0_REG_ADDR);
		datay1 = ADXL345_ReadReg(ADXL345_DATAY1_REG_ADDR);
		printf("%i	", datay1*4); //full res mode maintains 4mg/LSB. range bits set range.
		printf("%i	", datay0*4); //full res mode maintains 4mg/LSB. range bits set range.

		// these must be a multi byte read for coherency. todo: implement
		//	and in an ISR triggered by a pin interupt connected to INT1 or INT2 pins of ADXL345.
		dataz0 = ADXL345_ReadReg(ADXL345_DATAZ0_REG_ADDR);
		dataz1 = ADXL345_ReadReg(ADXL345_DATAZ1_REG_ADDR);
		printf("%i	", dataz1*4); //full res mode maintains 4mg/LSB. range bits set range.
		printf("%i\n\r", dataz0*4); //full res mode maintains 4mg/LSB. range bits set range.

	}
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/

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

        STM32f4_Discovery_Debug_Init();

        ITG3200_InitTypeDef ITG3200_InitStruct;
	ITG3200_InitStruct.Sample_Rate_Divider = 9;
	ITG3200_InitStruct.Full_Scale = ITG32000_DLPF_FS_FS_SEL_PLUS_MINUS_2000;
	ITG3200_InitStruct.Low_Pass_Freq = ITG3200_DLPF_FS_DLPF_CFG_5Hz;
	ITG3200_InitStruct.Interrupt_Config = ITG3200_INT_CFG_RAW_RDY_ENABLE;
	ITG3200_InitStruct.Power_Config = ITG3200_POWER_MGMT_H_RESET_ENABLE;
	ITG3200_InitStruct.Clock_Config = ITG3200_POWER_MGMT_CLK_SEL_INT_OSC;
	ITG3200_Init(&ITG3200_InitStruct);
	printf("Gyro initialization completed\r\n");

	uint8_t devid;
	int i;
	uint16_t fs_range;
	uint8_t dlpf_cutoff;
	uint8_t srdiv;
	ITG3200_DataPointTypeDef ITG3200_DataPoint;
	unsigned char titlestr[21];
	char string1[21];
	char string2[21];
	char string3[21];
	char string4[21];
	char string5[21];
	char string6[21];
	char string7[21];


	devid = ITG3200_Get_DevID();
	printf("DEVID : %i \r\n", devid);

	LCD_SetBackColor(LCD_COLOR_BLUE);
	LCD_SetTextColor(LCD_COLOR_WHITE);


	LCD_ClearLine(Line0);
	sprintf(titlestr, "ITG3200 DevID: 0x%X", devid);
	LCD_DisplayStringLine(Line0,titlestr);

	fs_range = ITG3200_Get_Fullscale_Range();
	LCD_ClearLine(Line1);
	sprintf(string1,"FSR:%i", fs_range);
	LCD_DisplayStringLine(Line1,string1);

	dlpf_cutoff = ITG3200_Get_DLPF_Bandwidth_Hz();
	LCD_ClearLine(Line2);
	sprintf(string2,"DLPF:%i", dlpf_cutoff);
	LCD_DisplayStringLine(Line2,string2);

	srdiv = ITG3200_Get_Sample_Rate_Divider();
	LCD_ClearLine(Line3);
	sprintf(string3,"SRDIV:%i", srdiv);
	LCD_DisplayStringLine(Line3,string3);

	LCD_SetBackColor(LCD_COLOR_GREEN);

	while (1)
	{
		for(i = 0; i < 1000000; i++){

		}

		ITG3200_DataPoint = ITG3200_Get_DataPoint();

		LCD_ClearLine(Line4);
		sprintf(string4,"T:%i", ITG3200_DataPoint.Temp);
		LCD_DisplayStringLine(Line4,string4);

		LCD_ClearLine(Line5);
		sprintf(string5,"X:%i", ITG3200_DataPoint.X);
		LCD_DisplayStringLine(Line5,string5);

		LCD_ClearLine(Line6);
		sprintf(string6,"Y:%i", ITG3200_DataPoint.Y);
		LCD_DisplayStringLine(Line6,string6);

		LCD_ClearLine(Line7);
		sprintf(string7,"Z:%i", ITG3200_DataPoint.Z);
		LCD_DisplayStringLine(Line7,string7);

		printf("DEVID:%X T:%i X:%i Y:%i Z:%i\r\n", devid, ITG3200_DataPoint.Temp, ITG3200_DataPoint.X, ITG3200_DataPoint.Y, ITG3200_DataPoint.Z);


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

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

	LCD_SetBackColor(LCD_COLOR_BLUE);
	LCD_SetTextColor(LCD_COLOR_WHITE);
	unsigned char titlestr[] = "DS3232 test";
	LCD_ClearLine(Line0);
	LCD_DisplayStringLine(Line0,titlestr);

	STM32f4_Discovery_Debug_Init();

	DS3232_InitTypeDef DS3232_InitStruct;
	DS3232_InitStruct.DS3232_CONTROL_SQW_RATE = DS3232_CONTROL_SQW_RATE_1Hz;
	DS3232_Init(&DS3232_InitStruct);
	DS3232_Set_Mode12Hr();
	printf("Clock initialization completed");


	int i;
	int sec;
	int min;
	int hour;

	char timestr[21] = "timestr init 1";
	char datestr[21] = "datestr init 1";
	//printf ("%i",strlen(datestr)); printf("\r\n");
	char tempstr[21] = "tempstr init";

	while (1)
	{
		for(i = 0; i < 1000000; i++){

		}

		LCD_ClearLine(Line1);
		DS3232_Get_Date_Str(datestr, strlen(datestr));
		LCD_DisplayStringLine(Line1,datestr);

		LCD_ClearLine(Line2);
		DS3232_Get_Time_Str(timestr ,strlen(timestr));
		LCD_DisplayStringLine(Line2,timestr);

		//LCD_ClearLine(Line3);
		//sprintf(tempstr,"%i", 2);
		//LCD_DisplayStringLine(Line3,tempstr);

		printf(datestr); printf("\t");
		//printf ("%i",strlen(datestr));
		printf(timestr); printf("\t");
		//printf(tempstr); printf("\t");
		printf("\r\n");

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

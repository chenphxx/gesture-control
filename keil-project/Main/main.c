#include "stm32f10x.h"
#include "main.h"
#include "i2c.h"
#include "usart1.h"
#include "delay.h"
#include "PAJ7620.h"


#define TIME 500

int main(void)
{	
    SysTick_Init();
    Usart1_Config();
    Nvic_Usart1_Config();
    I2C_Config();
    
    if(PAJ7620_Init()==false)
        Usart1_Send("PAJ7620 initialize error.\r\n");
    
	while(1)
	{
        uint8_t data[2]={0,0};	
        IIC_ReadData(PAJ7620_I2C_ADDR, 0x43, &data[0]);
        
		// 根据结果向PC发送信号
        switch (data[0]) 
		{
            case GES_RIGHT_FLAG:
				DELAY_MS(TIME);
				IIC_ReadData(PAJ7620_I2C_ADDR, 0x43, &data[0]);
				if(data[0] == GES_FORWARD_FLAG) 
				{
					Usart1_Send("Forward\r\n");
					DELAY_MS(TIME);
				}
				else if(data[0] == GES_BACKWARD_FLAG) 
				{
					Usart1_Send("Backward\r\n");
					DELAY_MS(TIME);
				}
				else
					Usart1_Send("Right\r\n");         
            break;
                
            case GES_LEFT_FLAG: 
				DELAY_MS(TIME);
				IIC_ReadData(PAJ7620_I2C_ADDR, 0x43, &data[0]);
				if(data[0] == GES_FORWARD_FLAG) 
				{
					Usart1_Send("Forward\r\n");
					DELAY_MS(TIME);
				}
				else if(data[0] == GES_BACKWARD_FLAG) 
				{
					Usart1_Send("Backward\r\n");
					DELAY_MS(TIME);
				}
				else
					Usart1_Send("Left\r\n");         
            break;   
            
            case GES_UP_FLAG:
				DELAY_MS(TIME);
				IIC_ReadData(PAJ7620_I2C_ADDR, 0x43, &data[0]);
				if(data[0] == GES_FORWARD_FLAG) 
				{
					Usart1_Send("Forward\r\n");
					DELAY_MS(TIME);
				}
				else if(data[0] == GES_BACKWARD_FLAG) 
				{
					Usart1_Send("Backward\r\n");
					DELAY_MS(TIME);
				}
				else
					Usart1_Send("Up\r\n");        
            break;
                
			case GES_DOWN_FLAG:
				DELAY_MS(TIME);
				IIC_ReadData(PAJ7620_I2C_ADDR, 0x43, &data[0]);
				if(data[0] == GES_FORWARD_FLAG) 
				{
					Usart1_Send("Forward\r\n");
					DELAY_MS(TIME);
				}
				else if(data[0] == GES_BACKWARD_FLAG) 
				{
					Usart1_Send("Backward\r\n");
					DELAY_MS(TIME);
				}
				else
					Usart1_Send("Down\r\n");         
            break;
            
            case GES_FORWARD_FLAG:
				Usart1_Send("Forward\r\n");
				DELAY_MS(TIME);
            break;
                
			case GES_BACKWARD_FLAG:		  
				Usart1_Send("Backward\r\n");
				DELAY_MS(TIME);
            break;
                
			case GES_CLOCKWISE_FLAG:
				Usart1_Send("Clockwise\r\n");
            break;
                
			case GES_COUNT_CLOCKWISE_FLAG:
				Usart1_Send("Counter_Clockwise\r\n");
            break; 
                
            default:
                IIC_ReadData(PAJ7620_I2C_ADDR, 0x44, &data[1]);
				if (data[1] == GES_WAVE_FLAG) 
					Usart1_Send("Wave\r\n");
            break;
        }
        DELAY_MS(100);
	}
}

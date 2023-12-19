#include <stdio.h>
#include "esp_log.h"
#include "driver/i2c.h"
#include "u8g2.h"
#include "u8x8.h"
#include "u8g2_myfont_chinese.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
void testDrawProcess(u8g2_t *u8g2)
{
	int i;
	char buff[20];
	for(i=10;i<=80;i=i+2)
	{
		u8g2_ClearBuffer(u8g2); 
			
		
		sprintf(buff,"%d%%",(int)(i/80.0*100));
		
		u8g2_SetFont(u8g2,STXINGKA);
		u8g2_DrawUTF8X2(u8g2,10,25,"欢迎使用 ");//
//		u8g2_DrawStr(u8g2,10,40,"Welcome to use");
		u8g2_SetFont(u8g2,u8g2_font_ncenB08_tf);
		u8g2_DrawStr(u8g2,100,49,buff);//当前进度显示
		
		u8g2_DrawRBox(u8g2,16,40,i,10,4);//圆角填充框矩形框
		u8g2_DrawRFrame(u8g2,16,40,80,10,4);//圆角矩形
		
		u8g2_SendBuffer(u8g2);
	}
	vTaskDelay(500 / portTICK_PERIOD_MS);
	u8g2_ClearBuffer(u8g2);
	u8g2_SetFont(u8g2,u8g2_font_ncenB12_tf);
	u8g2_DrawStr(u8g2,16,40,"Welcome!");//字符显示
	u8g2_SendBuffer(u8g2);
	vTaskDelay(500 / portTICK_PERIOD_MS);
}






void ssd1306_init(void)
{
    u8g2_t u8g2;
    int year=2023;
	int mon=3;
	int day=31;
	char data[20];
	
	int hour = 11;
	int mou=25;
	int sec = 31;
	int wendu;
	int shidu;
    char time1[20];
	char wendu1[20];
	char shidu1[20];


    u8g2Init(&u8g2);
    testDrawProcess(&u8g2);
    while (1)
    { 
        do{
        sec++;
        if(sec==60){
            sec=0;
            mou++;
            if(mou==60){
                mou=0;
                hour++;
                if(hour==24){
                    hour=0;
                }
            }
        }



					wendu=(int) 23;
					shidu=(int) 16;
					sprintf(wendu1,": %02d",wendu);
					sprintf(shidu1,": %02d",shidu);
					sprintf(time1,"%02d:%02d:%02d",hour,mou,sec);
					sprintf(data,"%d-%02d-%02d",year,mon,day);
					u8g2_FirstPage(&u8g2);
					u8g2_ClearBuffer(&u8g2);
								
					u8g2_DrawFrame(&u8g2,1,1,126,62);
					u8g2_SetFont(&u8g2,u8g2_font_ncenB08_tf);
					u8g2_DrawStr(&u8g2,4,11,time1);//字符显示	
					u8g2_SetFont(&u8g2,u8g2_font_open_iconic_email_1x_t);
					u8g2_DrawGlyph(&u8g2,64,12,64);//参考https://github.com/olikraus/u8g2/wiki/fntgrpiconic#open_iconic_weather_8x8 坐标为从左数
					u8g2_SetFont(&u8g2,u8g2_font_open_iconic_play_1x_t);
					u8g2_DrawGlyph(&u8g2,76,12,67);//参考https://github.com/olikraus/u8g2/wiki/fntgrpiconic#open_iconic_weather_8x8 坐标为从左数
					u8g2_SetFont(&u8g2,u8g2_font_open_iconic_other_1x_t);
					u8g2_DrawGlyph(&u8g2,115,12,70);//参考https://github.com/olikraus/u8g2/wiki/fntgrpiconic#open_iconic_weather_8x8 坐标为从左数
					
					
					
					
					u8g2_SetFont(&u8g2,u8g2_font_ncenB14_tf);
					u8g2_SetFont(&u8g2,STSONG);
					u8g2_DrawUTF8(&u8g2,5,59,"温度 ");
					u8g2_SetFont(&u8g2,STSONG);
					u8g2_DrawUTF8(&u8g2,66,59,"湿度 ");
					u8g2_SetFont(&u8g2,u8g2_font_ncenB10_tf);
					u8g2_DrawStr(&u8g2,40,60,wendu1);//字符显示	
					u8g2_SetFont(&u8g2,u8g2_font_ncenB10_tf);
					u8g2_DrawStr(&u8g2,101,60,shidu1);//字符显示	
					u8g2_SendBuffer(&u8g2);
                    vTaskDelay(1000 / portTICK_PERIOD_MS);
			}while(u8g2_NextPage(&u8g2));
        }
    
}

void app_main(void)
{
    ssd1306_init();
    
}

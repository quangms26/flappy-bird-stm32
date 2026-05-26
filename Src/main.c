#include "main.h"

#include "game.h"


ucg_t ucg;



void GPIO_Config(void);

void LCD_Config(void);



int main(void)
{

    delay_init();

    GPIO_Config();

    LCD_Config();

    Game_Init();


    while(1)
    {
        Game_Update();
    }
}

// GPIO CONFIG

void GPIO_Config(void)
{

    GPIO_InitTypeDef GPIO_InitStruct;

    // CLOCK

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,
                           ENABLE);

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,
                           ENABLE);

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,
                           ENABLE);

    // LED PA5

    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5;

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;

    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;

    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;

    GPIO_Init(GPIOA,
              &GPIO_InitStruct);

    // BUZZER PB0


    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;

    GPIO_Init(GPIOB,
              &GPIO_InitStruct);


    // BUTTON PC0 PC1

    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0 |
                               GPIO_Pin_1;

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;

    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;

    GPIO_Init(GPIOC,
              &GPIO_InitStruct);
}


// LCD CONFIG

void LCD_Config(void)
{

    ucg_Init(&ucg,
             ucg_dev_st7735_18x128x160_hw_spi,
             ucg_ext_st7735_18,
             ucg_com_hw_spi);

    ucg_SetRotate90(&ucg);

    ucg_ClearScreen(&ucg);
}

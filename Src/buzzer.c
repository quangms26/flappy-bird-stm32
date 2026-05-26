#include "main.h"

#include "buzzer.h"

void Buzzer_Beep(void)
{
    GPIO_SetBits(GPIOB,
                 GPIO_Pin_0);

    delay_ms(20);

    GPIO_ResetBits(GPIOB,
                   GPIO_Pin_0);
}

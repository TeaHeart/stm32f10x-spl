#include "fix.h"
#include "stm32f10x.h"

void delay_us(uint32_t duration) {
    SysTick->LOAD = 72 * duration;              // 设置定时器重装值
    SysTick->VAL = 0x00000000;                  // 清空当前计数值
    SysTick->CTRL = 0x00000005;                 // 设置时钟源为HCLK, 启动定时器
    while ((SysTick->CTRL & 0x00010000) == 0);  // 等待计数到0
    SysTick->CTRL = 0x00000004;                 // 关闭定时器
}

void delay_ms(uint32_t duration) {
    while (duration-- != 0) {
        delay_us(1000);
    }
}

int main() {
    SetSysClock();
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    GPIO_InitTypeDef GPIOInitStruct = {
            .GPIO_Pin = GPIO_Pin_13,
            .GPIO_Speed = GPIO_Speed_50MHz,
            .GPIO_Mode = GPIO_Mode_Out_PP
    };
    GPIO_Init(GPIOC, &GPIOInitStruct);
    while (1) {
        GPIO_SetBits(GPIOC, GPIO_Pin_13);
        delay_ms(1000);
        GPIO_ResetBits(GPIOC, GPIO_Pin_13);
        delay_ms(1000);
    }
}

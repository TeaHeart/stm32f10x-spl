# stm32f10x-spl

用于学习 STM32F10x, 修改自 [STM32F10x standard peripheral library](https://www.st.com/en/embedded-software/stsw-stm32054.html)

## 已知问题

1. 时钟频率不对
    - 使用 `fix.h` 中的 `void SetSysClock(void)`

# stm32f4-from-scratch

## related registers record
```
// RCC Register Base: 0x40023800
// AHB1 CLK ENABLE OFFSET: 0x30
// GPIOD CLK ENABLE: bit 3 (rw)

// GPIOD BASE 0x40020C00

// GPIO MODE OFFSET: 0x00
// GPIO12 ~ GPIO15: bit 24 ~ bit 31 (rw 01: output mode)

// GPIO ODR OFFSET: 0x14
// GPIO12 ~ GPIO15: bit 12 ~ bit 15 (rw)
```

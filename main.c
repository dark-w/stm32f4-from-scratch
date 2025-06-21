// RCC Register Base: 0x40023800
// AHB1 CLK ENABLE OFFSET: 0x30
// GPIOD CLK ENABLE: bit 3 (rw)

// GPIOD BASE 0x40020C00

// GPIO MODE OFFSET: 0x00
// GPIO12 ~ GPIO15: bit 24 ~ bit 31 (rw 01: output mode)

// GPIO ODR OFFSET: 0x14
// GPIO12 ~ GPIO15: bit 12 ~ bit 15 (rw)
#define RCC_AHB_1_CLK_ENABLE    (unsigned long *)0x40023830
#define GPIO_D_MODE             (unsigned long *)0x40020C00
#define GPIO_D_OUTPUT           (unsigned long *)0x40020C14

#define GPIO_PORT_D 3
#define GPIO_PIN_LED_GREEN      12
#define GPIO_PIN_LED_ORANGE     13
#define GPIO_PIN_LED_RED        14
#define GPIO_PIN_LED_BLUE       15

#define GPIO_MODE_OUTPUT_PUSH_PULL 0x01

int main()
{
    *RCC_AHB_1_CLK_ENABLE |= (1 << GPIO_PORT_D);
    *GPIO_D_MODE |= (GPIO_MODE_OUTPUT_PUSH_PULL << GPIO_PIN_LED_GREEN * 2);
    *GPIO_D_MODE |= (GPIO_MODE_OUTPUT_PUSH_PULL << GPIO_PIN_LED_ORANGE * 2);
    *GPIO_D_MODE |= (GPIO_MODE_OUTPUT_PUSH_PULL << GPIO_PIN_LED_RED * 2);
    *GPIO_D_MODE |= (GPIO_MODE_OUTPUT_PUSH_PULL << GPIO_PIN_LED_BLUE * 2);
    *GPIO_D_OUTPUT |= (1 << GPIO_PIN_LED_GREEN) | (1 << GPIO_PIN_LED_ORANGE)
        | (1 << GPIO_PIN_LED_RED) | (1 << GPIO_PIN_LED_BLUE);

    while (1) {}
    return 0;
}

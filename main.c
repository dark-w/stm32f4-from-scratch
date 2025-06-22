#define RCC_AHB_1_CLK_ENABLE    (unsigned long *)0x40023830
#define GPIO_D_MODE             (unsigned long *)0x40020C00
#define GPIO_D_OUTPUT           (unsigned long *)0x40020C14

#define GPIO_PORT_D 3
#define GPIO_PIN_LED_GREEN      12
#define GPIO_PIN_LED_ORANGE     13
#define GPIO_PIN_LED_RED        14
#define GPIO_PIN_LED_BLUE       15

#define GPIO_MODE_OUTPUT_PUSH_PULL 0x01

int bss_integer;
int data_integer = 0x12345678;
const int rodata_interget = 0xDEADBEEF;

int main()
{
    *RCC_AHB_1_CLK_ENABLE |= (1 << GPIO_PORT_D);
    
    *GPIO_D_MODE |= (GPIO_MODE_OUTPUT_PUSH_PULL << GPIO_PIN_LED_GREEN * 2);
    *GPIO_D_MODE |= (GPIO_MODE_OUTPUT_PUSH_PULL << GPIO_PIN_LED_ORANGE * 2);
    *GPIO_D_MODE |= (GPIO_MODE_OUTPUT_PUSH_PULL << GPIO_PIN_LED_RED * 2);
    *GPIO_D_MODE |= (GPIO_MODE_OUTPUT_PUSH_PULL << GPIO_PIN_LED_BLUE * 2);

    *GPIO_D_OUTPUT |= 1 << GPIO_PIN_LED_RED;
    
    bss_integer = 0x23456789;
    if (bss_integer == 0x23456789)
        *GPIO_D_OUTPUT |= 1 << GPIO_PIN_LED_GREEN;
    
    if (data_integer == 0x12345678)
        *GPIO_D_OUTPUT |= 1 << GPIO_PIN_LED_ORANGE;
    
    if (rodata_interget == 0xDEADBEEF)
        *GPIO_D_OUTPUT |= 1 << GPIO_PIN_LED_BLUE;

    while (1) {}
    return 0;
}

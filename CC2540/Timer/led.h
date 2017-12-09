#ifndef __LED_H__
#define __LED_H__
#include <ioCC2540.h>

#define LED1    P1_0
#define LED2    P1_1
#define LED3    P1_4
#define led1_on()       LED1 = 1;
#define led2_on()       LED2 = 1;
#define led3_on()       LED3 = 1;
#define led1_off()      LED1 = 0;
#define led2_off()      LED2 = 0;
#define led3_off()      LED3 = 0;
#define ledall_off()    led1_off();led2_off();led3_off()
extern void led_init(void);
extern void Delay(unsigned int time);
#endif
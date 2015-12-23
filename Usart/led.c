#include "led.h"

void led_init(void)
{
  P1SEL&=~((1<<0)|(1<<1)|(1<<4));
  P1DIR|=(1<<0)|(1<<1)|(1<<4);
  led1_off();
  led2_off();
  led3_off();

}
void Delay(unsigned int time)
{
  unsigned int i;
  while(time--)
  {
    for(i=0;i<10000;i++);
  }
}
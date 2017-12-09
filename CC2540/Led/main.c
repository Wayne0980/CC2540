#include "led.h"
void leddirtect(int dir)
{
  if(dir%2==0)
  {
    ledall_off();
    return;
  }
  switch(dir)
  {
    case 1:
      led1_on();
     break;
    case 3:
      led2_on();
      break;
    case 5:
      led3_on();
      break;
  }
}

void main(void)
{
  int index = 0;
  led_init();
  while(1)
  {
    leddirtect(index);
    Delay(10);
    index++;
    if(index>6)
      index = 0;
  }
}
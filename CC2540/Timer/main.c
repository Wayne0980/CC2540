#include "led.h"
#include "Timer.h"


unsigned long count = 0;
unsigned int index = 0;
#pragma vector=T1_VECTOR
__interrupt void T1_ISR(void)
{
    count++;
  if(count>1)
  {
    count = 0;
    index++;
    if(index>6)
      index = 0;
  }
}

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
  int oldindex = 0;
  led_init();
  Timer1_Init();
  while(1)
  {  
    if(oldindex!=index){
      leddirtect(index);
      oldindex = index;
    }
  }
}
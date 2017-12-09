#include "led.h"
#include "Timer.h"
#include "Uart.h"
#define BIT(n)  (1<<(n))
unsigned long count = 0;
unsigned int index = 0;
void leddirtect(unsigned int dir);

#pragma vector=T1_VECTOR
__interrupt void T1_ISR(void)
{
  // TODO:: Timer 1 interrupt
}
#pragma vector=URX0_VECTOR
__interrupt void URX0_ISR(void)
{
  index = U0DBUF;
  URX0IF = 0;
}
void leddirtect(unsigned int dir)
{
 
  ledall_off();
  switch(dir)
  {
    case 1:
      led1_on();
      Printf("Led1 On",7);
     break;
    case 2:
      led2_on();
      Printf("Led2 On",7);
      break;
    case 3:
      led3_on();
      Printf("Led3 On",7);
      break;
  default:
      led1_on();
      led2_on();
      led3_on();  
      Printf("All Led On",10);
      break;
  }
}
void InitClockControl(void)
{
  CLKCONCMD &= ~(BIT(6)); // ³]¬°32MHz
  while(!(SLEEPSTA & (BIT(6)))); 
  CLKCONCMD &= ~(BIT(5)|BIT(4)|BIT(3)|BIT(2)|BIT(1)|BIT(0));      
}
void main(void)
{
  led_init();
  //Timer1_Init();
  InitClockControl();
  Uart_Init();
  while(1)
  {  
    if(index){
      leddirtect(index);
      index = 0;
    }
  }
}
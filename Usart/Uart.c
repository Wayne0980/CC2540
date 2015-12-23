#include "Uart.h"
#define BIT(n)  (1<<(n))
void Uart_Init(void)
{
  PERCFG=0;
  P0SEL |=BIT(5)|BIT(4)|BIT(3)|BIT(2);
  P2DIR &=~(BIT(7)|BIT(6)); // Usart0
  
  U0CSR|=BIT(7);
  U0CSR|=BIT(6);
  
  U0GCR=9;
  U0BAUD=59;
  UTX0IF=0;
  
  
  URX0IE = 1;
  EA = 1;
}
void Printf(char *p,int len)
{
  unsigned int i;
  for(i=0;i<len;i++)
  {
    U0DBUF=*p++;
    while(!UTX0IF);
    UTX0IF=0;
  }
  U0DBUF=0x0a;
  while(!UTX0IF);
  UTX0IF=0;
}
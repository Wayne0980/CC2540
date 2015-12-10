#include "Timer.h"
void Timer1_Init(void)
{
  T1CTL&=~(0x0f);
  T1CTL|=(1<<0)/*自動重裝*/|(1<<2)/*32分頻*/;
  IEN1 |= 1<<1;
  IEN0 |= 1<<7;
}

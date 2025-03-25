// Задача 03-1: НОД четырех
// На вход программе подаются 4 натуральных числа не
// превосходящих 109. Требуется найти их наибольший общий делитель.

#include <stdio.h>

int nod(int a, int b)
{
  if (a == b || b == 0)
  {
    return a;
  }
  else
  {
    if (a > b)
    {
      return nod(b, a % b);
    }
    else
    {
      return nod(a, b % a);
    }
  }
}

int main(void)
{
  int value1, value2, value3, value4;
  scanf("%d%d%d%d", &value1, &value2, &value3, &value4);

  int nod12 = nod(value1, value2);
  int nod34 = nod(value3, value4);

  int answer = nod(nod12, nod34);

  printf("%d", answer);

  return 0;
}
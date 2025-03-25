// Задача 01-9: Подсчет битов
// На вход программе подается беззнаковое 32-битное целое число N.
// Требуется найти количество единичных битов в двоичном представлении данного числа.

#include <stdio.h>
int main(void)
{
  unsigned int n;
  unsigned int mask = 1;
  int count = 0;

  scanf("%u", &n);

  for (int i = 0; i <= 32; i++)
  {
    if ((mask & n) != 0)
      count++;
    mask = mask << 1;
  }
  printf("%d", count);
  return 0;
}

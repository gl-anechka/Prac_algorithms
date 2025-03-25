// Задача 03-6: Рекуррентная последовательность

#include <stdio.h>

int func(int i)
{
  if (i % 2 && i > 3)
  {
    return 2 * func(i + 3);
  }
  else if (i % 2 == 0 && i > 3)
  {
    return 3 + func(i / 2);
  }
  return i;
}

int main(void)
{
  int n;
  scanf("%d", &n);
  printf("%d", func(n));
  return 0;
}
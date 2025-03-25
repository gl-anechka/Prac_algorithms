// Задача 01-1: Разность максимума и минимума
// На стандартном потоке ввода задаётся натуральное число N (N > 0),
// после которого следует последовательность из N целых чисел.
// На стандартный поток вывода напечатайте разность между наибольшим и
// наименьшим элементами последовательности.

#include <stdio.h>

int main(void)
{
  int n, value, min, max, value1, value2;

  scanf("%d", &n);
  if (n >= 2)
  {
    scanf("%d%d", &value1, &value2);
    max = (value1 > value2) ? value1 : value2;
    min = (value1 < value2) ? value1 : value2;
    for (int i = 2; i < n; i++)
    {
      scanf("%d", &value);
      if (value > max) max = value;
      if (value < min) min = value;
    }
  }
  else
  {
    scanf("%d", &min);
    max = min;
  }

  printf("%d\n", max-min);
  return 0;
}
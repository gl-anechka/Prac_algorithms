// Задача 01-2: Число вхождений максимума
// На стандартном потоке ввода задаётся натуральное число N (N > 0),
// после которого следует последовательность из N целых чисел.
// На стандартный поток вывода напечатайте,
// сколько раз в этой последовательности встречается максимум.

#include <stdio.h>

int main(void)
{
  int n, value, max, count;

  scanf("%d", &n);
  scanf("%d", &max);
  count = 1;
  for (int i = 1; i < n; i++)
  {
    scanf("%d", &value);
    if (value == max)
    {
      max = value;
      count += 1;
    }
    else if (value > max)
    {
      max = value;
      count = 1;
    }
  }

  printf("%d\n", count);
  return 0;
}

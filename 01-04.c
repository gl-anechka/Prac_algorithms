// Задача 01-4: Длина максимальной возрастающей подпоследовательности
// На стандартном потоке ввода задаётся натуральное число N (N > 0),
// после которого следует последовательность из N целых чисел.
// На стандартный поток вывода напечатайте длину максимальной (по длине)
// возрастающей непрерывной подпоследовательности входной последовательности.

#include <stdio.h>

int main(void)
{
  int n, value, saved, count, maxcount;

  scanf("%d", &n);
  scanf("%d", &saved);
  count = 1;
  maxcount = 1;
  for (int i = 1; i < n; i++)
  {
    scanf("%d", &value);
    if (value > saved)
    {
      saved = value;
      count += 1;
    }
    else
    {
      saved = value;
      if (count > maxcount) maxcount = count;
      count = 1;
    }
  }

  if (count > maxcount) maxcount = count;
  printf("%d\n", maxcount);
  return 0;
}
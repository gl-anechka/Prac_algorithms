// Задача 01-8: Поиск последовательности бит
// На вход программе подается беззнаковое 32-битное целое число N и натуральное число K (1 ≤ K ≤ 31).
// Требуется взять K подряд идущих битов числа N так, чтобы полученное число было максимальным.
// Программа должна вывести полученное число.

#include <stdio.h>
int main(void)
{
  unsigned int n, k, value;
  unsigned int max = 0;
  unsigned int mask = 0;

  scanf("%u%u", &n, &k);

  // k подряд идущих бит для выборки
  for (unsigned int i = 1; i < k; i++)
  {
    mask = mask | (1 << (k-i));
  }
  mask = mask | 1;

  for (unsigned int i = 0; i <= 32; i++)
  {
    value = (mask & n) >> i;
    if (value > max)
      max = value;
    mask = mask << 1;
  }

  printf("%u", max);
  return 0;
}
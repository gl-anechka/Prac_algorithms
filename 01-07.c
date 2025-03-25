// Задача 01-7: Извлечение последовательности бит
// На вход программе подается беззнаковое 32-битное целое число N и натуральное число K (1 ≤ K ≤ 31).
// Требуется взять K младших битов числа N и вывести полученное таким образом число.

#include <stdio.h>
int main(void)
{
  unsigned int n, k;
  unsigned int mask = 0;
  scanf("%u%u", &n, &k);
  for (unsigned int i = 1; i < k; i++)
  {
    mask = mask | (1 << (k-i));
  }
  mask = mask | 1;
  printf("%u", mask & n);
  return 0;
}
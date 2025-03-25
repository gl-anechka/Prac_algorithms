// Задача 01-6: Поворот
// На вход программе подается беззнаковое 32-битное целое число N
// и натуральное число K (1 ≤ K ≤ 31).
// Требуется циклически сдвинуть биты числа N вправо на K битов и
// вывести полученное таким образом число.

#include <stdio.h>
int main(void)
{
  unsigned int n, k;
  unsigned int lastbit;
  scanf("%u%u", &n, &k);

  for (unsigned int i = 1; i <= k; i++)
  {
    lastbit = n & 1;
    lastbit = lastbit << 31;
    n = n >> 1;
    n = n | lastbit;
  }

  printf("%u", n);
  return 0;
}

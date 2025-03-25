// Задача 03-17: Утраивающаяся последовательность
// Бесконечная последовательность чисел A(1),A(2),... строится следующим образом:
// A(1) = 0
// Пусть построены элементы A(1), ... A(3m). Тогда элементы A(3m+1),...,A(3m+1)
// принимают значения А(3m)+3m, A(3m-1)+3m,...,A(1)+3m,A(1)+2*3m,A(2)+2*3m,...
// A(3m)+2*3m соответственно.
// Напишите программу, которая по заданному N находит A(N).
// Входные данные: число N (1 ≤ N ≤ 1000000000).
// Выходные данные: вывести значение A(N).

#include <stdio.h>
#include <math.h>

unsigned int arr[1000];

unsigned int rec(unsigned int m)
{
  if (m == 1) return 0;
  unsigned int now = (unsigned int) (log(m - 1) / log(3));

  if (m > pow(3, now) && m <= pow(3, now) * 2)
    return rec(m - 2 * (m - pow(3, now)) + 1) + (unsigned int) pow(3, now);
  else
    return rec(m - 2 * pow(3, now)) + 2 * (unsigned int) pow(3, now);
}

int main(void)
{
  unsigned n;
  scanf("%u", &n);

  for (int i = 1; i < 1000; i++)
  {
    printf("%u ", rec(i));
  }
  printf("\n%u", rec(n));
  return 0;
}
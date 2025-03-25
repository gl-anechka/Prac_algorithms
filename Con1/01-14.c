// Задача 01-14: Максимальное произведение
// На стандартном потоке ввода задаётся натуральное число N (N > 1),
// после которого следует последовательность из N целых 32-битных чисел Ai (1 ≤ i ≤ N).
// Требуется найти такие числа Ai, Aj (i ≠ j, 1 ≤ i,j ≤ N), что произведение Ai*Aj
// максимально. На стандартный поток вывода напечатайте эти числа: сначала меньшее,
// потом большее. Если различные пары чисел дают одно и то же максимальное произведение,
// напечатайте ту пару, сумма чисел в которой меньше.
// Указание: использовать массивы запрещается.

#include <stdio.h>

int min(int x, int y)
{
  return (x > y) ? y : x;
}

int max(int x, int y)
{
  return (x > y) ? x : y;
}

int main(void)
{
  int n;
  scanf("%d", &n);
  int min1 = 0, min2 = 0, max1 = 0, max2 = 0, x;

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &x);

    if (i == 0)
    {
      min1 = x;
      max1 = x;
    }
    else if (i == 1)
    {
      max2 = max(max1, x);
      min2 = min(min1, x);

      max1 = min(x, max1);
      min1 = max(x, min1);
    }

    if (x >= max2 && i > 1)
    {
      max1 = max2;
      max2 = x;
    }
    else if (x >= max1 && i > 1)
    {
      max1 = x;
    }

    if (x <= min2 && i > 1)
    {
      min1 = min2;
      min2 = x;
    }
    else if (x <= min1 && i > 1)
    {
      min1 = x;
    }
  }

  if (max1 * max2 > min1 * min2)
  {
    printf("%d %d", max1, max2);
  }
  else
  {
    printf("%d %d", min2, min1);
  }

  return 0;
}

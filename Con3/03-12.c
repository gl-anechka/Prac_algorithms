// Задача 03-12: Жертвоприношение
// Вводится целое число N (1 ≤ N ≤ 14), и следом N целых чисел A1,...,AN
// (0 ≤ Ai ≤ 100). Требуется найти два непустых подмножества таких, что
// сумма их элементов равна и максимальна среди всех возможных решений
// (подмножества не должны пересекаться), и вывести эту сумму или 0, если такой пары нет.

#include <stdio.h>
#include <math.h>

int main(void)
{
  int n, f = 0, s = 0, ans = 0;
  scanf("%d", &n);
  int num[n];

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &num[i]);
  }

  int arr[n];
  for (int i = (int) pow((double)3, (double)n) - 1; i >= 0; i--)
  {
    int now = i;
    for (int j = n - 1; j >= 0; j--)
    {
      arr[j] = now % 3;
      now /= 3;
    }
    f = 0;
    s = 0;
    for (int j = 0; j < n; j++)
    {
      if (arr[j] == 1)
      {
        f += num[j];
      }
      else if (arr[j] == 2)
      {
        s += num[j];
      }
    }
    if (f == s)
    {
      ans = f > ans ? f : ans;
    }
  }
  printf("%d", ans);
  return 0;
}
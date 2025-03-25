// Задача 02-5: Шары
// Дано N шаров. Требуется определить, есть ли среди них
// два шара, которые имеют общую точку.
// На стандартном потоке ввода задаётся натуральное число
// N (0 < N ≤ 100), после которого следуют N строк, описывающие шары.
// В каждой строке записаны координаты центра i-го шара xi yi zi и его
// радиус ri. xi, yi, zi и ri вещественные не превосходящие по модулю
// 1000. ri строго положительно.
// На стандартный поток вывода напечатайте YES, если среди шаров есть два,
// которые имеют общую точку. В противном случае напечатайте NO.

#include <stdio.h>
#include <math.h>

int main(void)
{
  int n, flag = 0;
  double x1, x2, y1, y2, z1, z2, r1, r2, dist;
  double epsilon = 0.0001;
  scanf("%d", &n);
  float data[n][4];  // массив из n массивов,
                     // содержащих по 4 эл-та типа float

  for (int i = 0; i < n; i ++)
  {
    scanf("%f %f %f %f", &data[i][0], &data[i][1],\
    &data[i][2], &data[i][3]);
  }

  for (int i = 0; i < n-1; i++)
    for (int j = i + 1; j < n; j++)
    {
      x1 = (double)data[i][0];
      x2 = (double)data[j][0];
      y1 = (double)data[i][1];
      y2 = (double)data[j][1];
      z1 = (double)data[i][2];
      z2 = (double)data[j][2];

      r1 = (double)data[i][3];
      r2 = (double)data[j][3];

      // расстояние между центрами шаров
      dist = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2));

      if (dist <= r1 + r2 + epsilon)
      {
        flag = 1;
        break;
      }
    }

  if (flag == 1)
    printf("YES");
  else
    printf("NO");
  return 0;
}
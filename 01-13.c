// Задача 01-13: Синус угла
// На стандартном потоке ввода задаётся число с плавающей точкой
// двойной точности X (X ≥ 0, X ≤ 2π) и натуральное число N (N > 0, N ≤ 10).
// На стандартный поток вывода напечатайте значение синуса угла в X радиан,
// вычисленное в виде суммы первых N членов разложения функции синус в ряд Тейлора:
// sin(x) = x - x3/3! + x5/5! - x7/7! + ...
// Для печати используйте форматное преобразование %.6lf

#include <stdio.h>

int main(void)
{
  double x, pow_x, factorial;
  double sin_x = 0.0;
  double light = 1.0;
  int n;
  scanf("%lf%d", &x, &n);
  n = 2 * n - 1;
  for (int i = 1; i <= n; i += 2)
  {
    pow_x = 1.0;
    factorial = 1.0;
    factorial = 1;
    for (int j = 1; j <= i; j++)
    {
      pow_x = pow_x * x;
      factorial = factorial * (double)j;
    }
    sin_x = sin_x + (light * pow_x) / factorial;
    light = light * (-1.0);
  }

  printf("%.6lf", sin_x);
  return 0;
}
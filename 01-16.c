// Задача 01-16: Медианы треугольника
// На вход программе подаются координаты вершин треугольника.
// Требуется найти координаты точки пересечения медиан данного треугольника.
// Ответ выводите с точностью до 4 знаков после запятой.

#include <stdio.h>

int main(void)
{
  double x1, y1, x2, y2, x3, y3;
  double mx, my;  // координата x, координата y

  scanf("%lf%lf", &x1, &y1);
  scanf("%lf%lf", &x2, &y2);
  scanf("%lf%lf", &x3, &y3);

  mx = (x1 + x2 + x3) / 3.0;
  my = (y1 + y2 + y3) / 3.0;

  printf("%.4lf %.4lf", mx, my);
  return 0;
}
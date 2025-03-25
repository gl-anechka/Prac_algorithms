// Задача 02-3: Чередование массивов
// Даны два массива a[] и b[]. Требуется составить массив, в который
// входят поочередно элементы первого и второго массивов, то есть элементы
// a[0], b[0], a[1], b[1] и так далее. Если длина массивов различна, требуется
// вывести в конце оставшуюся часть более длинного массива.
// На стандартном потоке ввода задано целое число N (N ≥ 0) и далее N элементов
// первого массива (если N = 0, массив считается пустым и ни одного элемента не
// задано), далее целое число M (M ≥ 0) и M элементов второго массива. Известно,
// что хотя бы один входной массив непуст.

#include <stdio.h>

int main(void)
{
  // массив a
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i ++)
  {
    scanf("%d", &a[i]);
  }

  // массив b
  int m;
  scanf("%d", &m);
  int b[m];
  for (int i = 0; i < m; i ++)
  {
    scanf("%d", &b[i]);
  }

  int min, i = 0;
  min = (n < m) ? n : m;  // минимальная длина массива

  for (; i < min; i++)
  {
    printf("%d %d ", a[i], b[i]);
  }

  if (n > min)
  {
    for (; i < n; i++)
    {
      printf("%d ", a[i]);
    }
  }
  else if (m > min)
  {
    for (; i < m; i++)
    {
      printf("%d ", b[i]);
    }
  }

  return 0;
}
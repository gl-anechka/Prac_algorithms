// Задача 03-8: Итерированная медиана
// Дан массив целых чисел нечетной длины N. По нему строится массив
// длины N-2 по следующему правилу: первый элемент нового массива равен
// медиане первого, второго и третьего элементов старого, второй элемент
// нового — медиане второго, третьего и четвертого элементов старого, и так
// далее. i-ый элемент нового массива равен медиане i-го, i+1-го и i+2-го.
// Далее по новому массиву строится следующий массив длины N-4 по такому же правилу.
// Затем строится массив длины N-6, и так далее. Процесс продолжается до тех пор,
// пока не получится массив длины 1. Ваша задача определить, чему будет равен
// единственный элемент этого массива. На стандартном потоке ввода задаётся нечетное
// натуральное число N (0 < N ≤ 1000), после которого следуют N целых чисел
// ai — элементы исходного массива (0 ≤ ai ≤ 106). На стандартный поток вывода
// напечатайте единственное число — значение единственного элемента конечного массива.
// Указание: в решении необходимо реализовать функцию, которая находит медиану трех чисел.

#include <stdio.h>

int max(int x, int y)
{
  return (x > y) ? x : y;
}

int min(int x, int y)
{
  return (x < y) ? x : y;
}

int mediana(int a, int b, int c)
{
  int maxim = max(max(a, b), c);
  int minim = min(min(a, b), c);
  return (a + b + c) - maxim - minim;
}

int main(void)
{
  int n;
  scanf("%d", &n);
  int arr[n];

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  while (n > 1)
  {
    for (int i = 0; i < n - 2; i++)
    {
      arr[i] = mediana(arr[i], arr[i+1], arr[i+2]);
    }
    n -= 2;
  }

  printf("%d", arr[0]);
  return 0;
}
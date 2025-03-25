// Задача 02-4: На складе истории
// На складе истории вдоль стены в два ряда стоят стопками кубические
// ящики одинакового размера. В каждом ряду стоят по N стопок.
// В i-ой стопке 1-го ряда стоит ai ящиков, а в i-ой стопке 2-го ряда стоит bi.
// Если посмотреть на ящики с большого расстояния, то некоторые ящики будут полностью
// закрывать другие. Из ящиков, стоящих в i-ых стопках 1-го и 2-го ряда видно только max(ai,bi) ящиков.
// Ваша задача определить, сколько всего ящиков видно, если смотреть на них с большого расстояния.
// На стандартном потоке ввода задаётся натуральное число N (0 < N ≤ 10000), после которого
// следует последовательность ai (0 ≤ ai ≤ 10000) из N целых чисел. Затем следует
// последовательность bi (0 ≤ bi ≤ 10000) из N целых чисел.
// На стандартный поток вывода напечатайте, сколько ящиков будет видно с большого расстояния.

#include <stdio.h>

int main(void)
{
  int n, count = 0;
  scanf("%d", &n);
  int a[n], b[n];

  for (int i = 0; i < n; i ++)
  {
    scanf("%d", &a[i]);
  }

  for (int i = 0; i < n; i ++)
  {
    scanf("%d", &b[i]);
  }

  for (int i = 0; i < n; i++)
  {
    count += ((a[i] > b[i]) ? a[i] : b[i]);
  }

  printf("%d", count);
  return 0;
}
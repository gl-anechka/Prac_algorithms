// Задача 02-7: Проверка на перестановочность
// На вход программе подается натуральное число N и, далее, N целых чисел.
// Все числа не превосходят 10000 по абсолютной величине.
// Программа должна выводить Yes, если данная последовательность задает
// перестановку и No в противном случае.

#include <stdio.h>

int main(void)
{
  int n, count = 0, value, flag = 1;
  scanf("%d", &n);
  int per[n+1];      // перестановки на вход

  for (int i = 0; i < n+1; i++)
  {
    per[i] = 0;
  }

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &value);
    if ((value < 0) || (value > n))
      count++;
    else
    {
      per[value]++;
      if (per[value] > 1)
        flag = 0;
    }
  }

  if ((flag == 1) && (count == 0))
    printf("Yes");
  else
    printf("No");

  return 0;
}
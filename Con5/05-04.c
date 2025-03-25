// Задача 05-4: Кто меньше?
// На вход программе подается последовательность натуральных чисел,
// заканчивающаяся нулем (ноль в последовательность не входит)
// a1, a2, ..., an, 0. Все числа в последовательности не превосходят 10^9.
// Требуется определить, сколько элементов последовательности меньше
// последнего ее элемента.

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int count = 0, size = 1, n;
  int *arr = (int *)malloc(sizeof(int));
  scanf("%d", &n);

  while (n != 0)
  {
    arr[count] = n;
    count++;

    // гарантия, что памяти в 3 раза больше
    if (count >= size)
    {
      size = count * 3;
      arr = realloc(arr, sizeof(int) * size);
    }
    scanf("%d", &n);
  }

  int last = arr[count - 1], cml = 0;

  for (int i = 0; i < count - 1; i++)
  {
    if (arr[i] < last)
    {
      cml++;
    }
  }

  printf("%d", cml);
  free(arr);
  return 0;
}
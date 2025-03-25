// Задача 04-8: Вычеркивание
// Сколько различных трехзначных чисел можно получить из заданного натурального
// N, вычеркивая цифры из его десятичной записи?
// Формат входных данных: единственное натуральное число N, не превосходящее 10100.
// Формат выходных данных: единственное целое число – найденное количество.

#include <stdio.h>
#include <string.h>

int main(void)
{
  char num[1000000];
  scanf("%s", num);

  long long len = strlen(num);
  int id = 0;
  int ans[1000];

  if (len < 3)
  {
    printf("0");
    return 0;
  }

  for (int i = 0; i < len; i++)
  {
    if (num[i] == '0')
    {
      continue;
    }
    for (int j = i + 1; j < len; j++)
    {
      for (int k = j + 1; k < len; k++)
      {
        int new = (num[i] - '0') * 100 + (num[j] - '0') * 10 + (num[k] - '0');
        int flag = 1;
        for (int l = 0; l < id; l++)
        {
          if (new == ans[l])
          {
            flag = 0;
            break;
          }
        }
        if (flag == 1)
        {
          ans[id++] = new;
        }
      }
    }
  }
  printf("%d", id);
  return 0;
}
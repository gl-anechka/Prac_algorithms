// Задача 04-3: Периоды строки
// На вход программе подается строка α длиной (обозначим |α|) не более 104 симоволов,
// состоящая из строчных латинских букв.
// Скажем, что строка α имеет период t, если
//    1 ≤ t ≤ |α|
//    a[i] = a[i - t] для всех t ≤ i < |α|
// Выведите все периоды данной строки в возрастающем порядке.

#include <stdio.h>
#include <string.h>

#define MAXLINE 10000

int main(void)
{
  char st[MAXLINE + 1];
  scanf("%s", st);

  int len = strlen(st);

  for (int t = 1; t < len; t++)
  {
    int flag = 1;
    for (int i = t; i < len; i++)
    {
      if (st[i] != st[i-t])
      {
        flag = 0;
      }
    }

    if (flag == 1)
    {
      printf("%d ", t);
    }
  }

  printf("%d", len);
  return 0;
}
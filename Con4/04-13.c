// Задача 04-13: Периоды большой строки
// На вход программе подается строка α длиной (обозначим |α|)
// не более 106 симоволов, состоящая из строчных латинских букв.
// Скажем, что строка α имеет период t, если
//    1 ≤ t ≤ |α|
//    a[i] = a[i - t] для всех t ≤ i < |α|
// Выведите все периоды данной строки в возрастающем порядке.

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000002

char st[MAXLINE];
int pi[MAXLINE];

void prefix_func(char *pat, int len)
{
  //int len = strlen(pat);
  pi[0] = 0;

  for (int i = 1; i < len; i++)
  {
    int j = pi[i - 1];
    while (j > 0 && pat[j] != pat[i])
    {
      j = pi[j - 1];
    }
    if (pat[j] == pat[i])
    {
      j++;
    }
    pi[i] = j;
  }
}

int main(void)
{
  scanf("%s", st);
  int len = strlen(st);
  prefix_func(st, len);

  int count = pi[len - 1];

  while (count != 0)
  {
    printf("%d ", len - count);
    count = pi[count - 1];
  }
  if (len != 0)
  {
    printf("%d", len);
  }

  return 0;
}
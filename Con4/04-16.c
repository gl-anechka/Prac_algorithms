// Задача 04-16: Маленький циклический сдвиг
// На вход программе подается строка длиной не более 2000000 символов,
// состоящая из 0 и 1, при этом нулей в ней не более 2000. Требуется написать
// программу, которая находит такой циклический сдвиг строки, что его результатом
// будет лексикографически минимальная из всех возможных строка.

#include <stdio.h>
#include <string.h>

#define MAXLINE 2000005

int main(void)
{
  char st[MAXLINE];
  scanf("%s", st);
  int len = strlen(st);

  int ans[len], new[len];
  for (int i = 0; i < len; i++)
  {
    ans[i] = st[i];
  }

  for (int i = 0; i < len; i++)
  {
    if (st[i] == '0')
    {
      for (int j = 0; j < len; j++)
      {
        new[j] = st[(i + j) % len];
      }
      int flag = 0;
      for (int j = 0; j < len; j++)
      {
        if (new[j] < ans[j])
        {
          flag = 1;
          break;
        }
        else if (new[j] > ans[j])
        {
          break;
        }
      }
      if (flag)
      {
        for (int j = 0; j < len; j++)
        {
          ans[j] = new[j];
        }
      }
    }
  }

  for (int i = 0; i < len; i++)
  {
    printf("%c", ans[i]);
  }
  return 0;
}
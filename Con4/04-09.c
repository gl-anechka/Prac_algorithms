// Задача 04-9: Выравнивание абзаца

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000002

int main(void)
{
  int k;
  scanf("%d", &k);
  char s[MAXLINE];
  fgets(s, MAXLINE, stdin);  // пустая строка
  fgets(s, MAXLINE, stdin);

  int i = 0;
  int count = 0;  // кол-во пробелов
  int start = 0;  // начало печати
  int end = k;    // конец печати (max размер строки)

  while (s[i] != '\n' && s[i] != '\0')
  {
    count = 0;
    while (i <= end && s[i] != '\n')
    {
      i++;
    }
    while ((s[i] != ' ' && s[i] != '\n') || (i - start > k))
    {
      i--;
    }

    for (int j = start; j < i; j++)
    {
      if (s[j] == ' ')
      {
        count++;
      }
    }

    if (count != 0)  // не одно слово и надо добавить пробелы
    {
      int whitesp[count];  // пробелы между словами
      int white = k - i + start + count;  // пробелы сейчас

      for (int j = 0; j < count; j++)
      {
        whitesp[j] = white / count;
      }
      white -= white / count * count;  // оставшиеся пробелы

      for (int j = 0; j < white; j++)
      {
        whitesp[j]++;
      }
      count = 0;

      for (int j = start; j < i; j++)
      {
        if (s[j] == ' ')
        {
          for (int jj = 0; jj < whitesp[count]; jj++)
          {
            printf(" ");
          }
          count++;  // (зд.) индексирование массива whitesp
        }
        else
        {
          printf("%c", s[j]);
        }
      }
      printf("\n");

    }
    else  // одно слово, пробелы до конца строки
    {
      for (int j = start; j < i; j++)
      {
        printf("%c", s[j]);
      }

      for (int j = 0; j < k - i + start; j++)
      {
        printf(" ");
      }
      printf("\n");
    }

    i++;
    start = i;
    end = start + k;
  }

  return 0;
}
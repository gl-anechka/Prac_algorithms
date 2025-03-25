// Задача 06-1: Статистика текста
// Во входном файле input.txt записан текст. Текст представляет собой набор
// абзацев (возможно, пустой), разделённых одной или более пустыми строками.
// Пустой считается строка, либо не содержащая символов вовсе, либо состоящая
// лишь из символов пробела. Каждый абзац представляет собой последовательность
// слов, разделённых одним или более символами пробела или переводом строки.
// Слово может содержать в себе заглавные или строчные латинские буквы, а
// также дефисы (символы «минус»). Последнее слово каждой строки может содержать
// переносы. Слова организуются в предложения, разделённые точками.
// Требуется составить статистику для текста, записанного во входном файле:
// число слов в тексте, число предложений в тексте, число абзацев в тексте.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 1 - пустая, 0 - не пустая строка
int isempty(char *s)
{
  int i = 0;
  while (s[i])
  {
    if (s[i] != ' ' && s[i] != '\n')
      return 0;
    i++;
  }
  return 1;
}

int countw(char *s, int f)
{
  int count = 0, i = 0;

  while (s[i])
  {
    if (f && s[i] == ' ')
    {
      f = 0;
    }
    else if (!f && ((s[i] == ' ' && isalpha(s[i-1])) || (s[i] == '-' && !s[i+2]) ||
    (s[i] == '\n' && isalpha(s[i-1])) || s[i] == '.'))
    {
      count++;
    }
    i++;
  }
  return count;
}

int points(char *s)
{
  int i = 0, count = 0;
  while (s[i])
  {
    if (s[i] == '.')
      count++;
    i++;
  }
  return count;
}

int main(void)
{
  FILE *file_in = fopen("input.txt", "r");
  FILE *file_out = fopen("output.txt", "w");

  if (file_in && file_out)
  {
    int w = 0;  // слова в тексте
    int s = 0;  // предложений в тексте
    int p = 0;  // абзацев в тексте

    char st[20005];
    int f = 0;

    while (fgets(st, 20005, file_in))
    {
      if (!isempty(st))
      {
        w += countw(st, f);
        s += points(st);

        if (st[strlen(st)-2] == '-')
          f = 1;
        else
          f = 0;
      }
      else
      {
        if (w != 0)
          p++;
      }
    }

    fprintf(file_out, "%d %d %d", w, (w != 0) ? s : 0, (w != 0) ? (p + 1) : p);
    fclose(file_in);
    fclose(file_out);
  }
  else
  {
    printf("No file\n");
    return 1;
  }

  return 0;
}
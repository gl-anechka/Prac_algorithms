// Задача 04-1: Префиксы и суффиксы
// На стандартном потоке ввода задаются две символьные строки,
// разделённые символом перевода строки. Каждая из строк не превышает
// по длине 104. В строках не встречаются пробельные символы.
// На стандартный поток вывода напечатайте два числа, разделённых пробелом:
// первое число — длина наибольшего префикса первой строки, являющегося суффиксом
// второй; второе число — наоборот, длина наибольшего суффикса первой строки,
// являющегося префиксом второй. Сравнение символов проводите с учётом регистра
// (т.е. символы 'a' и 'A' различны).

#include <stdio.h>
#include <string.h>

#define MAXLINE 10005

int pi[MAXLINE*2];

int prefix(char *pat)
{
  int len = strlen(pat);
  pi[0] = 0;

  for (int i = 1; i < len; i++)
  {
    int j = pi[i-1];
    while (j > 0 && pat[j] != pat[i])
    {
      j = pi[j-1];
    }
    if (pat[j] == pat[i])
    {
      j++;
    }
    pi[i] = j;
  }
  return pi[len-1];
}

int main(void)
{
  char st1[MAXLINE*2];
  char st2[MAXLINE*2];

  scanf("%s", st1);
  scanf("%s", st2);

  char st[MAXLINE*2];
  strcpy(st, st1);

  printf("%d ", prefix(strcat(strcat(st1, "#"), st2)));
  printf("%d", prefix(strcat(strcat(st2, "#"), st)));
  return 0;
}
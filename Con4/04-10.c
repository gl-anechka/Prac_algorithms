// Задача 04-10: Большие префиксы и суффиксы
// На стандартном потоке ввода задаются две символьные строки,
// разделённые символом перевода строки. Каждая из строк не превышает
// по длине 106. В строках не встречаются пробельные символы.
// На стандартный поток вывода напечатайте два числа, разделённых пробелом:
// первое число — длина наибольшего префикса первой строки, являющегося
// суффиксом второй; второе число — наоборот, длина наибольшего суффикса
// первой строки, являющегося префиксом второй. Сравнение символов проводите
// с учётом регистра (т.е. символы 'a' и 'A' различны).

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000002

char s1[MAXLINE*2];
char s2[MAXLINE*2];
char s_copy[MAXLINE*2];
int pi[MAXLINE*2];

int prefix_func(char *pat)
{
  int len = strlen(pat);
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

  return pi[len - 1];
}

int main(void)
{
  scanf("%s", s1);
  scanf("%s", s2);
  strcpy(s_copy, s1);

  printf("%d ", prefix_func(strcat(strcat(s1, "#"), s2)));
  printf("%d", prefix_func(strcat(strcat(s2, "#"), s_copy)));

  return 0;
}
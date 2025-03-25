// Задача 05-7: Сортировка строк
// Даны N строк различной длины, состоящих из символов латинского алфавита.
// Требуется отсортировать их в лексикографическом порядке.
// На стандартном потоке ввода в первой строке задано натуральное число N
// (1 ≤ N ≤ 500000) и в следующих N строках задано N последовательностей
// символов (строк), состоящих из строчных и заглавных латинских букв. Каждая
// строка входных данных ограничена символом перевода строки '\n'. Суммарная
// длина входных строк L удовлетворяет неравенству 1 ≤ L ≤ 9000000.
// На стандартный поток вывода напечатайте данные строки в лексикографическом
// порядке по возрастанию.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void *st1, const void *st2)
{
  char *s1 = *((char**) st1);
  char *s2 = *((char**) st2);

  int i = 0;
  while (s1[i] && s2[i])
  {
    if (s1[i] >= 'a' && s2[i] <= 'Z')
      return -1;
    else if (s2[i] >= 'a' && s1[i] <= 'Z')
      return 1;
    else if (s1[i] < s2[i])
      return -1;
    else if (s2[i] < s1[i])
      return 1;
    i++;
  }

  if (!s1[i] && !s2[i])
    return 0;
  else if (s1[i])
    return 1;
  else
    return -1;
}

int main(void)
{
  int n;
  scanf("%d", &n);

  char **arr = (char**) malloc(sizeof(char*) * n);
  char *st = (char*) calloc(9000000+500000, sizeof(char));
  int border = 0;

  for (int i = 0; i < n; i++)
  {
    scanf("%s", st + border);
    int len = strlen(st + border);

    arr[i] = st + border;
    border += len + 1;
    st[border - 1] = '\0';
  }

  qsort(arr, n, sizeof(char*), comp);

  for (int i = 0 ; i < n; i++)
  {
    printf("%s\n", arr[i]);
  }

  return 0;
}
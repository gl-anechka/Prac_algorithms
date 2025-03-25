// Задача 06-13: Сортировка таблицы

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

static int n;

typedef struct tstr
{
  char* p[20];
} tstr;


// считывает поле
char* getfield(char *st, int left)
{
  int right = left;
  while (st[left] == ' ')
    left++;
  right = left + 1;

  while (st[right] && st[right] != '\n' && st[right] != '"' && st[right] != ';')
  {
    if (isdigit(st[right]) && (st[right + 1] == ' ' || st[right + 1] == ';'))
    {
      right++;
      break;
    }
    right++;
  }
  if (st[right] == '"')
    right++;

  right--;
  char *field = (char*) calloc(right-left + 2, sizeof(char));
  strncpy(field, st+left, right - left + 1);
  return field;
}


// находит очередной разделитель
int findsep(char *s, int i)
{
  while (s[i])
  {
    if (s[i] == ';')
      return i;
    i++;
  }
  return -1;
}


// заносит данные в массив, возвращает кол-во полей
int func(tstr *arr, int i, char *st)
{
  int num_of_f = 0;
  int buf = 0, ii = 0;
  while (st[buf])
  {
    if (buf == -1)
      return num_of_f;
    char *now = getfield(st, (buf == 0) ? 0 : buf + 1);
    arr[i].p[ii] = now;
    num_of_f++;
    ii++;
    buf = findsep(st, buf + 1);
  }
  return num_of_f;
}


// сортировка по n-му столбцу
int comp(const void *CUR, const void *PREV)
{
  const tstr *cur = (tstr*) CUR;
  const tstr *prev = (tstr*) PREV;
  tstr s1 = *cur;
  tstr s2 = *prev;

  if (isdigit(s1.p[n][0]) && isdigit(s2.p[n][0]))
  {
    int a = atoi(s1.p[n]);
    int b = atoi(s2.p[n]);
    return a - b;
  }
  return strcmp(s1.p[n], s2.p[n]);
}


int main(void)
{
  FILE *fin = fopen("input.txt", "r");
  FILE *fout = fopen("output.txt", "w");

  fscanf(fin, "%d", &n);
  char st[2200];
  fgets(st, 2200, fin);  // пустая

  int i = 0;
  fgets(st, 2200, fin);
  tstr *arr = (tstr*) calloc(1, sizeof(tstr)); // массив структур
  int num_of_f = func(arr, i, st);
  i++;

  while (fgets(st, 2200, fin))
  {
    arr = (tstr*) realloc(arr, (unsigned) (i + 1) * sizeof(tstr));
    func(arr, i, st);
    i++;
  }

  qsort(arr, (unsigned) i, sizeof(tstr), comp);

  for (int j = 0; j < i; j++)
  {
    for (int k = 0; k < num_of_f; k++)
    {
      if (k == num_of_f - 1)
        fprintf(fout, "%s", arr[j].p[k]);
      else
        fprintf(fout, "%s;", arr[j].p[k]);
    }
    fprintf(fout, "\n");
  }

  return 0;
}
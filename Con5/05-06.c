// Задача 05-6: Опять палиндромы
// На вход программе подается число L, за которым следует строка s,
// состоящая из L маленьких латинских букв. Программа должна выводить
// YES если строка s является палиндромом и NO в противном случае.

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int l;
  scanf("%d", &l);
  char *st = (char*) malloc(sizeof(char) * (l+2));
  scanf("%s", st);

  for (int i = 0; i < l; i++)
  {
    if (st[i] != st[l - i - 1])
    {
      printf("NO");
      free(st);
      return 0;
    }
  }

  printf("YES");
  free(st);
  return 0;
}
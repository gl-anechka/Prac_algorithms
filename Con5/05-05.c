// Задача 05-5: Конкатенация строк
// На вход программе подается число L, за которым следуют строки
// s1, s2 и s3. Каждая из них состоит ровно из L маленьких латинских
// букв. Строки разделены одним или несколькими пробелами и/или переводами строк.
// Программа должна выводить строку, полученную конкатенацией строк s3, s1 и s2.
// Гарантируется, что памяти, выделенной программе, хватит для хранения всех трех строк.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int l;

char* stcopy(char *ans, char *in, int point)
{
  for (int i = 0; i < l; i++)
  {
    ans[point + i] = in[i];
  }
  return ans;
}

int main(void)
{
  scanf("%d", &l);

  char st[l+2];
  char *ans = (char*) malloc(sizeof(char) * 3 * l);

  scanf("%s", st);
  stcopy(ans, st, l);

  scanf("%s", st);
  stcopy(ans, st, 2 * l);

  scanf("%s", st);
  stcopy(ans, st, 0);

  ans[3*l] = '\0';
  printf("%s", ans);
  free(ans);

  return 0;
}
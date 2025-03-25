// Задача 06-12: Генерал танковых войск
// Входные данные. Дана строка состоящая из маленьких латинских
// букв и длины не более, чем 2000 символов. Выходные данные. Выведите
// единственное число — количество различных подстрок входной строки.
// Указание. Используйте для решения цифровой поиск (бор).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPH 26

typedef struct trie
{
  int left, right;
  struct trie *next[ALPH];
} trie;


trie* add(trie *head, char *s, int left, int right, int *ans)
{
  if (!head)
  {
    head = (trie*) calloc(1, sizeof(trie));
    head->left = left;
    head->right = right;
    *ans += right - left;
    return head;
  }

  int s_ind = left;
  int t_ind = head->left;
  while (s_ind < right && t_ind < head->right && s[s_ind] == s[t_ind])
  {
    s_ind++;
    t_ind++;
  }

  if (s_ind >= right)
  {
    return head;
  }
  else if (t_ind >= head->right)
  {
    head->next[s[s_ind] - 'a'] = add(head->next[s[s_ind] - 'a'], s, s_ind, right, ans);
  }
  else
  {
    trie *node = (trie*) calloc(1, sizeof(trie));
    node->left = head->left;
    node->right = t_ind;
    head->left = t_ind;
    node->next[s[t_ind] - 'a'] = head;
    node->next[s[s_ind] - 'a'] = add(node->next[s[s_ind] - 'a'], s, s_ind, right, ans);
    return node;
  }
  return head;
}


int main(void)
{
  char st[2005];
  scanf("%s", st);

  int len = strlen(st);
  int ans = 0;
  trie *head = NULL;

  for (int i = 0; i < len; i++)
  {
    head = add(head, st, i, len, &ans);
  }

  printf("%d", ans + 1);
  return 0;
}
// 06-18

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE 26

// суффиксный бор
struct trie
{
  int left, right;
  int left2, right2;
  struct trie *next[LINE];
};

// создаем бор
struct trie* add1(struct trie *node, char *st, int left, int right)
{
  if (node == NULL)
  {
    node = (struct trie*) calloc(1, sizeof(struct trie));
    node->left = left;
    node->right = right;
    return node;
  }

  int st_id = left;
  int node_id = node->left;

  while (st_id < right && node_id < node->right && st[st_id] == st[node_id])
  {
    st_id++;
    node_id++;
  }

  if (st_id >= right)  // ничего не меняется
  {
    return node;
  }
  else if (node_id >= node->right)  // новый суффикс
  {
    node->next[st[st_id] - 'a'] = add1(node->next[st[st_id] - 'a'], st, st_id, right);
  }
  else  // новая вершина
  {
    struct trie *new = (struct trie*) calloc(1, sizeof(struct trie));
    new->left = node->left;
    new->right = node_id;

    node->left = node_id;
    new->next[st[node_id] - 'a'] = node;
    new->next[st[st_id] - 'a'] = add1(new->next[st[st_id] - 'a'], st, st_id, right);
  }
  return node;
}


// добавляем в старый бор новые суффиксы
struct trie* add2(struct trie *node, char *st, char *st2, int left, int right)
{
  if (node == NULL)
  {
    return node;
  }

  int st_id = left;
  int node_id = node->left;

  while (st_id < right && node_id < node->right && st2[st_id] == st2[node_id])
  {
    st_id++;
    node_id++;
  }

  if (st_id - left > node->right2 - node->left2)
  {
    node->left2 = left;
    node->right2 = st_id;
  }

  if (st_id >= right)  // ничего не меняется
  {
    return node;
  }
  else if (node_id >= node->right)  // новый суффикс
  {
    node->next[st[st_id] - 'a'] = add2(node->next[st[st_id] - 'a'], st, st2, st_id, right);
  }
  else  // новая вершина
  {
    return node;
  }
  return node;
}

int counter(struct trie *node)
{
  int count = node->right2 - node->left2;

  for (int i = 0; i < LINE; i++)
  {
    if (node->next[i])
    {
      count += counter(node->next[i]);
    }
  }

  return count;
}

int main(void)
{
  char st1[4001];
  char st2[4001];

  scanf("%s", st1);
  int len1 = strlen(st1);
  scanf("%s", st2);
  int len2 = strlen(st2);

  struct trie *head = NULL;
  for (int i = 0; i < len1; i++)
  {
    head = add1(head, st1, i, len1);
  }

  for (int i = 0; i < len2; i++)
  {
    head = add2(head, st1, st2, i, len2);
  }

  printf("%d", counter(head) + 1);
  return 0;
}
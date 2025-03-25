// Задача 06-4: Деревья поиска

#include <stdio.h>
#include <stdlib.h>

// прошитое двоичное дерево поиска
typedef struct btree
{
  int key;
  int data;
  struct btree *left;
  struct btree *right;
  struct btree *parent;
} btree;


// возвращает указатель на найденную вершину или NULL
btree* find(btree *head, int k)
{
  if (!head || head->key == k)
    return head;
  else if (k < head->key)
    return find(head->left, k);
  else
    return find(head->right, k);
}


// добавление элемента
void add(btree *head, int k, int data, btree *par, btree **ans)
{
  if (!head)
  {
    head = (btree*) malloc(sizeof(btree));
    head->key = k;
    head->data = data;
    head->parent = par;
    head->left = NULL;
    head->right = NULL;
    if (*ans == NULL) *ans = head;
  }
  else if (head->key == k)
  {
    head->data = data;
  }
  else if (k < head->key)
  {
    add(head->left, k, data, head, ans);
  }
  else
  {
    add(head->right, k, data, head, ans);
  }
}


// минимальный элемент (относительно вершины)
btree* tmin(btree *node)
{
  while (node->left)
    node = node->left;
  return node;
}


// следующий после node элемент (во значению)
btree* succ(btree *node)
{
  btree *par;
  if (node->right)
    return tmin(node->right);

  par = node->parent;
  while (par && node == par->right)
  {
    node = par;
    par = par->parent;
  }
  return par;
}


// удаление элемента
void del(btree *head, int k)
{
  btree *node = find(head, k);
  if (!node) return;

  if (!node->left && !node->right) // нет потомков
  {
    free(node);
    btree *par = node->parent;
    if (node->key < par->key)
      par->left = NULL;
    else
      par->right = NULL;
  }
  else if (node->left && !node->right) // есть левый сын
  {
    btree *par = node->parent;
    if (node->key < par->key)
      par->left = node->left;
    else
      par->right = node->left;
  }
  else if (!node->left && node->right) // есть правый сын
  {
    btree *par = node->parent;
    if (node->key < par->key)
      par->left = node->right;
    else
      par->right = node->right;
  }
  else // есть оба сына
  {
    btree *new = succ(node);
    node->key = new->key;
    node->data = new->data;
    free(new);
  }
}


int main(void)
{
  char op;
  scanf("%c", &op);

  int key, data;

  btree *head = NULL;

  while (op != 'F')
  {
    switch (op)
    {
      case 'A':
        scanf("%d %d", &key, &data);
        // добавить/обновить данные по ключу
        add(head, key, data, NULL, &head);
        break;
      case 'D':
        scanf("%d", &key);
        // удалить вершину
        del(head, key);
        break;
      case 'S':
        scanf("%d", &key);
        // напечатать ключ и данные, если успешно найдено
        btree *node = find(head, key);
        if (node) printf("%d %d\n", node->key, node->data);
        break;
      default:
        break;
    }
    scanf("%c", &op);
  }

  return 0;
}
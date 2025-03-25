// Задача 06-6: Удаление
// Во входном файле input.txt записаны две строки, каждая из которых
// содержит последовательность из не более чем 10000 целых чисел.
// Обе последовательности заканчиваются числом -1 (и оно не входит в
// последовательность), остальные числа неотрицательны и не превосходят 109.
// Требуется в файл output.txt вывести без изменения порядка все члены первой
// последовательности, кроме тех которые встречаются во второй последовательности.

#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
  int key;
  struct list *next;
} list;


list* add(list *head, int k)
{
  list *node = (list*)malloc(sizeof(list));
  node->key = k;
  node->next = head;
  return node;
}


list* del_alnodes(list *head, int k)
{
  list *prev = NULL;
  list *oldhead = head;

  while (head)
  {
    if (head->key == k && prev)
    {
      prev->next = head->next;
      list *node = head;
      head = head->next;
      free(node);
    }
    else if (head->key == k && !prev)
    {
      oldhead = head->next;
      free(head);
      head = oldhead;
    }
    else
    {
      prev = head;
      head = head->next;
    }
  }
  return oldhead;
}


// рекурсивная печать списка
void fprintlist(list *head, FILE *file)
{
  if (head->next) fprintlist(head->next, file);
  fprintf(file, "%d ", head->key);
}


void dellist(list *head)
{
  while (head)
  {
    list *node = head;
    head = head->next;
    free(node);
  }
}


int main(void)
{
  FILE *filein = fopen("input.txt", "r");
  FILE *fileout = fopen("output.txt", "w");

  int n;
  fscanf(filein, "%d", &n);
  list *head = NULL;

  // первый список
  while (n != -1)
  {
    head = add(head, n);
    fscanf(filein, "%d", &n);
  }

  // второй список
  fscanf(filein, "%d", &n);
  while (n != -1)
  {
    head = del_alnodes(head, n);
    fscanf(filein, "%d", &n);
  }

  if (head) fprintlist(head, fileout);
  return 0;
}
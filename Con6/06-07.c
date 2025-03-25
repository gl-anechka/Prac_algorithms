// Задача 06-7: Удаление наоборот
// Во входном файле input.txt записаны две строки, каждая из которых
// содержит последовательность из не более чем 10000 целых чисел. Обе
// последовательности заканчиваются числом -1 (и оно не входит в последовательность),
// остальные числа неотрицательны и не превосходят 109. Требуется в файл output.txt
// вывести без изменения порядка все члены второй последовательности, кроме тех
// которые встречаются в первой последовательности.

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


int find(list *head, int k)
{
  while (head)
  {
    if (head->key == k)
      return 1;
    head = head->next;
  }
  return 0;
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
    int f = find(head, n);
    if (!f)
      fprintf(fileout, "%d ", n);
    fscanf(filein, "%d", &n);
  }

  fclose(filein);
  fclose(fileout);

  dellist(head);
  return 0;
}
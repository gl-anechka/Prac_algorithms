// Задача 06-3: Сортировка списка
// Во входном файле input.txt записана последовательность чисел. Числа в последовтельности
// целые, по модулю не превосходящие 109. Их количество не превышает 4000. Требуется
// отсортировать данную последовательность по неубыванию и вывести результат в файл output.txt.
// Указание: при решении данной задачи запрещается использовать массивы. Для хранения
// последовательности используйте однонаправленный или двунаправленный список.

#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
  int key;
  struct list *next;
} list;


list* add(list *head, int value)
{
  list *node = (list*) malloc(sizeof(list));
  node->key = value;
  node->next = head;
  return node;
}


void fprintlist(list *head, FILE *file)
{
  while (head)
  {
    fprintf(file, "%d ", head->key);
    head = head->next;
  }
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


list* find_min(list * head)
{
  list* next = head->next;

  while (next)
  {
    if (next->key < head->key)
      head = next;
    next = next->next;
  }
  return head;
}

void sort(list *head)
{
  while (head)
  {
    struct list *minnode = find_min(head);
    if (minnode != head)
    {
      int tmp = head->key;
      head->key = minnode->key;
      minnode->key = tmp;
    }
    head = head->next;
  }
}


int main(void)
{
  FILE *file_in = fopen("input.txt", "r");
  FILE *file_out = fopen("output.txt", "w");

  if (file_in && file_out)
  {
    list *head = NULL;
    int n;
    while (fscanf(file_in, "%d", &n) == 1)
    {
      head = add(head, n);
    }

    sort(head);

    fprintlist(head, file_out);
    fclose(file_in);
    fclose(file_out);

    dellist(head);
  }
  else
  {
    printf("No file\n");
    return 1;
  }

  return 0;
}
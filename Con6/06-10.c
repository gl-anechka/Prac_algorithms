// Задача 06-10: 2-перемешивание
// Последовательность ai состоит из N членов и задается формулой
//    ai = i
// К данной последовательности M раз применяют следующее преобразование:
// все члены последовательности, начиная с члена равного bj (1-ый парметр преобразования)
// и до члена равного cj (2-йо параметр преобразования) переносятся в начало.
// Их относительный порядок не меняется, так же как и порядок членов стоящих до члена
// равного bj или полсе cj. Гарантируется, что член равный bj встречается в
// последовательности не позже члена равного cj.
// Например, пусть исходная последовательность имела 7 членов и к ней было применено
// описанное преобразование с параметрами 4 и 6. Тогда получится последовательность
// (4, 5, 6, 1, 2, 3, 7). Если к это последовательности применить преобразование с
// параметрами 5 и 2 то получится последовательность (5, 6, 1, 2, 4, 3, 7).
// Требуется определить, какая последовательность получится в результате применения
// к исходной заданно серии преобрзований.
// Во входном файле input.txt записаны натуральные числа N и M, не превосходящие 105.
// За ними следуют M пар чисел - параметры преобразований.
// В выходной файл output.txt выведите полученную последовательность.

#include <stdio.h>
#include <stdlib.h>

struct list
{
  int value;
  struct list *prev;
  struct list *next;
};


void del_list (struct list **head)
{
  struct list* temp = (*head)->next;
  struct list* next = NULL;
  while (temp)
  {
    next = temp->next;
    free(temp);
    temp = next;
  }
  free(*head);
}


int main(void)
{
  FILE *file_in = fopen("input.txt", "r");
  FILE *file_out = fopen("output.txt", "w");

  if (file_in != NULL && file_out != NULL)
  {
    int n, m;
    fscanf(file_in, "%d%d", &n, &m);

    // массив указателей на эл-ты списка
    struct list **list = (struct list**) malloc((sizeof(struct list)) * n);

    struct list *prev = NULL;
    struct list *head = (struct list*) malloc(sizeof(struct list));
    struct list *now = head;

    for (int i = 0; i < n; i++)
    {
      now->value = i;
      now->prev = prev;
      now->next = (struct list*) malloc(sizeof(struct list));
      prev = now;
      list[i] = now;

      if (i < n-1)
      {
        now = now->next;
      }
      else
      {
        free(now->next);
        now->next = head;
        head->prev = now;
      }
    }

    struct list *node = now;

    int left, right;
    for (int i = 0; i < m; i++)
    {
      fscanf(file_in, "%d %d", &left, &right);
      right--;
      left--;

      if (right == node->value)  // кусок из конца списка перемещаем в начало
      {
        head = list[left];
        node = list[left]->prev;
      }
      else if (head->value != left)  // нетривиальное перемещение
      {
        // перевязываем указатели вне куска
        list[left]->prev->next = list[right]->next;
        list[right]->next->prev = list[left]->prev;

        // перевязываем указатели куска
        list[left]->prev = head->prev;
        head->prev->next = list[left];
        list[right]->next = head;
        head->prev = list[right];

        // новая голова списка
        head = list[left];
      }
    }

    for (int i = 0; i < n; i++)
    {
      fprintf(file_out, "%d ", head->value + 1);
      head = head->next;
      free(head->prev);
    }
    free(list);

    fclose(file_in);
    fclose(file_out);
  }
  else
  {
    printf("No file in directory\n");
    return 1;
  }

  return 0;
}
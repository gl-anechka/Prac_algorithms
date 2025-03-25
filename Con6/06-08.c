// Задача 06-8: Слова
// Во входном файле words.in вводится текст, состоящий из больших
// и маленьких латинских букв, а также символа пробела. Текст
// заканчивается точкой и имеет длину не более 106символов.
// Словом считается любая последовательность подряд идущих латинских
// букв (любого регистра). Требуется из каждого слова нечетной длины удалить
// центральный символ и вывести полученный тескт в файл words.out.
// Слова нужно разделять одним пробелом, в конце тескта вывести точку.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct word
{
  char letter;
  struct word *next;
};

struct list
{
  int len;
  struct word *arl;
  struct list *next;
};

void del_word (struct word **head)
{
  struct word* prev = NULL;
  while ((*head)->next)
  {
    prev = (*head);
    (*head) = (*head)->next;
    free(prev);
  }
  free(*head);
}


void del_list (struct list **head)
{
  struct list* prev = NULL;
  while ((*head)->next)
  {
    del_word(&((*head)->arl));

    prev = (*head);
    (*head) = (*head)->next;
    free(prev);
  }
  free(*head);
}

void pr_word (FILE *file, struct word **wd, int len)
{
  if ((*wd)->next != NULL)
  {
    pr_word(file, &((*wd)->next), len - 1);
  }
  if (len != 0)
  {
    fprintf(file, "%c", (*wd)->letter);
  }
}

void pr_sen (FILE *file, struct list **sp, int flag)
{
  if ((*sp)->next != NULL)
  {
    pr_sen(file, &((*sp)->next), (*sp)->len != 1 || flag);
  }

  if ((*sp)->len % 2 == 0)
  {
    pr_word(file, &((*sp)->arl), -1);

    if (flag)
    {
      fprintf(file, "%c", ' ');
    }
  }
  else if ((*sp)->len != 1)
  {
    pr_word(file, &((*sp)->arl), (*sp)->len / 2);

    if (flag)
    {
      fprintf(file, "%c", ' ');
    }
  }
}

int main (void)
{
  FILE *file_in = fopen("words.in", "r");
  FILE *file_out = fopen("words.out", "w");

  if (file_in != NULL && file_out != NULL)
  {
    struct list *sp = NULL;

    int flag = 1;
    char elem;

    while (flag != 0)
    {
      struct list *node = (struct list*) malloc(sizeof(struct list));
      node->len = 0;

      fscanf(file_in, "%c", &elem);
      node->arl = NULL;

      while (elem != ' ' && elem != '.')
      {
        struct word *word = (struct word*) malloc(sizeof(struct word));
        word->letter = elem;
        (node->len)++;
        word->next = node->arl;
        node->arl = word;

        fscanf(file_in, "%c", &elem);
      }
      node->next = sp;
      sp = node;

      if (elem == '.')
      {
        flag = 0;
      }
    }

    pr_sen(file_out, &sp, 0);
    fprintf(file_out, "%c", '.');

    del_list(&sp);

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
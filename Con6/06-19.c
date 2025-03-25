// 06-19

#include <stdio.h>
#include <stdlib.h>

#define unsch unsigned char
#define LINE 128

struct tree
{
  unsch letter;
  struct tree *left;   // поддерево с 0
  struct tree *right;  // поддерево с 1
};

// печать расшифрованного сообщения
void print_code(FILE *file, FILE *filew, struct tree *head)
{
  unsch value;
  struct tree *node = head;

  while (fread(&value, 1, 1, file))
  {
    for (unsch i = 0; i < 8; i++)
    {
      if (value % 2 == 0)
      {
        if (node->left == NULL)
        {
          break;
        }
      }
      else if (value % 2 == 1)
      {
        if (node->right == NULL)
        {
          break;
        }
      }

      if (value % 2 == 0)
      {
        node = node->left;
      }
      else
      {
        node = node->right;
      }
      value /= 2;

      if (node->left == NULL && node->right == NULL)
      {
        if (node->letter == 0)
        {
          break;
        }
        fwrite(&node->letter, 1, 1, filew);
        node = head;
      }
    }
  }
}


int main(void)
{
  FILE *file_in = fopen("crypto.01", "rb");
  FILE *file_out = fopen("text", "wb");

  if (file_in != NULL && file_out != NULL)
  {
    unsch k;
    fread(&k, 1, 1, file_in);

    struct tree *bin_tree = (struct tree*) calloc(1, sizeof(struct tree));

    // закодированные эл-ты
    //for (unsch i = 0; i < k; i++)
    for (int i = 0; i < (k == 0 ? 256 : k); i++)
    {
      unsch letter, len, code;
      fread(&letter, 1, 1, file_in);
      fread(&len, 1, 1, file_in);

      unsch code_sp[LINE];
      unsch id = 0;

      // записываем в массив биты числа
      unsch bytes = (len + 7) / 8;  // кол-во байтов для считывания
      for (unsch j = 0; j < bytes; j++)
      {
        fread(&code, 1, 1, file_in);
        //code = 0;

        //while (code > 0)
        for (unsch r = 0; id < len && r < 8; r++)
        {
          code_sp[id] = code % 2;
          code /= 2;
          id++;
        }
      }

      // подвешиваем новую вершину
      struct tree *node = bin_tree;
      for (unsch ii = 0; ii < len; ii++)
      {
        // новое поддерево
        if (code_sp[ii] == 0)
        {
          if (node->left == NULL)
          {
            node->left = (struct tree*) calloc(1, sizeof(struct tree));
          }
          node = node->left;
        }
        else
        {
          if (node->right == NULL)
          {
            node->right = (struct tree*) calloc(1, sizeof(struct tree));
          }
          node = node->right;
        }
      }
      node->letter = letter;
    }

    // расшифрованное сообщение
    print_code(file_in, file_out, bin_tree);

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
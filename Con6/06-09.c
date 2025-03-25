// Задача 06-9: Тайна пирамид
// Египетские археологи обнаружили в одной из гробниц носитель информации,
// предположительно, инопланетного происхождения. Изучение находящихся
// на нем файлов может пролить свет на историю Древнего Египта. Требуется
// прочитать последовательность 32-битных целых знаковых чисел, хранящихся
// в бинарном файле input.bin в формате little endian, и вывести в бинарный
// файл output.bin в таком же формате ответ на вопрос, является ли эта последовательность
// пирамидой, и если да, то неубывающей или невозрастающей. В случае неубывающей
// пирамиды нужно вывести 1, в случае невозрастающей (не являющейся при этом неубывающей) -
// -1, а если последовательность чисел не является пирамидой - 0.

#include <stdio.h>
#include <stdlib.h>

int pyramid[1024*1024+1];

int main(void)
{
  FILE *file_in = fopen("input.bin", "rb");
  FILE *file_out = fopen("output.bin", "wb");

  if (file_in != NULL && file_out != NULL)
  {
    int x, count = 0;
    while (fread(&x, sizeof(int), 1, file_in) == 1)
    {
      pyramid[count] = x;
      count++;
    }

    // неубывающая
    int flag = 1, i = 0, answer = 1;
    while (i * 2 + 2 < count)
    {
      flag = flag & (pyramid[i] <= pyramid[2*i+1] && pyramid[i] <= pyramid[2*i+2]);
      i++;
    }
    if (flag)
    {
      fwrite(&answer, sizeof(int), 1, file_out);
      goto end;
    }

    // невозрастающая
    flag = 1;
    i = 0;
    answer = -1;
    while (i * 2 + 2 < count)
    {
      flag = flag & (pyramid[i] >= pyramid[2*i+1] && pyramid[i] >= pyramid[2*i+2]);
      i++;
    }
    if (flag)
    {
      fwrite(&answer, sizeof(int), 1, file_out);
      goto end;
    }

    // последовательность
    answer = 0;
    fwrite(&answer, sizeof(int), 1, file_out);
  }
  else
  {
    printf("No file in directory\n");
    return 1;
  }

  end:
  fclose(file_in);
  fclose(file_out);

  return 0;
}
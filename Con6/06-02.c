// Задача 06-2: 1-перемешивание
// Последовательность ai состоит из N членов и задается формулой ai = i .
// К данной последовательности M раз применяют следующее преобразование:
// все члены последовательности, начиная с члена равного bj (парметр преобразования)
// и до последнего переносятся в начало (относительный порядок не меняется).
// Во входном файле input.txt записаны натуральные числа N и M, не превосходящие 10^5.
// За ними следуют M чисел - параметры преобразований.
// В выходной файл output.txt выведите полученную последовательность.

#include <stdio.h>

int main(void)
{
  FILE *file_in = fopen("input.txt", "r");
  FILE *file_out = fopen("output.txt", "w");

  if (file_in && file_out)
  {
    int n, m, par = 0;
    fscanf(file_in, "%d %d", &n, &m);

    for (int i = 0; i < m; i++)
    {
      fscanf(file_in, "%d", &par);
    }

    for (int i = 0; i < n; i++, par++)
    {
      fprintf(file_out, "%d ", (par % n > 0) ? (par % n) : par);
    }

    fclose(file_in);
    fclose(file_out);
  }
  else
  {
    printf("No file\n");
    return 1;
  }
  return 0;
}
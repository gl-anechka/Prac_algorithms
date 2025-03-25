// Задача 06-14: Наизнанку
// На вход подаётся бинарный файл в следующем формате:
// первые два байта являются целым числом, которое не превышает
// 2000 и задаёт размер квадратной матрицы, затем следуют целочисленные
// 32х битные элементы матрицы. Все числа находятся в представлении big-endian.
// Требуется отыскать след матрицы и вывести его в бинарный файл в
// виде 64х битного целого числа в формате big-endian.

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main(void)
{
  FILE *file_in = fopen("matrix.in", "rb");
  FILE *file_out = fopen("trace.out", "wb");

  if (file_in != NULL && file_out != NULL)
  {
    int n_big = 0, n_small = 0;
    fread(&n_big, 1, 1, file_in);
    fread(&n_small, 1, 1, file_in);
    int n = n_big << 8 | n_small;

    int elem;
    unsigned char elem_bits[4];
    long long tr = 0;

    for (int i = 0; i < n*n; i++)
    {
      fread(elem_bits, 1, 4, file_in);
      elem = ((int) elem_bits[0] << 24 | (int) elem_bits[1] << 16 |
              (int) elem_bits[2] << 8 | (int) elem_bits[3]);

      if (i / n == i % n)
      {
        tr += elem;
      }
    }

    int bits;
    for (int i = 0 ; i < 8; i++)
    {
      bits = tr >> 56;
      tr = tr << 8;
      fwrite(&bits, 1, 1, file_out);
      printf("%d", bits);
    }

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
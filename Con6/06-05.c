// Задача 06-5: Простой калькулятор
// Во входном файле input.txt задано арифметическое выражение,
// составленное из знаков плюс, минус и натуральных чисел, каждое
// из которых не превышает 109. Элементы выражения разделяются нулём
// или более пробелами. Другие символы во входном файле не встречаются.
// Все числа, вне зависимости от наличия ведущих нулей, должны восприниматься
// как десятичные.
// В выходной файл output.txt необходимо вывести результат вычисления выражения.
// Гарантируется, что для вычисления результата и всех промежуточных вычислений
// достаточно типа long long int.
// Количество чисел во входном файле не превышает 100000.

#include <stdio.h>

int main(void)
{
  FILE *file_in = fopen("input.txt", "r");
  FILE *file_out = fopen("output.txt", "w");

  long long int answer;
  long long int value;
  char op;

  if (file_in == NULL)
  {
    printf("Cannot open file %s\n", "input.txt");
    return 1;
  }
  else
  {
    fscanf(file_in, "%lld", &value);
    answer = value;

    while (fscanf(file_in, " %c ", &op) == 1)
    {
      fscanf(file_in, " %lld", &value);
      if (op == '+')
      {
        answer += value;
      }
      else
      {
        answer -= value;
      }
    }

    fclose(file_in);
  }

  if (file_out == NULL)
  {
    printf("No file %s\n", "output.txt");
    return 1;
  }
  else
  {
    fprintf(file_out, "%lld", answer);
    fclose(file_out);
  }

  return 0;
}
// Задача 01-12: Три наибольших числа в последовательности
// На стандартном потоке ввода задаётся натуральное число N (N ≥ 3),
// после которого следует последовательность из N целых чисел.
// На стандартный поток вывода напечатайте три наибольших числа из этой
// последовательности в следующем порядке:
// сначала наибольшее, затем второе по величине и, наконец, третье.
// Выводимые программой числа могут совпадать (например, если максимальное
// число встречается в последовательности дважды, его следует также выводить
// два раза: как наибольшее и второе по величине).

#include <stdio.h>

int main(void)
{
  int n, value, max1, max2, max3, value1, value2, value3;

  scanf("%d", &n);
  scanf("%d%d%d", &value1, &value2, &value3);

  if ((value1 >= value2) && (value1 >= value3))
  {
    max1 = value1;
    if (value2 >= value3)
    {
      max2 = value2;
      max3 = value3;
    }
    else
    {
      max2 = value3;
      max3 = value2;
    }
  }
  else if ((value2 >= value1) && (value2 >= value3))
  {
    max1 = value2;
    if (value1 >= value3)
    {
      max2 = value1;
      max3 = value3;
    }
    else
    {
      max2 = value3;
      max3 = value1;
    }
  }
  else
  {
    max1 = value3;
    if (value1 >= value2)
    {
      max2 = value1;
      max3 = value2;
    }
    else
    {
      max2 = value2;
      max3 = value1;
    }
  }

  for (int i = 3; i < n; i++)
  {
    scanf("%d", &value);
    if (value > max1)
    {
      max3 = max2;
      max2 = max1;
      max1 = value;
    }
    else if ((value > max2) && (value < max1))
    {
      max3 = max2;
      max2 = value;
    }
    else if ((value > max3) && (value < max2))
    {
      max3 = value;
    }
    else if ((value == max1) && (value > max2))
    {
      max2 = value;
    }
    else if ((value == max2) && (value > max3))
    {
      max3 = value;
    }
  }

  printf("%d %d %d\n", max1, max2, max3);
  return 0;
}

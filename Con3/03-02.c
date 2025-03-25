// Задача 03-2: Проще некуда
// На вход программе подается натуральное число N, не превосходящее 109.
// Требуется найти наименьшее возможное простое число P, больше либо равное N.
// Указание: реализуйте функцию isprime, проверяющую число на простоту.

#include <stdio.h>
#include <math.h>

int isprime(unsigned int n)
{
  for (unsigned int i = 2; i < (unsigned int) sqrt(n) + 1; i++)
  {
    if (n % i == 0)
    {
      return 0;
    }
  }
  return 1;
}

int main(void)
{
  unsigned int n;
  scanf("%u", &n);

  if (n < 3)
  {
    printf("2");
    return 0;
  }

  while (1)
  {
    if (isprime(n))
    {
      printf("%u", n);
      return 0;
    }
    n++;
  }
}
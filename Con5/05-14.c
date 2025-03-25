// Задача 05-14: Гиперпростые числа
// Простое натуральное число называется гиперпростым,
// если любое число, получающееся из него откидыванием нескольких
// последних цифр, тоже является простым. Например, число 7331 – гиперпростое,
// т.к. и оно само, и числа 733, 73, 7 являются простыми. Найдите все N-значные
// гиперпростые числа.
// Входные данные: единственное целое число N (1 ≤ N ≤ 9).
// Выходные данные: возрастающая последовательность целых чисел через пробел – ответ задачи.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int array[9];

// 0 - все ОК, 1 - не простое
int is_prime(int n)
{
  int lim = (int) round(sqrt(n));

  for (int i = 2; i <= lim; i++)
  {
    if (n % i == 0)
    {
      return 1;
    }
  }
  return 0;
}


void func(int numb, int n)
{
  if (numb == n)
  {
    int answ = 0;

    for (int i = 0; i < n; i++)
    {
      answ *= 10;
      answ += array[i];
    }
    if (is_prime(answ) == 0)
    {
      printf("%d ", answ);
    }
  }
  else if (numb == 0)
  {
    int larray[4] = {2, 3, 5, 7};
    for (int i = 0; i < 4; i++)
    {
      array[numb] = larray[i];
      int answ = 0;

      for (int j = 0; j < numb + 1; j++)
      {
        answ *= 10;
        answ += array[j];
      }
      if (is_prime(answ) == 0)
      {
        func(numb + 1, n);
      }
    }
  }
  else
  {
    int larray[4] = {1, 3, 7, 9};

    for (int i = 0; i < 4; i++)
    {
      array[numb] = larray[i];
      int answ = 0;

      for (int j = 0; j < numb + 1; j++)
      {
        answ *= 10;
        answ += array[j];
      }
      if (is_prime(answ) == 0)
      {
        func(numb + 1, n);
      }
    }
  }
}


int main(void)
{
  int n;
  scanf("%d", &n);

  func(0, n);
  return 0;
}
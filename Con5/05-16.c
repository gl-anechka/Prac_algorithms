// Задача 05-16: Апельсин
// К Вам на улице подходит незнакомец и говорит, что всем известно
// эффективное решение задачи вычисления i-ого члена последовательности
// Фибоначчи по модулю числа p*. Однако, теперь его интересует более общая
// задача для произвольной линейной рекуррентной последовательности, заданной формулой
// Fn = A1 * Fn-1 + ... + AkFn-k.
// Не в силах противостоять ему, Вы решаете помочь. Ваша задача посчитать FN mod p.
// Входные данные имеют следующий формат. Сначала идут целые положительные числа k, N, p
// каждое с новой строки.2 ≤ k ≤ 10, N ≤ 2*109, p ≤ 2*105. В следующей строке содержатся
// первые k членов данной последовательности F1..Fk. Каждое число целое неотрицательное
// и не превосходит 105. В последней строке файла содержатся коэффициенты A1..Ak.
// Каждое число целое неотрицательное и не превосходит 105.

#include <stdio.h>

// Возедение матрицы в степень
// На вход: указатель на исходную матрицу, размер матрицы,
// степень, модуль, матрица ответа.

void func(unsigned long *A, unsigned long k, unsigned long deg, unsigned long p, unsigned long *matrix)
{
  if (deg == 1)  // не надо возводить в степень, просто копируем значения
  {
    for (unsigned long i = 0; i < k; i++)
    {
      for (unsigned long j = 0; j < k; j++)
      {
        *(matrix + i * k + j) = *(A + i * k + j);
      }
    }
  }
  else  // надо возводить в степень
  {
    // при возведении в степень первая строка умножается,
    // а остальные съезжают вниз на одну
    unsigned long int_val[k][k];
    func(A, k, deg / 2, p, &int_val[0][0]);  // понижаем степень,
                                             // т.к. умеет умножать только 2 матрицы
    unsigned long ev_ans[k][k];
    for (unsigned long i = 0; i < k; i++)
    {
      for (unsigned long j = 0; j < k; j++)
      {
        ev_ans[i][j] = 0;
      }
    }

    for (unsigned long i = 0; i < k; i++)
    {
      for (unsigned long j = 0; j < k; j++)
      {
        for (unsigned long m = 0; m < k; m++)
        {
          ev_ans[i][j] = (ev_ans[i][j] + int_val[i][m] * int_val[m][j]) % p;
        }
      }
    }

    if (deg % 2)
    {
      unsigned long unev_ans[k][k];
      for (unsigned long i = 0; i < k; i++)
      {
        for (unsigned long j = 0; j < k; j++)
        {
          unev_ans[i][j] = 0;
        }
      }

      // еще одно умножение матриц (нечетная степень)
      for (unsigned long i = 0; i < k; i++)
      {
        for (unsigned long j = 0; j < k; j++)
        {
          for (unsigned long m = 0; m < k; m++)
          {
            unev_ans[i][j] = (unev_ans[i][j] + (*(A + i * k + m)) * ev_ans[m][j]) % p;
          }
        }
      }


      for (unsigned long i = 0; i < k * k; i++, ++matrix)
      {
        *matrix = unev_ans[i / k][i % k];
      }
    }
    else
    {
      for (unsigned long i = 0; i < k * k; i++, ++matrix)
      {
        *matrix = ev_ans[i / k][i % k];
      }
    }
  }
}


int main(void)
{
  unsigned long k, n, p;
  scanf("%lu%lu%lu", &k, &n, &p);

  unsigned long F[k];
  // члены последовательности
  for (unsigned long i = 0; i < k; i++)
  {
    scanf("%lu", &F[i]);
  }

  // матрица коэффициентов, где в первой строке стоят
  // заданные коэффициенты, под главной диагональю стоят 1,
  // а на остальных позииях 0
  unsigned long A[k][k];
  for (unsigned long i = 0; i < k; i++)
  {
    scanf("%lu", &A[0][i]);
  }

  for (unsigned long i = 1; i < k; i++)
  {
    for (unsigned long j = 0; j < k; j++)
    {
      if (i == j + 1)
      {
        A[i][j] = 1;
      }
      else
      {
        A[i][j] = 0;
      }
    }
  }

  // ответ уже есть среди значений
  if (n <= k)
  {
    printf("%lu", F[n-1] % p);
    return 0;
  }

  unsigned long matrix[k][k];  // A^(n-k)
  func(&A[0][0], k, n-k, p, &matrix[0][0]);

  unsigned long answer = 0;
  for (unsigned long i = 0; i < k; i++)
  {
    answer = (answer + matrix[0][i] * F[k-1-i]) % p;
  }

  printf("%lu", answer);
  return 0;

}
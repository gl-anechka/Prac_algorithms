// Задача 05-12: Решение системы линейных уравнений
// Грустная панда сидит и смотрит на систему линейных алгебраических уравнений
// Ax = b с целочисленными коэффициентами. С первого взгляда бросается в глаза,
// что все эти коэффициенты невелики. Для того, чтобы развеселить панду,
// требуется реализовать программу, которая смогла бы найти точное решение этой системы.
// На вход программе подается натуральное число N (N ≤ 500) и последовательность
// целых чисел a11, a12, ..., a1N, b1, a21, ...., aNN, bN. Требуется вывести
// последовательность целых чисел x1, ..., xN, являющихся решением данной системы уравнений.
// Панда уверена в том, что такое решение существует и единственно.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
  double epsilon = 0.000001;
  int n;
  scanf("%d", &n);

  // расширенная матрица
  double **Ab = (double**) malloc(sizeof(double*) * n);
  for (int i = 0; i < n; i++)
  {
    Ab[i] = (double*) malloc(sizeof(double) * (n + 1));

    // считываем строки расширенной матрицы
    for (int j = 0; j < n + 1; j++)
    {
      scanf("%lf", &Ab[i][j]);
    }
  }

  for (int i = 1; i < n; i++)
  {
    for (int j = i; j < n; j++)
    {
      // перестановка строк (если старший коэффиц. 0)
      if (fabs(Ab[i - 1][i - 1]) < epsilon)
      {
        int ind = i - 1;
        while (fabs(Ab[ind][i - 1]) < epsilon && ind < n)
        {
          ind++;
        }
        double* temp = Ab[i - 1];
        Ab[i - 1] = Ab[ind];
        Ab[ind] = temp;
      }

      // метод Гаусса (исключаем строки)
      if (fabs(Ab[i - 1][i - 1]) > epsilon)
      {
        double coef = Ab[j][i - 1] / Ab[i - 1][i - 1];
        for (int k = 0; k <= n; k++)
        {
          Ab[j][k] -= Ab[i - 1][k] * coef;
        }
      }
    }
  }

  double x[n];  // решение-столбец

  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = n - 1; j > i; j--)
    {
      Ab[i][n] -= Ab[i][j] * x[j];
    }
    x[i] = Ab[i][n] / Ab[i][i];
  }

  // free матрицы (двойной указатель)
  for (int i = 0; i < n; i++)
  {
    free(Ab[i]);
  }
  free(Ab);


  for (int i = 0; i < n; i++)
  {
    printf("%d\n", (int) round(x[i]));
  }

  return 0;
}
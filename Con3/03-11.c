// Задача 03-11: Сложение дробей
// Вводится целое число N (2 ≤ N ≤ 5), и следом N пар целых чисел
// A1,B1,...,AN,BN (0 ≤ Ai < Bi ≤ 50)
// Требуется найти сумму чисел A1/B1 + ... + AN/BN. Сумму необходимо вывести
// в видел трех неотрицательных целых чисел X, Y, Z, таких что требуемая
// сумма равняется X+Y/Z, причем Y/Z - правильная несократимая дробь.

#include <stdio.h>

int nod(int a, int b)
{
  if (a == b || b == 0)
  {
    return a;
  }
  else
  {
    if (a > b)
    {
      return nod(b, a % b);
    }
    else
    {
      return nod(a, b % a);
    }
  }
}

int max(int x, int y)
{
  return (x > y) ? x : y;
}

int min(int x, int y)
{
  return (x < y) ? x : y;
}

int main(void)
{
  int n;
  scanf("%d", &n);
  int a, b, a_cur, b_cur;

  scanf("%d%d", &a, &b);

  for (int i = 1; i < n; i++)
  {
    scanf("%d%d", &a_cur, &b_cur);
    a = a * b_cur + b * a_cur;
    b = b * b_cur;
  }

  int nd = nod(max(a, b), min(a, b));
  a /= nd;
  b /= nd;

  printf("%d %d %d", a / b, a % b, b);

  return 0;
}
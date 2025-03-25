// Задача 03-16: Суперстепень
// Даны натуральные числа a, b, c и m (a ≤ 9, b ≤ 9, c ≤ 9, m ≤ 10000).
// Кто-то выписал на доске все возможные сверхстепени, составленные из
// чисел a, b и c по модулю m (то есть abc mod m, acb mod m, bac mod m и так далее).
// Чему равно наибольшее из выписанных чисел?

#include <stdio.h>

unsigned int f_pow(unsigned int n, unsigned int deg)
{
  if (deg == 1) return n;
  if (deg % 2) return f_pow(n, deg / 2) * f_pow(n, deg / 2) * n;
  else return f_pow(n, deg / 2) * f_pow(n, deg / 2);
}

unsigned int f_pow_mod(unsigned int n, unsigned int deg, unsigned int m)
{
  if (deg == 1) return n % m;
  if (deg % 2) return f_pow_mod(n, deg / 2, m) * f_pow_mod(n, deg / 2, m) * n % m;
  else return f_pow_mod(n, deg / 2, m) * f_pow_mod(n, deg / 2, m) % m;
}

unsigned int max(unsigned int a, unsigned int b)
{
  return (a > b) ? a : b;
}

int main(void)
{
  unsigned int a, b, c, m;
  scanf("%u%u%u%u", &a, &b, &c, &m);

  unsigned int res = 0;

  res = max(f_pow_mod(a, f_pow(b, c), m), res);
  res = max(f_pow_mod(a, f_pow(c, b), m), res);
  res = max(f_pow_mod(b, f_pow(a, c), m), res);
  res = max(f_pow_mod(b, f_pow(c, a), m), res);
  res = max(f_pow_mod(c, f_pow(a, b), m), res);
  res = max(f_pow_mod(c, f_pow(b, a), m), res);

  printf("%u", res);
  return 0;
}
// Задача 03-18: Удваивающаяся последовательность
// Задается два числа N и A (1 ≤ N, A ≤ 2000000000). Строится бесконечная последовательность Xi.
// X1 = N mod 2010
// X2 = (X1#X1) mod 2010 ... Xi+1 = (Xi#Xi) mod 2010
// Здесь C mod D означает остаток от деления C на D. C#D - дает число, которое получится
// если приписать D к C. Например, 20#10 = 2010.
// Выведите одно слово YES если A встречается в последовательности X или NO если не встречается.

#include <stdio.h>
#include <math.h>

unsigned add(unsigned c, unsigned d)
{
  unsigned size = (unsigned)pow(10, (int)log10(d) + 1);
  c = c * size + d;
  return c;
}

int main(void)
{
  unsigned n, a;
  scanf("%u%u", &n, &a);

  unsigned xn = n % 2010;
  int count = 0;

  while (count < 1000000)
  {
    if (xn == a)
    {
      printf("YES");
      return 0;
    }
    xn = add(xn, xn) % 2010;
    count++;
  }

  printf("NO");
  return 0;
}
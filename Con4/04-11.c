// Задача 04-11: Экстерминатус
// Ваша задача состоит в том, чтобы извлечь из полученной информации коды запуска орудий.
// Передача состоит из заглавных и строчных латинских букв, цифр, а также 4 основных
// арифметических действий '+', '-', '*', '/'. Её длина не превосходит 2000 символов.
// Известно, что кодом является некоторая команда вида A op B, где A и B - целые
// неотрицательные числа, а op - одно из арифметических действий, результат которой является
// корректно вычислимым выражением модуль которого не превосходит 120000. При этом выражение
// "A op B" является подстрокой исходного сообшения. Гарантируется, что числа A,B и результат
// операции над ними не переполняют 32-х битные целые знаковые числа. Необходимо найти все такие
// команды и вывести их каждую с новой строки в виде A op B = res, где res - результат вычисления.
// Всё остальное считается мусором из других передач. Заметим, что для выражения A op1 B op2 C
// нужно вывести A op1 B = res1 и B op2 C = res2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int getnum(char *st)
{
  int num = 0;
  int i = 0;
  while ('0' <= st[i] && st[i] <= '9')
  {
    num = 10 * num + (st[i] - '0');
    i++;
  }
  return num;
}

int isop(char c)
{
  if (c == '+' || c == '*' || c == '/' || c == '-')
    return 1;
  else
    return 0;
}

int isnum(char c)
{
  if ('0' <= c && c <= '9') return 1;
  else return 0;
}

int skip(int num)
{
  if (num == 0) return 1;
  else return (int)log10(num) + 1;
}

int iscor(int a, int b, char op)
{
  switch (op)
  {
    case '+':
      if (abs(a + b) <= 120000) return a + b;
      break;
    case '-':
      if (abs(a - b) <= 120000) return a - b;
      break;
    case '*':
      if (abs(a * b) <= 120000) return a * b;
      break;
    case '/':
      if (b != 0 && abs(a / b) <= 120000) return a / b;
      break;
    default: return 130000;
  }
  return 130000;
}

int main(void)
{
  char st[2005];
  scanf("%s", st);
  int len = strlen(st);

  int i = 0, num1 = -1, num2 = -1;
  char op = 0;

  while (i < len)
  {
    // новый пример
    // первое число
    if (isnum(st[i]) && num1 == -1 && num2 == -1)
    {
      num1 = getnum(&st[i]);
      i += skip(num1);
      // операция
      if (i < len && isop(st[i]))
      {
        op = st[i];
        i++;
        // второе число
        if (i < len && isnum(st[i]) && num2 == -1)
        {
          num2 = getnum(&st[i]);
          i += skip(num2);
          if (iscor(num1, num2, op) != 130000)
          {
            printf("%d %c %d = %d\n", num1, op, num2, iscor(num1, num2, op));
          }
          num1 = -1;
        }
      }
    }
    // операции подряд
    else if (num1 == -1 && num2 != -1 && isop(st[i]) && isnum(st[i+1]))
    {
      num1 = num2;
      op = st[i];
      i++;
      num2 = getnum(&st[i]);
      i += skip(num2);

      if (iscor(num1, num2, op) != 130000)
      {
        printf("%d %c %d = %d\n", num1, op, num2, iscor(num1, num2, op));
      }
      num1 = -1;
    }
    else
    {
      num1 = -1;
      num2 = -1;
      i++;
    }
  }
  return 0;
}
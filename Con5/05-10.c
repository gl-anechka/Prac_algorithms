// Задача 05-10: Длинная арифметика
// Необходимо реализовать операции сложения, вычитания и умножения двух
// чисел a и b. Каждое число содержит не более 10000 десятичных знаков,
// то есть 0 ≤ a, b < 1010001.
// Входные данные:
// Числа a и b, разделённые знаком сложения, вычитания или умножения.
// Выходные данные: результат выполнения соответствующей операции

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 30000

int max(int a, int b)
{
  return (a > b) ? a : b;
}

int main(void)
{
  char st[MAXLINE];
  scanf("%s", st);

  int ind = 0;
  while(st[ind] != '+' && st[ind] != '-' && st[ind] != '*')
  {
    ind++;
  }

  char op = st[ind];  // знак операции
  int len1 = ind;  // конец первого числа
  ind++;

  while (st[ind] != '\0')
  {
    ind++;
  }
  int len2 = ind;  // конец второго числа

  // _________________
  if (op == '+')  // сложение
  {
    // длина числа - максимальная из двух числел + 1
    int size = max(len1 + 1, len2 - len1);
    int numb1[size];  // первое число, сюда же результат
    int numb2[size];  // второе число

    for (int i = 0; i < size; i++)
    {
      numb1[i] = 0;
      numb2[i] = 0;
    }

    for (int i = size - len1; i < size; i++)
    {
      numb1[i] = st[i - size + len1] - '0';
    }
    for (int i = size - len2 + len1 + 1; i < size; i++)
    {
      numb2[i] = st[i - size + len2] - '0';
    }

    int ost = 0;
    int elem;
    for (int i = size - 1; i >= 0; i--)
    {
      elem = (numb1[i] + numb2[i] + ost) / 10;
      numb1[i] = (numb1[i] + numb2[i] + ost) % 10;
      ost = elem;
    }
    if (numb1[0] != 0)
    {
      printf("%d", numb1[0]);
    }
    for (int i = 1; i < size; i++)
    {
      printf("%d", numb1[i]);
    }
  }
  else if (op == '-')  // вычитание
  {
    // длина числа - максимальная из двух числел + 1
    int size = max(len1 + 1, len2 - len1);
    int numb1[size];  // первое число, возможно сюда же результат
    int numb2[size];  // второе число, возможно сюда же результат

    for (int i = 0; i < size; i++)
    {
      numb1[i] = 0;
      numb2[i] = 0;
    }

    for (int i = size - len1; i < size; i++)
    {
      numb1[i] = st[i - size + len1] - '0';
    }
    for (int i = size - len2 + len1 + 1; i < size; i++)
    {
      numb2[i] = st[i - size + len2] - '0';
    }

    int bigger = 0;  // какое из чисел больше
    for (int i = 0; i < size; i++)
    {
      if (numb1[i] > numb2[i])
      {
        bigger = 1;
        break;
      }
      if (numb1[i] < numb2[i])
      {
        bigger = 2;
        break;
      }
    }

    if (bigger == 0)  // числа равны
    {
      printf("0");
      return 0;
    }
    else if (bigger == 1)  // первое больше
    {
      for (int i = size - 1; i > 0; i--)
      {
        if (numb1[i] < numb2[i])
        {
          numb1[i-1]--;
          numb1[i] = 10 + numb1[i] - numb2[i];
        }
        else
        {
          numb1[i] = numb1[i] - numb2[i];
        }
      }

      int flag = 1;
      for (int i = 0; i < size; i++)
      {
        if (numb1[i] == 0 && flag != 0)
        {
          continue;  // пропускаем нули в начале
        }
        else
        {
          printf("%d", numb1[i]);
          flag = 0;
        }
      }
    }
    else  // второе больше
    {
      for (int i = size - 1; i > 0; i--)
      {
        if (numb2[i] < numb1[i])
        {
          numb2[i-1]--;
          numb2[i] = 10 + numb2[i] - numb1[i];
        }
        else
        {
          numb2[i] = numb2[i] - numb1[i];
        }
      }

      int flag = 1;
      printf("-");
      for (int i = 0; i < size; i++)
      {
        if (numb2[i] == 0 && flag != 0)
        {
          continue;  // пропускаем нули в начале
        }
        else
        {
          printf("%d", numb2[i]);
          flag = 0;
        }
      }
    }
  }
  else  // умножение
  {
    int size = len2;
    int numb1[size];
    int numb2[size];

    for (int i = 0; i < size; i++)
    {
      numb1[i] = 0;
      numb2[i] = 0;
    }

    for (int i = size - len1; i < size; i++)
    {
      numb1[i] = st[i - size + len1] - '0';
    }
    for (int i = size - len2 + len1 + 1; i < size; i++)
    {
      numb2[i] = st[i - size + len2] - '0';
    }

    int answ[size];
    for (int i = 0; i < size; i++)
    {
      answ[i] = 0;
    }

    int ost = 0;
    for (int i = size - 1; i > size - len2 + len1; i--)
    {
      ost = 0;
      for (int j = size - 1; j >= size - len1 - 1; j--)
      {
        answ[j - size + i + 1] += (numb2[i] * numb1[j] + ost) % 10;
        ost = (numb2[i] * numb1[j] + ost) / 10;
      }
    }
    for (int i = size - 1; i > 0; i--)
    {
      answ[i-1] += answ[i] / 10;
      answ[i] %= 10;
    }

    int flag = 1;
    for (int i = 0; i < size; i++)
    {
      if (answ[i] == 0 && flag != 0)
      {
        continue;  // пропускаем нули в начале
      }
      else
      {
        printf("%d", answ[i]);
        flag = 0;
      }
    }
    if (flag == 1)  // 0*0 = 0
    {
      printf("0");
    }
  }

  return 0;
}
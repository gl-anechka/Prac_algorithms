// Задача 01-3: Шифр Цезаря
// На стандартном потоке ввода задается целое неотрицательное число N и
// последовательность допустимых символов в кодировке ASCII, оканчивающаяся точкой.
// Допустимые символы - латинские буквы 'a' ... 'z', 'A' ... 'Z' и пробел.
// Требуется закодировать латинские буквы ('a' ... 'z', 'A' ... 'Z') шифром Цезаря,
// пробелы вывести без изменения. Число N задает сдвиг в шифре.
// Шифр Цезаря заключается в следующем преобразовании.
// Пусть буквы алфавита пронумерованы от 0 до K - 1, где K - число символов в алфавите.
// Тогда символ с номером n кодируется символом с номером p = (n + N) mod K (mod - операция взятия остатка).
// На стандартном потоке вывода напечатать зашифрованное сообщение, оканчивающееся точкой.
// Преобразование требуется выполнять независимо для заглавных и строчных латинских букв.
// Подсказка: в кодировке ASCII как строчные, так и заглавные символы латинского алфавита
// образуют непрерывные последовательности кодов.

#include <stdio.h>
int main(void)
{
  int N, p;
  int letter;
  scanf("%d", &N);

  letter = getchar();
  while(letter != '.')
  {
    if (letter == ' ')
      printf(" ");
    else if (letter >= 'a' && letter <= 'z')
    {
      p = ((letter - 'a') + N) % 26;   // новый номер символа
      printf("%c", p + 'a');
    }
    else if (letter >= 'A' && letter <= 'Z')
    {
      p = ((letter - 'A') + N) % 26;   // новый номер символа
      printf("%c", p + 'A');
    }
    letter = getchar();
  }

  printf(".");
  return 0;
}

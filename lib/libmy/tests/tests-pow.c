/*
** tests-pow.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Sun Dec  28 14:26:59 2014 Louis Person
** Last update Sun Dec  28 14:26:59 2014 Louis Person
*/

#include "my.h"

void	test(const int nb, const int power, int expected)
{
  int	result;

  result = my_pow(nb, power);
  if (result != expected)
  {
    chalk_red("KO\n");
    my_putstr("\texpected '");
    my_putnbr(expected);
    my_putstr("' and got '");
    my_putnbr(result);
    my_putstr("' instead.\n\tInput was '");
    my_putnbr(nb);
    my_putstr("' and '");
    my_putnbr(power);
    my_putstr("'\n");
  }
  else
    chalk_green("OK\n");
}

int	main()
{
  test(10, 3, 1000);
  test(10, -4, 0);
  test(-2, 2, 4);
  test(4, 2, 16);
  test(4, 3, 64);
  test(100, 0, 1);
  return (0);
}

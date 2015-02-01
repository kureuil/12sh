/*
** tests-getnbr.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Sun Dec  28 13:52:43 2014 Louis Person
** Last update Sun Dec  28 13:52:43 2014 Louis Person
*/

#include "my.h"

void	test(const char *src, int expected)
{
  int	result;

  result = my_getnbr(src);
  if (result != expected)
  {
    chalk_red("KO\n");
    my_putstr("\texpected '");
    my_putnbr(expected);
    my_putstr("' and got '");
    my_putnbr(result);
    my_putstr("' instead.\n\tInput was '");
    my_putstr(src);
    my_putstr("'\n");
  }
  else
    chalk_green("OK\n");
}

int	main()
{
  test("42", 42);
  test("42a", 42);
  test("a42", 0);
  test("-42", -42);
  test("---++-124a-", 124);
  test("2147483647", 2147483647);
  test("2147483648", 0);
  test("-2147483648", -2147483648);
  test("-2147483649", 0);
  test("-2147483650", 0);
  return (0);
}

/*
** tests-indexof.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Sun Dec  28 15:19:21 2014 Louis Person
** Last update Sun Dec  28 15:19:21 2014 Louis Person
*/

#include <stdlib.h>
#include "my.h"

void	test(const char c, const char *str, int expected)
{
  int	result;

  result = index_of(c, str);
  if (result != expected)
  {
    chalk_red("KO\n");
    my_putstr("\texpected '");
    my_putnbr(expected);
    my_putstr("' and got '");
    my_putnbr(result);
    my_putstr("' instead.\n\tInput was '");
    my_putchar(c);
    my_putstr("' and '");
    my_putstr(str);
    my_putstr("'\n");
  }
  else
    chalk_green("OK\n");
  }

  int	main()
{
  test('i', "Hello World!", -1);
  test('H', "Hello World!", 0);
  test('e', "Hello World!", 1);
  test('e', NULL, -1);
  return (0);
}

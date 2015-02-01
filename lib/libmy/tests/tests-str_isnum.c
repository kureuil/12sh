/*
** tests-str_isnum.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Sat Dec  27 17:58:45 2014 Louis Person
** Last update Sat Dec  27 17:58:45 2014 Louis Person
*/

#include <stdlib.h>
#include "my.h"

void	test(const char *src, int expected)
{
  int	result;

  result = my_str_isnum(src);
  if (result != expected)
  {
    chalk_red("KO\n");
    my_putstr("\texpected '");
    my_put_nbr(expected);
    my_putstr("' and got '");
    my_put_nbr(result);
    my_putstr("' instead.\n\tInput was '");
    my_putstr(src);
    my_putstr("'\n");
  }
  else
    chalk_green("OK\n");
}

int	main()
{
  test("Hello World!", 0);
  test("HowAreYou", 0);
  test("007", 1);
  test("0 0 7", 0);
  test("", 0);
  test(NULL, 0);
  return (0);
}

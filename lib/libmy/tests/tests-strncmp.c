/*
** test-strncmp.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Sat Dec  27 15:52:47 2014 Louis Person
** Last update Sat Dec  27 15:52:47 2014 Louis Person
*/

#include <stdlib.h>
#include "my.h"

void	test(char *str1, char *str2, int n, int expected)
{
  int	result;

  result = my_strncmp(str1, str2, n);
  if (result != expected)
  {
    chalk_red("KO\n");
    my_putstr("\texpected ");
    my_put_nbr(expected);
    my_putstr(" and got ");
    my_put_nbr(result);
    my_putstr(" instead.\n\tInput was '");
    my_putstr(str1);
    my_putstr("' and '");
    my_putstr(str2);
    my_putstr("'\n");
  }
  else
    chalk_green("OK\n");
  }

  int	main()
{
  test("world", "hello", 5, 1);
  test("hello", "world", 5, -1);
  test("hello", "hello", 5, 0);
  test(NULL, "Hello", 5, 0);
  test(NULL, NULL, 1, 0);
  test(NULL, "", 1, 0);
  test("", "", 1, 0);
  return (0);
}

/*
** test-strcmp.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Sat Dec  27 15:52:47 2014 Louis Person
** Last update Sat Dec  27 15:52:47 2014 Louis Person
*/

#include <stdlib.h>
#include "my.h"

void	test(char *str1, char *str2, int expected)
{
  int	result;

  result = my_strcmp(str1, str2);
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
  test("world", "hello", 1);
  test("hello", "world", -1);
  test("hello", "hello", 0);
  test(NULL, "Hello", 0);
  test(NULL, NULL, 0);
  test(NULL, "", 0);
  test("", "", 0);
  return (0);
}

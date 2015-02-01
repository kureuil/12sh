/*
** tests-strcount.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Sat Dec  27 19:9:41 2014 Louis Person
** Last update Sat Dec  27 19:9:41 2014 Louis Person
*/

#include <stdlib.h>
#include "my.h"

void	test(char *haystack, char *needle, int expected)
{
  int	result;

  result = my_strcount(haystack, needle);
  if (result != expected)
  {
    chalk_red("KO\n");
    my_putstr("\texpected ");
    my_put_nbr(expected);
    my_putstr(" and got ");
    my_put_nbr(result);
    my_putstr(" instead.\n\tInput was '");
    my_putstr(haystack);
    my_putstr("' and '");
    my_putstr(needle);
    my_putstr("'\n");
  }
  else
    chalk_green("OK\n");
}

int	main()
{
  test("Hello World!", "l", 3);
  test("Hello World!", "o", 2);
  test("Hello World!", "!", 1);
  test("Hello World!Hello World!Hello World!Hello World!", "World!", 4);
  test("Hello World", "", 0);
  test("", "needle", 0);
  test("Hello World", NULL, 0);
  test(NULL, "needle", 0);
  test(NULL, NULL, 0);
  return (0);
}

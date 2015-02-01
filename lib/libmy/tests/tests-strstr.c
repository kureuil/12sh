/*
** tests-strstr.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Sat Dec  27 18:58:30 2014 Louis Person
** Last update Sat Dec  27 18:58:30 2014 Louis Person
*/

#include <stdlib.h>
#include "my.h"

void	test(char *haystack, char *needle, char *expected)
{
  char	*result;

  result = my_strstr(haystack, needle);
  if (my_strcmp(result, expected))
  {
    chalk_red("KO\n");
    my_putstr("\texpected '");
    my_putstr(expected);
    my_putstr("' and got '");
    my_putstr(result);
    my_putstr("' instead.\n\tInput was '");
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
  test("Hello world!", "lo", "lo world!");
  test("Hello world!", "world!", "world!");
  test("Hello world!", "", "Hello world!");
  test("Hello world!", "Baba", "");
  test("Hello world!", NULL, "Hello world!");
  test(NULL, "lo", NULL);
  return (0);
}

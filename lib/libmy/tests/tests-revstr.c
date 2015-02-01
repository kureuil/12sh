/*
** tests-revstr.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Sat Dec  27 17:18:2 2014 Louis Person
** Last update Sat Dec  27 17:18:2 2014 Louis Person
*/

#include <stdlib.h>
#include "my.h"

void	test(const char *src, char *expected)
{
  char	*result;

  result = my_revstr(my_strdup(src));
  if (my_strcmp(result, expected))
  {
    chalk_red("KO\n");
    my_putstr("\texpected '");
    my_putstr(expected);
    my_putstr("' and got '");
    my_putstr(result);
    my_putstr("' instead.\n\tInput was '");
    my_putstr(src);
    my_putstr("'\n");
  }
  else
    chalk_green("OK\n");
  }

  int	main()
{
  test("Hello World!", "!dlroW olleH");
  test("How Are You", "uoY erA woH");
  test("", "");
  test(NULL, NULL);
  return (0);
}

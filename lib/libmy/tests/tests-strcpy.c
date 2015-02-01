/*
** tests-strcpy.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Sat Dec  27 16:52:40 2014 Louis Person
** Last update Sat Dec  27 16:52:40 2014 Louis Person
*/

#include <stdlib.h>
#include "my.h"

void	test(char *dest, const char *src, char *expected)
{
  char	*result;

  result = my_strcpy(dest, src);
  if (my_strcmp(dest, expected))
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
  char	*dest;

  dest = malloc(64);
  test(dest, "Hello World!", "Hello World!");
  test(dest, "How Are You?", "How Are You?");
  test(dest, "", "");
  test(dest, NULL, "");
  test(NULL, "Hello World!", NULL);
  return (0);
}

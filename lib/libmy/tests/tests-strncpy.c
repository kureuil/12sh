/*
** tests-strncpy.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Sat Dec  27 16:59:48 2014 Louis Person
** Last update Sat Dec  27 16:59:48 2014 Louis Person
*/

#include <stdlib.h>
#include "my.h"

void	test(char *dest, const char *src, int n, char *expected)
{
  char	*result;

  result = my_strncpy(dest, src, n);
  if (my_strcmp(dest, expected))
  {
    chalk_red("KO\n");
    my_putstr("\texpected '");
    my_putstr(expected);
    my_putstr("' and got '");
    my_putstr(result);
    my_putstr("' instead.\n\tInput was '");
    my_putstr(src);
    my_putstr("' and size was '");
    my_put_nbr(n);
    my_putstr("'\n");
  }
  else
    chalk_green("OK\n");
  }

  int	main()
{
  char	*dest;

  dest = malloc(64);
  test(dest, "Hello World!", 12, "Hello World!");
  test(dest, "How Are You?", 12, "How Are You?");
  test(dest, "", 1, "");
  test(dest, NULL, 1, "");
  test(NULL, "Hello World!", 12, NULL);
  return (0);
}

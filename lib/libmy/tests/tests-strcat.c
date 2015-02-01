/*
** tests-strcat.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Sat Dec  27 18:41:3 2014 Louis Person
** Last update Sat Dec  27 18:41:3 2014 Louis Person
*/

#include <stdlib.h>
#include "my.h"

void	test(char *dest, const char *src, char *expected)
{
  char	*result;

  result = my_strcat(dest, src);
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
  my_strcpy(dest, "Hello");
  test(dest, " World!", "Hello World!");
  test(dest, NULL, dest);
  test(NULL, "How are you?", NULL);
  return (0);
}

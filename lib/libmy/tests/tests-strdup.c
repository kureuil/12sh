/*
** tests-strdup.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Sat Dec  27 17:14:0 2014 Louis Person
** Last update Sat Dec  27 17:14:0 2014 Louis Person
*/

#include <stdlib.h>
#include "my.h"

void	test(const char *src)
{
  char	*result;

  result = my_strdup(src);
  if (my_strcmp(result, src))
  {
    chalk_red("KO\n");
    my_putstr("\texpected '");
    my_putstr(src);
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
  test("Hello World!");
  test("How Are You");
  test("");
  test(NULL);
  return (0);
}

/*
** tests-strsep.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Sun Dec  28 0:28:47 2014 Louis Person
** Last update Sun Dec  28 0:28:47 2014 Louis Person
*/

#include <stdlib.h>
#include "my.h"

void	test(char *src, const char *delim, char *token, char *rest)
{
  char	*result;

  src = my_strdup(src);
  result = my_strsep(&src, delim);
  if (my_strcmp(result, token) || my_strcmp(src, rest))
  {
    chalk_red("KO\n");
    my_putstr("\texpected token '");
    my_putstr(token);
    my_putstr("' and got '");
    my_putstr(result);
    my_putstr("' instead.\n\texpected rest '");
    my_putstr(rest);
    my_putstr("' and got '");
    my_putstr(src);
    my_putstr("' instead.\n");
  }
  else
    chalk_green("OK\n");
}

int	main()
{
  test("Hello World!", " ", "Hello", "World!");
  test("Hello World!", "aba", "Hello World!", NULL);
  test("Hello World!", "l", "He", "lo World!");
  test("How are you ?", "are", "How ", " you ?");
  test("How are you ?", NULL, "How are you ?", NULL);
  test(NULL, "ui", NULL, NULL);
  return (0);
}

/*
** tests-str_capitalize.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Sat Dec  27 16:52:40 2014 Louis Person
** Last update Sat Dec  27 16:52:40 2014 Louis Person
*/

#include <stdlib.h>
#include "my.h"

void	test(char *src, char *expected)
{
  char	*result;

  result = my_strcapitalize(my_strdup(src));
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
  test("hello world", "Hello World");
  test("HOW ARE YOU", "How Are You");
  test("", "");
  test(NULL, NULL);
  test("hell-o world! HOW.ARE you?", "Hell-O World! How.are You?");
  return (0);
}
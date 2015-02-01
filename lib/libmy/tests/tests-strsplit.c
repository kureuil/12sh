/*
** tests-strsplit.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Sun Dec  28 0:53:9 2014 Louis Person
** Last update Tue Jan 20 14:25:19 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"

void	test(char *haystack, char *needle, char **expected)
{
  char	**result;
  int	c;

  result = my_strsplit(haystack, needle);
  c = 0;
  while (result[c] != NULL)
  {
    if (my_strcmp(result[c], expected[c]))
    {
      chalk_red("KO\n");
      my_putstr("\texpected token '");
      my_putstr(expected[c]);
      my_putstr("' and got '");
      my_putstr(result[c]);
      my_putstr("' instead.\n");
      free(result[c]);
      break;
    }
    free(result[c]);
    c++;
  }
  if (result[c] == NULL)
    chalk_green("OK\n");
  free(result);
}

int	main()
{
  char	*expected1[] = {"How", "are", "you"};
  char	*expected2[] = {"How", "are", "you"};
  char	*expected3[] = {"HOME", "/home/person_l"};
  char	*expected4[] = {"/usr/local/sbin", "/usr/local/bin", "/usr/sbin"};
  char	*expected5[] = {"/home/person_l"};

  test("How are you", " ", expected1);
  test("How  are you", " ", expected2);
  test("HOME=/home/person_l", "=", expected3);
  test("/usr/local/sbin:/usr/local/bin:/usr/sbin:", ":", expected4);
  test(NULL, ":", NULL);
  test("/home/person_l", NULL, expected5);
  return (0);
}

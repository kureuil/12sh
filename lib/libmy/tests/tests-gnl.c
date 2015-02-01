/*
** tests-gnl.c for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Mon Dec  29 16:9:5 2014 Louis Person
** Last update Mon Dec  29 16:9:5 2014 Louis Person
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

int	main()
{
  int	fd;
  char	*line;

  if ((fd = open("./tests/hello.txt", O_RDONLY)) == -1)
    chalk_red("KO: Could not open file.\n");
  else
    chalk_green("OK: file opened.\n");
  while ((line = get_next_line(fd)) != NULL)
  {
    my_putstr(line);
    my_putchar('\n');
    free(line);
  }
  if (close(fd) == -1)
    chalk_red("KO: Could not close file.\n");
  else
    chalk_green("OK: file closed.\n");
  return (0);
}

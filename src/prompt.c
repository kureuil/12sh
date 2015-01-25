/*
** prompt.c for minishell1 in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Sun Jan 25 22:13:19 2015 Louis Person
** Last update Mon Jan 26 00:51:33 2015 Louis Person
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void	prompt_print(t_dict *env)
{
  char	*user;
  int	fd;

  if ((fd = open("/dev/tty", O_WRONLY | O_APPEND)) == -1)
    return;
  user = dict_search(env, "USER");
  if (user != NULL)
    my_dputstr(fd, user);
  my_dputstr(fd, "$ ");
  close(fd);
}

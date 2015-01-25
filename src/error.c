/*
** error.c for minishell1 in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Thu Jan 22 00:18:16 2015 Louis Person
** Last update Sun Jan 25 22:36:28 2015 Louis Person
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void	handle_error(t_error err, t_darray *command)
{
  int	fd;

  if ((fd = open("/dev/tty", O_WRONLY | O_APPEND)) == -1)
    return;
  if (err == NOENT)
    {
      my_dputstr(fd, "mysh: command not found: ");
      my_dputstr(fd, command->data[0]);
      my_dputstr(fd, "\n");
    }
  if (command != NULL)
    free_dynamo(command);
  close(fd);
}


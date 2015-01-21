/*
** minishell.c for minishell1 in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Tue Jan 20 14:11:16 2015 Louis Person
** Last update Thu Jan 22 00:32:09 2015 Louis Person
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/limits.h>
#include "my.h"
#include "env.h"
#include "error.h"
#include "input.h"

int		main()
{
  char		*buffer;
  t_darray	*command;
  t_dict	*env;
  int	        readb;

  if ((env = parse_env()) == NULL)
    exit(1);
  if ((buffer = malloc(ARG_MAX + 1)) == NULL)
    handle_error(COULD_NOT_MALLOC, NULL);
  while ((readb = read(0, buffer, ARG_MAX)) > 0)
    {
      command = parse_input(buffer, readb);
      printf("%d: %s\n", readb, command->data[0]);
      free_dynamo(command);
    }
  dict_free(env, &free);
  return (0);
}

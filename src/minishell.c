/*
** minishell.c for minishell1 in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Tue Jan 20 14:11:16 2015 Louis Person
** Last update Sun Jan 25 22:32:17 2015 Louis Person
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
#include "prompt.h"
#include "command.h"
#include "builtins.h"

int		main()
{
  char		*buffer;
  t_darray	*command;
  t_dict	*env;
  t_dict	*builtins;
  int	        readb;
  t_error	ret;

  if ((env = parse_env()) == NULL)
    exit(1);
  if ((builtins = get_builtins()) == NULL)
    handle_error(COULD_NOT_MALLOC, NULL);
  if ((buffer = malloc(ARG_MAX + 1)) == NULL)
    handle_error(COULD_NOT_MALLOC, NULL);
  prompt_print(env);
  while ((readb = read(0, buffer, ARG_MAX)) > 0)
    {
      command = parse_input(buffer, readb);
      if ((ret = handle_command(command, env, builtins)) == QUIT)
        break;
      handle_error(ret, command);
      prompt_print(env);
    }
  dict_free(env, &free);
  dict_free(builtins, NULL);
  return (0);
}

/*
** exit.c for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Thu Jan 29 20:09:23 2015 Louis Person
** Last update Thu Jan 29 21:59:35 2015 Louis Person
*/

#include "my.h"
#include "shell.h"

t_error	builtin_exit(t_darray *cmd, t_shell *shell)
{
  shell->status = 0;
  if (cmd->current_size > 1 && cmd->data[1] != NULL)
    shell->status = my_getnbr(cmd->data[1]);
  return (QUIT);
}

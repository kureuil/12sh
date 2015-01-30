/*
** user.c for fabrish in /home/person_l/rendu/minishell1/fabrish
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Fri Jan 30 11:57:34 2015 Louis Person
** Last update Fri Jan 30 11:57:59 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"
#include "shell.h"

t_error	prompt_user(int fd, t_shell *shell)
{
  char	*user;

  if ((user = dict_search(shell->env, "USER")) == NULL)
    my_dputstr(fd, "tamer");
  else
    my_dputstr(fd, user);
  return (OK);
}

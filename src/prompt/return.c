/*
** return.c for fabrish in /home/person_l/rendu/minishell1/fabrish
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Fri Jan 30 11:58:58 2015 Louis Person
** Last update Fri Jan 30 11:59:07 2015 Louis Person
*/

#include "my.h"
#include "shell.h"

t_error	prompt_return(int fd, t_shell *shell)
{
  my_dput_nbr(fd, shell->status);
  return (OK);
}

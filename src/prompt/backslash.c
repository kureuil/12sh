/*
** backslash.c for fabrish in /home/person_l/rendu/minishell1/fabrish
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Fri Jan 30 11:58:29 2015 Louis Person
** Last update Fri Jan 30 11:58:46 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"
#include "shell.h"

t_error	prompt_backslash(int fd, t_shell *shell)
{
  shell = NULL;
  my_dputchar(fd, '\\');
  return (OK);
}

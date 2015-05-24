/*
** exit.c for 42sj in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Tue May 19 11:56:29 2015 Louis Person
** Last update Tue May 19 13:54:09 2015 Louis Person
*/

#include <assert.h>
#include <stdlib.h>
#include "shell.h"

int	sh_exit(struct s_shell *shell, int code)
{
  assert(shell != NULL);
  shell->exit = true;
  shell->returnvalue = code;
  return (0);
}

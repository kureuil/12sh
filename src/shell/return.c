/*
** return.c for 42sh in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Tue May 19 11:58:29 2015 Louis Person
** Last update Tue May 19 13:54:48 2015 Louis Person
*/

#include <assert.h>
#include <stdlib.h>
#include "shell.h"

int	sh_return(struct s_shell *shell, int code)
{
  assert(shell != NULL);
  shell->returnvalue = code;
  return (0);
}

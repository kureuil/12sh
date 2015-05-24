/*
** destroy.c for 42sh in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Tue May 19 11:53:53 2015 Louis Person
** Last update Sun May 24 02:03:58 2015 Louis Person
*/

#include <assert.h>
#include <unistd.h>
#include "shell.h"
#include "my/my.h"

int	sh_destroy(struct s_shell *shell)
{
  assert(shell != NULL);
  dict_destroy(shell->builtins);
  return (0);
}

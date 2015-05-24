/*
** cd.c for 42sh in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Sun May 24 06:30:09 2015 Brendan Rius
** Last update Sun May 24 07:59:48 2015 Brendan Rius
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include "env/env.h"
#include "error.h"

int		builtin_cd(size_t argc, char **argv)
{
  char		*dir;
  char		pwd[1024];
  char		oldpwd[1024];

  getcwd(oldpwd, 1023);
  if (argc <= 0)
    dir = my_getenv("HOME");
  else if (strcmp(argv[0], "-") == 0)
    dir = my_getenv("OLDPWD");
  else
    dir = argv[0];
  if (dir == NULL)
    return (-1);
  if (chdir(dir) != 0)
    my_perror();
  my_setenv("OLDPWD", oldpwd);
  my_setenv("PWD", getcwd(pwd, 1023));
  return (0);
}

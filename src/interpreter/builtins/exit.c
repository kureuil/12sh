/*
** exit.c for 42sh in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Sun May 24 08:42:08 2015 Louis Person
** Last update Sun May 24 08:54:38 2015 Louis Person
*/

#include "shell.h"

static int	my_getnbr(const char *str)
{
  int	sign;
  int	nb;
  int	c;

  sign = 1;
  nb = c = 0;
  while (str[c] == '+' || str[c] == '-')
    sign *= (str[c++]  == '-' ? -1 : 1);
  while (str[c] >= '0' && str[c] <= '9')
  {
    nb *= 10;
    nb += ((str[c] - '0') * sign);
    c++;
  }
  return (nb);
}

int			builtin_exit(size_t argc, char **argv)
{
  struct s_shell	*shell;

  shell = sh_get();
  if (argc == 0)
    {
      sh_exit(shell, 0);
    }
  else if (argc == 1)
    {
      sh_exit(shell, my_getnbr(argv[0]));
    }
  return (0);
}

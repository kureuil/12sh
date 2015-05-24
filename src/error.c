/*
** error.c for 42sh in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Wed Apr 22 10:38:59 2015 Brendan Rius
** Last update Sat May 23 20:53:05 2015 Louis Person
*/

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>
#include "error.h"

static void	my_error_msg(char *msg[])
{
  msg[E_CANNOTMALLOC] = "Cannot malloc\n";
  msg[E_CANNOTINITENV] = "Cannot init environment\n";
  msg[E_NOEXEC] = "%s is not executable or doesn't exist\n";
}

int		my_error(t_rcode code, ...)
{
  static char	*msg[_E_ERRORS];
  va_list	ap;

  if (msg[0] == NULL)
    my_error_msg(msg);
  va_start(ap, code);
  fprintf(stderr, "42sh: ");
  vfprintf(stderr, msg[code], ap);
  va_end(ap);
  return (-1);
}

void		my_perror(void)
{
  extern int	errno;

  fprintf(stderr, "%s: %s\n", "42sh", strerror(errno));
}

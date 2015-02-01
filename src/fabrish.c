/*
** fabrish.c for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Mon Jan 26 09:38:08 2015 Louis Person
** Last update Sun Feb  1 18:12:26 2015 Louis Person
*/

#define _GNU_SOURCE
#include <linux/limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include "my.h"
#include "eval.h"
#include "shell.h"
#include "prompt.h"

void		fabrish_exit(int sig)
{
  t_shell	*shell;

  if (sig != SIGQUIT && sig != SIGINT)
    return;
  shell = get_shell();
  if (shell->child != 0)
    kill(get_shell()->child, sig);
  shell_delete(get_shell());
  exit(0);
}

void	signals()
{
  signal(SIGQUIT, SIG_IGN);
  signal(SIGINT, SIG_IGN);
}

int		main()
{
  t_shell	*shell;
  char		*buffer;
  int		readb;
  int		retval;

  signals();
  if (shell_new(&shell) == -1)
    exit(1);
  if ((buffer = malloc(ARG_MAX + 1)) == NULL)
    exit(1);
  prompt_print(shell);
  while ((readb = read(0, buffer, ARG_MAX)) > 0)
    {
      buffer[readb] = 0;
      if (evalcmd(buffer, readb, shell) == QUIT)
	break;
      prompt_print(shell);
    }
  free(buffer);
  retval = (readb == 0 ? 0 : shell->status);
  shell_delete(shell);
  return (retval);
}

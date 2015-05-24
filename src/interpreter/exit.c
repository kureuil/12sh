/*
** exit.c<3> for 42sh in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Sun May 24 12:23:08 2015 Louis Person
** Last update Sun May 24 14:16:33 2015 Louis Person
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include "shell.h"

static char	*msg[32];

static void	get_sig_msg(char **msg)
{
  msg[SIGILL] = "Illegal Instruction";
  msg[SIGABRT] = "Aborted";
  msg[SIGFPE] = "Floating point exception";
  msg[SIGKILL] = "Killed";
  msg[SIGSEGV] = "Segmentation fault";
  msg[SIGTERM] = "Terminated";
  msg[SIGBUS] = "Bus Error";
}

int	report_exit_status(pid_t pid, int status, struct s_shell *shell)
{
  if (msg[SIGKILL] == NULL)
    get_sig_msg(msg);
  if (WIFEXITED(status))
    shell->returnvalue = WEXITSTATUS(status);
  else if (WIFSIGNALED(status))
    {
      if (msg[WTERMSIG(status)] != NULL)
	printf("[%d]%s\n", pid, msg[WTERMSIG(status)]);
      shell->returnvalue = 128 + WTERMSIG(status);
    }
  return (0);
}

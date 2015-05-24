/*
** init.c for 42sh in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Tue May 19 11:51:02 2015 Louis Person
** Last update Sun May 24 13:19:05 2015 Brendan Rius
*/

#include <assert.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "my/my.h"
#include "builtins.h"

struct s_shell	*g_shell = NULL;

static int	bi_create(struct s_builtin **builtinptr, bi_callback callback)
{
  *builtinptr = malloc(sizeof(struct s_builtin));
  if (*builtinptr == NULL)
    return (-1);
  (*builtinptr)->callback = callback;
  return (0);
}

static int		bi_register(struct s_shell *shell,
				    char *bin,
				    bi_callback callback)
{
  struct s_builtin	*builtin;

  if (bi_create(&builtin, callback) == -1)
    return (-1);
  if (dict_set(shell->builtins, bin, builtin) == -1)
    return (-1);
  return (0);
}

static void		register_builtins(struct s_shell *shell)
{
  bi_register(shell, "cd", &builtin_cd);
  bi_register(shell, "echo", &builtin_echo);
  bi_register(shell, "exit", &builtin_exit);
  bi_register(shell, "setenv", &builtin_setenv);
  bi_register(shell, "getenv", &builtin_getenv);
  bi_register(shell, "unsetenv", &builtin_unsetenv);
}

int	sh_init(struct s_shell *shell)
{
  assert(shell != NULL);
  shell->exit = false;
  shell->piped = false;
  shell->returnvalue = 0;
  shell->builtins = dict_new(llist_get_dict(), &free, NULL, &strcmp);
  if (shell->builtins == NULL)
    return (-1);
  shell->fd[0][0] = STDIN_FILENO;
  shell->fd[0][1] = -1;
  shell->fd[1][0] = -1;
  shell->fd[1][1] = STDOUT_FILENO;
  shell->fd[2][0] = -1;
  shell->fd[2][1] = STDERR_FILENO;
  shell->child = 0;
  g_shell = shell;
  register_builtins(shell);
  return (0);
}

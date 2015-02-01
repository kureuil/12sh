/*
** shell.c for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Mon Jan 26 09:48:27 2015 Louis Person
** Last update Sun Feb  1 18:37:58 2015 Louis Person
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"
#include "env.h"
#include "eval.h"
#include "shell.h"
#include "lexer.h"
#include "alias.h"
#include "builtins.h"

static t_shell	*g_shell = NULL;

int	shell_new(t_shell **shell)
{
  if (shell == NULL)
    return (-1);
  if ((*shell = malloc(sizeof(t_shell))) == NULL)
    return (-1);
  if (((*shell)->env = parse_env()) == NULL)
    return (-1);
  if (((*shell)->builtins = get_builtins()) == NULL)
    return (-1);
  if (((*shell)->alias = get_alias()) == NULL)
    return (-1);
  set_shell(*shell);
  (*shell)->prompt = "\\u(\\r)$> ";
  (*shell)->status = 0;
  (*shell)->child = 0;
  shell_config(".fabrishrc", *shell);
  return (0);
}

int	shell_delete(t_shell *shell)
{
  if (shell == NULL)
    return (-1);
  if (shell->env->size > 0)
    dict_free(shell->env, &free);
  else
    free(shell->env);
  if (shell->builtins->size > 0)
    dict_free(shell->builtins, &nofree);
  else
    free(shell->builtins);
  if (shell->alias->size > 0)
    dict_free(shell->alias, &nofree);
  else
    free(shell->alias);
  free(shell);
  return (0);
}

bool	set_shell(t_shell *shell)
{
  if (shell == NULL)
    return (false);
  g_shell = shell;
  return (true);
}

t_shell	*get_shell()
{
  return (g_shell);
}

void	shell_config(char *filename, t_shell *shell)
{
  char	*filepath;
  char	*file;
  char	*home;
  int	readb;
  int	fd;

  if ((home = dict_search(shell->env, "HOME")) == NULL)
    home = my_strdup(".");
  filepath = path(home, filename);
  if ((fd = open(filepath, O_RDONLY)) == -1)
    return;
  if ((file = malloc(1024 * 32)) == NULL)
    return;
  readb = my_read(fd, file, 1024 * 32 - 2);
  file[readb + 0] = '\n';
  file[readb + 1] = '\0';
  evalcmd(file, readb + 1, shell);
  close(fd);
  free(file);
}

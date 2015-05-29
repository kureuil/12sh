/*
** main.c for 42sh in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Sat May 23 17:44:00 2015 Louis Person
** Last update Sat May 30 00:45:47 2015 Louis Person
*/

#define _BSD_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "my/my.h"
#include "env/env.h"
#include "ast.h"
#include "shell.h"
#include "ui.h"
#include "expand.h"
#include "parser/parser.h"
#include "tokenizer/tokenizer.h"
#include "interpreter/interpreter.h"

static void	sig_send(int sig)
{
  struct s_shell	*shell;

  shell = sh_get();
  if (shell == NULL)
    return;
  if (isatty(STDIN_FILENO) && shell->child == 0)
    return;
  else if (!isatty(STDIN_FILENO))
    {
      if (shell->child != 0)
	kill(shell->child, sig);
      signal(sig, SIG_DFL);
      kill(getpid(), sig);
    }
  kill(shell->child, sig);
}

static char		*expand_cmd(char *line)
{
  int			i;
  struct s_string	str;
  ssize_t		shift;

  i = shift = 0;
  if (string_init(&str) != 0)
    return (NULL);
  while (line[i])
    {
      if (line[i] == '$')
	{
	  if ((shift = expand(line + i, &str)) == -1)
	    return (NULL);
	  i += shift;
	}
      else if (line[i] == '~')
	{
          if ((shift = tilde(line + i, &str)) == -1)
            return (NULL);
	  i += shift;
        }
      else if (string_push(&str, line[i++]) != 0)
	  return (NULL);
    }
  return (str._string);
}

static int		evalcmd(char *line, struct s_shell *shell)
{
  struct s_vec		tokens;
  struct s_btree	*tree;

  if ((line = expand_cmd(line)) == NULL)
    return (0);
  if (tokenize(line, &tokens) == -1)
    return (0);
  free(line);
  if (tokens.size == 0)
    return (0);
  if (parse(&tokens, &tree) == -1)
    return (vec_destroy(&tokens), 0);
  if (!is_ast_valid(tree))
    return (0);
  if (interpret(tree, shell) == -1)
    {
      vec_destroy(&tokens);
      btree_destroy(tree, &free_ast);
      return (0);
    }
  vec_destroy(&tokens);
  btree_destroy(tree, &free_ast);
  return (0);
}

static int		read_loop(struct s_shell *shell, t_dict *dict_key)
{
  char			*line;

  while (shell->exit == false)
    {
      if ((ui(dict_key, &line)) == EXIT_FAILURE)
	{
	  shell->returnvalue = EXIT_FAILURE;
	  shell->exit = true;
	  continue;
	}
      else if (line == NULL)
	{
	  shell->returnvalue = EXIT_SUCCESS;
	  shell->exit = true;
	  free(line);
	  continue;
	}
      if (evalcmd(line, shell) == -1)
	return (-1);
      free(line);
    }
  return (0);
}

int			main()
{
  int			ret;
  struct s_shell	shell;
  t_dict		*dict_key;

  init_env();
  ui_init(&dict_key);
  sh_init(&shell);
  signal(SIGTTOU, SIG_IGN);
  signal(SIGINT, &sig_send);
  signal(SIGTSTP, SIG_IGN);
  signal(SIGQUIT, &sig_send);
  if (read_loop(&shell, dict_key) == 0)
    ret = shell.returnvalue;
  else
    ret = EXIT_FAILURE;
  ui_destroy(dict_key);
  sh_destroy(&shell);
  destroy_env();
  return (ret);
}

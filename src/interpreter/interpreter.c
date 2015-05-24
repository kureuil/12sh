/*
** interpreter.c<2> for 42sh in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Tue Apr 21 18:04:38 2015 Louis Person
** Last update Sun May 24 19:41:37 2015 Louis Person
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <assert.h>
#include <stdlib.h>
#include "my/my.h"
#include "ast.h"
#include "shell.h"
#include "interpreter/interpreter.h"

/*
** @TESTABLE
*/

static void	get_interpreters(t_interpreter *interpreters)
{
  assert(interpreters != NULL);
  interpreters[TEMPTY] = &interpret_empty;
  interpreters[TPIPE] = &interpret_pipe;
  interpreters[TCMD] = &interpret_command;
  interpreters[TCOMPOSE] = &interpret_compose;
  interpreters[TORIF] = &interpret_orif;
  interpreters[TANDIF] = &interpret_andif;
}

int	command_supervisor(struct s_shell *shell, pid_t child)
{
  int		status;

  status = 0;
  waitpid(child, &status, 0);
  report_exit_status(child, status, shell);
  tcsetpgrp(STDIN_FILENO, getpgid(getpid()));
  shell->fd[0][0] = STDIN_FILENO;
  shell->fd[0][1] = -1;
  shell->fd[1][0] = -1;
  shell->fd[1][1] = STDOUT_FILENO;
  shell->fd[2][0] = -1;
  shell->fd[2][1] = STDERR_FILENO;
  return (0);
}

int			interpret(struct s_btree *head, struct s_shell *shell)
{
  t_interpreter		interpreters[_T_COUNT];
  struct s_ast_node	*node;

  assert(head != NULL);
  assert(shell != NULL);
  get_interpreters(interpreters);
  node = (struct s_ast_node *)head->data;
  interpreters[node->type](interpreters, shell, head);
  if (shell->child != 0)
    command_supervisor(shell, shell->child);
  return (0);
}

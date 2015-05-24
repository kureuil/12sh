/*
** dup.c for 42sh in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Sun May 24 18:59:34 2015 Louis Person
** Last update Sun May 24 22:47:23 2015 Louis Person
*/

#include <sys/stat.h>
#include <unistd.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "shell.h"
#include "ast.h"

static int	right_redir_setup(struct s_shell *shell,
				  struct s_ast_node_cmd *cmd)
{
  int		fd;

  (void) shell;
  fd = open(cmd->rredir,
	    O_WRONLY | O_CREAT |
	    (cmd->rtype == RT_RSIMPLE ? O_TRUNC : O_APPEND),
	    S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  if (fd == -1)
    return (-1);
  dup2(fd, STDOUT_FILENO);
  return (0);
}

static int	left_redir(struct s_shell *shell,
			   struct s_ast_node_cmd *cmd)
{
  int		fd;

  (void) shell;
  fd = open(cmd->lredir, O_RDONLY);
  if (fd == -1)
    return (-1);
  dup2(fd, STDIN_FILENO);
  return (0);
}

static int	dleft_redir(struct s_shell *shell,
			    struct s_ast_node_cmd *cmd)
{
  char		*line;
  int		pipefd[2];

  (void) shell;
  if (pipe(pipefd) == -1)
    return (-1);
  line = get_next_line(0);
  while (line != NULL)
    {
      write(pipefd[1], line, strlen(line));
      write(pipefd[1], "\n", 1);
      if (strcmp(line, cmd->lredir) == 0)
	break;
      line = get_next_line(0);
    }
  dup2(pipefd[0], STDIN_FILENO);
  close(pipefd[1]);
  return (0);
}

static int	tleft_redir(struct s_shell *shell,
			    struct s_ast_node_cmd *cmd)
{
  int		pipefd[2];

  if (pipe(pipefd) == -1)
    return (-1);
  shell->fd[0][0] = pipefd[0];
  shell->fd[0][1] = pipefd[1]; 
  dup2(shell->fd[0][0], STDIN_FILENO);
  write(pipefd[1], cmd->lredir, strlen(cmd->lredir));
  write(pipefd[1], "\n", 1);
  close(shell->fd[0][1]);
  return (0);
}

int		command_prepare(struct s_shell *shell,
				struct s_ast_node_cmd *cmd)
{
  if (shell->fd[0][0] != STDIN_FILENO)
    {
      dup2(shell->fd[0][0], STDIN_FILENO);
      close(shell->fd[0][1]);
    }
  else if (cmd->ltype != RT_LUNKNOWN)
    {
      if (cmd->ltype == RT_LSIMPLE)
	left_redir(shell, cmd);
      else if (cmd->ltype == RT_LDOUBLE)
	dleft_redir(shell, cmd);
      else
	tleft_redir(shell, cmd);
    }
  if (shell->fd[1][1] != STDOUT_FILENO)
    {
      dup2(shell->fd[1][1], STDOUT_FILENO);
      close(shell->fd[1][0]);
    }
  else if (cmd->rtype != RT_RUNKNOWN)
    {
      right_redir_setup(shell, cmd);
    }
  return (0);
}

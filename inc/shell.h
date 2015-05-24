/*
** shell.h for 42sh in /home/person_l/rendu/42sh/tests/interpreter
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Tue May  5 18:08:06 2015 Louis Person
** Last update Sun May 24 08:54:10 2015 Louis Person
*/

#ifndef SHELL_H_
# define SHELL_H_

# include <sys/types.h>
# include <stdbool.h>

# define MAX_PIPE	16

struct s_dict;

extern struct s_shell *g_shell;

struct s_shell
{
  bool		exit;
  int		returnvalue;
  int		fd[3][2];
  struct s_dict	*builtins;
  bool		piped;
  pid_t		child;
};

/*
** Initializes shell structure.
*/
int	sh_init(struct s_shell *shell);

/*
** Tells the shell to exit.
*/
int	sh_exit(struct s_shell *shell, int code);

/*
** Tells the shell to set the return value to code.
*/
int	sh_return(struct s_shell *shell, int code);

/*
** Destroys a shell structure.
*/
int	sh_destroy(struct s_shell *shell);

/*
** Retrieves a shell structure.
*/
struct s_shell	*sh_get(void);

#endif /* !SHELL_H_ */

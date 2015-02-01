/*
** shell.h for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Mon Jan 26 09:52:55 2015 Louis Person
** Last update Sun Feb  1 17:13:44 2015 Louis Person
*/

#ifndef SHELL_H_
# define SHELL_H_

# include <stdbool.h>
# include <sys/types.h>

typedef struct	s_shell
{
  struct s_dict	*env;
  struct s_dict	*builtins;
  struct s_dict	*alias;
  char		*prompt;
  int		status;
  pid_t		child;
}		t_shell;

int	shell_new(t_shell **);
int	shell_delete(t_shell *);
bool	set_shell(t_shell *);
t_shell	*get_shell();
void	shell_config(char *, t_shell *);

#endif /* !SHELL_H_ */

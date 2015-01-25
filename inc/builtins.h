/*
** builtins.h for minishell1 in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Fri Jan 23 18:23:21 2015 Louis Person
** Last update Sun Jan 25 22:44:15 2015 Louis Person
*/

#ifndef BUILTINS_H_
# define BUILTINS_H_

# include "my/error.h"

struct s_dict;
struct s_darray;

struct s_dict	*get_builtins();
void		register_builtins(struct s_dict *);

t_error		exit_builtin(struct s_darray *, struct s_dict *);
t_error		env_builtin(struct s_darray *, struct s_dict *);
t_error		setenv_builtin(struct s_darray *, struct s_dict *);
t_error		unsetenv_builtin(struct s_darray *, struct s_dict *);
t_error		getenv_builtin(struct s_darray *, struct s_dict *);
t_error		cd_builtin(struct s_darray *, struct s_dict *);

#endif /* !BUILTINS_H_ */

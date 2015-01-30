/*
** builtins.h for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Thu Jan 29 15:49:08 2015 Louis Person
** Last update Thu Jan 29 20:48:57 2015 Louis Person
*/

#ifndef BUILTINS_H_
# define BUILTINS_H_

# include "my/error.h"

struct s_darray;
struct s_shell;
struct s_dict;

typedef t_error (*t_builtin)(struct s_darray *, struct s_shell *);

struct s_dict	*get_builtins();

t_error	builtin_cd(struct s_darray *, struct s_shell *);
t_error	builtin_exit(struct s_darray *, struct s_shell *);
t_error	builtin_env(struct s_darray *, struct s_shell *);
t_error	builtin_setenv(struct s_darray *, struct s_shell *);
t_error	builtin_unsetenv(struct s_darray *, struct s_shell *);
t_error	builtin_getenv(struct s_darray *, struct s_shell *);

#endif /* !BUILTINS_H_ */

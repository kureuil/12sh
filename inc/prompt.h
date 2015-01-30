/*
** prompt.h for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Thu Jan 29 21:49:00 2015 Louis Person
** Last update Fri Jan 30 12:00:06 2015 Louis Person
*/

#ifndef PROMPT_H_
# define PROMPT_H_

# include "my/error.h"

struct s_shell;

typedef t_error (*t_conversion)(int, struct s_shell *);

void	prompt_print(struct s_shell *);

t_error	prompt_user(int, struct s_shell *);
t_error	prompt_backslash(int, struct s_shell *);
t_error	prompt_return(int, struct s_shell *);

#endif /* !PROMPT_H_ */

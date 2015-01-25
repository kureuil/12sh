/*
** command.h for minishell1 in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Thu Jan 22 00:25:16 2015 Louis Person
** Last update Fri Jan 23 18:34:15 2015 Louis Person
*/

#ifndef COMMAND_H_
# define COMMAND_H_

# include "my/error.h"

struct s_darray;
struct s_dict;

t_error	launch_command(char *, struct s_darray *, struct s_dict *);
t_error	handle_command(struct s_darray *, struct s_dict *, struct s_dict *);

#endif /* !COMMAND_H_ */

/*
** eval.h for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Mon Jan 26 16:57:08 2015 Louis Person
** Last update Wed Jan 28 10:38:28 2015 Louis Person
*/

#ifndef EVAL_H_
# define EVAL_H_

# include "my/error.h"

struct s_tree;
struct s_shell;

t_error	evalcmd(char *, int, struct s_shell *);

#endif /* !EVAL_H_ */

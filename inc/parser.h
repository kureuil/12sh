/*
** parser.h for fabrish in /home/person_l/rendu/minishell1/fabrish
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Wed Jan 28 11:50:56 2015 Louis Person
** Last update Fri Jan 30 10:48:20 2015 Louis Person
*/

#ifndef PARSER_H_
# define PARSER_H_

# include "my/error.h"

struct s_tree;
struct s_queue;

typedef t_error (*t_parser)(struct s_queue *, struct s_tree *);

t_error	parse(struct s_queue *, struct s_tree *);

t_error	parse_undefined(struct s_queue *, struct s_tree *);
t_error	parse_string(struct s_queue *, struct s_tree *);
t_error	parse_call(struct s_queue *, struct s_tree *);
t_error	parse_or(struct s_queue *, struct s_tree *);
t_error	parse_and(struct s_queue *, struct s_tree *);
t_error	parse_eoc(struct s_queue *, struct s_tree *);
t_error	parse_eof(struct s_queue *, struct s_tree *);
t_error	parse_sof(struct s_queue *, struct s_tree *);
t_error	parse_lparenthesis(struct s_queue *, struct s_tree *);
t_error	parse_rparenthesis(struct s_queue *, struct s_tree *);

#endif /* !PARSER_H_ */

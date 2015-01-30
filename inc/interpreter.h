/*
** interpreter.h for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Wed Jan 28 21:49:44 2015 Louis Person
** Last update Thu Jan 29 21:28:12 2015 Louis Person
*/

#ifndef INTERPRETER_H_
# define INTERPRETER_H_

# include "my/error.h"

struct s_tree;
struct s_token;
struct s_shell;

typedef t_error	(*t_behavior)(struct s_token *,
			      struct s_shell *,
			      struct s_tree *);

t_error		interpret(struct s_tree *, struct s_shell *);
t_error		process(struct s_token *,
			t_behavior *,
			struct s_shell *,
			struct s_tree *);
t_behavior	*get_behaviors();

t_error		behavior_sleep(struct s_token *, struct s_shell *, struct s_tree *);
t_error		behavior_call(struct s_token *, struct s_shell *, struct s_tree *);
t_error		behavior_and(struct s_token *, struct s_shell *, struct s_tree *);
t_error		behavior_or(struct s_token *, struct s_shell *, struct s_tree *);

#endif /* !INTERPRETER_H_ */

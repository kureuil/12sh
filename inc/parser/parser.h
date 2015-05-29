/*
** parser.h for 42sh in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Tue Apr 28 15:24:01 2015 Brendan Rius
** Last update Fri May 29 23:56:49 2015 Louis Person
*/

#ifndef PARSER_H_
# define PARSER_H_

struct s_iterator;
struct s_btree;
struct s_vec;

/*
** Parse a queue of tokens and make "btree" points to an AST
*/
int	parse(struct s_vec *tokens, struct s_btree **btree);

int	parse_exp_complete(struct s_iterator *i_tokens,
			   struct s_btree *node);

int	parse_exp_simple(struct s_iterator *i_tokens,
			 struct s_btree *node);

int	parse_exp_complete_l1(struct s_iterator *i,
			      struct s_btree *parent);

int	parse_exp_complete_l2(struct s_iterator *i,
			      struct s_btree *parent);

int	parse_exp_redir(struct s_iterator *i,
			struct s_btree *node);

int	parse_exp_rredir(struct s_iterator *i,
			 struct s_btree *node);

int	parse_exp_drredir(struct s_iterator *i,
			  struct s_btree *node);

int	parse_exp_lredir(struct s_iterator *i,
			 struct s_btree *node);

int	parse_exp_dlredir(struct s_iterator *i,
			  struct s_btree *node);

int	parse_exp_tlredir(struct s_iterator *i,
			  struct s_btree *node);

#endif /* !PARSER_H_ */

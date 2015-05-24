/*
** regex.h for 42sh in /home/brendan/rendu/42sh/src/regex
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Sat Apr 25 18:01:22 2015 Brendan Rius
** Last update Sat Apr 25 18:56:01 2015 Brendan Rius
*/

#ifndef REGEX_H_
# define REGEX_H_

# include <stdbool.h>

# define CONCAT_CHAR	37
# define PUSH(s, x)	(*(s)++ = (x))
# define POP(s)		(*--s)

typedef struct s_state	t_regex;

union			u_nodelist
{
  union u_nodelist	*next;
  struct s_state	*s;
};

struct			s_state
{
  int			c;
  struct s_state	*out1;
  struct s_state	*out2;
  unsigned int		lastlist;
};

struct			s_nfa_frag
{
  struct s_state	*start;
  union u_nodelist	*out;
};

struct			s_list
{
  struct s_state	**s;
  unsigned int		n;
};

enum
{
  MATCH = 256,
  SPLIT = 257
};

struct s_state	*state_new(int c,
			   struct s_state *out,
			   struct s_state *out1);

struct s_nfa_frag	frag_new(struct s_state *start,
				 union u_nodelist *out);

union u_nodelist	*list1(struct s_state **outp);

void			patch(union u_nodelist *l,
			      struct s_state *s);

union u_nodelist	*append(union u_nodelist *l1,
				union u_nodelist *l2);

struct s_state		*postfix2nfa(const char *postfix);

struct s_list	*startlist(struct s_state *start,
			   struct s_list *l);

bool		ismatch(struct s_list *l);

void	addstate(struct s_list *l,
		 struct s_state *s);

void			step(struct s_list *clist,
			     int c,
			     struct s_list *nlist);

bool	regex_match(t_regex *start, const char *s);

t_regex	*regex_compile(const char *s);

char	*regex2postfix(const char *re);

#endif /* !REGEX_H_ */

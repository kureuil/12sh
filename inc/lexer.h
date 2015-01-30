/*
** lexer.h for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Tue Jan 27 10:15:37 2015 Louis Person
** Last update Fri Jan 30 10:16:34 2015 Louis Person
*/

#ifndef LEXER_H_
# define LEXER_H_

# include "my/error.h"

struct s_darray;
struct s_queue;

typedef enum	e_ttype
{
  T_UNDEFINED,
  T_STRING,
  T_CALL,
  T_LREDIR,
  T_RREDIR,
  T_DRREDIR,
  T_DLREDIR,
  T_AND,
  T_OR,
  T_EOC,
  T_EOF,
  T_SOF,
  T_LPARENTHESIS,
  T_RPARENTHESIS,
  TOKEN_TYPES
}		t_ttype;

typedef struct	s_token
{
  t_ttype	type;
  void		*value;
}		t_token;

struct s_queue	*tokenize(char *, int);
t_error		interpret();
int		lexicon(struct s_darray **);

int		token_new(t_token **);
void		token_delete(void *);
struct s_tree	*token_root();

void		nofree(void *);

#endif /* !LEXER_H_ */

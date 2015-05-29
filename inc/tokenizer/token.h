/*
** token.h for 42sh in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Wed Apr 22 10:30:34 2015 Brendan Rius
** Last update Fri May 29 23:57:54 2015 Louis Person
*/

#ifndef TOKEN_H_
# define TOKEN_H_

# include <sys/types.h>
# include "my/str.h"

/*
** Define the different types of a token.
*/
enum	e_token_type
  {
    TT_PIPE,		/* a pipe (|) */
    TT_STRING,		/* a string (ab, 'ab', "ab", "a""b") */
    TT_SEMICOLON,	/* a semicolon (;) */
    TT_ORIF,		/* a or-if (||) */
    TT_ANDIF,		/* a and-if (&&) */
    TT_RREDIR,		/* a right redirection (>) */
    TT_LREDIR,		/* a left redirection (<) */
    TT_DRREDIR,		/* a double right redirection (>>) */
    TT_DLREDIR,		/* a double left redirection (<<) */
    TT_TLREDIR		/* a triple left redirection (<<<) */
  };

/*
** Represent a token
*/
struct			s_token
{
  enum e_token_type	type;	/* the type of the token */
  struct s_string	string;	/* the value of the token */
};

/*
** Create DYNAMICALLY a new token. Returns 0 on success.
*/
int	token_new(struct s_token **token_ptr);

/*
** Init a token. Returns 0 on success.
*/
int	token_init(struct s_token *token);

/*
** Free a token
*/
void	token_free(struct s_token *token);

#endif /* !TOKEN_H_ */

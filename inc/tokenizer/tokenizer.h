/*
** tokenizer.h for 42sh in /home/brendan/rendu/42sh/modules/tokenizer/src
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Apr 20 16:32:11 2015 Brendan Rius
** Last update Sun May  3 15:25:53 2015 Brendan Rius
*/

#ifndef TOKENIZER_H_
# define TOKENIZER_H_

# include <sys/types.h>

struct s_token;
struct s_vec;
struct s_string;

/*
** Tokenize the string "string" and stores the tokens in "queue".
** This function returns either the number of tokens, or -1
** on error.
*/
ssize_t	tokenize(const char *string, struct s_vec *queue);

/*
** This function eplaces two-chars strings such as
** [\, a] by single characters such as '\a'.
** This filter has to be applied when first before
** the tokenizing process and after the double quoted
** string expand
*/
int	special_char_filter(struct s_string *s);

/*
** ===============
** TOKENS
** ===============
** A token matcher tries to match "s" a greedy way (e.g it
** tries to find the biggest token it can find beginning
** at s) and fills "t" when a token if found.
** If there is an error while trying to match (for example
** strndup may fail to allocate space), the function returns
** -1. On success, this method will return the number of chars
** read to create the token.
*/

typedef ssize_t (*t_token_parser)(const char *, struct s_token *);

/*
** Parses TT_STRING
*/
ssize_t	parse_token_string(const char *s, struct s_token *t);

/*
** Parses TT_PIPE
*/
ssize_t	parse_token_pipe(const char *s, struct s_token *t);

/*
** Parses TT_RREDIR
*/
ssize_t	parse_token_rredir(const char *s, struct s_token *t);

/*
** Parses TT_LREDIR
*/
ssize_t	parse_token_lredir(const char *s, struct s_token *t);

/*
** Parses TT_DRREDIR
*/
ssize_t	parse_token_drredir(const char *s, struct s_token *t);

/*
** Parses TT_DLREDIR
*/
ssize_t	parse_token_dlredir(const char *s, struct s_token *t);

/*
** Parses TT_TLREDIR
*/
ssize_t	parse_token_tlredir(const char *s, struct s_token *t);

/*
** Parses TT_ANDIF
*/
ssize_t	parse_token_andif(const char *s, struct s_token *t);

/*
** Parses TT_ORIF
*/
ssize_t	parse_token_orif(const char *s, struct s_token *t);

/*
** Parses TT_SEMICOLON
*/
ssize_t	parse_token_semicolon(const char *s, struct s_token *t);

#endif /* !TOKENIZER_H_ */

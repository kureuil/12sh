/*
** mock.h for 42sh in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Apr 23 12:53:56 2015 Brendan Rius
** Last update Thu May 14 21:46:08 2015 Antoine Ouvrans
*/

#ifndef MOCK_H_
# define MOCK_H_
# ifdef MOCK_MODE

#  ifdef MOCK_MALLOC
#   include <sys/types.h>
extern void	*my_mock_malloc(size_t);
#   define malloc(x)	(my_mock_malloc(x))
#  endif

#  ifdef MOCK_STRDUP
extern char	*my_mock_strdup(const char *);
#   define strdup(x)	(my_mock_strdup(x))
#  endif

#  ifdef MOCK_TOKEN_NEW
struct s_token;
extern int	my_mock_token_new(struct s_token **);
#   define token_new(x)	(my_mock_token_new(x))
#  endif

#  ifdef MOCK_STRING_PUSH
struct s_string;
extern int	my_mock_string_push(struct s_string *string, char c);
#   define string_push(s, c) my_mock_string_push(s, c)
#  endif
# endif /* MOCK_MODE */
#endif /* !MOCK_H_ */

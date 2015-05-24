/*
** mocks.h for 42sh in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Apr 23 16:13:09 2015 Brendan Rius
** Last update Thu May 14 22:06:21 2015 Antoine Ouvrans
*/

#ifndef MOCKS_H_
# define MOCKS_H_

void	set_mock_malloc(void *(*f)(size_t));
void	*my_mock_malloc_null(size_t);
void	*my_mock_malloc_nb(size_t n);
void	set_malloc_fail_at(int n);

struct s_token;
void	set_mock_token_new(int (*f)(struct s_token **));
int	my_mock_token_new_fail(struct s_token **);

void	set_mock_strdup(char *(*f)(const char *));
char	*my_mock_strdup_null(const char *);

struct s_string;
void	set_mock_string_push(int (*f)(struct s_string *, char));
int	my_mock_string_push_fail(struct s_string *string, char c);
int	my_mock_string_push_fail_at(struct s_string *string, char c);
int	set_stringpush_fail_at(int n);

#endif /* !MOCKS_H_ */

/*
** string_push.c for 42sh in /home/ouvran_a/Documents/rendu/42sh/tests/mocks
** 
** Made by Antoine Ouvrans
** Login   <ouvran_a@epitech.net>
** 
** Started on  Thu May 14 21:44:09 2015 Antoine Ouvrans
** Last update Thu May 14 22:07:03 2015 Antoine Ouvrans
*/

#include "my/my.h"

static int	(*mock_string_push)(struct s_string *, char) = &string_push;
static int	string_push_fail_at;
int	my_mock_string_push(struct s_string *string, char c)
{
  return (mock_string_push(string, c));
}

int	my_mock_string_push_fail(struct s_string *string, char c)
{
  (void) string;
  (void) c;
  return (-1);
}

int	my_mock_string_push_fail_at(struct s_string *string, char c)
{
  if (string_push_fail_at <= 0)
    return (-1);
  string_push_fail_at--;
  return (string_push(string, c));
}

void	set_mock_string_push(int (*f)(struct s_string *, char))
{
  mock_string_push = f;
}

void    set_stringpush_fail_at(int n)
{
  string_push_fail_at = n;
}

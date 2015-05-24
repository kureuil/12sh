/*
** strdup.c for 42sh in /home/brendan/rendu/42sh/tests/mocks
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Fri May  1 20:02:15 2015 Brendan Rius
** Last update Sun May 24 01:57:00 2015 Brendan Rius
*/

#include <string.h>
#include <stdlib.h>

static char	*(*mock_strdup)(const char *) = &strdup;

char	*my_mock_strdup(const char *s)
{
  return (mock_strdup(s));
}

char	*my_mock_strdup_null(const char *s)
{
  (void) s;
  return (NULL);
}

void	set_mock_strdup(char *(*f)(const char *))
{
  mock_strdup = f;
}

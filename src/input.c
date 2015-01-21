/*
** input.c for minishell1 in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Thu Jan 22 00:28:29 2015 Louis Person
** Last update Thu Jan 22 00:28:48 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"

t_darray	*parse_input(char *line, int len)
{
  t_darray	*command;
  char		*token;

  command = create_dynamo(NULL);
  if (command == NULL)
    return (NULL);
  if (line[len - 1] == '\n')
    line[len - 1] = '\0';
  else
    line[len] = '\0';
  while ((token = my_strsep(&line, " ")) != NULL)
    command->add(command, token);
  return (command);
}

/*
** env.h for minishell1 in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Wed Jan 21 23:15:53 2015 Louis Person
** Last update Sun Jan 25 20:39:56 2015 Louis Person
*/

#ifndef ENV_H_
# define ENV_H_

struct s_dict;

struct s_dict	*parse_env();
char		*serialize_env(char *, char *);

#endif /* !ENV_H_ */

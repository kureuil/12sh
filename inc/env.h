/*
** env.h for minishell1 in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Wed Jan 21 23:15:53 2015 Louis Person
** Last update Thu Jan 22 00:17:47 2015 Louis Person
*/

#ifndef ENV_H_
# define ENV_H_

struct s_dict;

struct s_dict	*parse_env();
void		puts_env(void *);

#endif /* !ENV_H_ */

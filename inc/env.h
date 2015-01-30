/*
** env.h for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Wed Jan 28 10:25:06 2015 Louis Person
** Last update Thu Jan 29 12:06:50 2015 Louis Person
*/

#ifndef ENV_H_
# define ENV_H_

struct s_dict;

struct s_dict	*parse_env();
char		*serialize_env(char *, char *);
void		free_env(char **);

#endif /* !ENV_H_ */

/*
** path.h for minishell1 in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Thu Jan 22 00:21:01 2015 Louis Person
** Last update Sun Jan 25 23:52:32 2015 Louis Person
*/

#ifndef PATH_H_
# define PATH_H_

struct s_dict;

char	*path(char *, char *);
void	update_wd(struct s_dict *, char *);

#endif /* !PATH_H_ */

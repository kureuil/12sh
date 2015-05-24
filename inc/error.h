/*
** error.h for 42sh in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Wed Apr 22 10:38:18 2015 Brendan Rius
** Last update Sat May 23 20:49:38 2015 Louis Person
*/

#ifndef ERROR_H_
# define ERROR_H_

typedef enum	e_rcode
{
  E_CANNOTMALLOC,
  E_CANNOTINITENV,
  E_NOEXEC,
  _E_ERRORS
}		t_rcode;

int		my_error(t_rcode code, ...);

void		my_perror(void);

#endif /* !ERROR_H_ */

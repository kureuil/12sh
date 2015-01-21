/*
** dynamo.h for libmy in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Wed Nov 26 22:43:52 2014 Louis Person
** Last update Sun Jan 11 06:52:09 2015 Louis Person
*/

#ifndef MY_DYNAMO_H_
# define MY_DYNAMO_H_

typedef struct	s_darray
{
  void		**data;
  int		total_size;
  int		current_size;
  int		(*add)(struct s_darray *, void *);
  int		(*free)(void *);
}		t_darray;

t_darray	*create_dynamo(int (*)(void *));
int		free_dynamo(t_darray *);
int		add_item_to_dynamo(t_darray *, void *);
int		free_item_from_dynamo(void *);
t_error		dynamo_map(t_darray *, int (*)(void *));

#endif /* !MY_DYNAMO_H_ */

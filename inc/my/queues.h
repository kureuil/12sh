/*
** queues.h for libmy in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Wed Jan 28 12:59:02 2015 Louis Person
** Last update Wed Jan 28 13:40:16 2015 Louis Person
*/

#ifndef MY_QUEUES_H_
# define MY_QUEUES_H_

# include <stdbool.h>

typedef struct	s_node
{
  void		*data;
  struct s_node	*prev;
  struct s_node	*next;
}		t_node;

typedef struct	s_queue
{
  t_node	*first;
  t_node	*last;
  int		size;
  void		(*free)();
  void		*(*peek)(struct s_queue *);
  void		*(*pop)(struct s_queue *);
  bool		(*add)(struct s_queue *, void *);
}		t_queue;

t_error	queue_new(t_queue **, void (*)());
t_error	queue_delete(t_queue *);
void	*queue_peek(t_queue *);
void	*queue_pop(t_queue *);
bool	queue_add(t_queue *, void *);

#endif /* !MY_QUEUES_H_ */

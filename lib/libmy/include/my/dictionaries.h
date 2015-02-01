/*
** dictionaries.h for libmy in /home/person_l
**
** Made by Louis Person
** Login   <person_l@epitech.eu>
**
** Started on  Sun Dec  28 15:27:31 2014 Louis Person
** Last update Sun Jan 25 20:04:31 2015 Louis Person
*/

#ifndef MY_DICTIONARIES_H_
# define MY_DICTIONARIES_H_

struct s_tree;
struct s_darray;

typedef struct	s_bucket
{
  char		*key;
  void		*data;
}		t_bucket;

typedef struct	s_dict
{
  struct s_tree	*root;
  int		size;
}		t_dict;

int	dict_new(t_dict **);
int	dict_set(t_dict *, char*, void *);
void	*dict_search(t_dict *, char *);
int	dict_delete(t_dict *, char *, void (*)(void *));
int	dict_free(t_dict *, void (*)(void *));
int	dict_buckcmp(t_bucket *, t_bucket *);
int	dict_buck_keycmp(t_bucket *, char *);
void	dict_buck_free(t_bucket *);
int	dict_free_tree(t_tree *, void (*)(void *));
char	**dict_serialize(t_dict *, char *(*)(char *, char *));
void	dict_serialize_bucket(struct s_tree *,
			      struct s_darray *,
			      char *(*)(char *, char *));

#endif /* !MY_DICTIONARIES_H_*/

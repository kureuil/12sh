/*
** my.h for my in /home/person_l/projets/libmy/include
**
** Made by Louis Person
** Login   <person_l@epitech.net>
**
** Started on  Thu Oct  9 18:14:32 2014 Louis Person
** Last update Sun Feb  1 13:17:00 2015 Louis Person
*/

#ifndef MY_H_
# define MY_H_

# include <stdbool.h>
# include "my/error.h"
# include "my/strings.h"
# include "my/dynamo.h"
# include "my/queues.h"
# include "my/trees.h"
# include "my/dictionaries.h"
# include "my/chalk.h"

# define GNL_BUFFER 40000

int	my_getnbr_base(const char *, const char *);
int	my_getnbr(const char *);
int	my_isneg(int);
int	my_pow(const int, const int);
int	my_putchar(char);
int	my_putstr(const char *);
int	my_dputstr(int, const char *);
int	my_dputchar(int, char);
int	my_putnbr_base(int, char *);
int	my_put_nbr(int);
int	my_putnbr(int);
int	my_dputnbr_base(int, int, char *);
int	my_dput_nbr(int, int);
int	my_dput_ulnbr(int, unsigned long);
void	my_sort_int_tab(int *, int);
int	my_square_root(int);
void	my_swap(int *, int *);
char	**my_str_to_wordtab(char *);
int	my_show_wordtab(char **);
int	my_is_in(const char *, const char);
int	get_nbr_len(int);
int	index_of(const char, const char *);
char	*get_next_line(int);
char	*my_getenv(char **, const char *);
int	my_read(int, char *, int);
void	*my_memcpy(void *, void *, int);
char	*path(char *, char *);
int	copy(int, int);
t_error	check_existence(char *);

#endif /* !MY_H_ */

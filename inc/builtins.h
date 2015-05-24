/*
** builtins.h for 42sh in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Sun May 24 06:42:03 2015 Louis Person
** Last update Sun May 24 13:17:13 2015 Brendan Rius
*/

#ifndef BUILTINS_H_
# define BUILTINS_H_

# include <sys/types.h>

typedef int (*bi_callback)(size_t argc, char **argv);

struct		s_builtin
{
  bi_callback	callback;
};

int	builtin_cd(size_t argc, char **argv);

int	builtin_echo(size_t argc, char **argv);

int	builtin_exit(size_t argc, char **argv);

int	builtin_setenv(size_t argc, char **argv);

int	builtin_getenv(size_t argc, char **argv);

int	builtin_unsetenv(size_t argc, char **args);

#endif /* !BUILTINS_H_ */

/*
** expand.h for 42sh in /home/ouvran_a/Documents/rendu/42sh
** 
** Made by Antoine Ouvrans
** Login   <ouvran_a@epitech.net>
** 
** Started on  Sat May 23 18:06:16 2015 Antoine Ouvrans
** Last update Sun May 24 18:53:38 2015 Antoine Ouvrans
*/

#ifndef EXPAND_H_
# define EXPAND_H_

#include "my/my.h"

/*
** Expand function appends environnement variable to string
*/

ssize_t           expand(const char *str, struct s_string *variable);

/*
** Tilde function appends HOME to string
*/

ssize_t           tilde(const char *str, struct s_string *string);

#endif

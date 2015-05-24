/*
** mctype.h for 42Sh in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Wed Apr 22 09:57:07 2015 Brendan Rius
** Last update Sun May  3 15:08:22 2015 Brendan Rius
*/

#ifndef MCTYPE_H_
# define MCTYPE_H_

# define IS_LOWER(c)	((c) >= 'a' && (c) <= 'z')
# define IS_UPPER(c)	((c) >= 'A' && (c) <= 'Z')
# define IS_ALPHA(c)	(IS_LOWER(c) || IS_UPPER(c))
# define IS_DIGIT(c)	((c) >= '0' && (c) <= '9')
# define IS_ALNUM(c)	(IS_ALPHA(c) || IS_DIGIT(c))
# define IS_BLANK(c)	((c) == ' ' || (c) == '\t')
# define IS_GRAPH(c)	((c) >= '!' && (c) <= '~')
# define IS_PRINT(c)	(IS_GRAPH(c) || (c) == ' ')

#endif /* !MCTYPE_H_ */

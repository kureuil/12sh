/*
** lexicon.h for fabrish in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Tue Jan 27 14:36:37 2015 Louis Person
** Last update Fri Jan 30 10:21:12 2015 Louis Person
*/

#ifndef LEXICON_H_
# define LEXICON_H_

struct s_token;

struct s_token	*grammar_eof(char **);
struct s_token	*grammar_eoc(char **);
struct s_token	*grammar_and(char **);
struct s_token	*grammar_or(char **);
struct s_token	*grammar_lparenthesis(char **);
struct s_token	*grammar_rparenthesis(char **);
struct s_token	*grammar_call(char **);

#endif /* !LEXICON_H_ */

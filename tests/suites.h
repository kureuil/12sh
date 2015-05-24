/*
** suites.h for 42sh in /home/brendan/rendu/42sh/tests/tokenizer/tokens
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Apr 23 15:29:00 2015 Brendan Rius
** Last update Sun May  3 16:13:30 2015 Louis Person
*/

#ifndef SUITES_H_
# define SUITES_H_

# include <check.h>

Suite	*tokenizer_suite();

Suite	*token_suite();

Suite	*env_suite();

Suite	*token_parser_semicolon_suite();

Suite	*token_parser_pipe_suite();

Suite	*token_parser_orif_suite();

Suite	*token_parser_rredir_suite();
Suite	*token_parser_drredir_suite();

Suite	*token_parser_lredir_suite();
Suite	*token_parser_dlredir_suite();
Suite	*token_parser_tlredir_suite();

Suite	*token_parser_andif_suite();

Suite	*token_parser_string_suite();

Suite	*parser_suite();

Suite	*interpreter_suite();

#endif /* !SUITES_H_ */

/*
** parser.c for 42sh in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Tue Apr 28 15:34:02 2015 Brendan Rius
** Last update Sat May 23 00:21:20 2015 Louis Person
*/

#include <check.h>
#include "tokenizer/tokenizer.h"
#include "tokenizer/token.h"
#include "parser/parser.h"
#include "my/my.h"

START_TEST (test_parser)
{
  struct s_vec		tokens;
  struct s_btree	*tree;

  tokenize("echo -n hello world | cat ; ls -alHi || echo lol && cat out", &tokens);
  parse(&tokens, &tree);
}
END_TEST

/*
** ============
** SETUP
** ============
*/
Suite	*parser_suite()
{
  Suite	*s;
  TCase	*tc_assertions;
  TCase	*tc_core;

  s = suite_create("Parser");

  tc_assertions = tcase_create("Assertions");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_parser);

  suite_add_tcase(s, tc_assertions);
  suite_add_tcase(s, tc_core);

  return (s);
}

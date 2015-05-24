/*
** tokenizer.c for 42sh in /home/brendan/rendu/42sh/tests/tokenizer
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Fri May  1 19:33:10 2015 Brendan Rius
** Last update Sun May 24 14:08:06 2015 Brendan Rius
*/

#include <check.h>
#include <signal.h>
#include "tokenizer/tokenizer.h"
#include "tokenizer/token.h"
#include "my/my.h"

START_TEST (test_tokenize_complex)
{
  const char		*s = "ls -alhi | cat";
  struct s_vec		vec;
  struct s_token	*t;

  vec_init(&vec, 0, NULL);
  tokenize(s, &vec);

  vec_pop(&vec, (void **) &t);
  ck_assert_int_eq(t->type, TT_STRING);
  ck_assert_int_eq(t->string.len, 3);
  ck_assert_str_eq(t->string._string, "cat");

  vec_pop(&vec, (void **) &t);
  ck_assert_int_eq(t->type, TT_PIPE);
  ck_assert_int_eq(t->string.len, 1);
  ck_assert_str_eq(t->string._string, "|");

  vec_pop(&vec, (void **) &t);
  ck_assert_int_eq(t->type, TT_STRING);
  ck_assert_int_eq(t->string.len, 5);
  ck_assert_str_eq(t->string._string, "-alhi");

  vec_pop(&vec, (void **) &t);
  ck_assert_int_eq(t->type, TT_STRING);
  ck_assert_int_eq(t->string.len, 2);
  ck_assert_str_eq(t->string._string, "ls");
}
END_TEST


START_TEST (test_tokenize_complex2)
{
  const char		*s = "echo hello world && ls";
  struct s_vec		vec;
  struct s_token	*t;

  vec_init(&vec, 0, NULL);
  tokenize(s, &vec);

  vec_pop(&vec, (void **) &t);
  ck_assert_int_eq(t->type, TT_STRING);
  ck_assert_int_eq(t->string.len, 2);
  ck_assert_str_eq(t->string._string, "ls");

  vec_pop(&vec, (void **) &t);
  ck_assert_int_eq(t->type, TT_ANDIF);
  ck_assert_int_eq(t->string.len, 2);
  ck_assert_str_eq(t->string._string, "&&");

  vec_pop(&vec, (void **) &t);
  ck_assert_int_eq(t->type, TT_STRING);
  ck_assert_int_eq(t->string.len, 5);
  ck_assert_str_eq(t->string._string, "world");

  vec_pop(&vec, (void **) &t);
  ck_assert_int_eq(t->type, TT_STRING);
  ck_assert_int_eq(t->string.len, 5);
  ck_assert_str_eq(t->string._string, "hello");

  vec_pop(&vec, (void **) &t);
  ck_assert_int_eq(t->type, TT_STRING);
  ck_assert_int_eq(t->string.len, 4);
  ck_assert_str_eq(t->string._string, "echo");
}
END_TEST

START_TEST (test_tokenizer_null_string)
{
  struct s_vec tq;

  tokenize(NULL, &tq);
}
END_TEST

START_TEST (test_tokenizer_null_token_queue)
{
  tokenize("hello", NULL);
}
END_TEST

Suite	*tokenizer_suite()
{
  Suite	*s;
  TCase	*tc_assertions;
  TCase	*tc_core;

  s = suite_create("Tokenizer");

  tc_assertions = tcase_create("Assertions");
  tcase_add_test_raise_signal(tc_assertions, test_tokenizer_null_string, SIGABRT);
  tcase_add_test_raise_signal(tc_assertions, test_tokenizer_null_token_queue, SIGABRT);

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_tokenize_complex);
  tcase_add_test(tc_core, test_tokenize_complex2);

  suite_add_tcase(s, tc_core);
  suite_add_tcase(s, tc_assertions);

  return (s);
}

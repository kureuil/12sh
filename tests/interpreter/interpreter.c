/*
** interpreter.c for 42sh in /home/person_l/rendu/42sh
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Sun May  3 15:25:44 2015 Louis Person
** Last update Sun May 24 14:08:39 2015 Brendan Rius
*/

#include <check.h>
#include <signal.h>
#include "interpreter/interpreter.h"
#include "tokenizer/tokenizer.h"
#include "tokenizer/token.h"
#include "parser/parser.h"
#include "shell.h"
#include "my/my.h"
#include "ast.h"
#include "env/env.h"

START_TEST(test_check_ast)
{
  struct s_vec		tokens;
  struct s_btree	*tree;

  init_env();
  tokenize("ls -alHi", &tokens);
  parse(&tokens, &tree);
  ck_assert_int_eq(is_ast_valid(tree), true);
}
END_TEST

START_TEST(test_check_ast2)
{
  struct s_vec		tokens;
  struct s_btree	*tree;

  init_env();
  tokenize("lszefzef -alHi", &tokens);
  parse(&tokens, &tree);
  ck_assert_int_eq(is_ast_valid(tree), false);
}
END_TEST

START_TEST(test_check_ast3)
{
  struct s_vec		tokens;
  struct s_btree	*tree;

  init_env();
  tokenize("/zelfizeoguibzef", &tokens);
  parse(&tokens, &tree);
  ck_assert_int_eq(is_ast_valid(tree), false);
}
END_TEST

START_TEST(test_check_ast4)
{
  struct s_vec		tokens;
  struct s_btree	*tree;

  init_env();
  tokenize("./zelfizeoguibzef", &tokens);
  parse(&tokens, &tree);
  ck_assert_int_eq(is_ast_valid(tree), false);
}
END_TEST

START_TEST(test_find_executable)
{
  char	e[100];

  init_env();
  ck_assert_int_eq(find_executable("ls", e, 100), 0);
  ck_assert_str_eq(e, "/bin/ls");
}
END_TEST

START_TEST(test_find_executable2)
{
  char	e[100];

  init_env();
  ck_assert_int_ne(find_executable("lzegzegzeg", e, 100), 0);
}
END_TEST

START_TEST(test_interpret_null_head)
{
  struct s_shell	shell;

  sh_init(&shell);
  interpret(NULL, &shell);
}
END_TEST

START_TEST(test_interpret_null_shell)
{
  struct s_btree	tree;
  interpret(&tree, NULL);
}
END_TEST

START_TEST(test_interpret_simple_command)
{
  struct s_vec		tokens;
  struct s_btree	*tree;
  struct s_shell	shell;

  sh_init(&shell);
  tokenize("/bin/echo hello world", &tokens);
  parse(&tokens, &tree);
  init_env();
  interpret(tree, &shell);
}
END_TEST

START_TEST(test_interpret_composed_command)
{
  struct s_vec		tokens;
  struct s_btree	*tree;
  struct s_shell	shell;

  sh_init(&shell);
  tokenize("/bin/echo Hello World ; /bin/ls", &tokens);
  parse(&tokens, &tree);
  init_env();
  interpret(tree, &shell);
}
END_TEST

START_TEST(test_interpret_with_path)
{
  struct s_vec		tokens;
  struct s_btree	*tree;
  struct s_shell	shell;

  sh_init(&shell);
  tokenize("/bin/ls", &tokens);
  parse(&tokens, &tree);
  init_env();
  interpret(tree, &shell);
}
END_TEST

START_TEST(test_interpret_andif_command)
{
  struct s_vec		tokens;
  struct s_btree	*tree;
  struct s_shell	shell;

  sh_init(&shell);
  tokenize("/bin/ls --color=auto && /bin/echo hello world", &tokens);
  parse(&tokens, &tree);
  init_env();
  interpret(tree, &shell);
}
END_TEST

START_TEST(test_interpret_orif_command)
{
  struct s_vec		tokens;
  struct s_btree	*tree;
  struct s_shell	shell;

  sh_init(&shell);
  tokenize("/bin/kill -0 || /bin/echo oh laule", &tokens);
  parse(&tokens, &tree);
  init_env();
  interpret(tree, &shell);
}
END_TEST

START_TEST(test_interpret_pipe_command)
{
  struct s_vec		tokens;
  struct s_btree	*tree;
  struct s_shell	shell;

  sh_init(&shell);
  tokenize("/bin/echo Hello World | /bin/echo -n", &tokens);
  parse(&tokens, &tree);
  init_env();
  interpret(tree, &shell);
}
END_TEST

START_TEST(test_interpret_multipipe_command)
{
  struct s_vec		tokens;
  struct s_btree	*tree;
  struct s_shell	shell;

  sh_init(&shell);
  tokenize("/bin/echo Hello World | /usr/bin/echo -n | /bin/echo -e", &tokens);
  parse(&tokens, &tree);
  init_env();
  interpret(tree, &shell);
}
END_TEST

START_TEST(test_interpret_suicide)
{
  struct s_vec		tokens;
  struct s_btree	*tree;
  struct s_shell	shell;

  sh_init(&shell);
  tokenize("/bin/kill -11 0", &tokens);
  parse(&tokens, &tree);
  init_env();
  interpret(tree, &shell);
}
END_TEST

Suite	*interpreter_suite()
{
  Suite	*s;
  TCase	*tc_assertions;
  TCase	*tc_core;

  s = suite_create("Interpreter");
  tc_assertions = tcase_create("Assertions");
  tc_core = tcase_create("Core");
  tcase_add_test_raise_signal(tc_assertions, test_interpret_null_head, SIGABRT);
  tcase_add_test_raise_signal(tc_assertions, test_interpret_null_shell, SIGABRT);
  tcase_add_test(tc_core, test_interpret_simple_command);
  /* tcase_add_test(tc_core, test_interpret_composed_command); */
  tcase_add_test(tc_core, test_interpret_with_path);
  /* tcase_add_test(tc_core, test_interpret_andif_command); */
  /* tcase_add_test(tc_core, test_interpret_orif_command); */
  tcase_add_test(tc_core, test_interpret_pipe_command);
  tcase_add_test(tc_core, test_interpret_multipipe_command);
  tcase_add_test(tc_core, test_interpret_suicide);
  tcase_add_test(tc_core, test_find_executable);
  tcase_add_test(tc_core, test_find_executable2);
  tcase_add_test(tc_core, test_check_ast);
  tcase_add_test(tc_core, test_check_ast2);
  tcase_add_test(tc_core, test_check_ast3);
  tcase_add_test(tc_core, test_check_ast4);
  suite_add_tcase(s, tc_assertions);
  suite_add_tcase(s, tc_core);
  return (s);
}

#include <check.h>
#include <stdlib.h>
#include "suites.h"

int		main()
{
  int		number_failed;
  SRunner	*sr;

  sr = srunner_create(tokenizer_suite());
  srunner_add_suite(sr, token_suite());
  srunner_add_suite(sr, env_suite());
  srunner_add_suite(sr, token_parser_semicolon_suite());
  srunner_add_suite(sr, token_parser_rredir_suite());
  srunner_add_suite(sr, token_parser_pipe_suite());
  srunner_add_suite(sr, token_parser_orif_suite());
  srunner_add_suite(sr, token_parser_lredir_suite());
  srunner_add_suite(sr, token_parser_tlredir_suite());
  srunner_add_suite(sr, token_parser_drredir_suite());
  srunner_add_suite(sr, token_parser_dlredir_suite());
  srunner_add_suite(sr, token_parser_andif_suite());
  srunner_add_suite(sr, token_parser_string_suite());
  srunner_add_suite(sr, parser_suite());
  srunner_add_suite(sr, interpreter_suite());
  srunner_add_suite(sr, expand_suite());

  srunner_run_all(sr, CK_VERBOSE);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

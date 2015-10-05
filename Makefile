##
## Makefile for 42sh in /home/ouvran_a/Documents/rendu/42sh
## 
## Made by Antoine Ouvrans
## Login   <ouvran_a@epitech.net>
## 
## Started on  Sat Apr 18 13:08:40 2015 Brendan Rius
## Last update Fri Aug 14 20:57:45 2015 Louis Person
##

NAME	= 42sh

BASE_DIR 	= .

LIB_DIR		= $(BASE_DIR)/lib
LIB_MY		= $(LIB_DIR)/libmy.a
INC_DIR 	= $(BASE_DIR)/inc
TESTS_DIR 	= $(BASE_DIR)/tests

SRCS_DIR	= $(BASE_DIR)/src

CFLAGS	= -Wall -Wextra -pedantic
CFLAGS	+= -I $(INC_DIR)
CFLAGS	+= -std=c99 -D _POSIX_C_SOURCE=200809L
LDFLAGS	= -L $(LIB_DIR) -lncurses
LDLIBS	= -l my

debug: CFLAGS	+= -g

test:  CFLAGS	+= -g -fprofile-arcs -ftest-coverage -D MOCK_MODE
test:  LDLIBS	+= -l check -l m -l pthread -l rt -l gcov
test:  CC	= gcc

# Env
ENV_DIR_SRCS	= $(SRCS_DIR)/env
ENV_DIR_TESTS	= $(TESTS_DIR)/env
ENV_SRCS	= $(ENV_DIR_SRCS)/env.c
ENV_TESTS	= $(ENV_DIR_TESTS)/env.c

# Parser
PARSER_DIR_SRCS		= $(SRCS_DIR)/parser
PARSER_DIR_TESTS	= $(TESTS_DIR)/parser
PARSER_SRCS		= $(PARSER_DIR_SRCS)/parse.c \
			$(PARSER_DIR_SRCS)/exp_complete.c \
			$(PARSER_DIR_SRCS)/exp_complete_l1.c \
			$(PARSER_DIR_SRCS)/exp_complete_l2.c \
			$(PARSER_DIR_SRCS)/exp_simple.c \
			$(PARSER_DIR_SRCS)/exp_redir.c \
			$(PARSER_DIR_SRCS)/exp_rredir.c \
			$(PARSER_DIR_SRCS)/exp_drredir.c \
			$(PARSER_DIR_SRCS)/exp_lredir.c \
			$(PARSER_DIR_SRCS)/exp_dlredir.c \
			$(PARSER_DIR_SRCS)/exp_tlredir.c
PARSER_TESTS		= $(PARSER_DIR_TESTS)/parser.c

# Tokenizer
TOKENIZER_DIR_SRCS	= $(SRCS_DIR)/tokenizer
TOKENIZER_DIR_TESTS	= $(TESTS_DIR)/tokenizer
TOKENIZER_SRCS		= $(TOKENIZER_DIR_SRCS)/token.c \
			$(TOKENIZER_DIR_SRCS)/tokenizer.c \
			$(TOKENIZER_DIR_SRCS)/special_char_filter.c \
			$(TOKENIZER_DIR_SRCS)/tokens/token_string.c \
			$(TOKENIZER_DIR_SRCS)/tokens/token_pipe.c \
			$(TOKENIZER_DIR_SRCS)/tokens/token_rredir.c \
			$(TOKENIZER_DIR_SRCS)/tokens/token_lredir.c \
			$(TOKENIZER_DIR_SRCS)/tokens/token_drredir.c \
			$(TOKENIZER_DIR_SRCS)/tokens/token_dlredir.c \
			$(TOKENIZER_DIR_SRCS)/tokens/token_tlredir.c \
			$(TOKENIZER_DIR_SRCS)/tokens/token_andif.c \
			$(TOKENIZER_DIR_SRCS)/tokens/token_orif.c \
			$(TOKENIZER_DIR_SRCS)/tokens/token_semicolon.c
TOKENIZER_TESTS		= $(TOKENIZER_DIR_TESTS)/tokenizer.c \
			$(TOKENIZER_DIR_TESTS)/token.c \
			$(TOKENIZER_DIR_TESTS)/tokens/token_semicolon.c \
			$(TOKENIZER_DIR_TESTS)/tokens/token_rredir.c \
			$(TOKENIZER_DIR_TESTS)/tokens/token_pipe.c \
			$(TOKENIZER_DIR_TESTS)/tokens/token_orif.c \
			$(TOKENIZER_DIR_TESTS)/tokens/token_lredir.c \
			$(TOKENIZER_DIR_TESTS)/tokens/token_tlredir.c \
			$(TOKENIZER_DIR_TESTS)/tokens/token_drredir.c \
			$(TOKENIZER_DIR_TESTS)/tokens/token_dlredir.c \
			$(TOKENIZER_DIR_TESTS)/tokens/token_andif.c \
			$(TOKENIZER_DIR_TESTS)/tokens/token_string.c

# UI
UI_DIR_SRCS	= $(SRCS_DIR)/ui
UI_DIR_TESTS	= $(TESTS_DIR)/ui
UI_SRCS		= $(UI_DIR_SRCS)/ui.c \
		  $(UI_DIR_SRCS)/disp_str/ui_disp_cmdl.c \
		  $(UI_DIR_SRCS)/disp_str/ui_disp_part_cmdl.c \
		  $(UI_DIR_SRCS)/disp_str/ui_disp_prompt.c \
		  $(UI_DIR_SRCS)/disp_str/ui_init_disp_cmdl.c \
		  $(UI_DIR_SRCS)/disp_str/ui_modul_str.c \
		  $(UI_DIR_SRCS)/disp_str/ui_init_tty.c \
		  $(UI_DIR_SRCS)/disp_str/ui_clear_window.c \
		  $(UI_DIR_SRCS)/edit_str/ui_backspace_cmdl.c \
		  $(UI_DIR_SRCS)/edit_str/ui_copy_cmdl.c \
		  $(UI_DIR_SRCS)/edit_str/ui_copy_str.c \
		  $(UI_DIR_SRCS)/edit_str/ui_cut_begin_cmdl.c \
		  $(UI_DIR_SRCS)/edit_str/ui_cut_cmdl.c \
		  $(UI_DIR_SRCS)/edit_str/ui_cut_end_cmdl.c \
		  $(UI_DIR_SRCS)/edit_str/ui_del_char_cmdl.c \
		  $(UI_DIR_SRCS)/edit_str/ui_delete_zone_str.c \
		  $(UI_DIR_SRCS)/edit_str/ui_exit_cmdl.c \
		  $(UI_DIR_SRCS)/edit_str/ui_send_str.c \
		  $(UI_DIR_SRCS)/edit_str/ui_get_end_cmdl.c \
		  $(UI_DIR_SRCS)/edit_str/ui_init_cmdl.c \
		  $(UI_DIR_SRCS)/edit_str/ui_init_edit_str.c \
		  $(UI_DIR_SRCS)/edit_str/ui_jump_word.c \
		  $(UI_DIR_SRCS)/edit_str/ui_macro.c \
		  $(UI_DIR_SRCS)/edit_str/ui_move_cursor.c \
		  $(UI_DIR_SRCS)/edit_str/ui_paste_cmdl.c \
		  $(UI_DIR_SRCS)/edit_str/ui_remove_char_cmdl.c \
		  $(UI_DIR_SRCS)/edit_str/ui_set_select_pos.c \
		  $(UI_DIR_SRCS)/edit_str/ui_switch_inser_mod.c \
		  $(UI_DIR_SRCS)/edit_str/ui_write_cmdl.c \
		  $(UI_DIR_SRCS)/edit_str/ui_write_number.c \
		  $(UI_DIR_SRCS)/get_event_key/pubsub.c \
		  $(UI_DIR_SRCS)/get_event_key/ui_get_keycode.c \
		  $(UI_DIR_SRCS)/get_event_key/ui_get_key_event.c \
		  $(UI_DIR_SRCS)/get_event_key/ui_main_init.c \
		  $(UI_DIR_SRCS)/get_event_key/ui_init_termcaps.c \
		  $(UI_DIR_SRCS)/get_event_key/ui_prepare_dict_vec.c \
		  $(UI_DIR_SRCS)/get_event_key/ui_link_event_keycode.c \
		  $(UI_DIR_SRCS)/get_event_key/ui_pub_event.c \
		  $(UI_DIR_SRCS)/get_event_key/ui_raw_mod.c \
		  $(UI_DIR_SRCS)/get_event_key/ui_set_tgetenv.c \
		  $(UI_DIR_SRCS)/emergency_prompt/emergency_prompt.c \
		  $(UI_DIR_SRCS)/math/mathematic.c

# Shell
SHELL_DIR_SRCS		= $(SRCS_DIR)/shell
SHELL_DIR_TESTS		= $(TESTS_DIR)/shell

SHELL_SRCS		= $(SHELL_DIR_SRCS)/init.c \
			$(SHELL_DIR_SRCS)/exit.c \
			$(SHELL_DIR_SRCS)/return.c \
			$(SHELL_DIR_SRCS)/destroy.c \
			$(SHELL_DIR_SRCS)/get.c

# Interpreter
INTERPRETER_DIR_SRCS	= $(SRCS_DIR)/interpreter
INTERPRETER_DIR_TESTS	= $(TESTS_DIR)/interpreter

INTERPRETER_SRCS	= $(INTERPRETER_DIR_SRCS)/interpreter.c \
			$(INTERPRETER_DIR_SRCS)/interpreter_pipe.c \
			$(INTERPRETER_DIR_SRCS)/interpreter_command.c \
			$(INTERPRETER_DIR_SRCS)/interpreter_compose.c \
			$(INTERPRETER_DIR_SRCS)/interpreter_orif.c \
			$(INTERPRETER_DIR_SRCS)/interpreter_andif.c \
			$(INTERPRETER_DIR_SRCS)/interpreter_empty.c \
			$(INTERPRETER_DIR_SRCS)/find_executable.c \
			$(INTERPRETER_DIR_SRCS)/check_ast.c \
			$(INTERPRETER_DIR_SRCS)/exit.c \
			$(INTERPRETER_DIR_SRCS)/dup.c \
			$(INTERPRETER_DIR_SRCS)/builtins/cd.c \
			$(INTERPRETER_DIR_SRCS)/builtins/echo.c \
			$(INTERPRETER_DIR_SRCS)/builtins/exit.c \
			$(INTERPRETER_DIR_SRCS)/builtins/setenv.c \
			$(INTERPRETER_DIR_SRCS)/builtins/getenv.c \
			$(INTERPRETER_DIR_SRCS)/builtins/unsetenv.c
INTERPRETER_TESTS	= $(INTERPRETER_DIR_TESTS)/interpreter.c

# Expand
EXPAND_DIR_SRCS		= $(SRCS_DIR)/expand
EXPAND_DIR_TESTS	= $(TESTS_DIR)/expand

EXPAND_SRCS		= $(EXPAND_DIR_SRCS)/variable.c \
			$(EXPAND_DIR_SRCS)/tilde.c
EXPAND_TESTS		= $(EXPAND_DIR_TESTS)/variables.c

SRCS	= $(TOKENIZER_SRCS) \
	$(UI_SRCS) \
	$(INTERPRETER_SRCS) \
	$(ENV_SRCS) \
	$(PARSER_SRCS) \
	$(SHELL_SRCS) \
	$(EXPAND_SRCS)

SRCS	+= $(SRCS_DIR)/error.c
SRCS	+= $(SRCS_DIR)/ast.c
OBJS	= $(SRCS:.c=.o)
MOBJS	= $(SRCS:.c=.mock.o)

SRCS_MAIN	= $(SRCS_DIR)/main.c

OBJS_MAIN	= $(SRCS_MAIN:.c=.o)

SRCS_TESTS	= $(TOKENIZER_TESTS) \
		$(UI_TESTS) \
		$(INTERPRETER_TESTS) \
		$(ENV_TESTS) \
		$(PARSER_TESTS) \
		$(EXPAND_TESTS)

SRCS_TESTS	+= $(TESTS_DIR)/main.c \
		$(TESTS_DIR)/mocks/malloc.c \
		$(TESTS_DIR)/mocks/strdup.c \
		$(TESTS_DIR)/mocks/token_new.c \
		$(TESTS_DIR)/mocks/string_push.c
OBJS_TESTS	= $(SRCS_TESTS:.c=.o)

# NORMAL COMPILATION
all: $(NAME)

$(LIB_MY):
	$(MAKE) --directory lib/my

$(NAME): $(LIB_MY) $(OBJS) $(OBJS_MAIN)
	$(CC) -o $(NAME) $(OBJS) $(OBJS_MAIN) $(LDFLAGS) $(LDLIBS)

debug: $(LIB_MY) $(OBJS) $(OBJS_MAIN)
	$(CC) -o $(NAME) $(OBJS) $(OBJS_MAIN) $(LDFLAGS) $(LDLIBS)

# TESTS
%.mock.o: %.mock.c
	$(CC) -c -o $@ $< $(CFLAGS)

mock:
	$(TESTS_DIR)/testable.py $(SRCS)

test: mock $(MOBJS) $(OBJS_TESTS) $(LIB_MY)
	$(CC) -o /tmp/test $(MOBJS) $(OBJS_TESTS) $(LDFLAGS) $(LDLIBS)
	/tmp/test
	gcovr -r $(SRCS_DIR)

# CLEAN
clean:
	$(RM) $(MOBJS) $(OBJS) $(OBJS_TESTS)
	find $(BASE_DIR) -name "*.gcov" -delete
	find $(BASE_DIR) -name "*.mock.c" -delete
	find $(BASE_DIR) -name "*.gcda" -delete
	find $(BASE_DIR) -name "*.gcno" -delete
	find $(BASE_DIR) -name "*.~" -delete

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all test clean fclean re test test_tokenizer mock

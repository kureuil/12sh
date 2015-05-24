/*
** interpreter.h for 42sh in /home/person_l/rendu/42sh
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Sun May  3 18:16:21 2015 Louis Person
** Last update Sun May 24 20:11:01 2015 Louis Person
*/

#ifndef INTERPRETER_H_
# define INTERPRETER_H_

# include <sys/types.h>
# include <stdbool.h>

struct s_btree;
struct s_shell;
struct s_ast_node_cmd;

typedef int (*t_interpreter)();

int	interpret(struct s_btree *head, struct s_shell *shell);

int	interpret_pipe(t_interpreter *interpreters,
		       struct s_shell *shell,
		       struct s_btree *tnode);

int	interpret_command(t_interpreter *interpreters,
			  struct s_shell *shell,
			  struct s_btree *tnode);

int	interpret_compose(t_interpreter *interpreters,
			  struct s_shell *shell,
			  struct s_btree *tnode);

int	interpret_orif(t_interpreter *interpreters,
		       struct s_shell *shell,
		       struct s_btree *tnode);

int	interpret_andif(t_interpreter *interpreters,
			struct s_shell *shell,
			struct s_btree *tnode);

int	interpret_empty(t_interpreter *interpreters,
			struct s_shell *shell,
			struct s_btree *tnode);

int	command_supervisor(struct s_shell *shell, pid_t child);

int	report_exit_status(pid_t pid, int status, struct s_shell *shell);

int	command_prepare(struct s_shell *shell, struct s_ast_node_cmd *cmd);

/*
** Find an executable's path by its name.
** The environment shall be init'ed.
** In case of success, returns 0 and copy at most
** n bytes of the executable to dest.
*/
int	find_executable(const char *name, char *dest, size_t n);

/*
** Check is the AST is valid
*/
bool	is_ast_valid(struct s_btree *ast);

#endif /* !INTERPRETER_H_ */

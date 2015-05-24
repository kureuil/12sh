/*
** interpreter.h for 42sh in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Tue Apr 21 17:31:46 2015 Louis Person
** Last update Sun May 24 17:28:18 2015 Brendan Rius
*/

#ifndef AST_H_
# define AST_H_

# include "my/vector.h"

enum	e_ast_node_type
{
  TPIPE,
  TCMD,
  TCOMPOSE,
  TORIF,
  TANDIF,
  TEMPTY,
  _T_COUNT
};

struct		s_ast_node_cmd
{
  struct s_vec	command;	/* args */
  enum
    {
      RT_RUNKNOWN,
      RT_RSIMPLE,
      RT_RDOUBLE
    }		rtype;		/* type of right redir */
  enum
    {
      RT_LUNKNOWN,
      RT_LSIMPLE,
      RT_LDOUBLE,
      RT_LTRIPLE
    }		ltype;		/* type of left redir */
  char		*rredir;	/* file of a right redirection (>, >>) */
  char		*lredir;	/* file of a left redirection (<, <<, <<<) */
};

struct				s_ast_node
{
  enum e_ast_node_type		type;
  union
  {
    struct s_ast_node_cmd	cmd;
  }				value;
};

/*
** Allocates a new struct s_ast_node, returns 0 on success and -1 on error.
*/
int	ast_node_new(struct s_ast_node **ptr);

void	free_ast(struct s_ast_node *n);

#endif /* !AST_H_ */

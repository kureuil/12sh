/*
** edit_cmdl.h for termcaps in /home/paris_e/Travail/Cprograme/Semestre2/42sh/V2
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Sun Apr 26 17:12:16 2015 Adrien Paris
** Last update Sun May 24 21:30:41 2015 Adrien Paris
*/

#ifndef _EDIT_CMDL_
# define _EDIT_CMDL_

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "pubsub.h"

# define SIZE_CMDL	100000

typedef struct          s_command_line
{
  bool                  insert_mod;
  char                  str[SIZE_CMDL];
  size_t                cursor;
  size_t                size;
  char                  copy[SIZE_CMDL];
  size_t                size_copy;
  ssize_t               select_pos;
  unsigned int		time;
  char			*prompt;
  char			*username;
  char			*hostname;
  int			exit;
  bool			emergency;
  int			tty;
}			t_command_line;

/*
** This function suscribe the edition of the cmdl to some event,
** mainly key_event, with the pubsub mechanic.
*/
int	ui_init_edit_cmdl();

/*
** This one just initialized the global cmdl of type t_command_line.
*/
void	ui_init_command_line();

/*
** This function reset a string of size SIZE_CMDL.
** It will put a lot of 1 in it (to make sure to be
** not stoped by an hazardous zero), and will fill
** the two first char to ' ' and '\0'.
*/
void	ui_init_str_line(char str[SIZE_CMDL]);

/*
** Will reset the str, but keep the copy
*/
void	ui_reset_command_line();

/*
** This function will give you the size of the string set in parameter
** sub 1, or the SIZE_CMDL sub 1.
*/
int	ui_get_end_cmdl(char str[SIZE_CMDL]);

/*
** This function will move all from the right of the 'pos' from one
** step to the right from the 'str' and put a new char 'c' a the
** place of the 'pos'.
*/
int     ui_insert_char_to_str(const char c, const int pos, char *str);

/*
** This function will choose if your in insert mod, wich operation to do
** It will write a char were your cursore is.
** write in the str of the global cmdl, with the cursor from the global cmdl.
** it be use with the pubsub mecanic.
*/
void	ui_write_cmdl(t_event e, void *c);

/*
** Like his name says, this one will move the cursor to the left,
** of the global cmdl;
*/
void	ui_move_cursor_left(t_event e, void *data);

/*
** The same as move_cursor_left() but for the right.
*/
void	ui_move_cursor_right(t_event e, void *data);

/*
** Set the cursor at the begining of the str of the global cmdl.
*/
void	ui_move_cursor_begin(t_event e, void *data);

/*
** Set the cursor at the end of the str of the global cmdl.
*/
void	ui_move_cursor_end(t_event e, void *data);

/*
** Make the cursor jump all the alpha-num to the right.
*/
void	ui_jump_word_backward(t_event e, void *data);

/*
** Make the cursor jump all the alpha-num to the left.
*/
void	ui_jump_word_forward(t_event e, void *data);

/*
** It will set were the selection start. It will keep is
** position while it's not reset with 'reset_select_pos'
*/
void	ui_set_select_pos(t_event e, void *data);

/*
** It will reset the position of the selection.
** (set to -1).
*/
void	ui_reset_select_pos(t_event e, void *data);

/*
** Will move all the char of the str at the right of the pos
** to the left, it will remove the char were the pos is.
*/
int	ui_remove_char_to_cmdl(int pos, char str[SIZE_CMDL]);

/*
** This function will choose wich kind of remove to do,
** if you are in insert mod or not, or if you are removing a selection.
*/
void	ui_backspace_cmdl(t_event e, void *data);

/*
** This function will choose wich kind of remove to do,
** if you are removing a selection or not.
*/
void	ui_delete_char_cmdl(t_event e, void *data);

/*
** This function will remove all the char who are between the cursor
** and the select_pos.
*/
void	ui_delete_selection();

/*
** When it's call this function will switch the insert_mod
** to true or false. (it's a boolean value)
*/
void	ui_switch_insert_mod(t_event e, void *data);

/*
** This function will copy from the begening of the 'src' in a scale of 'size'
** in the 'dest' from the 'pos'.
*/
int	ui_copy_zone_cmdl(char *src, int size, char *dest, int pos);

/*
** This function will delete from the begening of 'str' in a scale of 'size'.
*/
void    ui_delete_zone_str(char *str, int size);

/*
** This function will paste what there is in the copy (in the cmdl)
** to the str (of the cmdl).
*/
void	ui_paste_cmdl(t_event e, void *data);

/*
** It will copy the selection of the str (of the cmdl),
** to the copy (of the cmdl too)
*/
void	ui_copy_cmdl(t_event e, void *data);

/*
** It will delete the selection and copy it into the 'copy' (of the cmdl)
**
*/
void	ui_cut_cmdl(t_event e, void *data);

/*
** It will delete from the cursor to the end and copy what was delete
** to the 'copy' (of the cmdl as usual)
*/
void	ui_cut_end_cmdl(t_event e, void *data);

/*
** It will delete from the begin to the cursor and copy what was delete
** to the 'copy' (of the cmdl as usual)
*/
void	ui_cut_begin_cmdl(t_event e, void *data);

/*
** It will write the 'nb', than you pass in parameter,
** into the str (of the cmdl). it will use the 'ui_write_cmdl'
** without use the pubsub systeme.
*/
void	ui_write_number(int nb);

void	ui_exit_cmdl(t_event e, void *data);

void	ui_abort_cmdl(t_event e, void *data);

void	ui_send_str_cmdl(t_event e, void *data);

#endif	/* _EDIT_CMDL_ */

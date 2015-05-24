/*
** get_key.h for termcaps in /home/paris_e/Travail/Cprograme/Semestre2/42sh/V2
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Sun Apr 26 17:48:38 2015 Adrien Paris
** Last update Sun May 24 01:28:45 2015 Adrien Paris
*/

#ifndef _GET_KEY_
# define _GET_KEY_

#include <termios.h>
#include "my/my.h"

/*
** This function will set 'struct termios *t' in the tcsetattr function, but
** will write a warning msg if it failed.
*/
int			ui_set_attr(struct termios *t);

/*
** This function will get all the interaction keyboard, and send an event
** in function of the type of the interaction.
*/
int			ui_get_event_key();

/*
** will recover a code of combinaison of keyboard
** (it possible to have a combinison of one key) from the standard input.
** There is a list of macro of different code in 'key_code.h'
*/
unsigned long		ui_get_keycode();

/*
** Will set the terminal in a raw mod.
*/
int			ui_raw_mode();

/*
** Will look for the Term name and put into the tgetent function.
** unfortunetly, the tgetent function use 16 malloc than we can't free,
** and loose 0,02 Ko.
*/
int			ui_set_tgetenv();

/*
** It will reset as default config.
*/
int			ui_end_termcaps(struct termios *save_tc);

/*
** It will set the terminal in raw_mod and prepare the termcaps
** and will save the actual config in save_tc.
*/
int			ui_init_termcaps(struct termios *save_tc);

/*
** It wil post an event in function of the key_code, in the category
** edit_str
*/
void			ui_getkey_edit_str(unsigned long code);

/*
** It wil post an event in function of the key_code, in the category
** move_cursor
*/
void			ui_getkey_move_cursor(unsigned long code);

/*
** It wil post an event in function of the key_code, in the category
** select
*/
void			ui_getkey_select(unsigned long code);

/*
** It wil post an event in function of the key_code, in the category
** copy_paste
*/
void			ui_getkey_copy_paste(unsigned long code);

/*
** It wil post an event in function of the key_code, in the category
** option
*/
void			ui_getkey_option(unsigned long code);

/*
** It wil post an event in function of the key_code, in the category
** option
*/
void                    ui_getkey_macro(unsigned long code);

void			ui_pub_event(unsigned long code, t_dict *dict_key);

int			ui_compare_key_eq_int(void *a, void *b);

t_dict			*ui_link_event_keycode();

int			ui_link_ev_kc(t_dict *dict_key,
				      unsigned long key, int nb_arg, ...);

char			*emergency_prompt();

#endif	/* _GET_KEY_ */

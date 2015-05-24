/*
** ui_link_event_keycode.c for 42sh in /home/paris_e/Travail/Cprograme/Semestre2/42sh/42sh
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Tue May 12 16:09:17 2015 Adrien Paris
** Last update Sun May 24 18:59:23 2015 Adrien Paris
*/

#include <stdarg.h>
#include <sys/types.h>
#include "my/dictionnary.h"
#include "my/vector.h"
#include "my/llist.h"
#include "pubsub.h"
#include "ui/get_key.h"
#include "ui/key_code.h"

int	ui_link_ev_kc_move(t_dict *dict_key)
{
  int	ret;

  ret = 0;
  ret += ui_link_ev_kc(dict_key, K_HOME, 1, UI_MOVE_BEGIN);
  ret += ui_link_ev_kc(dict_key, K_END, 1, UI_MOVE_END);
  ret += ui_link_ev_kc(dict_key, K_F3, 1, UI_REC_MACRO);
  ret += ui_link_ev_kc(dict_key, K_F4, 1, UI_PLAY_MACRO);
  ret += ui_link_ev_kc(dict_key, K_LEFT, 1, UI_MOVE_LEFT);
  ret += ui_link_ev_kc(dict_key, K_RIGHT, 1, UI_MOVE_RIGHT);
  ret += ui_link_ev_kc(dict_key, K_CTRL_LEFT, 1, UI_JUMP_WORD_LEFT);
  ret += ui_link_ev_kc(dict_key, K_CTRL_RIGHT, 1, UI_JUMP_WORD_RIGHT);
  ret += ui_link_ev_kc(dict_key, K_M_LEFT, 2, UI_SET_SELECT_POS, UI_MOVE_LEFT);
  ret += ui_link_ev_kc(dict_key, K_M_RIGHT, 2, UI_SET_SELECT_POS,
		       UI_MOVE_RIGHT);
  ret += ui_link_ev_kc(dict_key, K_CTRL_M_LEFT, 2, UI_SET_SELECT_POS,
		       UI_JUMP_WORD_LEFT);
  ret += ui_link_ev_kc(dict_key, K_CTRL_M_RIGHT, 2, UI_SET_SELECT_POS,
		       UI_JUMP_WORD_RIGHT);
  return (ret);
}

int	ui_link_ev_kc_edit(t_dict *dict_key)
{
  int	ret;

  ret = 0;
  ret += ui_link_ev_kc(dict_key, K_DEL, 1, UI_DEL);
  ret += ui_link_ev_kc(dict_key, K_BACKSPACE, 1, UI_BACKSPACE);
  ret += ui_link_ev_kc(dict_key, K_ALT_W, 1, UI_COPY);
  ret += ui_link_ev_kc(dict_key, K_CTRL_Y, 1, UI_PASTE);
  ret += ui_link_ev_kc(dict_key, K_CTRL_W, 1, UI_CUT);
  ret += ui_link_ev_kc(dict_key, K_CTRL_K, 1, UI_CUT_END);
  ret += ui_link_ev_kc(dict_key, K_CTRL_U, 1, UI_CUT_BEGIN);
  ret += ui_link_ev_kc(dict_key, K_INSERT, 1, UI_INSERT);
  ret += ui_link_ev_kc(dict_key, K_ENTER, 1, UI_SEND_STR);
  ret += ui_link_ev_kc(dict_key, K_CTRL_D, 1, UI_EXIT);
  ret += ui_link_ev_kc(dict_key, K_CTRL_C, 1, UI_ABORT);
  ret += ui_link_ev_kc(dict_key, K_CTRL_L, 1, UI_CLEAR_WIN);
  return (ret);
}

void			ui_destroy_vector_event(struct s_vec *vec)
{
  vec_destroy(vec);
  free(vec);
}

t_dict			*ui_link_event_keycode()
{
  t_dict		*dict_key;
  t_dict_interface	*llist;

  if ((llist = llist_get_dict()) == NULL)
    return (NULL);
  if ((dict_key = dict_new(llist, &ui_destroy_vector_event, NULL,
			   &ui_compare_key_eq_int)) == NULL)
    return (NULL);
  if (ui_link_ev_kc_move(dict_key) != 0)
    return (NULL);
  if (ui_link_ev_kc_edit(dict_key) != 0)
    return (NULL);
  return (dict_key);
}

/*
** init_edit_str.c for ui in /home/paris_e/Travail/Cprograme/Semestre2/42sh/V2
** 
** Made by Adrien Paris
** Login   <paris_e@epitech.net>
** 
** Started on  Sun Apr 26 17:23:48 2015 Adrien Paris
** Last update Sat May 23 16:38:26 2015 Adrien Paris
*/

#include <stdlib.h>
#include "pubsub.h"
#include "mathematic.h"
#include "ui/edit_cmdl.h"
#include "ui/macro.h"

t_command_line	g_cmdl;

int		ui_init_move_cmdl_sub()
{
  int		ret;

  ret = 0;
  ret += math_is_neg(vm_register_hook(UI_MOVE_LEFT, &ui_move_cursor_left));
  ret += math_is_neg(vm_register_hook(UI_MOVE_RIGHT, &ui_move_cursor_right));
  ret += math_is_neg(vm_register_hook(UI_JUMP_WORD_LEFT,
				      &ui_jump_word_backward));
  ret += math_is_neg(vm_register_hook(UI_JUMP_WORD_RIGHT,
				      &ui_jump_word_forward));
  ret += math_is_neg(vm_register_hook(UI_MOVE_BEGIN, &ui_move_cursor_begin));
  ret += math_is_neg(vm_register_hook(UI_MOVE_END, &ui_move_cursor_end));
  ret += math_is_neg(vm_register_hook(UI_SET_SELECT_POS, &ui_set_select_pos));
  ret += math_is_neg(vm_register_hook(UI_RESET_SELECT_POS,
				      &ui_reset_select_pos));
  ret += math_is_neg(vm_register_hook(UI_INSERT, &ui_switch_insert_mod));
  ret += math_is_neg(vm_register_hook(UI_SEND_STR, &ui_send_str_cmdl));
  return (-ret);
}

int		ui_init_edit_cmdl_sub()
{
  int		ret;

  ret = 0;
  ret += math_is_neg(vm_register_hook(UI_WRITE, &ui_write_cmdl));
  ret += math_is_neg(vm_register_hook(UI_BACKSPACE, &ui_backspace_cmdl));
  ret += math_is_neg(vm_register_hook(UI_DEL, &ui_delete_char_cmdl));
  ret += math_is_neg(vm_register_hook(UI_COPY, &ui_copy_cmdl));
  ret += math_is_neg(vm_register_hook(UI_PASTE, &ui_paste_cmdl));
  ret += math_is_neg(vm_register_hook(UI_CUT, &ui_cut_cmdl));
  ret += math_is_neg(vm_register_hook(UI_CUT_END, &ui_cut_end_cmdl));
  ret += math_is_neg(vm_register_hook(UI_CUT_BEGIN, &ui_cut_begin_cmdl));
  ret += math_is_neg(vm_register_hook(UI_EXIT, &ui_exit_cmdl));
  ret += math_is_neg(vm_register_hook(UI_ABORT, &ui_abort_cmdl));
  return (-ret);
}

int		ui_init_edit_cmdl()
{
  int		ret;

  ret = 0;
  ui_init_command_line();
  ret += math_is_neg(ui_init_macro_sub());
  ret += math_is_neg(ui_init_edit_cmdl_sub());
  ret += math_is_neg(ui_init_move_cmdl_sub());
  return (-ret);
}

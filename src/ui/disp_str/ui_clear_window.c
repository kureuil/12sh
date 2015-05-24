/*
** ui_clear_window.c for 42sh in /home/adrien/Travail/Cprograme/Semestre2/42sh/42sh
** 
** Made by Adrien Paris
** Login   <adrien@epitech.net>
** 
** Started on  Sun May 24 13:46:01 2015 Adrien Paris
** Last update Sun May 24 22:48:19 2015 Adrien Paris
*/

#include <stdlib.h>
#include "ui/disp_cmdl.h"
#include "ui/edit_cmdl.h"

void			ui_clear_window(t_event e, void *data)
{
  (void) e;
  (void) data;
  ui_modul_str("cl");
  ui_disp_prompt();
}

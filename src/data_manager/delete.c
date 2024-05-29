/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 27/05/2024 01:39:29 ******************************************************
** keryan.houssin <keryan.houssin@aldrin.efrits.fr>
** - Avant-Cyclade -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"data_manager.h"

static void		delete_data(t_data			*data)
{
  string_delete(data->data);
  bunny_free(data);
}

void			efdelete_data_manager(t_data_manager	*manager)
{
  if (!manager)
    return;
  delete_data(manager->data);
  bunny_free(manager);
}

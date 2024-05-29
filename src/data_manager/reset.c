/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 27/05/2024 01:39:22 ******************************************************
** keryan.houssin <keryan.houssin@aldrin.efrits.fr>
** - Avant-Cyclade -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"data_manager.h"

static void		reset_data(t_data			*data)
{
  int			i;

  i = 0;
  while (i < 3)
    {
      data->info[i].type = 0;
      i += 1;
    }
  string_clear(data->data);
}

void			efreset_data_manager(t_data_manager	*data)
{
  data->stage = SD_NONE;
  data->index_bit = 0;
  data->index_byte = 0;
  data->cur_byte = 0;
  reset_data(data->data);
}

/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 23/05/2024 18:32:49 ******************************************************
** keryan.houssin <keryan.houssin@jemison.efrits.fr>
** - Avant Cyclade -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"data_manager.h"

static void		*short_return(const char	*err_msg)
{
  bunny_perror(err_msg);
  return(NULL);
}

static t_data		*new_data()
{
  t_data		*new_data;
  int			i;

  new_data = bunny_malloc(sizeof(t_data));
  if (!new_data)
    return(short_return("Error bunny_malloc new_data"));
  i = 0;
  while (i < 3)
    {
      new_data->info[i].type = 0;
      i += 1;
    }
  new_data->data = efstring_new();
  return(new_data);
}

t_data_manager		*efnew_data_manager()
{
  t_data_manager	*new_manager;

  new_manager = bunny_malloc(sizeof(t_data_manager));
  if (!new_manager)
    return(short_return("Error bunny_malloc new_data_manager"));
  efinit_data_manager(new_manager);
  new_manager->stage = SD_NONE;
  new_manager->data = new_data();
  if (!new_manager->data)
    {
      bunny_free(new_manager);
      return(NULL);
    }
  return(new_manager);
}

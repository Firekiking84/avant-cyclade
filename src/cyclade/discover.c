/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 27/05/2024 01:39:49 ******************************************************
** keryan.houssin <keryan.houssin@aldrin.efrits.fr>
** - Avant-Cyclade -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"cyclade.h"

#include		<string.h>

int			efdiscover_cyclade(t_cyclade		*cyclade)
{
  t_data_manager	*new_manager;

  new_manager = efnew_data_manager_settings(cyclade->id, cyclade->id, 0, NULL);
  if (!new_manager)
    return(-1);
  efsend_manager_cyclade(cyclade, new_manager);
  return(0);
}

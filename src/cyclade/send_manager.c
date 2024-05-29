/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 27/05/2024 01:39:38 ******************************************************
** keryan.houssin <keryan.houssin@aldrin.efrits.fr>
** - Avant-Cyclade -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"cyclade.h"

int			efsend_manager_cyclade(t_cyclade		*cyclade,
					       t_data_manager		*manager)
{
  t_data_manager	*copy_manager;

  if (!efpush_queue(cyclade->queue[DS_OUT_LEFT], manager))
    return(-1);
  copy_manager = efcopy_data_manager(manager);
  if (!copy_manager)
    return(-1);
  if (!efpush_queue(cyclade->queue[DS_OUT_RIGHT], copy_manager))
    return(-1);
  return(0);
}

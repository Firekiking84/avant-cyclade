/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 27/05/2024 01:39:41 ******************************************************
** keryan.houssin <keryan.houssin@aldrin.efrits.fr>
** - Avant-Cyclade -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"cyclade.h"

#include		<stdio.h>

static bool		target_in_contact(t_cyclade	*cyclade,
					  uint32_t	target)
{
  uint32_t		i;

  i = 0;
  while (i < cyclade->nb_ids)
    {
      if (cyclade->network_ids[i] == target)
	return(true);
      i += 1;
    }
  printf("Be advised that the target is unknow from your contact. It can never reach its destination...\n");
  return(false);
}

int			efsend_data_cyclade(t_cyclade	*cyclade,
					    uint32_t	target,
					    void	*data,
					    uint32_t	datalen)
{
  t_data_manager	*manager;

  target_in_contact(cyclade, target);
  manager = efnew_data_manager_settings(target, cyclade->id, datalen, data);
  if (!manager)
    return(-1);
  efsend_manager_cyclade(cyclade, manager);
  return(0);
}

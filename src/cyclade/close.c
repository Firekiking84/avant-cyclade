/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 27/05/2024 01:39:51 ******************************************************
** keryan.houssin <keryan.houssin@aldrin.efrits.fr>
** - Avant-Cyclade -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"cyclade.h"

void			efclose_cyclade(t_cyclade	*cyclade)
{
  int			i;
  int			j;

  if (cyclade->network_ids)
    bunny_free(cyclade->network_ids);
  if (!cyclade->simulation)
    bunny_delete_vm110n(cyclade->card);
  else
    bunny_free(cyclade->card);
  i = 0;
  while (i < 4)
    {
      efdelete_data_manager(cyclade->data[i]);
      j = 0;
      while (j < cyclade->queue[i]->nb_node)
	{
	  efdelete_data_manager(efpop_queue(cyclade->queue[i]));
	  j += 1;
	}
      efdelete_queue(cyclade->queue[i]);
      i += 1;
    }
  bunny_free(cyclade);
}

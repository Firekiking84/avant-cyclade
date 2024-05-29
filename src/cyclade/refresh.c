/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 27/05/2024 13:18:51 ******************************************************
** keryan.houssin <keryan.houssin@terechkova.efrits.fr>
** - Avant-Cyclade -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"cyclade.h"

void			efrefresh_cyclade(t_cyclade	*cyclade)
{
  if (!cyclade->simulation)
    bunny_vm110n_read(cyclade->card);
  else
    efread_simulation_vm110n(cyclade->card);
  if ((cyclade->card->analog_inputs[PI_A_CLOCK] > 0.5) != cyclade->prev_clock_state)
    {
      cyclade->prev_clock_state = (cyclade->card->analog_inputs[PI_A_CLOCK] > 0.5);
      if (cyclade->prev_clock_state == CS_WRITE)
	efwrite_cyclade(cyclade);
      else
	{
	  efread_cyclade(cyclade);
	  efmanage_rcv_data_cyclade(cyclade);
	}
    }
}

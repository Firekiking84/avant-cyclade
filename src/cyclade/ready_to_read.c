/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 24/05/2024 16:12:32 ******************************************************
** keryan.houssin <keryan.houssin@terechkova.efrits.fr>
** - Avant-Cyclade -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"cyclade.h"

static void		manage_making_entry(t_cyclade		*cyclade)
{
  if (cyclade->making_entry_left)
    {
      if (cyclade->card->digital_inputs[PI_CHECK_IN_RIGHT])
	{
	  cyclade->card->digital_outputs[PO_OUT1_LEFT] = cyclade->card->digital_inputs[PI_IN1_RIGHT];
	  cyclade->card->digital_outputs[PO_OUT2_LEFT] = cyclade->card->digital_inputs[PI_IN2_RIGHT];
	  cyclade->card->digital_outputs[PO_CHECK_OUT_LEFT] = cyclade->card->digital_inputs[PI_CHECK_IN_RIGHT];
	}
      else
	cyclade->making_entry_left = false;
    }
  if (cyclade->making_entry_right)
    {
      if (cyclade->card->digital_inputs[PI_CHECK_IN_LEFT])
	{
	  cyclade->card->digital_outputs[PO_OUT1_RIGHT] = cyclade->card->digital_inputs[PI_A_IN1_LEFT] > 0.5;
	  cyclade->card->digital_outputs[PO_OUT2_RIGHT] = cyclade->card->digital_inputs[PI_IN2_LEFT];
	  cyclade->card->digital_outputs[PO_CHECK_OUT_RIGHT] = cyclade->card->digital_inputs[PI_CHECK_IN_LEFT];
	}
      else
	cyclade->making_entry_right = false;
    }
}

static bool		check_state_msg(t_data_manager		*manager)
{
  if (manager->stage == SD_NONE)
    return(false);
  if (manager->stage != SD_DATA)
    efreset_data_manager(manager);
  else if (manager->stage == SD_DATA)
    {
      if (manager->data->info[SD_LEN_DATA].type != (uint32_t)manager->data->data->str_len)
	manager->data->info[SD_LEN_DATA].type = manager->data->data->str_len;
      return(true);
    }
  return(false);
}


static void		ready_to_read_side(t_cyclade		*cyclade,
					   t_data_stream	data_stream,
					   t_pin_input_num	check_in_pin)
{
  if (!cyclade->card->digital_inputs[check_in_pin])
    {
      if (check_state_msg(cyclade->data[data_stream]))
	{
	  efinit_data_manager(cyclade->data[data_stream]);
	  efpush_queue(cyclade->queue[data_stream], cyclade->data[data_stream]);
	  cyclade->data[data_stream] = efnew_data_manager();
	}
      cyclade->data[data_stream]->stage = SD_NONE;
    }
  else if (cyclade->data[data_stream]->stage == SD_NONE)
    cyclade->data[data_stream]->stage = SD_DEST;
}

void			efready_to_read_cyclade(t_cyclade	*cyclade)
{
  manage_making_entry(cyclade);
  ready_to_read_side(cyclade, DS_IN_LEFT, PI_CHECK_IN_LEFT);
  ready_to_read_side(cyclade, DS_IN_RIGHT, PI_CHECK_IN_RIGHT);
}

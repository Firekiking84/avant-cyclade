/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 27/05/2024 01:33:52 ******************************************************
** keryan.houssin <keryan.houssin@aldrin.efrits.fr>
** - Avant-Cyclade -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"cyclade.h"

static void		read_inputs(t_cyclade		*cyclade,
				    t_data_stream	data_stream,
				    t_pin_input_num	input_pin1,
				    t_pin_input_num	input_pin2)
{
  if (input_pin1 == PI_A_IN1_LEFT)
    {
      EDIT_BIT(cyclade->data[data_stream]->cur_byte,
	       cyclade->data[data_stream]->index_bit,
	       cyclade->card->analog_inputs[input_pin1] > 0.5);
    }
  else
    {
      EDIT_BIT(cyclade->data[data_stream]->cur_byte,
	       cyclade->data[data_stream]->index_bit,
	       cyclade->card->digital_inputs[input_pin1]);
    }
  cyclade->data[data_stream]->index_bit += 1;
  EDIT_BIT(cyclade->data[data_stream]->cur_byte,
	   cyclade->data[data_stream]->index_bit,
	   cyclade->card->digital_inputs[input_pin2]);
  cyclade->data[data_stream]->index_bit += 1;
}

static void		push_byte(t_data_manager	*data,
				  t_cyclade		*cyclade,
				  t_data_stream		data_stream)
{
  if (data->stage != SD_DATA)
    data->data->info[data->stage].bytes[data->index_byte] = data->cur_byte;
  else
    string_push_back(data->data->data, data->cur_byte);
  data->index_bit = 0;
  data->index_byte += 1;
  if (data->stage < SD_DATA && data->index_byte == 4)
    {
      data->index_byte = 0;
      data->stage += 1;
    }
  if (data->stage == SD_DATA && data->index_byte == data->data->info[SD_LEN_DATA].type)
    {
      efinit_data_manager(cyclade->data[data_stream]);
      efpush_queue(cyclade->queue[data_stream], data);
      cyclade->data[data_stream] = efnew_data_manager();
    }
}

void			efread_cyclade(t_cyclade	*cyclade)
{
  efready_to_read_cyclade(cyclade);
  if (cyclade->data[DS_IN_LEFT]->stage != SD_NONE)
    {
      read_inputs(cyclade, DS_IN_LEFT, PI_A_IN1_LEFT, PI_IN2_LEFT);
      if (cyclade->data[DS_IN_LEFT]->index_bit == 8)
	push_byte(cyclade->data[DS_IN_LEFT], cyclade, DS_IN_LEFT);
    }
  if (cyclade->data[DS_IN_RIGHT]->stage != SD_NONE)
    {
      read_inputs(cyclade, DS_IN_RIGHT, PI_IN1_RIGHT, PI_IN2_RIGHT);
      if (cyclade->data[DS_IN_RIGHT]->index_bit == 8)
	push_byte(cyclade->data[DS_IN_RIGHT], cyclade, DS_IN_RIGHT);
    }
}

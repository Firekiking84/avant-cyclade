/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 27/05/2024 01:33:41 ******************************************************
** keryan.houssin <keryan.houssin@aldrin.efrits.fr>
** - Avant-Cyclade -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"cyclade.h"

#include		<stdio.h>

static void		manage_index(t_cyclade			*cyclade,
				     t_data_stream		data_stream,
				     t_data_manager		*manager)
{
  manager->index_bit += 1;
  if (manager->index_bit == 8)
    {
      manager->index_bit = 0;
      manager->index_byte += 1;
      if (manager->stage != SD_DATA && manager->index_byte == 4)
	{
	  manager->index_byte = 0;
	  manager->stage += 1;
	}
      if (manager->stage == SD_DATA && manager->index_byte == manager->data->info[SD_LEN_DATA].type)
	{
	  efdelete_data_manager(manager);
	  cyclade->data[data_stream] = NULL;
	}
    }
}

static void		write_manager(t_cyclade			*cyclade,
				      t_data_stream		data_stream,
				      t_data_manager		*manager,
				      t_pin_output_num		*out_pins)
{
  t_my_int		info;

  if (manager->stage != SD_DATA)
    {
      info = manager->data->info[manager->stage];
      cyclade->card->digital_outputs[out_pins[0]] = GET_BIT(info.bytes[manager->index_byte],
							    manager->index_bit);
      manage_index(cyclade, data_stream, manager);
      cyclade->card->digital_outputs[out_pins[1]] = GET_BIT(info.bytes[manager->index_byte],
							    manager->index_bit);
      manage_index(cyclade, data_stream, manager);
    }
  else
    {
      cyclade->card->digital_outputs[out_pins[0]] = GET_BIT(manager->data->data->str[manager->index_byte],
							    manager->index_bit);
      manage_index(cyclade, data_stream, manager);
      cyclade->card->digital_outputs[out_pins[1]] = GET_BIT(manager->data->data->str[manager->index_byte],
							    manager->index_bit);
      manage_index(cyclade, data_stream, manager);
    }
}

static void		write_outputs(t_cyclade			*cyclade,
				      t_data_stream		data_stream,
				      t_pin_output_num		check_pin,
				      t_pin_output_num		*out_pins)
{
  if (!cyclade->data[data_stream] && cyclade->card->digital_outputs[check_pin])
    cyclade->card->digital_outputs[check_pin] = false;
  else if (!cyclade->data[data_stream] && !cyclade->card->digital_outputs[check_pin])
    {
      cyclade->data[data_stream] = efpop_queue(cyclade->queue[data_stream]);
      cyclade->card->digital_outputs[check_pin] = (cyclade->data[data_stream] != NULL);
      efinit_data_manager(cyclade->data[data_stream]);
    }
  if (cyclade->data[data_stream])
      write_manager(cyclade, data_stream, cyclade->data[data_stream], out_pins);
}

void			efwrite_cyclade(t_cyclade		*cyclade)
{
  t_pin_output_num	out_pins[2];

  if (!cyclade->making_entry_left)
    {
      out_pins[0] = PO_OUT1_LEFT;
      out_pins[1] = PO_OUT2_LEFT;
      write_outputs(cyclade, DS_OUT_LEFT, PO_CHECK_OUT_LEFT, out_pins);
    }
  if (!cyclade->making_entry_right)
    {
      out_pins[0] = PO_OUT1_RIGHT;
      out_pins[1] = PO_OUT2_RIGHT;
      write_outputs(cyclade, DS_OUT_RIGHT, PO_CHECK_OUT_RIGHT, out_pins);
    }
  if (!cyclade->simulation)
    bunny_vm110n_write(cyclade->card);
  else
    efwrite_simulation_vm110n(cyclade->card);
}

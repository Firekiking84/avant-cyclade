/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 27/05/2024 11:46:50 ******************************************************
** keryan.houssin <keryan.houssin@terechkova.efrits.fr>
** - Avant-Cyclade -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"cyclade.h"

#include		<stdio.h>

static void		print_rcv_data(t_cyclade		*cyclade,
				       t_data_manager		*manager)
{
  printf("%u ", cyclade->id);
  if (manager->data->info[SD_EMETTOR].type != cyclade->id)
    printf(" received from %u : %s\n", manager->data->info[SD_EMETTOR].type,
	   manager->data->data->str);
  else
    efmanage_discover_result_cyclade(cyclade, manager->data);
  efdelete_data_manager(manager);
}

static void		manage_other_discover(t_cyclade		*cyclade,
					      t_data_manager	*manager,
					      t_data_stream	data_stream)
{
  t_my_int		id;

  manager->data->info[SD_LEN_DATA].type += 4;
  id.type = cyclade->id;
  string_push_back(manager->data->data, id.bytes[0]);
  string_push_back(manager->data->data, id.bytes[1]);
  string_push_back(manager->data->data, id.bytes[2]);
  string_push_back(manager->data->data, id.bytes[3]);
  if (data_stream == DS_IN_LEFT)
    efpush_queue(cyclade->queue[DS_OUT_RIGHT], manager);
  else
    efpush_queue(cyclade->queue[DS_OUT_LEFT], manager);
}


static void		efmanage_rcv_side_data(t_cyclade	*cyclade,
					       t_data_stream	data_stream)
{
  t_data_manager	*manager;

  manager = efpop_queue(cyclade->queue[data_stream]);
  if (!manager)
    return;
  if (manager->data->info[SD_DEST].type == cyclade->id)
    print_rcv_data(cyclade, manager);
  else if (manager->data->info[SD_DEST].type == manager->data->info[SD_EMETTOR].type)
    manage_other_discover(cyclade, manager, data_stream);
  else
    {
      if (data_stream == DS_IN_LEFT)
	efpush_queue(cyclade->queue[DS_OUT_RIGHT], manager);
      else
	efpush_queue(cyclade->queue[DS_OUT_LEFT], manager);
    }
}

void			efmanage_rcv_data_cyclade(t_cyclade	*cyclade)
{
  efmanage_rcv_side_data(cyclade, DS_IN_LEFT);
  efmanage_rcv_side_data(cyclade, DS_IN_RIGHT);
}

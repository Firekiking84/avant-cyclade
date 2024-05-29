/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 27/05/2024 13:56:40 ******************************************************
** keryan.houssin <keryan.houssin@terechkova.efrits.fr>
** - Avant-Cyclade -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"cyclade.h"

#include		<stdio.h>

static void		set_cyclade_attribut(t_cyclade			*cyclade,
					     t_data			*data)
{
  cyclade->nb_ids = data->info[SD_LEN_DATA].type / 4;
  if (cyclade->network_ids)
    bunny_free(cyclade->network_ids);
  cyclade->network_ids = bunny_malloc(sizeof(uint32_t) * cyclade->nb_ids);
  if (!cyclade->network_ids)
    {
      bunny_perror("Error alloc network ids");
      cyclade->nb_ids = 0;
    }
}

void			efmanage_discover_result_cyclade(t_cyclade	*cyclade,
							 t_data		*data)
{
  uint32_t		i;
  int			index_str;
  t_my_int		id;

  printf("User currently on your network : \n");
  i = 0;
  index_str = 0;
  set_cyclade_attribut(cyclade, data);
  while (i < cyclade->nb_ids)
    {
      id.bytes[0] = data->data->str[index_str];
      index_str += 1;
      id.bytes[1] = data->data->str[index_str];
      index_str += 1;
      id.bytes[2] = data->data->str[index_str];
      index_str += 1;
      id.bytes[3] = data->data->str[index_str];
      index_str += 1;
      printf("\t- %u\n", id.type);
      if (cyclade->network_ids)
	cyclade->network_ids[i] = id.type;
      i += 1;
    }
}


#include		"data_manager.h"

t_data_manager		*efcopy_data_manager(t_data_manager	*other)
{
  t_data_manager	*new;

  new = efnew_data_manager_settings(other->data->info[SD_DEST].type,
				    other->data->info[SD_EMETTOR].type,
				    other->data->info[SD_LEN_DATA].type,
				    other->data->data->str);
  if (!new)
    return(NULL);
  new->stage = other->stage;
  new->index_byte = other->index_byte;
  new->index_bit = other->index_bit;
  new->cur_byte = other->cur_byte;
  return(new);
}

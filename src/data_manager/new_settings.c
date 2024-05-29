#include		"data_manager.h"

void			*short_return(const char		*err_msg)
{
  bunny_perror(err_msg);
  return(NULL);
}

t_data			*new_data_settings(uint32_t		dest_id,
					   uint32_t		emettor_id,
					   uint32_t		len_data,
					   const char		*set_data)
{
  t_data		*data;
  uint32_t		i;

  data = bunny_malloc(sizeof(t_data));
  if (!data)
    return(short_return("Error bunny_malloc new_data"));
  data->info[SD_DEST].type = dest_id;
  data->info[SD_EMETTOR].type = emettor_id;
  data->info[SD_LEN_DATA].type = len_data;
  data->data = efstring_new();
  if (!set_data || efstring_resize(data->data, len_data) == -1)
    return(data);
  i = 0;
  while (i < len_data)
    {
      string_push_back(data->data, set_data[i]);
      i += 1;
    }
  return(data);
}

t_data_manager		*efnew_data_manager_settings(uint32_t	dest_id,
						     uint32_t	emettor_id,
						     uint32_t	len_data,
						     const char	*data)
{
  t_data_manager	*manager;

  manager = bunny_malloc(sizeof(t_data_manager));
  if (!manager)
    return(short_return("Error bunny_malloc new_data_manager_settings "));
  efinit_data_manager(manager);
  manager->stage = SD_NONE;
  manager->data = new_data_settings(dest_id, emettor_id, len_data, data);
  if (!manager->data)
    {
      bunny_free(manager);
      return(NULL);
    }
  return(manager);
}

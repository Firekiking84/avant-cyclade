#ifndef		__DATA_MANAGER_H__

#define		__DATA_MANAGER_H__

#include	"efstring.h"

#include	<stddef.h>
#include	<lapin.h>

typedef enum		e_stage_data // Need to work with s_data->info
  {
    SD_NONE = -1,
    SD_DEST,
    SD_EMETTOR,
    SD_LEN_DATA,
    SD_DATA
  }			t_stage_data;

typedef union		u_my_int
{
  uint32_t		type;
  char			bytes[4];
}			t_my_int;

typedef struct		s_data
{
  t_my_int		info[3]; // work with enum e_stage_data
  t_string		*data;
}			t_data;

typedef struct		s_data_manager
{
  t_stage_data		stage;
  uint32_t		index_byte;
  uint32_t		index_bit;
  char			cur_byte;
  t_data		*data;
}			t_data_manager;

t_data_manager		*efnew_data_manager();
t_data_manager		*efcopy_data_manager(t_data_manager	*other);
t_data_manager		*efnew_data_manager_settings(uint32_t	dest_id,
						     uint32_t	emettor_id,
						     uint32_t	len_data,
						     const char	*data);
void			efdelete_data_manager(t_data_manager	*data);
void			efinit_data_manager(t_data_manager	*manager);
void			efreset_data_manager(t_data_manager	*data);
void			efdata_to_string(t_string		*str,
					 void			*data,
					 uint32_t		size_data);

#endif	//	__DATA_MANAGER_H__

/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 27/05/2024 01:39:31 ******************************************************
** keryan.houssin <keryan.houssin@aldrin.efrits.fr>
** - Avant-Cyclade -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"data_manager.h"

void			efdata_to_string(t_string	*str,
					 void		*data,
					 uint32_t	size_data)
{
  uint32_t		i;
  char			*data_str;

  data_str = (char *)data;
  string_clear(str);
  i = 0;
  while (i < size_data)
    {
      string_push_back(str, data_str[i]);
      i += 1;
    }
}

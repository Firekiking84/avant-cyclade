/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 27/05/2024 01:39:11 ******************************************************
** keryan.houssin <keryan.houssin@aldrin.efrits.fr>
** - Avant-Cyclade -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"efstring.h"

#include		<stdlib.h>
#include		<string.h>

int			string_append_str(t_string		*string,
					  const char		*str)
{
  int			len_str;

  len_str = strlen(str);
  if ((string->str_len + len_str) > string->size_alloc)
    if (efstring_resize(string, (string->str_len + len_str + 1)) == -1)
      return(-1);
  strcat(string->str, str);
  string->str_len += len_str;
  return(0);
}

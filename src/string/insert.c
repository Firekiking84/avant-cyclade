/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 27/05/2024 01:38:50 ******************************************************
** keryan.houssin <keryan.houssin@aldrin.efrits.fr>
** - Avant-Cyclade -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"efstring.h"

#include		<stdlib.h>

int			string_insert(t_string			*string,
				      int			index,
				      char			c)
{
  int			i;

  if (index < 0 || index > string->str_len)
    return(-1);
  if (!string->str || index == string->str_len)
    return(string_push_back(string, c));
  string->str_len += 1;
  if (string->str_len == string->size_alloc)
    {
      if (efstring_resize(string, string->size_alloc + 10) == -1)
	return(-1);
    }
  i = string->str_len;
  while (i > index)
    {
      string->str[i] = string->str[i - 1];
      i -= 1;
    }
  string->str[i] = c;
  return(0);
}

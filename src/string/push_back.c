/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 27/05/2024 01:36:24 ******************************************************
** keryan.houssin <keryan.houssin@aldrin.efrits.fr>
** - Avant-Cyclade -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"efstring.h"
#include		<stdlib.h>

int			string_push_back(t_string	*string,
					 char		c)
{
  if (!string->str)
    {
      string->size_alloc = 2;
      string->str = bunny_malloc(sizeof(char) * string->size_alloc);
      if (!string->str)
	return(-1);
      string->str_len = 0;
    }
  string->str_len += 1;
  if (string->str_len == string->size_alloc)
    {
      if (efstring_resize(string, string->size_alloc + 10) == -1)
	return(-1);
    }
  string->str[string->str_len - 1] = c;
  string->str[string->str_len] = '\0';
  return(0);
}

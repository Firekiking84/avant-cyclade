/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 27/05/2024 01:38:58 ******************************************************
** keryan.houssin <keryan.houssin@aldrin.efrits.fr>
** - Avant-Cyclade -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include		"efstring.h"

int			string_erase(t_string		*string,
				     int		index)
{
  int			i;

  if (string->str_len > 0 && index >= 0 && index < string->str_len)
    {
      i = index;
      while (i < string->str_len)
	{
	  string->str[i] = string->str[i + 1];
	  i += 1;
	}
      string->str_len -= 1;
      return(1);
    }
  return(0);
}

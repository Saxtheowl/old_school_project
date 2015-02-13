#include <stdlib.h>
#include "../my.h"

int		is_full_space(char *tab)
{
  int i;

  i = 0;
  while (tab[i] != '\n')
    {
      if (tab[i] != ' ')
	return (1);
      if (tab[i + 1] == '\n')
	return (0);
      i = i + 1;
    }
}

int		is_full_space2(char *tab)
{
  int i;
  
  i = 0;
  while (tab[i] != '\0')
    {
      if (tab[i] != ' ')
	return (1);
      if (tab[i + 1] == '\0')
	return (0);
       i = i + 1;
       }
  return(0);
}

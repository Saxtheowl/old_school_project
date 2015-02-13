#include "../my.h"

int		*put_zero(int *tab)
{
  int		i;

  i = 0;
  while (tab[i])
    {
      tab[i] = 0;
      i++;
    }
  return (tab);
}

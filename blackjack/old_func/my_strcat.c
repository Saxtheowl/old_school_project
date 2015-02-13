#include "../my.h"

char		*my_strncat(char *dest, char *src, int nb)
{
  int		i;
  int		f;

  i = 0;
  f = 0;
  while (dest && dest[i])
    i = i + 1;
  while (f < nb)
    {
      dest[i] = src[f];
      i = i + 1;
      f = f + 1;
    }
  dest[i] = '\0';
  return (dest);
}

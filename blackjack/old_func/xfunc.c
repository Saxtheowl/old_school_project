#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../my.h"

void	*xmalloc(int size)
{
  void	*ptr;

  if ((ptr = malloc(size)) == NULL)
    {
      my_putstr("CANT MALLOC SRY\n");
      exit(0);
    }
  return (ptr);
}

int		xread(int place, void *buffer, int nbbyte)
{
  int		nb;

  nb = read(place, buffer, nbbyte);
  if (nb == -1)
    {
      my_putstr("CANT READ SRY\n");
      exit(0);
    }
  return (nb);
}

int		xwrite(int place, void *buffer, int nbbyte)
{
  int		nb;

  nb = write(place, buffer, nbbyte);
    if (nb == -1)
      {
	my_putstr("CANT WRITE SRY\n");
	exit(0);
      }
  return (nb);
}

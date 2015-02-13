#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../my.h"
#include "../my_list.h"

void    *xmalloc(int size)
{
  void    *ptr;

  if ((ptr = malloc(size)) == NULL)
    {
      printf("CANT MALLOC SRY\n");
      my_exit();
    }
  return (ptr);
}

int		xfork()
{
  pid_t		pid;
  int		i;

  if ((pid = fork()) == -1)
    {
      printf("CANT FORK SRY");
      my_exit();
    }
  return (pid);
}

int		xread(int place, void *buffer, int nbbyte)
{
  int		nb;

  nb = read(place, buffer, nbbyte);
  if (nb == -1)
    {
      printf("CANT READ SRY\n");
      my_exit();
    }
  return (nb);
}

int		xwrite(int place, void *buffer, int nbbyte)
{
  int		nb;

  nb = write(place, buffer, nbbyte);
    if (nb == -1)
      {
	printf("CANT WRITE SRY\n");
	my_exit();
      }
  return (nb);
}

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "../my_list.h"
#include "../my.h"

int	my_exit()
{
  pid_t	pid;
  int	i;

  pid = getpid();
  i = kill(pid, SIGQUIT);
  if (i == -1)
    return (-1);
  return (0);
}

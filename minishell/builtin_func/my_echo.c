#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "../my_list.h"
#include "../my.h"


int		launch_echo(char **commands, t_envlist **env_cp)
{
  int		i;
  int		flag;

  i = 1;
  flag = 0;
  if(commands[1] == 0)
    {
      printf("\n");
      return(0);
    }
  if(strcmp(commands[1], "-n") == 0)
    {
      flag = 1;
      i = 2;
    }
  while(commands[i])
    {
      printf("%s\n", commands[i]);
      i++;
    }
  if(flag == 0)
    printf("\n");
  return(0);
}

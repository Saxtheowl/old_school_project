#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>
#include "my_list.h"
#include "my.h"

int		main(int ac, char **av, char **env)
{
  int		i;
  t_envlist     **env_cp;

  i = 0;
  if(env[i] == NULL)
    {
      printf("NO ENV DETECTED :D\n");
      return(0);
    }
  make_env(env, &env_cp);
  while (42)
    hook_all(env_cp);
  free(env_cp);
}

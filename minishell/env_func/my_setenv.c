#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../my_list.h"
#include "../my.h"

int             my_setenv(char *name, char *info, t_envlist **env_cp)
{
  t_envlist	*tmp;
  char		*save_pwd;

  tmp = *env_cp;
  while (tmp != NULL)
    {
      if (strcmp(tmp->name, name) == 0)
        {
          free(tmp->info);
          tmp->info = malloc(sizeof(*info) * (strlen(info) + 1));
          strcpy(tmp->info, info);
          return (0);
        }
      tmp = tmp->next;
    }
  my_put_end_listt(env_cp, name, info);
  return (0);
}

int		verif_setenv_func(char **commands, t_envlist **env_cp)
{
  int		i;
  char		**dbtab;

  dbtab = xmalloc(sizeof(*dbtab) * 1);
  dbtab[0] = strdup("env");
  i = 0;
  if(commands[1] == 0)
    {
      exec_env_func(dbtab, env_cp, 1);
      return(0);
    }
  while(commands[1][i])
    {
      if(commands[1][i] == '=')
	{
	  printf("setenv: Syntax Error.\n");
	  return(0);
	}
      i++;
    }
  if(commands[2] == 0)
    my_setenv(commands[1], "", env_cp);
  else
    my_setenv(commands[1], commands[2], env_cp);
  return(0);
}

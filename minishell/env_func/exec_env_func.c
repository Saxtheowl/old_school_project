#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../my_list.h"
#include "../my.h"

int		exec_env_func(char **commands, t_envlist **env_cp, int choice)
{
  t_envlist *start;
  
  start = *env_cp;
  if (choice == 1 || strcmp(commands[0], "env") == 0)
    {
      while ((*env_cp) != NULL)
	{
	  printf("%s=%s\n", (*env_cp)->name, (*env_cp)->info);
	  (*env_cp) = (*env_cp)->next;
	}
      *env_cp = start;
      return(0);
    }
  else if(strcmp(commands[0], "setenv") == 0)
      verif_setenv_func(commands, env_cp);
  else if(strcmp(commands[0], "unsetenv") == 0)
    {
      if(commands[1] == 0)
	{
	  printf("unsetenv: Too few arguments.\n");
	  return(0);
	}
      my_unsetenv(commands[1], env_cp);
    }
}

int		launch_pwd(char **commands, t_envlist **env_cp)
{
  t_envlist	*start;

  start = *env_cp;
  while((*env_cp) != NULL)
    {
      if(strcmp((*env_cp)->name, "PWD") == 0)
	printf("%s\n", (*env_cp)->info);
      (*env_cp) = (*env_cp)->next;
    }
  *env_cp = start;
}

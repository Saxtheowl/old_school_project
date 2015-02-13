#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "../my_list.h"
#include "../my.h"

int		launch_cd(char **commands, t_envlist **env_cp)
{
  char		**saved_path;
  t_envlist	*start;

  start = *env_cp;
  saved_path = xmalloc(sizeof(*saved_path) * 2);
  while((*env_cp) != NULL)
    {
      if(strcmp((*env_cp)->name, "HOME") == 0)
	saved_path[0] = strdup((*env_cp)->info);
      else if(strcmp((*env_cp)->name, "PWD") == 0)
	saved_path[1] = strdup((*env_cp)->info);
      (*env_cp) = (*env_cp)->next;
    }
  *env_cp = start;
  if(commands[1] == 0 || (is_full_space2(commands[1]) && commands[1] == 0 || (commands[2] == 0 
    && commands[1][0] == '~' && commands[1][1] == '\0')))
    {
      if(test_chdir(saved_path, env_cp))
	return(0);
    } 
  moar_cd(commands ,env_cp);
}

int		moar_cd(char **commands, t_envlist **env_cp)
{
  char		**saved_path;
  t_envlist	*start;

  start = *env_cp;
  saved_path = xmalloc(sizeof(*saved_path) * 2);
  while((*env_cp) != NULL)
    {
      if(strcmp((*env_cp)->name, "SAVED_PATH") == 0)
	saved_path[0] = strdup((*env_cp)->info);
      else if(strcmp((*env_cp)->name, "PWD") == 0)
	saved_path[1] = strdup((*env_cp)->info);
      (*env_cp) = (*env_cp)->next;
    }
  (*env_cp) = start;
  moar_cd2(commands, env_cp, saved_path);
}

int		moar_cd2(char **commands, t_envlist **env_cp, char **saved_path)
{
  t_envlist	*start;

  if(commands[1][0] == '-' && commands[1][1] == '\0')
    {
      if(chdir(saved_path[0]) == -1)
	{
	  printf("%s: No such file or directory.\n", saved_path[0]);
	  return(0);
	}
      my_setenv("PWD", saved_path[0], env_cp);
      my_setenv("SAVED_PATH", saved_path[1], env_cp);
      return(0);
    }
    moar_cd3(commands, env_cp, saved_path);
}

int		moar_cd3(char **commands, t_envlist **env_cp, char **saved_path)
{  

  if(!(chdir(commands[1])))
    {
      my_setenv("SAVED_PATH", saved_path[1], env_cp);
      my_setenv("PWD", commands[1], env_cp);
      return(0);
    }
  else
    {
      printf("%s: No such file or directory.\n", commands[1]);
      return(0);
    }
}

int		test_chdir(char **saved_path, t_envlist **env_cp)
{
    if(chdir(saved_path[0]) == -1)
    {
      printf("%s: No such file or directory.\n", saved_path[0]);
      return(1);
      }
    else
    {
      my_setenv("PWD", saved_path[0], env_cp);
      my_setenv("SAVED_PATH", saved_path[1], env_cp);
      return(1);
    }
}


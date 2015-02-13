#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../my_list.h"
#include "../my.h"

int             my_unsetenv(char *name, t_envlist **env_cp)
{
  t_envlist      *tmp;
  t_envlist      *prev;

  tmp = *env_cp;
  if (*env_cp != 0)
    if (strcmp((*env_cp)->name, name) == 0)
      {
        prev = (*env_cp)->next;
	// free((*env_cp)->info);
        //free((*env_cp)->name);
        //free(*env_cp);
        *env_cp = prev;
        return (0);
      }
  my_unsetenvv(name, env_cp);
}

int             my_unsetenvv(char *name, t_envlist **env_cp)
{
  t_envlist      *tmp;
  t_envlist      *prev;

  tmp = *env_cp;
  while (tmp->next != NULL)
    {
      if (strcmp(tmp->next->name, name) == 0)
        {
          prev = tmp->next->next;
          //free(tmp->next->info);
          //free(tmp->next->name);
          //free(tmp->next);
          tmp->next = prev;
          return (0);
        }
      tmp = tmp->next;
    }
  return (0);
}

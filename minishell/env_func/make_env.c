#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../my_list.h"
#include "../my.h"

char            *place_data(char *str, int i)
{
  int           f;
  char          *data;

  f = 0;
  data = malloc(sizeof(*data) * (strlen(str) + 1));
  if(i == 0)
    {
      while(str[i] != '=')
        {
          data[i] = str[i];
          i++;
        }
      data[i] = '\0';
      return(data);
    }
  while(str[i] != '\0')
    {
      data[f++] = str[i++];
      data[f] = '\0';
    }
  return(data);
}

void            make_env(char **env, t_envlist **new_env)
{
  int           i;
  int           f;
  char          *data_name;
  char          *data_info;

  i = 0;
  f = 0;
  //  *new_env = NULL;
  while (env[i] != NULL)
    {
      data_name = place_data(env[i], 0);
      while(env[i][f] != '=')
        f++;
      data_info = place_data(env[i], f + 1);
      if(strcmp("PWD", data_name) == 0)
	my_setenv("SAVED_PWD", data_info, new_env);
      my_setenv(data_name, data_info, new_env);
      i++;
      f = 0;
      //free(data_name);
      //free(data_info);
    }
}

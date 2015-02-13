#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../my_list.h"
#include "../my.h"

int		elemlen(t_envlist *list)
{
  int		i;

  i = strlen(list->name);
  i = i + strlen(list->info);
  return(i);
}

int		nb_elem(t_envlist *list)
{
  int		i;

  i = 0;
  while(list != NULL)
    {
      list = list->next;
      i++;
    }
  return(i);
}

void		copy_elem(t_envlist *list, char *str)
{
  strcpy(str, list->name);
  strcat(str, "=");
  strcat(str, list->info);
}

char		**trans_list_to_dbtab(t_envlist **list)
{
  char		**dbtab;
  int		i;
  t_envlist	*start;

  i = 0;
  dbtab = xmalloc(sizeof(*dbtab)* nb_elem((*list)) + 1);
  start = *list;
  while((*list) != NULL)
    {
      dbtab[i] = xmalloc(sizeof(**dbtab) * elemlen((*list)) +2);
      copy_elem((*list), dbtab[i]);
      (*list) = (*list)->next;
      i++;
    }
  dbtab[i] = NULL;
  *list = start;
  return(dbtab);
}

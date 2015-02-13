#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../my_list.h"
#include "../my.h"

int             my_put_in_listt(t_envlist **list, void *name, void *info)
{
  t_envlist        *new;

  if ((new = malloc(sizeof(*new) * 1)) == NULL)
    return (1);
  new->next = *list;
  *list = new;
  if (name != NULL)
    {
      new->name = malloc(sizeof(*name) * (strlen(name) + 1));
      strcpy(new->name, name);
    }
  if (info != NULL)
    {
      new->info = malloc(sizeof(*info) * (strlen(info) + 1));
      strcpy(new->info, info);
    }
  return (0);
}

int		my_put_end_listt(t_envlist **list, void *name, void *info)
{
  t_envlist	*save;
  t_envlist	*new;

  if (*list == NULL)
    return (my_put_in_listt(list, name, info));
  save = *list;
  if ((new = malloc(sizeof(*new) * 1)) == NULL)
    return (1);
  while (save->next != NULL)
    save = (save)->next;
  if (name != NULL)
    {
      new->name = malloc(sizeof(*name) * (strlen(name) + 1));
      strcpy(new->name, name);
    }
  if (info != NULL)
    {
      new->info = malloc(sizeof(*info) * (strlen(info) + 1));
      strcpy(new->info, info);
    }
  //  new->name = name;
  //  new->prev = save;
  new->next = NULL;
  save->next = new;
  return (0);
}


void        my_rev_list(t_envlist **begin)
{
  t_envlist    *tmp;
  t_envlist    *next;
  t_envlist    *prevv;

  prevv = NULL;
  tmp = *begin;
  while ((*begin) != NULL)
    {
      next = (*begin)->next;
      (*begin)->next = prevv;
      prevv = tmp;
      tmp = next;
      *begin = next;
    }
  *begin = prevv;
}

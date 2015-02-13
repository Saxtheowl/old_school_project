#ifndef         __MY_LIST_H__
#define         __MY_LIST_H__


typedef struct          s_envlist
{
  struct s_envlist      *next;
  char                  *name;
  char                  *info;
}                       t_envlist;


#endif /* __MY_LIST_H__ */

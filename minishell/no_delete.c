#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "my_list.h"
#include "my.h"

void		my_putchar(char c)
{
  xwrite(1, &c, 1);
}

int		my_strlen(char *str)
{
  int i;

  i = 0;

  while (str[i] != '\0')
    i++;
  return (i);
}

void		print_sup_number()
{
  my_putstr("-2147483648");
}

int		some_calc(int nb)
{
   if (nb < 0)
    {
      my_putchar(45);
      nb = nb * -1;
    }
  return (nb);
}

int		my_put_nbr(int nb)
{
  int	p;
  char	b;
  int	test_div;
  int	save_nb;

  p = 1;
  if (nb < - 2147483647)
    {
      print_sup_number();
      return (0);
    }
  nb = some_calc(nb);
  save_nb = nb;
  while (nb >= 10)
    {
      p = p * 10;
      nb = nb / 10;
    }
  while (p > 0)
    {
      b = save_nb / p;
      save_nb = save_nb % p;
      my_putchar(b + '0');
      p = p / 10;
    }
}


char		*epur_strrr(char *str, int i, int j)
{
  char		*str2;

  while (str[i] != '\0')
    {
      str2[j++] = str[i++];
      if (str[i] == ' ' || str[i] == '\t')
	{
	  str2[j++] = ' ';
	  while (str[i] == ' ' || str[i] == '\t')
	    i++;
	}
    }
  return (str2);
}

char		*epur_strr(char *str)
{
  char		*str2;
  int		i;
  int		j;

  i = 0;
  j = 0;
  str2 = xmalloc(sizeof(str2) * my_strlen(str));
  while (str[i] == ' ' || str[i] == '\t' || str[i] == ';')
    i = i + 1;
  str2 = epur_strrr(str, i, 0);
  return (str2);
}

char	        *my_strncpyy(char *str, char *str2, int i)
{
  int i2;

  i2 = 0;
  while (str[i] != '\0' && str[i] != ' ')
    {
      str2[i2] = str[i];
      i2 = i2 + 1;
      i = i + 1;
    }
  return (str2);
}

char		**str_to_wordtabb(char *str)
{
  char		**dbtab;
  int		i;
  int		j;

  i = 0;
  j = 0;
  str = epur_strr(str);
  dbtab = xmalloc(sizeof(dbtab) * my_strlenn(str));
  while (str[i] != '\0')
    {
      dbtab[j] = xmalloc(sizeof(dbtab[j]) * my_strlennn(str, i));
      dbtab[j] = my_strncpyy(str, dbtab[j], i);
      i = my_strlennn(str, i) + 1;
      j++;
    }
  dbtab[j + 1] = NULL;
  return (dbtab);
}


int		my_strlenn(char *str)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      i++;
      if (str[i] == ' ')
	j++;
    }
  return (j + 1);
}

int		my_strlennn(char *str, int i)
{
  while (str[i] != ' ' && str[i] != '\0')
    i++;
  return (i);
}

void		print_dbtab(char **dbtab)
{
  int		i;

  i = 0;
  while (dbtab[i])
    {
      my_putstr(dbtab[i]);
      my_putchar('\n');
      i = i + 1;
    }
}

int		my_strlen_dbtab(char **dbtab)
{
  int		i;
  int		j;
  int		k;

  i = 0;
  j = 0;
  k = 0;
  while (dbtab[i] != '\0')
    {
      while (dbtab[i][j] != '\0')
      {
	j = j + 1;
      }
    i = i + 1;
    k = k + j;
    j = 0;
    }
  return (k);
}

char		*copy_next_line_dbtab(char **env_cp)
{
  static  int	i;
  int		f;
  char		*tab;

  f = 0;
  tab = xmalloc(sizeof(tab) * 3000);
  while (env_cp[i][f] )
    {
      tab[f] = env_cp[i][f];
      f = f + 1;
    }
  i = i + 1;
  tab[f + 1] = '\0';
  return (tab);
}

char		**copy_env(char **env_cp)
{
  char		**env_cpp;
  char		*str;
  int		i;

  i = 0;
  env_cpp = xmalloc(sizeof(str) * (my_strlen_dbtab(env_cp)));
  while (env_cp[i] != NULL)
    {
      env_cpp[i] = copy_next_line_dbtab(env_cp);
      i = i + 1;
    }
  env_cpp[i] = NULL;
  return (env_cpp);
}

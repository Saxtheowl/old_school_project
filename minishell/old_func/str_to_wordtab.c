#include <stdlib.h>
#include <string.h>
#include "../my.h"

void		my_strncpy(char *dest, char *src, int n)
{
  int i;

  i = 0;
  while(i < n)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
}


int		word_len(char *str)
{
  int i;

  i = 0;
  while(str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
    {
      i++;
    }
  return(i);
}

int		nb_word(char *str)
{
  int i;
  int nb_wordd;

  i = 0;
  nb_wordd = 0;
  while(str[i] != '\0' && str[i] != '\n')
    {
      while(str[i] == ' ' || str[i] == '\t' && str[i] != '\0')
	i++;
      if(str[i] != ' ' && str[i] != '\t' && str[i] != '\0' && str[i] != '\n')
	{
	  nb_wordd++;
	  while(str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
	    i++;
	}
    }
  return(nb_wordd);
}


char		**str_to_wordtab(char *str)
{
  int		i;
  int		f;
  int		nb_wordd;
  char		**dbtab;

  i = 0;
  f = 0;
  nb_wordd = nb_word(str);
    dbtab = malloc(sizeof(*dbtab) * nb_wordd + 1);
  while(f != nb_wordd)
    {
      while(str[i] == ' ' || str[i] == '\t' && str[i] != '\0')
	i++;
      if(str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
	{
	  dbtab[f] = malloc(sizeof(**dbtab) * word_len(&str[i]));
	  memset(dbtab[f], 0, word_len(&str[i])); /* useless shit */
	  my_strncpy(dbtab[f], &str[i], word_len(&str[i]));
	  f++;
	  i = i + word_len(&str[i]);
	}
    }
  dbtab[f] = NULL;
  return(dbtab);
}

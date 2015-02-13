void		my_strcpy(char *dest, char *src)
{
  int		i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
}

void		my_strncpy(char *dest, char *src, int n)
{
  int		i;

  i = 0;
  while (src[i] && i < n)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
}

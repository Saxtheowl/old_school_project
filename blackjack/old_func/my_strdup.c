#include <stdlib.h>
#include "../my.h"

char		*my_strdup(char *str)
{
  char		*to_copy;

  to_copy = xmalloc(sizeof(*to_copy) * (my_strlen(str) + 1));
  if (to_copy == NULL)
    return (NULL);
  my_strcpy(to_copy, str);
  return (to_copy);
}

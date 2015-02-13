#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "../my_list.h"
#include "../my.h"

int		exec_all(t_envlist **env_cp, char **commands)
{
  char		*path;
  char		**dbtab_env;
  int		status;
  pid_t		pid;

  dbtab_env = trans_list_to_dbtab(env_cp);
  path = xmalloc(sizeof(*path) * 100);
  path = strdup("/bin/");
  strncat(path, commands[0], strlen(commands[0]));
  pid = fork();
  if(pid == 0)
    execve(path, commands, dbtab_env);
  else
    {
      wait(&status);
      return(1);
    }
}

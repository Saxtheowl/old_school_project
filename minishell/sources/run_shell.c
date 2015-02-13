#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>
#include "../my_list.h"
#include "../my.h"

int		test_first_command(char **commands)
{
  if (is_full_space(commands[0]) != 1)
    return (3);
  else
    {
      print_not_found(commands[0]);
      printf(": command not found.\n");
    }
  return (3);
}

char		**some_epur(char **commands)
{
  int		i;
  char		*new_str;

  i = 0;
  while(commands[i + 1])
    i++;
  new_str = malloc(sizeof(*new_str) * strlen(commands[i]));
  strncat(new_str, commands[i], strlen(commands[i]) -1);
  commands[i] = strdup(new_str);
  return(commands);
}

char		**run(char **commands, t_envlist **env_cp)
{
  if (strcmp(commands[0], "exit") == 0)
    {
      exit(1);
      //    my_exit();
    }
  else if(strcmp(commands[0], "cd") == 0)
    {
      launch_cd(commands, env_cp);
      return(0);
    }
  else if(strcmp(commands[0], "echo") == 0)
    {
      launch_echo(commands, env_cp);
      return(0);
    }
  else if(strcmp(commands[0], "pwd") == 0)
    {
      launch_pwd(commands, env_cp);
      return(0);
    }
  else  if(!(exec_env_func(commands, env_cp, 0)))
    return(0);
  else if(exec_all(env_cp, commands) == 1)
    return(0);
  test_first_command(commands);
  return(0);
}

int		hook_all(t_envlist **env_cp)
{
  char		*save;
  char		*prompt;
  char		**commands;
  char		**env_cpp;

  prompt = "$>";
  my_putstr(prompt);
  save = hook_full_instr();
  commands = str_to_wordtab(save);
  if(commands[0] != NULL)
    {
      commands = some_epur(commands);
      run(commands, env_cp);
    }
}

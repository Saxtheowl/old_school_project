#include <time.h>
#include <stdlib.h>
#include "my.h"

int		main_menu()
{
  char		*commands;
  char		*prompt;

  my_putstr("\nWelcome to the game of blackjack\n\n");
  my_putstr("Enter 1, 2, or 3 for\n\n");
  my_putstr("1 - Launch the game\n\n2 - Read the rules and option");
  my_putstr(" about this game\n\n");
  my_putstr("3 - Quit the game\n\n");
  commands = put_prompt();
  if (my_strcmp(commands, "1") == 0)
    start_game(1);
  else if (my_strcmp(commands, "2") == 0)
    print_rules();
  else if (my_strcmp(commands, "3") == 0)
    exit(0);
  else
    main_menu();
}

int		main()
{
  main_menu();
}

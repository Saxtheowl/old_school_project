#ifndef		__MY_H__
# define       	__MY_H__

#include "my_list.h"

int		is_even(int);
int		my_getnbr(char *);
void		my_putchar(char);
void		putnbr_rec(unsigned int);
void		my_putnbr(int);
void		my_putstr(char *);
int		my_strcmp(char *, char *);
int		my_strncmp(char *, char *, int);
void		my_strcpy(char *, char *);
void		my_strncpy(char *, char *, int);
char		*my_strncat(char *, char *, int );
char		*my_strncat(char *, char *, int);
char		*my_strdup(char *);
int		my_strlen(char *);
int		*put_zero(int *);
void		*xmalloc(int);
int		xread(int, void *, int);
int		xwrite(int, void *, int);

char		*some_epur(char *);
char		hook_char();
char		*hook_full_instr();
int		dat_rand(int);
int		print_rules();
char		*put_prompt();
int		check_size(int);
t_game		get_cnfg_game(t_game);
int		not_on_the_deck(int *, int);
t_game		generate_all_cards(t_game);
t_game		get_all_type(t_game);
t_game		init_all(t_game, int);
t_game		reset_all(t_game);
t_game		check_result(t_game, int, int);
void		print_result(t_game, int);
int		is_alive(t_game, int, int);
void		print_color(char **, int);
void		print_card(char **, int);
t_game		double_bet(t_game, int);
t_game		abandon_ship(t_game, int);
t_game		want_insu(t_game, int, int);
t_game		what_if_ace(t_game, int, int);
int		what_choice(int);
void		print_i_player(int);
void		print_i_card(t_game, int, int, int);
int		is_ace(int);
t_game		xmoar_card(t_game, int, int, int);
t_game		xxmoar_card(t_game, int, int, int);
t_game		moar_card(t_game, int, int, int);
t_game		giff_me_card(t_game, int, int, int);
int		split_spotted(t_game, int);
t_game		ask_split(t_game, int);
t_game		ask_special(t_game, int);
void		what_card(t_game, int);
int		get_value(t_game, int, int, int);
int		get_value_de(t_game, int);
t_game		calc_blackjack(t_game, int, int, int);
t_game		is_blackjack(t_game, int, int);
int		print_d(t_game, int, int);
t_game		xplay_dealer(t_game);
t_game		play_dealer(t_game, int, int);
t_game		delivery(t_game, int);
t_game		what_bet(t_game, int, int);
int		all_play(t_game);
int		test_all_bust(t_game);
t_game		xget_result_s(t_game, int, int);
t_game		get_result_s(t_game);
t_game		xget_result(t_game, int, int);
t_game		get_result(t_game);
void		print_round(t_game);
void		launch_game(t_game, int);
void		start_game(int);
int		main_menu();
int		main();

#endif /*__MY_H__ */

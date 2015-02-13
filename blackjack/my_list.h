#ifndef         __MY_LIST_H__
# define         __MY_LIST_H__

typedef struct		s_cnfg
{
  int			players;
  int			*moar_c;
  int			stack;
  int			idx_c;
  int			t_bet;
}			t_cnfg;

typedef	struct		s_game
{
  int			*cards;
  char			**type;
  int			**players;
  int			**value_p;
  int			value_d;
  int			*dealer;
  int			*stack;
  int			*bet;
  int			*bet_s;
  struct s_cnfg		cnfg;
}			t_game;

#endif /* __MY_LIST_H__ */

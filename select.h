/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakaria <szakaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:47:32 by szakaria          #+#    #+#             */
/*   Updated: 2019/12/19 12:48:38 by szakaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/types.h>
# include <unistd.h>
# include <curses.h>
# include <fcntl.h>
# include <term.h>
# include <sys/ioctl.h>
# define M 109
# define ONE 49
# define TWO 50
# define TREE 51
# define S 115
# define ITALIC 105
# define BLOD 98
# define COLOR 99
# define ZERO 48
# define ENTRE 10
# define DELETE 127
# define UP 4283163
# define RIGHT 4414235
# define DOWN 4348699
# define LEFT 4479771
# define SPACE 32
# define EXIT 27
# define BUFF_SIZE 1024

typedef struct	s_mode
{
	int model;
	int bigname;
	int supp;
	int select;
	int color;
	int blod;
	int italic;
	int simple;
	int one;
	int two;
	int tree;
}				t_mode;

typedef struct	s_key
{
	int c;
	int m;
	int fd;
	int up;
	int down;
	int space;
	int exit;
	int supp;
	int entre;
	int color;
	int italic;
	int zero;
	int one;
	int two;
	int tree;
	int b;
	int i;
	int s;
	int xx;
	int yy;
}				t_key;

t_key			*key_historique(t_key *key);
t_key			*select_keybord(char **av);
t_key			*keybord_active(t_key *key);
t_key			*keybord_deactivate(t_key *key);
void			old_selection(t_mode *mode, t_key *key, char **av);
t_mode			*mode_historique(t_mode *mode);
void			check_signal(void);
int				big_name(char **av);
void			lance_signal(int signal);
void			signal_size(int signal);
void			active_mode(int mode);
void			ft_free(t_key *key, t_mode *mode);
int				check_sizeofterminal(void);
void			affichage_win(t_mode *mode, t_key *key, char **av, int big);
void			bonus_selection(t_key *key, t_mode *mode, char **av);
void			something_to_affiche(char **av, t_mode *mode, t_key *key);
void			mode_total_selection(t_mode *mode, char **av);
void			generateur(t_mode *mode, t_key *key, char **av);
void			ft_color(char *av, int x, int y, t_mode *mode);
void			bonus_first(t_key *key, t_mode *mode, char **av);
char			**argv_historique(char **av);
int				select0(char **av);
int				active_selection(t_mode *mode, int i, int mod);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakaria <szakaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:36:51 by szakaria          #+#    #+#             */
/*   Updated: 2019/12/19 13:27:41 by szakaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

int			big_name(char **av)
{
	int	i;
	int	big;

	big = 0;
	i = 1;
	while (av[i])
	{
		if ((size_t)big < ft_strlen(av[i]))
			big = ft_strlen(av[i]);
		i++;
	}
	return (big + 1);
}

int			check_sizeofterminal(void)
{
	struct winsize	term;
	char			**av;
	int				len;
	int				total;
	int				bigname;

	total = 0;
	len = 0;
	ioctl(2, TIOCGWINSZ, &term);
	av = argv_historique(NULL);
	bigname = big_name(av);
	while (av[len])
		len++;
	ioctl(3, TIOCGWINSZ, &term);
	total = term.ws_col / (bigname + 10) * term.ws_row;
	ft_putstr_fd(tgetstr("cl", NULL), 2);
	if (total - 4 < len)
		ft_putstr_fd(" ⛔️\x1b[31m \x1b[1m  WE NEED SPACE PLEASE ... !\033[0m"
				, 2);
	else
		affichage_win(mode_historique(NULL), key_historique(NULL), av, bigname);
	return (1);
}

void		active_mode(int mode)
{
	if (mode == 1)
	{
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, 0), 2);
		ft_putstr_fd(tgetstr("us", NULL), 2);
	}
	if (mode == 2)
	{
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, 0), 2);
		ft_putstr_fd(tgetstr("mr", NULL), 2);
	}
	if (mode == 3)
		ft_putstr_fd(tgetstr("me", NULL), 2);
}

void		affichage_win(t_mode *mode, t_key *key, char **av, int big)
{
	struct winsize	term;
	int				i;
	int				x;
	int				y;

	y = 3;
	x = 0;
	i = 0;
	ioctl(2, TIOCGWINSZ, &term);
	while (term.ws_row > y && av[i++])
		if (mode[i].supp == 0)
		{
			if (i == key->yy)
				active_mode(1);
			active_selection(mode, i, 1);
			ft_color(av[i], x, y, mode);
			if (y + 1 == term.ws_row)
			{
				x += big + 3;
				y = 2;
			}
			active_selection(mode, i, 0);
			y++;
		}
	mode_total_selection(mode_historique(NULL), av);
}

void		signal_size(int signal)
{
	if (signal == SIGWINCH)
		check_sizeofterminal();
}

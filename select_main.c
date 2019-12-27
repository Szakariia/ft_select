/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakaria <szakaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:50:21 by szakaria          #+#    #+#             */
/*   Updated: 2019/12/18 17:43:45 by szakaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

int			select0(char **av)
{
	while (1)
	{
		check_sizeofterminal();
		generateur(mode_historique(NULL), key_historique(NULL), av);
	}
	return (1);
}

t_mode		*malloc_mode(char **av)
{
	t_mode	*mode;
	int		i;

	i = 0;
	while (av[i])
		i++;
	mode = (t_mode *)malloc(sizeof(t_mode) * i + 1);
	i = 0;
	mode->color = 1;
	mode->bigname = big_name(av);
	while (av[i])
	{
		mode[i].select = 0;
		mode[i].supp = 0;
		i++;
	}
	return (mode);
}

void		manger_error(int ac)
{
	char *term_type;

	if (ac < 2)
	{
		ft_putstr(" ⛔️ \x1b[31m \x1b[1m Usage : [ We need same argument ");
		ft_putendl("to run this programme ]\033[0m");
		exit(0);
	}
	term_type = getenv("TERM");
	if (!term_type)
	{
		ft_putstr(" ⛔️ \x1b[31m \x1b[1m Specify a terminal");
		ft_putendl(" type with `setenv TERM <yourtype>'.\033[0m");
		exit(0);
	}
	else if (tgetent(NULL, term_type) != 1)
	{
		ft_putendl(" ⛔️ \x1b[31m \x1b[1m Terminal type is not defined.\033[0m");
		exit(0);
	}
}

int			main(int ac, char **av)
{
	struct termios	config;
	t_key			*key;
	t_mode			*mode;

	manger_error(ac);
	key = select_keybord(av);
	mode = malloc_mode(av);
	if (tcgetattr(0, &config) < 0)
		ft_putstr_fd("error", 2);
	config.c_lflag &= ~(ECHO | ICANON);
	if (tcsetattr(0, 0, &config) < 0)
		ft_putstr_fd("error", 2);
	check_signal();
	ft_putstr_fd(tgetstr("ti", NULL), 2);
	ft_putstr_fd(tgetstr("vi", NULL), 2);
	argv_historique(av);
	mode_historique(mode);
	key_historique(key);
	select0(av);
	return (0);
}

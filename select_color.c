/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakaria <szakaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:35:24 by szakaria          #+#    #+#             */
/*   Updated: 2019/12/19 13:39:47 by szakaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void		mode_total_selection(t_mode *mode, char **av)
{
	char	*tmp;
	int		i;
	int		yes;
	int		no;

	tmp = NULL;
	yes = 0;
	no = 0;
	i = 0;
	while (av[i++])
		if (mode[i].supp == 0 && i != 0)
			mode[i].select == 0 ? no++ : yes++;
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), 1, 1), 2);
	ft_putstr_fd("\x1b[1m\x1b[92m ✔ SELECTION : ", 2);
	tmp = ft_itoa(yes);
	ft_putstr_fd(tmp, 2);
	free(tmp);
	ft_putstr_fd("\x1b[1m\x1b[31m      ✘ NO SELECTION : ", 2);
	tmp = ft_itoa(no);
	ft_putstr_fd(tmp, 2);
	free(tmp);
	ft_putstr_fd("\x1b[0m", 2);
	ft_putstr_fd(tgetstr("me", NULL), 2);
}

int			ft_color3(struct stat sb, int x)
{
	x = 0;
	if ((S_ISDIR(sb.st_mode)) && ((sb.st_mode) & S_IWUSR)
			&& ((sb.st_mode) & S_IWGRP) && ((sb.st_mode) & S_IWOTH))
	{
		ft_putstr_fd("\033[0;30m", 2);
		x++;
	}
	else if (((sb.st_mode) & S_IFMT) == S_IFDIR)
	{
		ft_putstr_fd("\033[1;36m", 2);
		x++;
	}
	else if (((sb.st_mode) & S_IFMT) == S_IFSOCK)
	{
		ft_putstr_fd("\033[0;32m", 2);
		x++;
	}
	else if (((sb.st_mode) & S_IFMT) == S_IFLNK || (sb.st_mode) & S_IXUSR)
	{
		ft_putstr_fd("\033[92m", 2);
		x++;
	}
	return (x);
}

void		ft_color(char *av, int x, int y, t_mode *mode)
{
	struct stat	sb;
	int			i;
	int			per;

	i = 0;
	if (mode->blod == 1)
		ft_putstr_fd("\x1b[1m", 2);
	else if (mode->italic == 1)
		ft_putstr_fd("\x1b[3m", 2);
	if (mode->color == 1)
	{
		per = lstat(av, &sb);
		if (per == 0)
		{
			i = ft_color3(sb, x);
			if (i == 0)
				ft_putstr_fd("\x1b[93m", 2);
		}
	}
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), x, y), 2);
	ft_putstr_fd(av, 2);
	if (mode->color == 1)
		ft_putstr_fd("\x1b[0m", 2);
	active_mode(3);
}

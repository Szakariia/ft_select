/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_generateur.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakaria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:40:23 by szakaria          #+#    #+#             */
/*   Updated: 2019/12/19 13:52:51 by szakaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void		ft_free(t_key *key, t_mode *mode)
{
	free(mode);
	free(key);
	exit(0);
}

int			number_selection(t_mode *mode, char **av)
{
	int	select;
	int	i;

	i = 1;
	select = 0;
	while (av[i])
	{
		if (mode[i].select == 1)
			select++;
		i++;
	}
	return (select);
}

void		entre(char **av, t_mode *mode, t_key *key)
{
	int i;
	int select;

	ft_putstr_fd(tgetstr("te", NULL), 2);
	ft_putstr_fd(tgetstr("ve", NULL), 2);
	i = 1;
	select = number_selection(mode, av);
	while (av[i])
	{
		if (mode[i].select == 1 && select > 1)
		{
			ft_putstr_fd(av[i], 1);
			ft_putstr_fd(" ", 1);
			select--;
		}
		else if (mode[i].select == 1 && select == 1)
			ft_putendl_fd(av[i], 1);
		i++;
	}
	ft_free(key, mode);
}

void		generateur2(t_mode *mode, t_key *key, char **av)
{
	if (key->italic == 1)
		mode->italic = mode->italic == 1 ? 0 : 1;
	else if (key->entre == 1)
		entre(av, mode, key);
	else if (key->zero == 1)
		bonus_first(key, mode, av);
	else if (key->down == 1)
	{
		key->yy = key->yy == key->i - 1 ? 1 : key->yy + 1;
		while (mode[key->yy].supp == 1)
			key->yy = key->yy == key->i - 1 ? 1 : key->yy + 1;
	}
	else if (key->up == 1)
	{
		key->yy = key->yy == 1 ? key->i - 1 : key->yy - 1;
		while (mode[key->yy].supp == 1)
			key->yy = key->yy == 1 ? key->i - 1 : key->yy - 1;
	}
	else if (key->space == 1 || key->supp == 1)
		old_selection(mode, key, av);
	mode_historique(mode);
	key_historique(key);
}

void		generateur(t_mode *mode, t_key *key, char **av)
{
	key = keybord_active(key);
	if (key->exit == 1)
	{
		ft_putstr_fd(tgetstr("te", NULL), 2);
		ft_putstr_fd(tgetstr("ve", NULL), 2);
		ft_free(key, mode);
	}
	else if (key->one == 1 || key->s == 1)
		bonus_selection(key, mode, av);
	else if (key->color == 1)
	{
		mode->color = mode->color == 1 ? 0 : 1;
		mode_historique(mode);
		key_historique(key);
	}
	else if (key->b == 1)
	{
		mode->blod = mode->blod == 1 ? 0 : 1;
		mode_historique(mode);
		key_historique(key);
	}
	else
		generateur2(mode, key, av);
}

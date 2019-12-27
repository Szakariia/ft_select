/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_generateur2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakaria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:52:57 by szakaria          #+#    #+#             */
/*   Updated: 2019/12/19 13:53:42 by szakaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void		something_to_affiche(char **av, t_mode *mode, t_key *key)
{
	int affiche;
	int i;

	affiche = 0;
	i = 1;
	while (av[i])
	{
		if (mode[i].supp == 1)
			affiche++;
		i++;
	}
	if (affiche == i - 1)
	{
		ft_putstr_fd(tgetstr("te", NULL), 2);
		ft_putstr_fd(tgetstr("ve", NULL), 2);
		ft_free(key, mode);
	}
}

void		old_selection(t_mode *mode, t_key *key, char **av)
{
	if (key->space == 1)
	{
		mode[key->yy].select = mode[key->yy].select == 0 ? 1 : 0;
		!av[key->yy + 1] ? key->yy = 1 : key->yy++;
	}
	else if (key->supp == 1)
	{
		ft_putstr_fd(tgetstr("cl", NULL), 2);
		mode[key->yy].supp = 1;
		something_to_affiche(av, mode, key);
	}
	while (av[key->yy] && mode[key->yy].supp == 1)
	{
		if (av[key->yy + 1] == NULL)
			key->yy = 0;
		key->yy++;
	}
	mode_historique(mode);
	key_historique(key);
}

int			active_selection(t_mode *mode, int i, int mod)
{
	char	**av;

	av = argv_historique(NULL);
	if (mode[i].supp == 1 || !av[i])
		return (0);
	else if (mode[i].select == 1)
	{
		if (mod == 1)
			active_mode(2);
		else
			ft_putstr_fd("\x1b[1m\x1b[92m ✔\x1b[0m", 2);
	}
	else if (mode[i].select == 0 && mod == 0)
		ft_putstr_fd("\x1b[1m\x1b[31m ✘\x1b[0m", 2);
	return (1);
}

void		bonus_first(t_key *key, t_mode *mode, char **av)
{
	int i;

	i = 0;
	while (av[i])
	{
		mode[i].select = 0;
		mode[i].supp = 0;
		mode[i].one = 0;
		mode[i].two = 0;
		mode[i].tree = 0;
		mode[i].blod = 0;
		mode[i].italic = 0;
		mode[i].simple = 0;
		mode[i].color = 1;
		i++;
	}
	key->yy = 1;
	mode_historique(mode);
	key_historique(key);
}

void		bonus_selection(t_key *key, t_mode *mode, char **av)
{
	int i;

	i = 0;
	if (key->s == 1)
		while (av[i])
		{
			mode[i].select = 1;
			i++;
		}
	if (key->one == 1)
		while (av[i])
		{
			mode[i].select = mode[i].select == 1 ? 0 : 1;
			i++;
		}
	mode_historique(mode);
	key_historique(key);
}

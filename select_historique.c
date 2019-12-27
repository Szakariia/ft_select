/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_historique.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakaria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:48:16 by szakaria          #+#    #+#             */
/*   Updated: 2019/12/18 16:49:29 by szakaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

char		**argv_historique(char **av)
{
	static char	**history;

	if (av)
		history = av;
	return (history);
}

t_key		*key_historique(t_key *key)
{
	static t_key		*history;

	if (key)
		history = key;
	return (history);
}

t_mode		*mode_historique(t_mode *mode)
{
	static t_mode		*history;

	if (mode)
		history = mode;
	return (history);
}

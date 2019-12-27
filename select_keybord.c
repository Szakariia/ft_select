/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_keybord.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakaria <szakaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:42:45 by szakaria          #+#    #+#             */
/*   Updated: 2019/12/19 13:23:25 by szakaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

t_key		*keybord_deactivate(t_key *key)
{
	key->up = 0;
	key->down = 0;
	key->space = 0;
	key->exit = 0;
	return (key);
}

t_key		*keybord_active(t_key *key)
{
	int buff;
	int len;

	buff = 0;
	len = 0;
	if ((len = read(2, &buff, sizeof(int))) > 0)
	{
		key->one = ONE == buff ? 1 : 0;
		key->two = TWO == buff ? 1 : 0;
		key->tree = TREE == buff ? 1 : 0;
		key->b = BLOD == buff ? 1 : 0;
		key->italic = ITALIC == buff ? 1 : 0;
		key->s = S == buff ? 1 : 0;
		key->entre = ENTRE == buff ? 1 : 0;
		key->zero = ZERO == buff ? 1 : 0;
		key->color = COLOR == buff ? 1 : 0;
		key->supp = DELETE == buff ? 1 : 0;
		key->up = UP == buff ? 1 : 0;
		key->down = DOWN == buff ? 1 : 0;
		key->space = SPACE == buff ? 1 : 0;
		key->exit = EXIT == buff ? 1 : 0;
	}
	return (key);
}

t_key		*select_keybord(char **av)
{
	t_key	*key;

	key = (t_key *)malloc(sizeof(t_key));
	key->yy = 1;
	key->xx = 0;
	key->i = 0;
	while (av[key->i])
		key->i++;
	return (key);
}

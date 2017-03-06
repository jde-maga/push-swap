/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_properties.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 16:49:35 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/29 17:07:10 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

int		sorted_check(t_pile *pile)
{
	int i;

	i = 0;
	while (i < pile->size - 1)
	{
		if (pile->data[i] < pile->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		start_sorted_check(t_pile *pile, int start)
{
	int i;
	int bufi;

	i = 0;
	bufi = 0;
	while (pile->data[i] != start)
		i++;
	while (bufi != pile->size - 1)
	{
		if (i == pile->size - 1)
		{
			i = 0;
			if (LAST_ELEM(pile) < FIRST_ELEM(pile))
				return (0);
			bufi++;
		}
		else
		{
			if (pile->data[i] < pile->data[i + 1])
				return (0);
			i++;
			bufi++;
		}
	}
	return (1);
}

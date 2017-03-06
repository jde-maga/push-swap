/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_properties_pile.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 13:23:39 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/29 17:32:20 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

int				get_biggest_number_pile(t_pile *pile)
{
	int i;
	int otp;

	i = 1;
	otp = pile->data[0];
	while (i < pile->size)
	{
		if (pile->data[i] > otp)
			otp = pile->data[i];
		i++;
	}
	return (otp);
}

int				get_smallest_number_pile(t_pile *pile)
{
	int i;
	int otp;

	i = 1;
	otp = pile->data[0];
	while (i < pile->size)
	{
		if (pile->data[i] < otp)
			otp = pile->data[i];
		i++;
	}
	return (otp);
}

static int		get_left(t_pile *pile, int stop, int i)
{
	int left;

	left = 0;
	while (pile->data[i] != stop)
	{
		left++;
		i--;
		if (i == -1)
			i = pile->size - 1;
	}
	return (left);
}

int				get_direction(t_pile *pile, int start, int stop)
{
	int i;
	int bufi;
	int left;
	int right;

	left = 0;
	right = 0;
	if (!pile->size)
		return (0);
	i = 0;
	while (pile->data[i] != start)
		i++;
	bufi = i;
	left = get_left(pile, stop, i);
	i = bufi;
	while (pile->data[i] != stop)
	{
		right++;
		i++;
		if (i == pile->size)
			i = 0;
	}
	if (left < right)
		return (RIGHT);
	return (LEFT);
}

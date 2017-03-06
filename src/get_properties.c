/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_properties.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 13:24:19 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/29 17:17:57 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

int		get_smallest_number(t_pile *a, t_pile *b)
{
	int i;
	int otp;

	i = 1;
	otp = a->data[0];
	while (i < a->size)
	{
		if (a->data[i] < otp)
			otp = a->data[i];
		i++;
	}
	i = 0;
	while (i < b->size)
	{
		if (b->data[i] < otp)
			otp = b->data[i];
		i++;
	}
	return (otp);
}

int		get_biggest_number(t_pile *a, t_pile *b)
{
	int i;
	int otp;

	i = 1;
	otp = a->data[0];
	while (i < a->size)
	{
		if (a->data[i] > otp)
			otp = a->data[i];
		i++;
	}
	i = 0;
	while (i < b->size)
	{
		if (b->data[i] > otp)
			otp = b->data[i];
		i++;
	}
	return (otp);
}

int		get_ranking(t_pile *pile, int rank)
{
	long	target;
	long	buf;
	int		i;
	int		j;

	i = 1;
	j = 0;
	target = get_smallest_number_pile(pile);
	while (i != rank)
	{
		buf = get_biggest_number_pile(pile) + 1;
		while (j != pile->size)
		{
			if (pile->data[j] > target && pile->data[j] < buf)
				buf = pile->data[j];
			j++;
		}
		target = buf;
		j = 0;
		i++;
	}
	return (target);
}

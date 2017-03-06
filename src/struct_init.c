/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 17:37:43 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/29 17:11:45 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

t_pile	*pushswap_struct_init(int size)
{
	t_pile *pile;

	pile = malloc(sizeof(int) + sizeof(int *));
	pile->data = malloc(sizeof(int) * size);
	pile->size = 0;
	return (pile);
}

void	properties_refresh(t_pile *a, t_pile *b, t_ppties *ppties)
{
	ppties->smallest_a = get_smallest_number_pile(a);
	ppties->smallest_b = get_smallest_number_pile(b);
	ppties->biggest_a = get_biggest_number_pile(a);
	ppties->biggest_b = get_biggest_number_pile(b);
}

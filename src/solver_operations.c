/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 16:47:09 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/29 17:18:28 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	get_all_below_target(t_pile *a, t_pile *b, int target)
{
	int i;
	int bufsize;

	i = 0;
	bufsize = a->size;
	while (i < bufsize)
	{
		if (LAST_ELEM(a) < target)
			push(a, b, "pb ");
		else
			rotate(a, "ra ");
		i++;
	}
}

void	push_biggest_b(t_pile *b, t_pile *a, t_ppties *ppties)
{
	int direction;

	direction = get_direction(b, LAST_ELEM(b), ppties->biggest_b);
	while (LAST_ELEM(b) != ppties->biggest_b)
	{
		if (direction == LEFT)
			revrotate(b, "rrb ");
		else
			rotate(b, "rb ");
	}
	push(b, a, "pa ");
}

void	push_smallest_a(t_pile *b, t_pile *a, t_ppties *ppties)
{
	int direction;

	direction = get_direction(a, LAST_ELEM(a), ppties->smallest_a);
	while (LAST_ELEM(a) != ppties->smallest_a)
	{
		if (direction == LEFT)
			revrotate(a, "rra ");
		else
			rotate(a, "ra ");
	}
	push(a, b, "pb ");
}

void	put_back_a(t_pile *a, t_ppties *ppties)
{
	int i;

	i = 0;
	if (sorted_check(a))
		return ;
	while (a->data[i] != ppties->biggest_a)
		i++;
	while (LAST_ELEM(a) != ppties->biggest_a
			&& FIRST_ELEM(a) != ppties->smallest_a)
	{
		if (i >= a->size - i)
			rotate(a, "ra ");
		else
			revrotate(a, "rra ");
	}
	if (i >= a->size - i)
		rotate(a, "ra");
	else
		revrotate(a, "rra");
}

void	fake_swap(t_pile *pile)
{
	int buf;

	if (pile->size < 2)
		return ;
	buf = pile->data[pile->size - 1];
	pile->data[pile->size - 1] = pile->data[pile->size - 2];
	pile->data[pile->size - 2] = buf;
}

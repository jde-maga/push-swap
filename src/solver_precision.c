/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 16:43:02 by jde-maga          #+#    #+#             */
/*   Updated: 2016/05/20 19:15:14 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

int		easysolver(t_pile *a, t_pile *b, t_ppties *ppties)
{
	properties_refresh(a, b, ppties);
	if (start_sorted_check(a, ppties->biggest_a))
	{
		put_back_a(a, ppties);
		return (1);
	}
	fake_swap(a);
	if (start_sorted_check(a, ppties->biggest_a))
	{
		fake_swap(a);
		swap(a, "sa ");
		put_back_a(a, ppties);
		return (1);
	}
	fake_swap(a);
	return (0);
}

void	solver_sizethree(t_pile *a, t_pile *b, t_ppties *ppties)
{
	properties_refresh(a, b, ppties);
	while (!sorted_check(a))
	{
		if (FIRST_ELEM(a) == ppties->biggest_a
			&& ALAST_ELEM(a) < LAST_ELEM(a))
			swap(a, "sa");
		else if (FIRST_ELEM(a) == ppties->smallest_a
				&& ALAST_ELEM(a) > LAST_ELEM(a))
			revrotate(a, "rra");
		else if (FIRST_ELEM(a) == ppties->smallest_a
				&& ALAST_ELEM(a) < LAST_ELEM(a))
			rotate(a, "ra ");
		else if (LAST_ELEM(a) == ppties->biggest_a
				&& ALAST_ELEM(a) == ppties->smallest_a)
			rotate(a, "ra");
		else if (LAST_ELEM(a) == ppties->smallest_a
				&& ALAST_ELEM(a) == ppties->biggest_a)
			swap(a, "sa ");
	}
}

void	solver_sizefour(t_pile *a, t_pile *b, t_ppties *ppties)
{
	properties_refresh(a, b, ppties);
	if (easysolver(a, b, ppties))
		return ;
	if (LAST_ELEM(a) == ppties->smallest_a)
	{
		push(a, b, "pb ");
		solver_sizethree(a, b, ppties);
		return (push(b, a, " pa"));
	}
	else if (FIRST_ELEM(a) == ppties->smallest_a)
	{
		revrotate(a, "rra ");
		solver_sizefour(a, b, ppties);
	}
	else if (ALAST_ELEM(a) == ppties->smallest_a)
	{
		rotate(a, "ra ");
		solver_sizefour(a, b, ppties);
	}
	else
	{
		rotate(a, "ra ");
		rotate(a, "ra ");
		solver_sizefour(a, b, ppties);
	}
}

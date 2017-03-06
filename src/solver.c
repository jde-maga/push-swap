/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 16:51:02 by jde-maga          #+#    #+#             */
/*   Updated: 2016/05/25 15:37:46 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

static int		cut_table(t_pile *pile)
{
	if (pile->size <= 60)
		return (4);
	if (pile->size <= 100)
		return (6);
	if (pile->size <= 200)
		return (8);
	if (pile->size <= 300)
		return (10);
	if (pile->size <= 400)
		return (12);
	if (pile->size <= 500)
		return (14);
	if (pile->size <= 800)
		return (16);
	if (pile->size <= 1000)
		return (20);
	if (pile->size <= 2000)
		return (25);
	if (pile->size <= 5000)
		return (30);
	if (pile->size <= 10000)
		return (40);
	return (50);
}

void			solver_midsize(t_pile *a, t_ppties *ppties, t_pile *b)
{
	int i;
	int j;

	properties_refresh(a, b, ppties);
	if (easysolver(a, b, ppties))
		return ;
	i = a->size - 4;
	j = 0;
	while (j != i)
	{
		properties_refresh(a, b, ppties);
		push_smallest_a(b, a, ppties);
		j++;
	}
	solver_sizefour(a, b, ppties);
	while (j)
	{
		push(b, a, " pa");
		j--;
	}
}

static int		anti_worstcase(t_pile *a)
{
	int buf;

	buf = FIRST_ELEM(a);
	FIRST_ELEM(a) = a->data[1];
	a->data[1] = buf;
	if (start_sorted_check(a, FIRST_ELEM(a)))
	{
		ft_printf("rra rra sa ra ra");
		return (1);
	}
	buf = FIRST_ELEM(a);
	FIRST_ELEM(a) = a->data[1];
	a->data[1] = buf;
	return (0);
}

void			solver(t_pile *a, t_pile *b, t_ppties *ppties)
{
	properties_refresh(a, b, ppties);
	if (sorted_check(a))
		return ;
	else if (a->size == 2 && ALAST_ELEM(a) < LAST_ELEM(a))
		swap(a, "sa");
	else if (anti_worstcase(a))
		return ;
	else if (a->size == 3)
		solver_sizethree(a, b, ppties);
	else if (a->size == 4)
		solver_sizefour(a, b, ppties);
	else
		solver_midsize(a, ppties, b);
}

void			solver_bigpile(t_pile *a, t_pile *b, t_ppties *ppties)
{
	int i;
	int bufsize;
	int cut;

	bufsize = a->size;
	i = 0;
	properties_refresh(a, b, ppties);
	cut = cut_table(a);
	while (i != cut)
	{
		get_all_below_target(a, b, get_ranking(a, bufsize / cut + 1));
		i++;
	}
	get_all_below_target(a, b, ppties->biggest_a);
	properties_refresh(a, b, ppties);
	while (b->size != 1)
	{
		properties_refresh(a, b, ppties);
		push_biggest_b(b, a, ppties);
	}
	push(b, a, "pa");
}

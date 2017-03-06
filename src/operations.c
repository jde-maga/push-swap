/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 17:13:26 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/29 17:20:56 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	swap(t_pile *pile, char *str)
{
	int buf;

	if (pile->size < 2)
		return ;
	buf = pile->data[pile->size - 1];
	pile->data[pile->size - 1] = pile->data[pile->size - 2];
	pile->data[pile->size - 2] = buf;
	if (ft_strcmp("double", str))
		ft_printf("%s", str);
}

void	push(t_pile *from, t_pile *to, char *str)
{
	if (!from->size)
		return ;
	to->data[to->size] = from->data[from->size - 1];
	to->size++;
	from->size--;
	ft_printf("%s", str);
}

void	rotate(t_pile *pile, char *str)
{
	int i;
	int buf;

	if (pile->size < 2)
		return ;
	i = pile->size - 1;
	while (i > 0)
	{
		buf = pile->data[i];
		pile->data[i] = pile->data[i - 1];
		pile->data[i - 1] = buf;
		i--;
	}
	if (ft_strcmp("double", str))
		ft_printf("%s", str);
}

void	revrotate(t_pile *pile, char *str)
{
	int i;
	int buf;

	if (pile->size < 2)
		return ;
	i = 0;
	while (i < pile->size - 1)
	{
		buf = pile->data[i];
		pile->data[i] = pile->data[i + 1];
		pile->data[i + 1] = buf;
		i++;
	}
	if (ft_strcmp("double", str))
		ft_printf("%s", str);
}

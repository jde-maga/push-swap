/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 12:19:15 by jde-maga          #+#    #+#             */
/*   Updated: 2016/05/20 19:14:14 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

static int		pushswap_isint(char *s)
{
	int		i;
	long	c;

	if (ft_strlen(s) > 11 || (ft_strlen(s) == 11
							&& (s[0] != '+' && s[0] != '-')))
		return (0);
	if (!ft_isdigit(s[0]) && s[0] != '+' && s[0] != '-')
		return (0);
	i = 1;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	c = ft_atoi_long(s);
	if (c > INT_MAX || c < INT_MIN)
		return (0);
	return (1);
}

int				duplicate_check(t_pile *pile)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (i < pile->size - 1)
	{
		while (j < pile->size)
		{
			if (pile->data[i] == pile->data[j])
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

t_pile			*input_parser(int ac, char **av)
{
	t_pile	*pile;
	int		i;
	int		j;

	j = ac - 2;
	i = 0;
	pile = pushswap_struct_init(ac - 1);
	pile->size = ac - 1;
	while (i < ac - 1)
	{
		if (!pushswap_isint(av[i + 1]))
			return (NULL);
		pile->data[j] = ft_atoi(av[i + 1]);
		j--;
		i++;
	}
	if (duplicate_check(pile))
		return (NULL);
	return (pile);
}

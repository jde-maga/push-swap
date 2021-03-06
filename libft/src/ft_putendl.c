/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 17:01:28 by jde-maga          #+#    #+#             */
/*   Updated: 2015/12/08 13:57:30 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putendl(char const *s)
{
	if (s)
	{
		while (*s)
		{
			write(1, &(*s), 1);
			s++;
		}
		write(1, "\n", 1);
	}
}

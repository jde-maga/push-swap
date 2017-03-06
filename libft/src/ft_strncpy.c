/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:34:42 by jde-maga          #+#    #+#             */
/*   Updated: 2015/11/30 17:43:42 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (n)
	{
		if (!src[i])
			dst[j] = 0;
		else if (src[i])
		{
			dst[j] = src[i];
			i++;
		}
		j++;
		n--;
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:19:34 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/19 12:14:51 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atoi_long(const char *str)
{
	long otp;
	long sign;
	long i;

	otp = 0;
	i = 0;
	sign = 1;
	while (str[i] >= 1 && str[i] <= 32)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		otp = otp * 10 + str[i] - '0';
		i++;
	}
	return (otp * sign);
}

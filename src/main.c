/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 15:30:56 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/29 17:26:59 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void			debug_printpile(t_pile s)
{
	int i;

	i = 0;
	ft_printf("pile size : %d\npile data :\n", s.size);
	while (i < s.size)
	{
		ft_printf("%d ", s.data[i]);
		i++;
	}
	ft_printf("\n\n");
}

static int		error(void)
{
	ft_putendl_fd("Error", 2);
	return (0);
}

int				main(int ac, char **av)
{
	t_pile		*a;
	t_pile		*b;
	t_ppties	*ppties;

	b = pushswap_struct_init(ac - 1);
	ppties = malloc(sizeof(int) * 4);
	if (ac < 2 || (a = input_parser(ac, av)) == NULL)
		return (error());
	if (a->size <= 25)
		solver(a, b, ppties);
	else
		solver_bigpile(a, b, ppties);
	ft_printf("\n");
	free(a->data);
	free(b->data);
	free(a);
	free(b);
	free(ppties);
	return (0);
}

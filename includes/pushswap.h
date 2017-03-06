/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 16:47:01 by jde-maga          #+#    #+#             */
/*   Updated: 2016/04/29 17:35:27 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

# include <libft.h>

# define LAST_ELEM(pile) pile->data[pile->size - 1]
# define FIRST_ELEM(pile) pile->data[0]
# define ALAST_ELEM(pile) pile->data[pile->size - 2]

# define LEFT 42
# define RIGHT -42
# define DEBUG(pile) printf("\n\n");debug_printpile(*pile);printf("\n");

typedef struct	s_pile
{
	int		size;
	int		*data;
}				t_pile;

typedef struct	s_ppties
{
	int		smallest_a;
	int		biggest_a;
	int		smallest_b;
	int		biggest_b;
}				t_ppties;

t_pile			*input_parser(int ac, char **av);

void			solver(t_pile *a, t_pile *b, t_ppties *ppties);
void			solver_bigpile(t_pile *a, t_pile *b, t_ppties *ppties);
int				easysolver(t_pile *a, t_pile *b, t_ppties *ppties);
void			solver_sizethree(t_pile *a, t_pile *b, t_ppties *ppties);
void			solver_sizefour(t_pile *a, t_pile *b, t_ppties *ppties);

t_pile			*pushswap_struct_init(int size);
void			properties_refresh(t_pile *a, t_pile *b, t_ppties *ppties);

void			swap(t_pile *pile, char *str);
void			push(t_pile *from, t_pile *to, char *str);
void			rotate(t_pile *pile, char *str);
void			revrotate(t_pile *pile, char *str);

int				get_ranking(t_pile *pile, int rank);
int				get_biggest_number_pile(t_pile *pile);
int				get_smallest_number_pile(t_pile *pile);
int				get_direction(t_pile *pile, int start, int stop);

void			get_all_below_target(t_pile *a, t_pile *b, int target);
void			push_biggest_b(t_pile *b, t_pile *a, t_ppties *ppties);
void			push_smallest_a(t_pile *b, t_pile *a, t_ppties *ppties);
void			put_back_a(t_pile *a, t_ppties *ppties);
void			fake_swap(t_pile *pile);

int				sorted_check(t_pile *pile);
int				start_sorted_check(t_pile *pile, int start);

void			debug_printpile(t_pile s);

#endif

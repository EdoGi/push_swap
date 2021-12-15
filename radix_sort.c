/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 22:55:28 by egiacomi          #+#    #+#             */
/*   Updated: 2021/12/15 21:17:59 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_big(t_stack *aroot, t_stack *broot, t_stack *mv)
{
	int		bits;
	int		max_val;
	int		i;
	int		j;
	int		size;

	size = aroot->nbr;
	bits = 0;
	j = -1;
	max_val = ft_max_rank(aroot);
	while (max_val >> bits)
		++bits;
	while (++j < bits)
	{
		i = -1;
		while (++i < size)
		{
			if ((aroot->next->rank >> j) & 1)
				mv_rotate (aroot, mv, 'a');
			else
				mv_push(aroot, broot, mv, 'b');
		}
		ft_b_to_a(aroot, broot, mv);
	}
}

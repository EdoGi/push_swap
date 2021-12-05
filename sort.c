/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:51:41 by egiacomi          #+#    #+#             */
/*   Updated: 2021/12/06 00:01:38 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Sort stack with 3 values and less */
void	ft_sort_small(t_stack *aroot, t_stack *broot, t_stack *mv)
{
	t_stack	*it;

	it = aroot->next;
	while (!(ft_is_sorted(aroot)))
	{
		
	}
}

/*
		if (it->rank == 0)
		{
			mv_reverse_rotate(aroot, mv, 'a');
			mv_swap(aroot, mv, 'a');
		}
		if (it->rank == 1)
		{
			if (it->next->rank == 0)
				mv_swap(aroot, mv 'a');
			if (it->next->rank == 2)
				mv_reverse_rotate(aroot, mv, 'a');
		}
		if (it->rank == 2)
		{
			if (it->next->rank == 0)
				mv_rotate(aroot, mv 'a');
			if (it->next->rank == 1)
			{
				mv_rotate(aroot, mv, 'a');
				mv_swap(aroot, mv, 'a');
			}
		}
*/

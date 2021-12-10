/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:51:41 by egiacomi          #+#    #+#             */
/*   Updated: 2021/12/10 22:19:28 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Sort stack with 3 values and less */
void	ft_sort_small(t_stack *aroot, t_stack *mv)
{
	t_stack	*it;

	it = aroot->next;
	if (it->rank == 0)
	{
		mv_reverse_rotate(aroot, mv, 'a');
		mv_swap(aroot, mv, 'a');
	}
	else if (it->rank == 1)
	{
		if (it->next->rank == 0)
			mv_swap(aroot, mv, 'a');
		else if (it->next->rank == 2)
			mv_reverse_rotate(aroot, mv, 'a');
	}
	else if (it->rank == 2)
	{
		mv_rotate(aroot, mv, 'a');
		if (aroot->next->rank == 1)
			mv_swap(aroot, mv, 'a');
	}
}

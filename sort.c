/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:51:41 by egiacomi          #+#    #+#             */
/*   Updated: 2021/12/10 23:54:55 by egiacomi         ###   ########.fr       */
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

void	ft_sort_medium(t_stack *aroot, t_stack *broot, t_stack *mv)
{
	t_stack	*it;
	int		lenght;
	int		i;

	i = 0;
	printf("hello\n");
	while (ft_stack_size(aroot) > 3)
	{
		it = aroot->next;
		printf("\tfirst is %d\nand i is %d\nfor %d size\n", it->nbr, i, ft_stack_size(aroot));
		if (it->rank != i)
		{
			while (it->rank != i)
				it = it->next;
			lenght = ft_stack_size(aroot);
			if (it->idx < (lenght / 2))
				ft_down_top_ra(aroot, it->rank, mv);
			else if
				ft_down_top_rra(aroot, it->rank, mv);
		}
		mv_push(aroot, broot, mv, 'b');
		i++;
	}
	ft_sort_small(aroot, mv);
	ft_b_to_a(aroot, broot, mv);
}

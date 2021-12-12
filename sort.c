/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:51:41 by egiacomi          #+#    #+#             */
/*   Updated: 2021/12/12 20:52:10 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Sort stack with 3 values and less */
void	ft_sort_three(t_stack *aroot, t_stack *mv)
{
	t_stack	*it;

	ft_set_rank(aroot);
	if (!ft_is_sorted(aroot))
	{
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
}

/* Sort stack with 10 values and less */
void	ft_sort_small(t_stack *aroot, t_stack *broot, t_stack *mv)
{
	t_stack	*it;
	int		i;

	i = 0;
	while (ft_stack_size(aroot) > 3)
	{
		it = aroot->next;
		while (it->rank != i)
			it = it->next;
		mv_optimal_move_top(aroot, it, mv, 'a');
		mv_push(aroot, broot, mv, 'b');
		i++;
	}
	ft_sort_three(aroot, mv);
	ft_b_to_a(aroot, broot, mv);
}

/* Sort stack with 100 values and less */
void	ft_sort_medium(t_stack *aroot, t_stack *broot, t_stack *mv, int chunk)
{
	t_stack	*it;
	int		add;

	add = chunk;
	while (ft_stack_size(aroot) != 0)
	{
		it = aroot->next;
		while (it != aroot)
		{
			it = aroot->next;
			while (it->rank > chunk && it != aroot)
				it = it->next;
			if (it->rank <= chunk && it != aroot)
			{
				mv_optimal_move_top(aroot, it, mv, 'a');
				mv_push(aroot, broot, mv, 'b');
			}
		}
		chunk += add;
	}
	ft_sort_b_to_a(aroot, broot, mv);
}

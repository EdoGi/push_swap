/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 22:48:00 by egiacomi          #+#    #+#             */
/*   Updated: 2021/12/12 20:55:55 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max_rank(t_stack *root)
{
	t_stack	*it;
	int		max;

	max = 0;
	it = root->next;
	while (it != root)
	{
		if (it->rank > max)
			max = it->rank;
		it = it->next;
	}
	return (max);
}

void	ft_down_top_ra(t_stack *root, int element_rank, t_stack *mv, char s)
{
	t_stack	*first;

	first = root->next;
	while (first->rank != element_rank)
	{
		mv_rotate(root, mv, s);
		first = root->next;
	}
}

void	ft_down_top_rra(t_stack *root, int element_rank, t_stack *mv, char s)
{
	t_stack	*first;

	first = root->next;
	while (first->rank != element_rank)
	{
		mv_reverse_rotate(root, mv, s);
		first = root->next;
	}
}

void	ft_b_to_a(t_stack *aroot, t_stack *broot, t_stack *mv)
{
	while (broot->next != broot)
		mv_push(broot, aroot, mv, 'a');
}

void	ft_sort_b_to_a(t_stack *aroot, t_stack *broot, t_stack *mv)
{
	t_stack	*it;
	int		i;

	i = ft_max_rank(broot);
	while (ft_stack_size(broot) != 0)
	{
		it = broot->next;
		while (it->rank != i)
			it = it->next;
		mv_optimal_move_top(broot, it, mv, 'b');
		mv_push(broot, aroot, mv, 'a');
		i--;
	}
}

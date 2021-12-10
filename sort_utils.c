/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 22:48:00 by egiacomi          #+#    #+#             */
/*   Updated: 2021/12/10 23:18:38 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_down_top_ra(t_stack *root, int element_rank, t_stack *mv)
{
	t_stack	*first;

	first = root->next;
	while (first->rank != element_rank)
	{
		mv_rotate(root, mv, 'a');
		first = root->next;
	}
}

void	ft_down_top_rra(t_stack *root, int element_rank, t_stack *mv)
{
	t_stack	*first;

	first = root->next;
	while (first->rank != element_rank)
	{
		mv_reverse_rotate(root, mv, 'a');
		first = root->next;
	}
}

void	ft_b_to_a(t_stack *aroot, t_stack *broot, t_stack *mv)
{
	t_stack	*it;

	it = broot->next;
	while (it != broot)
		mv_push(broot, aroot, mv, 'a');
}

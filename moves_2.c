/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:52:16 by egiacomi          #+#    #+#             */
/*   Updated: 2021/12/12 17:07:31 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Rotate root_stack and take char 's' to know whether its "ra" or "rb" */
void	mv_rotate(t_stack *root, t_stack *mv, char s)
{
	t_stack	*first_to_last;

	first_to_last = root->next;
	first_to_last->prev = root->prev;
	root->prev->next = first_to_last;
	ft_stkadd_next(first_to_last, root);
	if (s == 'a')
		ft_stkadd_bot(mv, NULL, 0, "ra");
	else
		ft_stkadd_bot(mv, NULL, 0, "rb");
	ft_setidx(root);
}

void	mv_rotate_rotate(t_stack *aroot, t_stack *broot, t_stack *mv)
{
	mv_rotate(aroot, mv, 'a');
	mv_rotate(broot, mv, 'b');
}

/* Reverse rotate stack and take char 's' to know whether its "rra" or "rrb" */
void	mv_reverse_rotate(t_stack *root, t_stack *mv, char s)
{
	t_stack	*last_to_first;

	last_to_first = root->prev;
	last_to_first->next = root->next;
	root->next->prev = last_to_first;
	ft_stkadd_prev(last_to_first, root);
	if (s == 'a')
		ft_stkadd_bot(mv, NULL, 0, "rra");
	else
		ft_stkadd_bot(mv, NULL, 0, "rrb");
	ft_setidx(root);
}

void	mv_reverse_rotate_rotate(t_stack *aroot, t_stack *broot, t_stack *mv)
{
	mv_reverse_rotate(aroot, mv, 'a');
	mv_reverse_rotate(broot, mv, 'b');
}

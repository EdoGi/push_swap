/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:36:42 by egiacomi          #+#    #+#             */
/*   Updated: 2021/12/05 15:38:04 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mv_swap(t_stack *root, t_stack *mv, char s)
{
	t_stack	*toswap;

	toswap = root->next->next;
	ft_stkadd_top(root, toswap, 0, NULL);
	if (s == 'a')
		ft_stkadd_bot(mv, NULL, 0, "sa");
	else
		ft_stkadd_bot(mv, NULL, 0, "sb");
}

void	mv_swap_swap(t_stack *aroot, t_stack *broot, t_stack *mv)
{
	mv_swap(aroot, mv, 'a');
	mv_swap(broot, mv, 'b');
}

void	mv_push(t_stack *root_give, t_stack *root_receive, t_stack *mv, char s)
{
	t_stack	*element;

	if (root_give->next != root_give)
	{
		element = root_give->next;
		ft_stkadd_top(root_receive, element, 0, NULL);
		root_give->nbr -= 1;
		root_receive->nbr += 1;
	}
	if (s == 'a')
		ft_stkadd_bot(mv, NULL, 0, "pa");
	else
		ft_stkadd_bot(mv, NULL, 0, "pb");
}

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
}

void	mv_rotate_rotate(t_stack *aroot, t_stack *broot, t_stack *mv)
{
	mv_rotate(aroot, mv, 'a');
	mv_rotate(broot, mv, 'b');
}

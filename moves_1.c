/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:36:42 by egiacomi          #+#    #+#             */
/*   Updated: 2021/12/04 18:50:47 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mv_swap(t_stack *root)
{
	t_stack	*toswap;

	toswap = root->next->next;
	ft_stkadd_top(root, toswap, 0);
}

void	mv_swap_swap(t_stack *aroot, t_stack *broot)
{
	mv_swap(aroot);
	mv_swap(broot);
}

void	mv_push(t_stack *root_give, t_stack *root_receive)
{
	t_stack	*element;

	if (root_give->next != root_give)
	{
		element = root_give->next;
		ft_stkadd_top(root_receive, element, 0);
		root_give->nbr -= 1;
		root_receive->nbr += 1;
	}
}

void	mv_rotate(t_stack *root)
{
	t_stack	*first_to_last;

	first_to_last = root->next;
	first_to_last->prev = root->prev;
	root->prev->next = first_to_last;
	ft_stkadd_next(first_to_last, root);
}

void	mv_rotate_rotate(t_stack *aroot, t_stack *broot)
{
	mv_rotate(aroot);
	mv_rotate(broot);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:36:42 by egiacomi          #+#    #+#             */
/*   Updated: 2021/12/04 17:44:03 by egiacomi         ###   ########.fr       */
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

	element = root_give->next;
	ft_stkadd_top(root_receive, element, 0);
	// ft_delstk(element, root_give);
}

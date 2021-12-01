/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:36:42 by egiacomi          #+#    #+#             */
/*   Updated: 2021/12/01 20:03:54 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mv_swap(t_stack **astk)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = (*astk)->next->next;
	tmp2 = (*astk);
	tmp2->next = tmp1;
	(*astk) = (*astk)->next;
	(*astk)->next = tmp2;
}

void	mv_swap_swap(t_stack **astk, t_stack **bstk)
{
	mv_swap(astk);
	mv_swap(bstk);
}

void	mv_rotate(t_stack **astk)
{
	
}

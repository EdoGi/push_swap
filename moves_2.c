/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:52:16 by egiacomi          #+#    #+#             */
/*   Updated: 2021/12/04 19:03:05 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mv_reverse_rotate(t_stack *root)
{
	t_stack	*last_to_first;

	last_to_first = root->prev;
	last_to_first->next = root->next;
	root->next->prev = last_to_first;
	ft_stkadd_prev(last_to_first, root);
}

void	mv_reverse_rotate_rotate(t_stack *aroot, t_stack *broot)
{
	mv_reverse_rotate(aroot);
	mv_reverse_rotate(broot);
}

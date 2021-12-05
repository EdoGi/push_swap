/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:51:41 by egiacomi          #+#    #+#             */
/*   Updated: 2021/12/05 21:41:42 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_rank(t_stack *aroot)
{
	t_stack	*it;
	t_stack	*ic;

	it = aroot->next;
	while (it != aroot)
	{
		it->rank = 0;
		ic = aroot->next;
		while (ic != aroot)
		{
			if (it->nbr > ic->nbr)
				it->rank += 1;
			ic = ic->next;
		}
		it = it->next;
	}
}

/*
void	ft_pre_sort(t_stack *aroot)
{
	t_stack	*copy;
	t_stack	*ita;
	t_stack	*itc;

	copy = ft_createstk();
	if (copy)
	{
		ita = aroot->next;
		ft_stkadd_top(copy, ita, NULL, NULL);
		ita = ita->next;
		while (ita != aroot)
		{
			itc = copy->next;
			while (itc->nbr < ita->nbr)
				itc = itc->next;
			ft_stkadd_prev(itc, ita);
			ita = ita->next;
		}
	}
	ft_stk_supercleaner(ita, itc, copy, NULL);
}
*/
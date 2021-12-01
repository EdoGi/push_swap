/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:26:42 by egiacomi          #+#    #+#             */
/*   Updated: 2021/12/01 18:33:38 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_newstk(void *nbr)
{
	t_stack	*newstack;

	newstack = malloc(sizeof(t_stack));
	if (newstack)
	{
		newstack->nbr = nbr;
		newstack->next = NULL;
	}
	return (newstack);
}

void	ft_stkadd_top(t_stack **astk, t_stack *new)
{
	if (!*astk)
		*astk = new;
	else
	{
		new->next = *astk;
		*astk = new;
	}
}

void	ft_stkadd_bot(t_stack **astk, t_stack *new)
{
	if (astk)
	{
		if (!*astk)
			*astk = new;
		else
			ft_stklast(*astk)->next = new;
	}
}

t_stack	*ft_stklast(t_stack *stk)
{
	while (stk && stk->next)
		stk = stk->next;
	return (stk);
}

int	ft_stksize(t_stack *stk)
{
	int	i;

	i = 0;
	while (stk)
	{
		stk = stk->next;
		i++;
	}
	return (i);
}

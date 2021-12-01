/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:26:42 by egiacomi          #+#    #+#             */
/*   Updated: 2021/12/01 23:10:59 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	**ft_createstk(void)
{
	t_stack	*(*root);

	root = malloc(sizeof(t_stack));
	if (root)
	{
		(*root)->next = root;
		(*root)->prev = root;
		(*root)->nbr = 0;
	}
	return (&root);
}

void	ft_stkadd_top(t_stack **root, int val)
{
	t_stack	*new;

	if (root)
	{
		new->nbr = val;
		new->prev = (*root);
		new->next = (*root)->next;
		(*root)->next = new;
		(*root)->nbr += 1;
	}
}

void	ft_stkadd_next(t_stack *element, t_stack *new, t_stack **root)
{
	if (new)
	{
		new->next = element->next;
		new->prev = element;
		element->next->prev = new;
		element->next = new;
		(*root)->nbr += 1;
	}
}

void	ft_stkadd_prev(t_stack *element, t_stack *new, t_stack **root)
{
	if (new)
	{
		new->prev = element->prev;
		new->next = element;
		element->prev->next = new;
		element->prev = new;
		(*root)->nbr += 1;
	}
}


/*
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

t_stack	*ft_stklast(t_stack *stk)
{
	while (stk && stk->next)
		stk = stk->next;
	return (stk);
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
*/

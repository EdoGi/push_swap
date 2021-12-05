/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:26:42 by egiacomi          #+#    #+#             */
/*   Updated: 2021/12/05 18:37:12 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_setidx(t_stack *root)
{
	t_stack	*it;
	int		i;

	root->idx = 0;
	it = root->next;
	i = 1;
	while (it != root)
	{
		it->idx = i;
		it = it->next;
		i++;
	}
}

void	ft_stkadd_next(t_stack *element, t_stack *new)
{
	if (new)
	{
		new->next = element->next;
		new->prev = element;
		element->next->prev = new;
		element->next = new;
	}
}

void	ft_stkadd_prev(t_stack *element, t_stack *new)
{
	if (new)
	{
		new->prev = element->prev;
		new->next = element;
		element->prev->next = new;
		element->prev = new;
	}
}

void	ft_stkadd_top(t_stack *root, t_stack *element, int val, char *s)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (root)
	{
		if (!element)
		{
			new->nbr = val;
			new->mv = s;
		}
		else
		{
			new->nbr = element->nbr;
			new->mv = s;
			ft_delstk(element, root);
		}
		ft_stkadd_next(root, new);
		root->nbr += 1;
	}
}

void	ft_stkadd_bot(t_stack *root, t_stack *element, int val, char *s)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (root)
	{
		if (!element)
		{
			new->nbr = val;
			new->mv = s;
		}
		else
		{
			new->nbr = element->nbr;
			new->mv = s;
			ft_delstk(element, root);
		}
		ft_stkadd_prev(root, new);
		root->nbr += 1;
	}
}

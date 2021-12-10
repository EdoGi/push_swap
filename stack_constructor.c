/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_constructor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:33:05 by egiacomi          #+#    #+#             */
/*   Updated: 2021/12/10 22:53:07 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Create a stack Double-Chained Circular Linked List with Root as start/end */
t_stack	*ft_createstk(void)
{
	t_stack	*root;

	root = malloc(sizeof(t_stack));
	if (root)
	{
		root->next = root;
		root->prev = root;
		root->nbr = 0;
		root->idx = 0;
	}
	return (root);
}

/* Delete an element in root stack */
void	ft_delstk(t_stack *element, t_stack *root)
{
	if (element)
	{
		element->prev->next = element->next;
		element->next->prev = element->prev;
		root->nbr -= 1;
		free(element);
	}
}

/* Delete and free all element in root stack */
void	ft_stkclean(t_stack *root)
{
	t_stack	*clean;
	t_stack	*tmp;

	if (root)
	{
		clean = root->next;
		while (clean != root)
		{
			tmp = clean->next;
			free(clean);
			clean = tmp;
		}
	}
	free(root);
}

/* Set correct index's in root_parameter stack */
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

/* Delete and free 4 stack in the same time */
void	ft_stk_supercleaner(t_stack *a, t_stack *b, t_stack *c, t_stack *d)
{
	if (a)
		ft_stkclean(a);
	if (b)
		ft_stkclean(b);
	if (c)
		ft_stkclean(c);
	if (d)
		ft_stkclean(d);
}

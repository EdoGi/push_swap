/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_cleaner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:33:05 by egiacomi          #+#    #+#             */
/*   Updated: 2021/12/05 18:20:37 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

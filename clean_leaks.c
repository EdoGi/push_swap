/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_leaks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:33:05 by egiacomi          #+#    #+#             */
/*   Updated: 2021/12/01 18:47:52 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stkdelone(t_stack *stk)
{
	stk->nbr = NULL;
	free(stk);
}

void	ft_stkclear(t_stack **stk)
{
	t_stack	*tmp;

	if (!stk)
		return ;
	if (*stk)
	{
		while (*stk)
		{
			tmp = (*stk)->next;
			(*stk)->nbr = NULL;
			free(*stk);
			(*stk) = tmp;
		}
	}
}

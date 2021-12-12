/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:36:42 by egiacomi          #+#    #+#             */
/*   Updated: 2021/12/12 17:18:38 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swap root_stack and take char 's' to know whether its "sa" or "sb" */
void	mv_swap(t_stack *root, t_stack *mv, char s)
{
	t_stack	*toswap;

	toswap = root->next->next;
	ft_stkadd_top(root, toswap, 0, NULL);
	if (s == 'a')
		ft_stkadd_bot(mv, NULL, 0, "sa");
	else
		ft_stkadd_bot(mv, NULL, 0, "sb");
	ft_setidx(root);
}

void	mv_swap_swap(t_stack *aroot, t_stack *broot, t_stack *mv)
{
	mv_swap(aroot, mv, 'a');
	mv_swap(broot, mv, 'b');
}

/* Push and take char 's' to know whether its "pa" (s = a) or "pb" (s != a) */
void	mv_push(t_stack *root_give, t_stack *root_receive, t_stack *mv, char s)
{
	t_stack	*element;

	if (root_give->next != root_give)
	{
		element = root_give->next;
		ft_stkadd_top(root_receive, element, 0, NULL);
		root_give->nbr -= 1;
		root_receive->nbr += 1;
	}
	if (s == 'a')
		ft_stkadd_bot(mv, NULL, 0, "pa");
	else
		ft_stkadd_bot(mv, NULL, 0, "pb");
	ft_setidx(root_give);
	ft_setidx(root_receive);
}

/* Move an element from stack_root to top_of_stack in minimum moves */
void	mv_optimal_move_top(t_stack *root, t_stack *element, t_stack *mv)
{
	int	lenght;

	lenght = ft_stack_size(root);
	if (element->idx <= ((lenght / 2) + 1))
		ft_down_top_ra(root, element->rank, mv);
	else
		ft_down_top_rra(root, element->rank, mv);
}

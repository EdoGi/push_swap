/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:51:41 by egiacomi          #+#    #+#             */
/*   Updated: 2021/12/12 20:25:50 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Sort stack with 3 values and less */
void	ft_sort_three(t_stack *aroot, t_stack *mv)
{
	t_stack	*it;

	ft_set_rank(aroot);
	if (!ft_is_sorted(aroot))
	{
		it = aroot->next;
		if (it->rank == 0)
		{
			mv_reverse_rotate(aroot, mv, 'a');
			mv_swap(aroot, mv, 'a');
		}
		else if (it->rank == 1)
		{
			if (it->next->rank == 0)
				mv_swap(aroot, mv, 'a');
			else if (it->next->rank == 2)
				mv_reverse_rotate(aroot, mv, 'a');
		}
		else if (it->rank == 2)
		{
			mv_rotate(aroot, mv, 'a');
			if (aroot->next->rank == 1)
				mv_swap(aroot, mv, 'a');
		}
	}
}

/* Sort stack with 10 values and less */
void	ft_sort_small(t_stack *aroot, t_stack *broot, t_stack *mv)
{
	t_stack	*it;
	int		i;

	i = 0;
	while (ft_stack_size(aroot) > 3)
	{
		it = aroot->next;
		while (it->rank != i)
			it = it->next;
		mv_optimal_move_top(aroot, it, mv);
		mv_push(aroot, broot, mv, 'b');
		i++;
	}
	ft_sort_three(aroot, mv);
	ft_b_to_a(aroot, broot, mv);
}

/* Sort stack with 100 values and less */
void	ft_sort_medium(t_stack *aroot, t_stack *broot, t_stack *mv, int chunk)
{
	t_stack	*it;
	int		add;
	// int		loop;
	// int		size;

	add = chunk;
	// size = ft_stack_size(aroot);
	// loop = 1;
	while (ft_stack_size(aroot) != 0)
	{
		// printf("\nadd is %d and chunk is %d for %d stack size\n", add, chunk, size);
		it = aroot->next;
		while (it != aroot)
		{
			// printf("loop SIZE STACK  is : %d\n\n", ft_stack_size(aroot));
			it = aroot->next;
			while (it->rank > chunk && it != aroot)
			{
				// printf("nbr %d got : %d > %d\n", it->nbr, it->rank, chunk);
				it = it->next;
			}
			if (it->rank <= chunk && it != aroot)
			{
				// printf("PUSH >>  %d with rank %d\n\n", it->nbr, it->rank);
				mv_optimal_move_top(aroot, it, mv);
				mv_push(aroot, broot, mv, 'b');
			}
			// else if (it == aroot)
			// {
			// 	printf("\n\nSTOOOOOOOOOOOOOOOOOP\n\n");
			// 	loop = 0;
			// }
			// printf("loop is %d\n", loop);
		}
		// printf("\nchunk is %d\n", chunk);
		chunk += add;
		// printf("\nchunk is %d and %d for size : %d\n", chunk, ft_stack_size(aroot), ft_max_rank(broot));
	}
	// printf("coucou%d", ft_stack_size(broot));
	ft_sort_b_to_a(aroot, broot, mv);
}

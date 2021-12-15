/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:27:47 by egiacomi          #+#    #+#             */
/*   Updated: 2021/12/15 19:21:54 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Set Rank to each number (rank = actual order in sorted list) */
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

/* Fill stack A after checking Error on each Value  */
int	ft_fill_stack_a(t_stack *aroot, char *val)
{
	long	nbr;

	if (!(ft_isnumber(val)))
		return (0);
	nbr = ft_atoi(val);
	if (ft_exist(aroot, nbr) || ft_islong(nbr))
		return (0);
	ft_stkadd_top(aroot, NULL, nbr, NULL);
	return (1);
}

/* SetUp (Inputs, Parsing, Filling A stack) & handle Error message */
t_stack	*ft_setup(int ac, char **av, t_stack *aroot, t_stack *broot)
{
	int		i;
	t_stack	*mv;

	i = ac;
	mv = ft_createstk();
	if (!mv)
	{
		ft_stk_supercleaner(aroot, broot, NULL, NULL);
		return (NULL);
	}
	while (--i > 0)
	{
		if (!(ft_fill_stack_a(aroot, av[i])))
		{
			ft_putstr_fd("Error\n", 2);
			ft_stk_supercleaner(mv, broot, aroot, NULL);
			return (0);
		}
	}
	ft_setidx(aroot);
	return (mv);
}

void	ft_sorting(t_stack *aroot, t_stack *broot, t_stack *mv, int ac)
{
	if (ac <= 4)
		ft_sort_three(aroot, mv);
	else if (ac <= 11)
		ft_sort_small(aroot, broot, mv);
	else if (ac <= 101)
		ft_sort_medium(aroot, broot, mv, (ft_stack_size(aroot) / 5));
	else if (ac >= 101)
		ft_sort_medium(aroot, broot, mv, (ft_stack_size(aroot) / 10));
	ft_print_mooves(mv);
	ft_stk_supercleaner(mv, broot, aroot, NULL);
}

int	main(int ac, char **av)
{
	t_stack	*aroot;
	t_stack	*broot;
	t_stack	*mv;

	aroot = ft_createstk();
	broot = ft_createstk();
	if (!(aroot) || !(broot) || (ac < 2))
	{
		if (aroot)
			ft_stkclean(aroot);
		if (broot)
			ft_stkclean(broot);
		return (0);
	}
	mv = ft_setup(ac, av, aroot, broot);
	if (!mv)
		return (0);
	ft_set_rank(aroot);
	if (ft_is_sorted(aroot))
	{
		ft_stk_supercleaner (mv, aroot, broot, NULL);
		return (0);
	}
	ft_sorting(aroot, broot, mv, ac);
}

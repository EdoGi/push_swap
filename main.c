/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:27:47 by egiacomi          #+#    #+#             */
/*   Updated: 2021/12/05 23:20:43 by egiacomi         ###   ########.fr       */
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

	if (ac < 2)
		return (0);
	i = ac;
	mv = ft_createstk();
	while (--i > 0)
	{
		if (!(ft_fill_stack_a(aroot, av[i])))
		{
			ft_putstr_fd("Error\n", 2);
			ft_stkclean(broot);
			ft_stkclean(aroot);
			ft_stkclean(mv);
			return (0);
		}
	}
	ft_setidx(aroot);
	return (mv);
}

int	main(int ac, char **av)
{
	t_stack	*aroot;
	t_stack	*broot;
	t_stack	*mv;

	aroot = ft_createstk();
	broot = ft_createstk();
	if (!(aroot) || !(broot))
		return (0);
	mv = ft_setup(ac, av, aroot, broot);
	if (!mv)
		return (0);
	ft_set_rank(aroot);
	if (ft_is_sorted(aroot))
		return (0);
	if (ac < 4)
		ft_sort_small(aroot, broot, mv);
	ft_stk_supercleaner(mv, broot, aroot, NULL);
}

/*
	ft_stkadd_top(broot, NULL, 75, NULL);
	printf("\n%d aroot numbers\n", aroot->nbr);
	for (it = aroot->next ; it != aroot ; it = it->next)
		printf("aroot %d at idx : %d with rank : %d\n", it->nbr, it->idx, it->rank);
	mv_push(broot, aroot, mv, 'a');
	printf("\nPUSH : %d aroot numbers\n", aroot->nbr);
	for (it = aroot->next ; it != aroot ; it = it->next)
		printf("aroot %d at idx : %d with rank : %d\n", it->nbr, it->idx, it->rank);
	mv_rotate(aroot, mv, 'a');
	printf("\nROTATE : %d aroot numbers\n", aroot->nbr);
	for (it = aroot->next ; it != aroot ; it = it->next)
		printf("aroot %d at idx : %d with rank : %d\n", it->nbr, it->idx, it->rank);
	mv_swap(aroot, mv, 'a');
	printf("\nSWAP : %d aroot numbers\n", aroot->nbr);
	for (it = aroot->next ; it != aroot ; it = it->next)
		printf("aroot %d at idx : %d with rank : %d\n", it->nbr, it->idx, it->rank);
	mv_reverse_rotate(aroot, mv, 'a');
	printf("\nREVERSE R : %d aroot numbers\n", aroot->nbr);
	for (it = aroot->next ; it != aroot ; it = it->next)
		printf("aroot %d at idx : %d with rank : %d\n", it->nbr, it->idx, it->rank);
	printf("\nMOOVES :\n");
	for (it = mv->next ; it != mv ; it = it->next)
		printf("%s\n", it->mv);
*/
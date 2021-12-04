/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:54:14 by egiacomi          #+#    #+#             */
/*   Updated: 2021/12/04 19:04:35 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	main(int ac, char **av)
{
	int		a;
	int		b;
	int		c;
	int		i;
	t_stack	*aroot;
	t_stack	*broot;
	t_stack	*it;

	a = atoi(av[1]);
	b = atoi(av[2]);
	c = atoi(av[3]);
	aroot = ft_createstk();
	broot = ft_createstk();

	ft_stkadd_top(aroot, NULL, a);
	printf("%d aroot numbers\n", aroot->nbr);
	for (it = aroot->next ; it != aroot ; it = it->next)
		printf("aroot %d\n", it->nbr);
	
	ft_stkadd_top(aroot, NULL, b);
	printf("%d aroot numbers\n", aroot->nbr);
	for (it = aroot->next ; it != aroot ; it = it->next)
		printf("aroot %d\n", it->nbr);
	
	ft_stkadd_bot(aroot, NULL, c);
	printf("%d aroot numbers\n", aroot->nbr);
	for (it = aroot->next ; it != aroot ; it = it->next)
		printf("aroot %d\n", it->nbr);
	
	ft_delstk(aroot->next, aroot);
	printf("%d aroot numbers\n", aroot->nbr);	
	for (it = aroot->next ; it != aroot ; it = it->next)
		printf("aroot %d\n", it->nbr);
	
	mv_swap(aroot);
	printf("swapping\n");
	for (it = aroot->next ; it != aroot ; it = it->next)
		printf("aroot %d\n", it->nbr);

	// printf("%d aroot numbers\n", aroot->nbr);	
	// printf("%d broot numbers\n", broot->nbr);	
	// mv_push(broot, aroot);
	// printf("pushing\n");
	// for (it = aroot->next ; it != aroot ; it = it->next)
	// 	printf("aroot %d\n", it->nbr);
	// printf("%d aroot numbers\n", aroot->nbr);
	// for (it = broot->next ; it != broot ; it = it->next)
	// 	printf("broot %d\n", it->nbr);
	// printf("%d broot numbers\n", broot->nbr);	

	// printf("%d aroot numbers\n", aroot->nbr);	
	// printf("%d broot numbers\n", broot->nbr);	
	// mv_push(aroot, broot);
	// printf("pushing\n");
	// for (it = aroot->next ; it != aroot ; it = it->next)
	// 	printf("aroot %d\n", it->nbr);
	// printf("%d aroot numbers\n", aroot->nbr);	
	// for (it = broot->next ; it != broot ; it = it->next)
	// 	printf("broot %d\n", it->nbr);
	// printf("%d broot numbers\n", broot->nbr);

	ft_stkadd_top(aroot, NULL, b);
	printf("%d aroot numbers\n", aroot->nbr);
	for (it = aroot->next ; it != aroot ; it = it->next)
		printf("aroot %d\n", it->nbr);
	mv_rotate(aroot);
	printf("rotating\n");
	printf("%d aroot numbers\n", aroot->nbr);
	for (it = aroot->next ; it != aroot ; it = it->next)
		printf("aroot %d\n", it->nbr);

	mv_reverse_rotate(aroot);
	mv_reverse_rotate(aroot);
	printf("2 rev_rotating\n");
	printf("%d aroot numbers\n", aroot->nbr);
	for (it = aroot->next ; it != aroot ; it = it->next)
		printf("aroot %d\n", it->nbr);
	ft_stkclean(broot);
	ft_stkclean(aroot);
	return (0);
}


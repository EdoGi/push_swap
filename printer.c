/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:03:59 by egiacomi          #+#    #+#             */
/*   Updated: 2021/12/15 21:40:39 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = -1;
	if (s)
	{
		while (s[++i])
			ft_putchar_fd(s[i], fd);
	}
}

/* Print the moves used to sort in stdout with \n after each move */
void	ft_print_moves(t_stack *mv)
{
	t_stack	*it;

	it = mv->next;
	while (it != mv)
	{
		ft_putstr_fd(it->mv, 1);
		ft_putchar_fd('\n', 1);
		it = it->next;
	}
}

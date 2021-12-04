/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:21:14 by egiacomi          #+#    #+#             */
/*   Updated: 2021/12/04 19:04:05 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_list
{
	int				nbr;
	struct s_list	*prev;
	struct s_list	*next;
}					t_stack;

t_stack	*ft_createstk(void);
void	ft_stkadd_next(t_stack *element, t_stack *new);
void	ft_stkadd_prev(t_stack *element, t_stack *new);
void	ft_stkadd_top(t_stack *root, t_stack *element, int val);
void	ft_stkadd_bot(t_stack *root, t_stack *element, int val);
void	ft_delstk(t_stack *element, t_stack *root);
void	ft_stkclean(t_stack *root);
void	mv_swap(t_stack *root);
void	mv_swap_swap(t_stack *aroot, t_stack *broot);
void	mv_push(t_stack *root_give, t_stack *root_receive);
void	mv_rotate(t_stack *root);
void	mv_reverse_rotate(t_stack *root);
void	mv_reverse_rotate_rotate(t_stack *aroot, t_stack *broot);

#endif

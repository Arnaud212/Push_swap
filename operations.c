/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:37:26 by agiraud           #+#    #+#             */
/*   Updated: 2021/10/22 09:32:28 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_sa(t_stack *stack_a)
{
	int	tmp;

	while (stack_a->prev)
		stack_a = stack_a->prev;
	tmp = stack_a->next->value;
	stack_a->next->value = stack_a->value;
	stack_a->value = tmp;
	ft_putstr_fd("sa\n", 1);
	return (stack_a);
}

t_stack	*ft_sb(t_stack *stack_b)
{
	int	tmp;

	while (stack_b->prev)
		stack_b = stack_b->prev;
	tmp = stack_b->next->value;
	stack_b->next->value = stack_b->value;
	stack_b->value = tmp;
	ft_putstr_fd("sb\n", 1);
	return (stack_b);
}

t_stack	*ft_ra(t_stack *stack_a)
{
	t_stack	*head;
	t_stack	*ret;

	while (stack_a->prev)
		stack_a = stack_a->prev;
	head = stack_a;
	stack_a = stack_a->next;
	ret = stack_a;
	stack_a->prev = NULL;
	while (stack_a->next)
		stack_a = stack_a->next;
	stack_a->next = head;
	head->prev = stack_a;
	head->next = NULL;
	ft_putstr_fd("ra\n", 1);
	return (ret);
}

t_stack	*ft_rb(t_stack *stack_b)
{
	t_stack	*head;
	t_stack	*ret;

	while (stack_b->prev)
		stack_b = stack_b->prev;
	head = stack_b;
	stack_b = stack_b->next;
	ret = stack_b;
	stack_b->prev = NULL;
	while (stack_b->next)
		stack_b = stack_b->next;
	stack_b->next = head;
	head->prev = stack_b;
	head->next = NULL;
	ft_putstr_fd("rb\n", 1);
	return (ret);
}

t_stack	*ft_rra(t_stack *stack_a)
{
	t_stack	*last;

	while (stack_a->next)
		stack_a = stack_a->next;
	last = stack_a;
	stack_a = stack_a->prev;
	stack_a->next = NULL;
	while (stack_a->prev)
		stack_a = stack_a->prev;
	stack_a->prev = last;
	last->prev = NULL;
	last->next = stack_a;
	ft_putstr_fd("rra\n", 1);
	return (last);
}

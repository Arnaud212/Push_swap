/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:02:01 by agiraud           #+#    #+#             */
/*   Updated: 2021/10/22 09:54:21 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_pb_else(t_frame *frame, t_stack *first)
{
	frame->stack_a = get_top(frame->stack_a);
	first = frame->stack_a;
	frame->stack_a = frame->stack_a->next;
	frame->stack_a->prev = NULL;
	first->next = NULL;
	frame->stack_b = first;
	return (first);
}

void	ft_pb(t_frame *frame)
{
	t_stack	*first;

	first = NULL;
	if (frame->stack_b != NULL)
	{
		frame->stack_b = get_top(frame->stack_b);
		if (frame->stack_a)
		{
			frame->stack_a = get_top(frame->stack_a);
			first = frame->stack_a;
			frame->stack_a = frame->stack_a->next;
			if (frame->stack_a)
				frame->stack_a->prev = NULL;
			frame->stack_b->prev = first;
			first->next = frame->stack_b;
		}
	}
	else
		first = ft_pb_else(frame, first);
	ft_putstr_fd("pb\n", 1);
}

static t_stack	*ft_pa_else(t_frame *frame, t_stack *first)
{
	first = NULL;
	if (frame->stack_b)
	{
		frame->stack_b = get_top(frame->stack_b);
		first = frame->stack_b;
		frame->stack_b = frame->stack_b->next;
		frame->stack_b->prev = NULL;
		first->next = NULL;
		frame->stack_a = first;
	}
	return (first);
}

void	ft_pa(t_frame *frame)
{
	t_stack	*first;

	first = NULL;
	if (frame->stack_a != NULL)
	{
		frame->stack_a = get_top(frame->stack_a);
		if (frame->stack_b)
		{
			frame->stack_b = get_top(frame->stack_b);
			first = frame->stack_b;
			frame->stack_b = frame->stack_b->next;
			if (frame->stack_b)
				frame->stack_b->prev = NULL;
			frame->stack_a->prev = first;
			first->next = frame->stack_a;
		}
	}
	else
		first = ft_pa_else(frame, first);
	ft_putstr_fd("pa\n", 1);
}

t_stack	*ft_rrb(t_stack *stack_b)
{
	t_stack	*last;

	last = NULL;
	if (ft_get_stack_length(stack_b) > 1)
	{
		 while (stack_b && stack_b->next)
			stack_b = stack_b->next;
		last = stack_b;
		stack_b = stack_b->prev;
		stack_b->next = NULL;
		while (stack_b->prev)
			stack_b = stack_b->prev;
		stack_b->prev = last;
		last->prev = NULL;
		last->next = stack_b;
	}
	ft_putstr_fd("rrb\n", 1);
	return (last);
}

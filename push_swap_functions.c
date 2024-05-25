/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 04:54:52 by agiraud           #+#    #+#             */
/*   Updated: 2021/10/22 09:53:23 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_in_chunk(t_frame *frame, int start, int end, int value)
{
	while (start < end)
		if (value == frame->sorted_stack[start++])
			return (1);
	return (0);
}

int	scan_from_top(t_frame *frame, int start, int end)
{
	int	moves;

	moves = 0;
	while (frame->stack_a->prev)
		frame->stack_a = frame->stack_a->prev;
	while (frame->stack_a->next)
	{
		if (is_in_chunk(frame, start, end, frame->stack_a->value))
		{
			frame->hold_first = frame->stack_a->value;
			return (moves);
		}
		frame->stack_a = frame->stack_a->next;
		moves++;
	}
	return (moves);
}

int	scan_from_bottom(t_frame *frame, int start, int end)
{
	int		moves;

	moves = 0;
	while (frame->stack_a->next)
		frame->stack_a = frame->stack_a->next;
	while (frame->stack_a->prev)
	{
		if (is_in_chunk(frame, start, end, frame->stack_a->value))
		{
			frame->hold_second = frame->stack_a->value;
			return (moves);
		}
		frame->stack_a = frame->stack_a->prev;
		moves++;
	}
	return (moves);
}

int	get_biggest(t_frame frame)
{
	int	pos;
	int	i;
	int	biggest_value;

	i = 0;
	pos = 0;
	while (frame.stack_b->prev)
		frame.stack_b = frame.stack_b->prev;
	biggest_value = frame.stack_b->value;
	while (frame.stack_b)
	{
		if (biggest_value <= frame.stack_b->value)
		{
			biggest_value = frame.stack_b->value;
			pos = i;
		}
		i++;
		frame.stack_b = frame.stack_b->next;
	}
	return (pos);
}

int	verify_if_sorted(t_stack *stack_a)
{
	int	length;

	length = ft_get_stack_length(stack_a);
	while (stack_a->prev)
		stack_a = stack_a->prev;
	while (length > 1)
	{
		if (stack_a->value > stack_a->next->value)
			return (1);
		stack_a = stack_a->next;
		length--;
	}
	return (0);
}

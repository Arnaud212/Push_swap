/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 05:11:39 by agiraud           #+#    #+#             */
/*   Updated: 2021/10/22 09:51:39 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_top(t_stack *stack)
{
	while (stack->prev)
		stack = stack->prev;
	return (stack);
}

t_stack	*get_last(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

static void	under_middle_nb(t_frame	*frame, int middle_nb)
{
	int	i;

	i = 0;
	while (i < frame->nb_param)
	{
		if (frame->stack_a->value < middle_nb)
			ft_pb(frame);
		else
			frame->stack_a = ft_ra(frame->stack_a);
		i++;
	}
}

t_stack	*sort_5_params(t_frame *frame)
{
	int		middle_nb;
	t_stack	*tmp;

	middle_nb = frame->sorted_stack[frame->nb_param / 2];
	while (frame->stack_a->prev)
		frame->stack_a = frame->stack_a->prev;
	tmp = frame->stack_a;
	under_middle_nb(frame, middle_nb);
	frame->nb_param = ft_get_stack_length(frame->stack_a);
	if (frame->nb_param == 3)
		frame->stack_a = sort_3_params(frame->stack_a);
	else
	{
		frame->stack_a = get_top(frame->stack_a);
		if (frame->stack_a->value > frame->stack_a->next->value)
			frame->stack_a = ft_sa(frame->stack_a);
	}
	while (frame->stack_b->prev)
		frame->stack_b = frame->stack_b->prev;
	if (frame->stack_b->value < frame->stack_b->next->value)
		frame->stack_b = ft_sb(frame->stack_b);
	ft_pa(frame);
	ft_pa(frame);
	return (frame->stack_a);
}

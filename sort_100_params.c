/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:21:21 by agiraud           #+#    #+#             */
/*   Updated: 2021/10/22 09:52:38 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_frame	*push_nb(t_frame *frame, int start, int end)
{
	int		hold_first_moves;
	int		hold_second_moves;

	hold_first_moves = scan_from_top(frame, start, end);
	hold_second_moves = scan_from_bottom(frame, start, end);
	if (hold_first_moves <= hold_second_moves)
	{
		while (hold_first_moves-- > 0)
			frame->stack_a = ft_ra(frame->stack_a);
		ft_pb(frame);
	}
	else
	{
		while (hold_second_moves >= 0)
		{
			frame->stack_a = ft_rra(frame->stack_a);
			hold_second_moves--;
		}
		ft_pb(frame);
	}
	return (frame);
}

static int	move_to_top_and_push(t_frame *frame)
{
	int	half;
	int	nb_pos;

	nb_pos = get_biggest((*frame));
	half = ft_get_stack_length(frame->stack_b) / 2;
	if (nb_pos < half)
	{
		while (nb_pos-- > 0)
			ft_rb((*frame).stack_b);
		ft_pa(frame);
	}
	else
	{
		nb_pos = ft_get_stack_length(frame->stack_b) - nb_pos ;
		while (nb_pos-- > 0)
			ft_rrb((*frame).stack_b);
		ft_pa(frame);
	}
	return (1);
}

t_frame	*push_back(t_frame *frame)
{
	while (frame->stack_b)
		move_to_top_and_push(frame);
	return (frame);
}

int	sort_100_params(t_frame *frame)
{
	int	chunk_length;
	int	chunk_start;
	int	i;
	int	j;
	int	cut;

	i = 0;
	j = 0;
	chunk_length = ft_get_stack_length(frame->stack_a) / 5;
	cut = chunk_length;
	chunk_start = 0;
	while (i < 5)
	{
		while (j++ < chunk_length)
			frame = push_nb(frame, chunk_start, chunk_length);
		chunk_length += cut;
		chunk_start += cut;
		i++;
	}
	frame->nb_param = ft_get_stack_length(frame->stack_a);
	while (frame->stack_a)
		ft_pb(frame);
	frame = push_back(frame);
	return (1);
}

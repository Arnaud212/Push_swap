/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 02:03:03 by agiraud           #+#    #+#             */
/*   Updated: 2021/10/22 09:55:12 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_over_100_params(t_frame *frame)
{
	int	chunk_length;
	int	chunk_start;
	int	i;
	int	j;
	int	cut;

	i = 0;
	j = 0;
	chunk_length = ft_get_stack_length(frame->stack_a) / 13;
	cut = chunk_length;
	chunk_start = 0;
	while (i < 13)
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

static void	sort_by_nb_param(t_frame *frame)
{
	if (frame->nb_param == 1 || frame->nb_param == 2)
	{
		frame->stack_a = get_top(frame->stack_a);
		if (frame->stack_a->value > frame->stack_a->next->value)
			frame->stack_a = ft_sa(frame->stack_a);
	}
	else if (frame->nb_param == 3)
		frame->stack_a = sort_3_params(frame->stack_a);
	else if (frame->nb_param > 3 && frame->nb_param < 6)
		frame->stack_a = sort_5_params(frame);
	else if (frame->nb_param > 5 && frame->nb_param < 101)
		sort_100_params(frame);
	else
		sort_over_100_params(frame);
}

int	main(int ac, char **av)
{
	int		i;
	t_frame	frame;
	int		length;

	i = 0;
	if (ac > 1)
	{
		initialise(ac, av, &frame);
		frame.nb_param = ft_get_stack_length(frame.stack_a);
		length = ft_get_stack_length(frame.stack_a);
		if (!duplicates_nb(&frame, frame.sorted_stack, length))
		{
			ft_putstr_fd("Error\n", 1);
			return (0);
		}
		if (verify_if_sorted(frame.stack_a))
			sort_by_nb_param(&frame);
		free_stack(frame.stack_a);
		free(frame.sorted_stack);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:58:47 by agiraud           #+#    #+#             */
/*   Updated: 2021/10/22 09:52:03 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_cases(int nb1, int nb2, int nb3)
{
	if (nb1 > nb2 && nb2 < nb3 && nb3 > nb1)
		return (1);
	else if (nb1 > nb2 && nb2 > nb3 && nb3 < nb1)
		return (2);
	else if (nb1 > nb2 && nb2 < nb3 && nb3 < nb1)
		return (3);
	else if (nb1 < nb2 && nb2 > nb3 && nb3 > nb1)
		return (4);
	else if (nb1 < nb2 && nb2 > nb3 && nb3 < nb1)
		return (5);
	return (0);
}

t_stack	*sort_3_params(t_stack *stack_a)
{
	int	nb1;
	int	nb2;
	int	nb3;

	stack_a = get_top(stack_a);
	nb1 = stack_a->value;
	nb2 = stack_a->next->value;
	nb3 = stack_a->next->next->value;
	if (ft_cases(nb1, nb2, nb3) == 1)
		stack_a = ft_sa(stack_a);
	else if (ft_cases(nb1, nb2, nb3) == 2)
	{
		stack_a = ft_sa(stack_a);
		stack_a = ft_rra(stack_a);
	}
	else if (ft_cases(nb1, nb2, nb3) == 3)
		stack_a = ft_ra(stack_a);
	else if (ft_cases(nb1, nb2, nb3) == 4)
	{
		stack_a = ft_sa(stack_a);
		stack_a = ft_ra(stack_a);
	}
	else if (ft_cases(nb1, nb2, nb3) == 5)
		stack_a = ft_rra(stack_a);
	return (stack_a);
}

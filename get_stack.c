/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 03:06:41 by agiraud           #+#    #+#             */
/*   Updated: 2021/10/22 10:00:34 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack_a(void)
{
	t_stack	*stack_a;

	stack_a = malloc(sizeof(t_stack));
	stack_a->next = NULL;
	stack_a->prev = NULL;
	return (stack_a);
}

t_stack	*add_list(t_stack *stack)
{
	t_stack	*new_stack;

	new_stack = create_stack_a();
	stack->next = new_stack;
	new_stack->prev = stack;
	return (new_stack);
}

t_stack	*get_stack_a(char **av2, t_stack *stack_a)
{
	int	i;
	int	check;

	stack_a = create_stack_a();
	i = 0;
	check = 0;
	while (av2[i])
	{
		stack_a->value = ft_atoi(av2[i], &check);
		if (check)
			exit(1);
		if (av2[i + 1] != NULL)
			stack_a = add_list(stack_a);
		i++;
	}
	return (stack_a);
}

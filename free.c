/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 04:11:30 by agiraud           #+#    #+#             */
/*   Updated: 2021/10/22 09:19:16 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	int		i;
	int		length;
	t_stack	*tmp;

	i = 0;
	length = ft_get_stack_length(stack);
	while (stack->prev)
		stack = stack->prev;
	while (i < length)
	{
		tmp = stack;
		if (stack)
			stack = stack->next;
		free(tmp);
		i++;
	}
}

void	free_2tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			if (tab[i])
				free(tab[i]);
			i++;
		}
		free(tab);
	}
}

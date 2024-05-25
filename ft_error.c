/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 02:25:42 by agiraud           #+#    #+#             */
/*   Updated: 2021/10/22 10:01:36 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(char **av2)
{
	int	i;
	int	j;

	j = 0;
	while (av2[j])
	{
		i = 0;
		while (i < av2[j][i])
		{
			if (ft_isdigit(av2[j][i]) == 0)
			{
				if (!(i == 0 && (av2[j][i] == '-' || av2[j][i] == '+')))
				{
					ft_putstr_fd("Error\n", 1);
					free_2tab(av2);
					return (0);
				}
			}
			i++;
		}
		j++;
	}
	return (1);
}

int	duplicates_nb(t_frame *frame, int *tab, int length)
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (i < length)
		{
			if (tab[i] == tab[i + 1])
			{
				free_stack(frame->stack_a);
				free(frame->sorted_stack);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

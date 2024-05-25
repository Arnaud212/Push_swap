/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 02:03:46 by agiraud           #+#    #+#             */
/*   Updated: 2021/10/22 10:03:09 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_stack_length(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack && stack->prev)
		stack = stack->prev;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	calcule_param(char **av, int param)
{
	int		i;
	char	**tab;
	int		count;

	count = 0;
	param = 0;
	i = 1;
	while (av[i])
	{
		count = 0;
		if (ft_strchr(av[i], ' '))
		{
			tab = ft_split(av[i], ' ');
			while (tab[count++])
				param++;
			free_2tab(tab);
		}
		else if (av[i][0])
			param++;
		i++;
	}
	return (param);
}

static char	**new_av(int param, char **av, char **av2)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 1;
	j = 0;
	k = 0;
	av2 = (char **)malloc(sizeof(char *) * param + 1);
	while (av[i])
	{
		if (ft_strchr(av[i], ' ') && av[i][0])
		{
			k = 0;
			tab = ft_split(av[i], ' ');
			while (tab[k])
				av2[j++] = ft_strdup(tab[k++]);
			free_2tab(tab);
		}
		else if (av[i][0])
			av2[j++] = ft_strdup(av[i]);
		i++;
	}
	av2[j] = NULL;
	return (av2);
}

static int	*ft_sort_stack(int *stack, int param)
{
	int	tmp;
	int	i;

	i = 0;
	while (i < param - 1)
	{
		if (stack[i] > stack[i + 1])
		{
			tmp = stack[i];
			stack[i] = stack[i + 1];
			stack[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
	return (stack);
}

void	initialise(int param, char **av, t_frame *frame)
{
	int		i;
	int		check;
	char	**av2;
	int		j;

	i = 0;
	j = 0;
	check = 0;
	av2 = NULL;
	param = calcule_param(av, param);
	av2 = new_av(param, av, av2);
	if (!ft_error(av2))
		exit(1);
	frame->sorted_stack = malloc(sizeof(int) * param);
	while (av2[i])
	{
		frame->sorted_stack[i] = ft_atoi(av2[i], &check);
		if (check)
			exit(1);
		i++;
	}
	frame->stack_a = get_stack_a(av2, frame->stack_a);
	free_2tab(av2);
	frame->sorted_stack = ft_sort_stack(frame->sorted_stack, param);
}

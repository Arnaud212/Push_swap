/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 02:03:51 by agiraud           #+#    #+#             */
/*   Updated: 2021/10/22 09:59:49 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

typedef struct s_frame
{
	int		*sorted_stack;
	int		nb_param;
	int		hold_first;
	int		hold_second;
	t_stack	*stack_a;
	t_stack	*stack_b;
}				t_frame;

t_stack		*ft_sa(t_stack *stack_a);
t_stack		*ft_sb(t_stack *stack_b);
t_stack		*ft_ra(t_stack *stack_a);
t_stack		*ft_rb(t_stack *stack_b);
t_stack		*ft_rra(t_stack *stack_a);
t_stack		*ft_rrb(t_stack *stack_b);
void		ft_pa(t_frame *frame);
void		ft_pb(t_frame *frame);
long long	ft_atoi(const char *str, int *check);
int			ft_isdigit(int c);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
int			ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);
t_stack		*create_stack_a(void);
t_stack		*add_list(t_stack *stack);
t_stack		*get_stack_a(char **av2, t_stack *stack_a);
int			ft_error(char **av2);
int			ft_get_stack_length(t_stack *stack);
void		initialise(int param, char **av, t_frame *frame);
void		free_stack(t_stack *stack);
int			duplicates_nb(t_frame *frame, int *tab, int length);
int			verify_if_sorted(t_stack *stack);
t_stack		*get_top(t_stack *stack);
t_stack		*get_last(t_stack *stack);
t_stack		*sort_3_params(t_stack *stack_a);
t_stack		*sort_5_params(t_frame *frame);
int			sort_100_params(t_frame *frame);
t_frame		*push_nb(t_frame *frame, int start, int end);
int			scan_from_top(t_frame *frame, int start, int end);
int			scan_from_bottom(t_frame *frame, int start, int end);
t_frame		*push_back(t_frame *frame);
int			get_biggest(t_frame frame);
void		free_2tab(char **tab);

#endif

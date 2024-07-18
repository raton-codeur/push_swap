/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:06:37 by qhauuy            #+#    #+#             */
/*   Updated: 2024/03/27 15:31:42 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../f.h"

void	sa(t_stack *a, t_stack *b, t_list **operations)
{
	swap(a);
	if (list_add_back(operations, "sa"))
		return (free_stacks(a, b), ft_putendl_fd("Error", 2), exit(1));
}

void	sb(t_stack *a, t_stack *b, t_list **operations)
{
	swap(b);
	if (list_add_back(operations, "sb"))
		return (free_stacks(a, b), ft_putendl_fd("Error", 2), exit(1));
}

void	ss(t_stack *a, t_stack *b, t_list **operations)
{
	swap(a);
	swap(b);
	if (list_add_back(operations, "ss"))
		return (free_stacks(a, b), ft_putendl_fd("Error", 2), exit(1));
}

void	pb(t_stack *a, t_stack *b, t_list **operations)
{
	push(a, b);
	if (list_add_back(operations, "pb"))
		return (free_stacks(a, b), ft_putendl_fd("Error", 2), exit(1));
}

void	pa(t_stack *a, t_stack *b, t_list **operations)
{
	push(b, a);
	if (list_add_back(operations, "pa"))
		return (free_stacks(a, b), ft_putendl_fd("Error", 2), exit(1));
}

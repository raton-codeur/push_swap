/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:09:19 by qhauuy            #+#    #+#             */
/*   Updated: 2024/03/27 15:31:28 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../f.h"

void	ra(t_stack *a, t_stack *b, t_list **operations)
{
	rotate(a);
	if (list_add_back(operations, "ra"))
		return (free_stacks(a, b), ft_putendl_fd("Error", 2), exit(1));
}

void	rb(t_stack *a, t_stack *b, t_list **operations)
{
	rotate(b);
	if (list_add_back(operations, "rb"))
		return (free_stacks(a, b), ft_putendl_fd("Error", 2), exit(1));
}

void	rr(t_stack *a, t_stack *b, t_list **operations)
{
	rotate(a);
	rotate(b);
	if (list_add_back(operations, "rr"))
		return (free_stacks(a, b), ft_putendl_fd("Error", 2), exit(1));
}

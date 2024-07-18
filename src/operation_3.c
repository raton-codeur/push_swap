/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:29:47 by qhauuy            #+#    #+#             */
/*   Updated: 2024/03/27 15:31:02 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../f.h"

void	rra(t_stack *a, t_stack *b, t_list **operations)
{
	reverse_rotate(a);
	if (list_add_back(operations, "rra"))
		return (free_stacks(a, b), ft_putendl_fd("Error", 2), exit(1));
}

void	rrb(t_stack *a, t_stack *b, t_list **operations)
{
	reverse_rotate(b);
	if (list_add_back(operations, "rrb"))
		return (free_stacks(a, b), ft_putendl_fd("Error", 2), exit(1));
}

void	rrr(t_stack *a, t_stack *b, t_list **operations)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (list_add_back(operations, "rrr"))
		return (free_stacks(a, b), ft_putendl_fd("Error", 2), exit(1));
}

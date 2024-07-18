/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_3_bottom_b_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:47:07 by qhauuy            #+#    #+#             */
/*   Updated: 2024/03/27 15:39:21 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../f.h"

void	base_bottom_b_abc(t_sub_stack ss, t_list **operations)
{
	rrb(ss.a, ss.b, operations);
	rrb(ss.a, ss.b, operations);
	rrb(ss.a, ss.b, operations);
	pa(ss.a, ss.b, operations);
	pa(ss.a, ss.b, operations);
	pa(ss.a, ss.b, operations);
}

void	base_bottom_b_acb(t_sub_stack ss, t_list **operations)
{
	rrb(ss.a, ss.b, operations);
	rrb(ss.a, ss.b, operations);
	pa(ss.a, ss.b, operations);
	rrb(ss.a, ss.b, operations);
	pa(ss.a, ss.b, operations);
	pa(ss.a, ss.b, operations);
}

void	base_bottom_b_bac(t_sub_stack ss, t_list **operations)
{
	rrb(ss.a, ss.b, operations);
	rrb(ss.a, ss.b, operations);
	sb(ss.a, ss.b, operations);
	rrb(ss.a, ss.b, operations);
	pa(ss.a, ss.b, operations);
	pa(ss.a, ss.b, operations);
	pa(ss.a, ss.b, operations);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_3_bottom_b_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:47:15 by qhauuy            #+#    #+#             */
/*   Updated: 2024/03/27 15:39:48 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../f.h"

void	base_bottom_b_bca(t_sub_stack ss, t_list **operations)
{
	rrb(ss.a, ss.b, operations);
	rrb(ss.a, ss.b, operations);
	pa(ss.a, ss.b, operations);
	pa(ss.a, ss.b, operations);
	rrb(ss.a, ss.b, operations);
	pa(ss.a, ss.b, operations);
}

void	base_bottom_b_cab(t_sub_stack ss, t_list **operations)
{
	rrb(ss.a, ss.b, operations);
	pa(ss.a, ss.b, operations);
	rrb(ss.a, ss.b, operations);
	rrb(ss.a, ss.b, operations);
	pa(ss.a, ss.b, operations);
	pa(ss.a, ss.b, operations);
}

void	base_bottom_b_cba(t_sub_stack ss, t_list **operations)
{
	rrb(ss.a, ss.b, operations);
	pa(ss.a, ss.b, operations);
	rrb(ss.a, ss.b, operations);
	pa(ss.a, ss.b, operations);
	rrb(ss.a, ss.b, operations);
	pa(ss.a, ss.b, operations);
}

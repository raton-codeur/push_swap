/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_3_bottom_a_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:46:43 by qhauuy            #+#    #+#             */
/*   Updated: 2024/03/27 15:36:04 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../f.h"

void	base_bottom_a_abc(t_sub_stack ss, t_list **operations)
{
	rra(ss.a, ss.b, operations);
	pb(ss.a, ss.b, operations);
	rra(ss.a, ss.b, operations);
	rra(ss.a, ss.b, operations);
	sa(ss.a, ss.b, operations);
	pa(ss.a, ss.b, operations);
}

void	base_bottom_a_acb(t_sub_stack ss, t_list **operations)
{
	rra(ss.a, ss.b, operations);
	rra(ss.a, ss.b, operations);
	sa(ss.a, ss.b, operations);
	rra(ss.a, ss.b, operations);
	sa(ss.a, ss.b, operations);
}

void	base_bottom_a_bac(t_sub_stack ss, t_list **operations)
{
	rra(ss.a, ss.b, operations);
	rra(ss.a, ss.b, operations);
	pb(ss.a, ss.b, operations);
	rra(ss.a, ss.b, operations);
	sa(ss.a, ss.b, operations);
	pa(ss.a, ss.b, operations);
}

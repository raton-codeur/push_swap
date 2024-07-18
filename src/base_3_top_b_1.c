/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_3_top_b_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:46:18 by qhauuy            #+#    #+#             */
/*   Updated: 2024/03/27 15:40:07 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../f.h"

void	base_top_b_abc(t_sub_stack ss, t_list **operations)
{
	pa(ss.a, ss.b, operations);
	sb(ss.a, ss.b, operations);
	pa(ss.a, ss.b, operations);
	sa(ss.a, ss.b, operations);
	pa(ss.a, ss.b, operations);
	sa(ss.a, ss.b, operations);
}

void	base_top_b_acb(t_sub_stack ss, t_list **operations)
{
	pa(ss.a, ss.b, operations);
	pa(ss.a, ss.b, operations);
	sa(ss.a, ss.b, operations);
	pa(ss.a, ss.b, operations);
	sa(ss.a, ss.b, operations);
}

void	base_top_b_bac(t_sub_stack ss, t_list **operations)
{
	pa(ss.a, ss.b, operations);
	sb(ss.a, ss.b, operations);
	pa(ss.a, ss.b, operations);
	sa(ss.a, ss.b, operations);
	pa(ss.a, ss.b, operations);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_3_top_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:46:40 by qhauuy            #+#    #+#             */
/*   Updated: 2024/03/27 15:36:04 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../f.h"

void	base_only_3_a(t_sub_stack ss, t_list **operations)
{
	int	case_3;

	case_3 = get_case_3(ss);
	if (case_3 == acb)
	{
		rra(ss.a, ss.b, operations);
		sa(ss.a, ss.b, operations);
	}
	else if (case_3 == bac)
		sa(ss.a, ss.b, operations);
	else if (case_3 == bca)
		rra(ss.a, ss.b, operations);
	else if (case_3 == cab)
		ra(ss.a, ss.b, operations);
	else if (case_3 == cba)
	{
		ra(ss.a, ss.b, operations);
		sa(ss.a, ss.b, operations);
	}
}

void	base_top_a_acb(t_sub_stack ss, t_list **operations)
{
	if ((ss.a)->size_array == 3)
		base_only_3_a(ss, operations);
	else
	{
		pb(ss.a, ss.b, operations);
		sa(ss.a, ss.b, operations);
		pa(ss.a, ss.b, operations);
	}
}

void	base_top_a_bca(t_sub_stack ss, t_list **operations)
{
	if ((ss.a)->size_array == 3)
		base_only_3_a(ss, operations);
	else
	{
		pb(ss.a, ss.b, operations);
		sa(ss.a, ss.b, operations);
		pa(ss.a, ss.b, operations);
		sa(ss.a, ss.b, operations);
	}
}

void	base_top_a_cab(t_sub_stack ss, t_list **operations)
{
	if ((ss.a)->size_array == 3)
		base_only_3_a(ss, operations);
	else
	{
		sa(ss.a, ss.b, operations);
		pb(ss.a, ss.b, operations);
		sa(ss.a, ss.b, operations);
		pa(ss.a, ss.b, operations);
	}
}

void	base_top_a_cba(t_sub_stack ss, t_list **operations)
{
	if ((ss.a)->size_array == 3)
		base_only_3_a(ss, operations);
	else
	{
		sa(ss.a, ss.b, operations);
		pb(ss.a, ss.b, operations);
		sa(ss.a, ss.b, operations);
		pa(ss.a, ss.b, operations);
		sa(ss.a, ss.b, operations);
	}
}

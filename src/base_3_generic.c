/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_3_generic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:45:21 by qhauuy            #+#    #+#             */
/*   Updated: 2024/03/27 15:34:21 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../f.h"

void	base_3_top_a(t_sub_stack ss, t_list **operations)
{
	int	case_3;

	if ((ss.a)->size_array == 3)
		base_only_3_a(ss, operations);
	case_3 = get_case_3(ss);
	if (case_3 == bac)
		sa(ss.a, ss.b, operations);
	else if (case_3 == acb)
		base_top_a_acb(ss, operations);
	else if (case_3 == bca)
		base_top_a_bca(ss, operations);
	else if (case_3 == cab)
		base_top_a_cab(ss, operations);
	else if (case_3 == (cba))
		base_top_a_cba(ss, operations);
}

void	base_3_top_b(t_sub_stack ss, t_list **operations)
{
	int	case_3;

	case_3 = get_case_3(ss);
	if (case_3 == abc)
		base_top_b_abc(ss, operations);
	else if (case_3 == acb)
		base_top_b_acb(ss, operations);
	else if (case_3 == bac)
		base_top_b_bac(ss, operations);
	else if (case_3 == bca)
		base_top_b_bca(ss, operations);
	else if (case_3 == cab)
		base_top_b_cab(ss, operations);
	else if (case_3 == (cba))
		base_top_b_cba(ss, operations);
}

void	base_3_bottom_a(t_sub_stack ss, t_list **operations)
{
	int	case_3;

	case_3 = get_case_3(ss);
	if (case_3 == abc)
		base_bottom_a_abc(ss, operations);
	else if (case_3 == acb)
		base_bottom_a_acb(ss, operations);
	else if (case_3 == bac)
		base_bottom_a_bac(ss, operations);
	else if (case_3 == bca)
		base_bottom_a_bca(ss, operations);
	else if (case_3 == cab)
		base_bottom_a_cab(ss, operations);
	else if (case_3 == (cba))
		base_bottom_a_cba(ss, operations);
}

void	base_3_bottom_b(t_sub_stack ss, t_list **operations)
{
	int	case_3;

	case_3 = get_case_3(ss);
	if (case_3 == abc)
		base_bottom_b_abc(ss, operations);
	else if (case_3 == acb)
		base_bottom_b_acb(ss, operations);
	else if (case_3 == bac)
		base_bottom_b_bac(ss, operations);
	else if (case_3 == bca)
		base_bottom_b_bca(ss, operations);
	else if (case_3 == cab)
		base_bottom_b_cab(ss, operations);
	else if (case_3 == (cba))
		base_bottom_b_cba(ss, operations);
}

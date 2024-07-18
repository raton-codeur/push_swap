/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_from_sub_stack_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:39:31 by qhauuy            #+#    #+#             */
/*   Updated: 2024/03/27 13:34:41 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../f.h"

void	get_array_and_start(t_sub_stack ss, int **array, int *i)
{
	if (ss.position == top_a || ss.position == bottom_a)
	{
		*array = (ss.a)->array;
		if (ss.position == top_a || ss.position == top_b)
			*i = (ss.a)->start;
		else
			*i = (ss.a)->end;
	}
	else
	{
		*array = (ss.b)->array;
		if (ss.position == top_a || ss.position == top_b)
			*i = (ss.b)->start;
		else
			*i = (ss.b)->end;
	}
}

int	get_next_index(t_sub_stack ss, int i)
{
	if (ss.position == top_a || ss.position == top_b)
		return ((i + 1) % (ss.a)->size_array);
	else
		return (get_previous_index(ss.a, i));
}

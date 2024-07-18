/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_generic_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:38:02 by qhauuy            #+#    #+#             */
/*   Updated: 2024/03/27 13:34:41 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../f.h"

void	swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	get_previous_index(t_stack *s, int i)
{
	if (i == 0)
		return (s->size_array - 1);
	else
		return (i - 1);
}

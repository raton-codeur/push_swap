/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:29:13 by qhauuy            #+#    #+#             */
/*   Updated: 2024/03/27 14:29:45 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../f.h"

void	deep_free(char **a, int i)
{
	int	j;

	j = 0;
	while (j < i)
		free(a[j++]);
	free(a);
}

void	free_stack(t_stack *s)
{
	if (s != NULL)
		free(s->array);
	free(s);
}

void	free_stacks(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
}

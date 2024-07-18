/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_from_sub_stack_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:39:17 by qhauuy            #+#    #+#             */
/*   Updated: 2024/03/27 13:34:41 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../f.h"

t_next	get_next_sub_stacks(t_sub_stack ss)
{
	t_next	result;

	result.high = (t_sub_stack){ss.a, ss.b, 0, 0};
	result.medium = (t_sub_stack){ss.a, ss.b, 0, 0};
	result.low = (t_sub_stack){ss.a, ss.b, 0, 0};
	result.high.position = top_a;
	result.medium.position = bottom_a;
	result.low.position = bottom_b;
	if (ss.position == top_a)
		result.high.position = top_b;
	if (ss.position == bottom_a)
		result.medium.position = top_b;
	if (ss.position == bottom_b)
		result.low.position = top_b;
	return (result);
}

int	get_value(t_sub_stack ss, int i)
{
	int	*array;
	int	j;
	int	k;
	int	result;

	get_array_and_start(ss, &array, &k);
	result = get_lowest_value(ss);
	j = 0;
	while (j < i)
	{
		result = get_next_value(ss, result);
		k = get_next_index(ss, k);
		j++;
	}
	return (result);
}

int	get_next_value(t_sub_stack ss, int n)
{
	int	*array;
	int	result;
	int	i;
	int	j;

	result = n;
	get_array_and_start(ss, &array, &i);
	j = 0;
	while (j < ss.size)
	{
		if (array[i] > n)
		{
			if (result == n || array[i] < result)
				result = array[i];
		}
		i = get_next_index(ss, i);
		j++;
	}
	return (result);
}

int	get_lowest_value(t_sub_stack ss)
{
	int	*array;
	int	i;
	int	result;
	int	j;

	get_array_and_start(ss, &array, &i);
	result = array[i];
	i = get_next_index(ss, i);
	j = 1;
	while (j < ss.size)
	{
		if (array[i] < result)
			result = array[i];
		i = get_next_index(ss, i);
		j++;
	}
	return (result);
}

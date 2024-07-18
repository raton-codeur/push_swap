/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:27:15 by qhauuy            #+#    #+#             */
/*   Updated: 2024/03/29 19:43:37 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../f.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_list	*operations;

	if (argc >= 2)
	{
		initialization(&argc, argv, &a, &b);
		operations = sort(a, b);
		while (optimize(&operations))
			;
		list_print(operations);
		list_clear(&operations);
	}
	return (0);
}

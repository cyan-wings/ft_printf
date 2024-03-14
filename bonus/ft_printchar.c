/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:29:51 by myeow             #+#    #+#             */
/*   Updated: 2024/03/10 18:00:58 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	ft_printchar(t_data *data, int c)
{
	int	width;

	width = data->flags.width;
	printf("%i\n", width);
	if (data->flags.hyphen)
	{
		ft_appendchar_buffer(data, c, 1);
		ft_appendchar_buffer(data, ' ', --width);
	}
	else
	{
		ft_appendchar_buffer(data, ' ', --width);
		ft_appendchar_buffer(data, c, 1);
	}
	return (OK);
}

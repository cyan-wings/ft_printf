/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:21:16 by myeow             #+#    #+#             */
/*   Updated: 2024/03/13 21:35:35 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	ft_printstring(t_data *data, const char *str)
{
	int	w;
	int	p;

	if (!str)
		return (ft_printstring(data, "(null)"));
	w = data->flags.width;
	p = data->flags.precision;
	if (p == -1)
		p = ft_strlen(str);
	if (data->flags.hyphen)
	{
		ft_appendstr_buffer(data, str, p);
		ft_appendchar_buffer(data, ' ', w - p);
	}
	else
	{
		ft_appendchar_buffer(data, ' ', w - p);
		ft_appendstr_buffer(data, str, p);
	}
	return (OK);
}

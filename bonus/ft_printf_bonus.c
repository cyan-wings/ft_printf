/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:02:22 by myeow             #+#    #+#             */
/*   Updated: 2024/03/14 12:07:38 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"
#include <stdio.h>

int	init_data(t_data *data, va_list *arg_list)
{
	data->count = 0;
	data->args = arg_list;
	data->buffer = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!data->buffer)
		return (0);
	data->buffer_idx = 0;
	return (1);
}

static int	ft_printf_parse(t_data *data, const char **sptr)
{
	int	f;

	f = 0;
	while (**sptr)
	{
		if (**sptr == '%' && *++*sptr)
		{
			f = ft_format(data, sptr);
			if (f && f != UNDEFINED_ERROR)
				return (PARSE_ERROR);
			ft_format_specifier(data);
		}
		else
			ft_write_buffer(data, **sptr);
		++*sptr;
	}
	ft_flush_buffer(data);
	return (OK);
}

int	ft_printf_bonus(const char *str, ...)
{
	t_data	data;
	va_list	args;

	if (!str)
		return (0);
	init_data(&data, &args);
	va_start(*(data.args), str);
	printf("%d\n", ft_printf_parse(&data, &str));
	va_end(*(data.args));
	free(data.buffer);
	return (data.count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:16:46 by myeow             #+#    #+#             */
/*   Updated: 2024/03/08 19:03:09 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_format(char c, va_list *arg)
{
	int	count;

	count = 0;
	if (c == '%')
		count += ft_putchar('%');
	else if (c == 'c')
		count += ft_putchar(va_arg(*arg, int));
	else if (c == 's')
		count += ft_putstr(va_arg(*arg, char *));
	else if (c == 'p')
	{
		count += ft_putstr("0x");
		count += ft_putaddr((uintptr_t) va_arg(*arg, void *), BASE16);
	}
	else if (c == 'd' || c == 'i')
		count += ft_putnbr_base(va_arg(*arg, int), BASE10, 10);
	else if (c == 'u')
		count += ft_putnbr_base(va_arg(*arg, unsigned int), BASE10, 10);
	else if (c == 'x')
		count += ft_putnbr_base(va_arg(*arg, unsigned int), BASE16, 16);
	else if (c == 'X')
		count += ft_putnbr_base(va_arg(*arg, unsigned int), BASE16CAPS, 16);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	count = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && *++str && ft_in(SPECIFIERS, *str))
			count += ft_format(*str++, &args);
		else
			count += ft_putchar(*str++);
	}
	va_end(args);
	return (count);
}

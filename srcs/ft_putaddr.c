/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:11:06 by myeow             #+#    #+#             */
/*   Updated: 2024/03/08 15:21:26 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putaddr(uintptr_t n, char *base)
{
	if (n < 16)
		return (ft_putchar(base[n]));
	else
		return (ft_putaddr(n / 16, base) + ft_putchar(base[n % 16]));
}

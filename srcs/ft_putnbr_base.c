/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:22:57 by myeow             #+#    #+#             */
/*   Updated: 2024/03/08 15:31:15 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbr_base(long long int n, char *base, int base_len)
{
	if (n < 0)
		return (ft_putchar('-') + ft_putnbr_base(-n, base, base_len));
	if (n < base_len)
		return (ft_putchar(base[n]));
	else
		return (ft_putnbr_base(n / base_len, base, base_len) + \
			ft_putchar(base[n % base_len]));
}

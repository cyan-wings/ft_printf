/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 23:01:10 by myeow             #+#    #+#             */
/*   Updated: 2024/03/13 21:32:50 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	*ft_memset(void *b, int c, size_t len)
{
	while (len--)
		*((unsigned char *) b + len) = c;
	return (b);
}

void	*ft_bzero(void *s, size_t n)
{
	return (ft_memset(s, 0, n));
}

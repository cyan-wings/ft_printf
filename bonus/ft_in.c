/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:49:36 by myeow             #+#    #+#             */
/*   Updated: 2024/03/09 00:59:29 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	ft_in(char *s, char c)
{
	while (*s)
		if (*s++ == c)
			return (1);
	if (!c)
		return (1);
	return (0);
}

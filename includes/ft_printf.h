/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:46:09 by myeow             #+#    #+#             */
/*   Updated: 2024/03/08 15:21:56 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define SPECIFIERS "cspdiuxX"
# define BASE10 "0123456789"
# define BASE16 "0123456789abcdef"
# define BASE16CAPS "0123456789ABCDEF"

int		ft_putchar(char c);
int		ft_putstr(char *c);
int		ft_strlen(char *s);
int		ft_putnbr_base(long long int n, char *base, int base_len);
int		ft_putaddr(uintptr_t n, char *base);
int		ft_in(char *s, char c);
int		ft_printf(const char *str, ...);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:12:49 by restevez          #+#    #+#             */
/*   Updated: 2025/01/03 11:27:54 by restevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long nbr, char *base)
{
	unsigned long	len;

	len = 0;
	while (base[len] != '\0')
		len++;
	if (nbr > len - 1)
		ft_putnbr_base(nbr / len, base);
	write(1, &base[nbr % len], 1);
}

size_t	ft_printf_s(char **str, va_list **args)
{
	*str = ft_strdup(va_arg(**args, const char *));
	ft_putstr_fd(*str, 1);
	return (ft_strlen(*str));
}

size_t	ft_printf_id(char **str, va_list **args)
{
	int		nbr;

	nbr = va_arg(**args, int);
	*str = ft_itoa(nbr);
	ft_putstr_fd(*str, 1);
	return (ft_strlen(*str));
}

size_t	ft_printf_p(va_list **args)
{
	ft_putstr_fd("0x", 1);
	ft_putnbr_base(va_arg(**args, unsigned long),
		"0123456789abcdef");
	return (15);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:12:49 by restevez          #+#    #+#             */
/*   Updated: 2025/01/10 03:24:18 by restevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr_base(size_t nbr, char *base, size_t *chr_count)
{
	size_t	len;

	len = 0;
	while (base[len] != '\0')
		len++;
	*chr_count += 1;
	if (len > 0 && nbr > len - 1)
		ft_putnbr_base(nbr / len, base, chr_count);
	write(1, &base[nbr % len], 1);
	return (*chr_count);
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

size_t	ft_printf_u(va_list **args)
{
	char	*str;

	va_arg(**args, unsigned int);
	str = ft_strdup("to be implemented");
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

size_t	ft_printf_p(va_list **args)
{
	size_t	chr_count;

	chr_count = 2;
	ft_putstr_fd("0x", 1);
	return (ft_putnbr_base(va_arg(**args, unsigned long),
			"0123456789abcdef", &chr_count));
}

size_t	ft_printf_x(va_list **args, char *base)
{
	size_t	chr_count;

	chr_count = 0;
	return (ft_putnbr_base(va_arg(**args, unsigned long), base, &chr_count));
}

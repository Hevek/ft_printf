/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 04:22:08 by restevez          #+#    #+#             */
/*   Updated: 2025/01/11 04:24:54 by restevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"
# include <limits.h>

size_t	ft_printf_s(va_list **args);
size_t	ft_printf_id(char **str, va_list **args);
size_t	ft_printf_p(va_list **args);
size_t	ft_printf_x(va_list **args, char *base);
size_t	ft_printf_u(va_list **args);
size_t	ft_putunbr_base(size_t nbr, char *base, size_t *chr_count);
size_t	ft_putnbr_base(unsigned int nbr, char *base, size_t *chr_count);

#endif

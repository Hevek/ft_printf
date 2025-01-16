/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 04:22:08 by restevez          #+#    #+#             */
/*   Updated: 2025/01/03 11:39:09 by restevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

void	ft_putnbr_base(unsigned long nbr, char *base);
size_t	ft_printf_s(char **str, va_list **args);
size_t	ft_printf_id(char **str, va_list **args);
size_t	ft_printf_p(va_list **args);

#endif

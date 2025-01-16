/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 02:46:00 by restevez          #+#    #+#             */
/*   Updated: 2025/01/03 11:36:05 by restevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *str, ...);
static int	ft_flag_selector(char flag, va_list *args);

/* ft_printf(str, infinite):
• Don’t implement the buffer management of the original printf().
• Your function has to handle the following conversions: cspdiuxX%
• Your function will be compared against the original printf().
• You must use the command ar to create your library.
Using the libtool command is forbidden.
• Your libftprintf.a has to be created at the root of your repository

You have to implement the following conversions:
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.

You don’t have to do all the bonuses.
Bonus list:
• Manage any combination of the following flags: ’-0.’ and the field
minimum width under all conversions.
• Manage all the following flags: ’# +’ (Yes, one of them is a space)

External functs.:
malloc, free, write,
va_start, va_arg, va_copy, va_end

Flag characters

The character % is followed by zero or more of the following flags:

#	The value should be converted to an "alternate form".
For  o  conversions,  the  first character  of  the  output
string is made zero (by prefixing a 0 if it was not zero already).
For x and X conversions, a nonzero result has the string "0x"
(or "0X"  for  X conversions)  prepended  to it.
For a, A, e, E, f, F, g, and G conversions, the result will always
contain a decimal point, even if no digits follow it (normally, a
decimal point  appears in the results of those conversions only if
a digit follows).  For g and G conversions, trailing zeros are not
removed from the result as they  would  otherwise be. For other
conversions, the result is undefined.

0	The value should be zero padded.  For d, i, o, u, x, X, a, A,
e, E, f, F, g, and G conversions, the converted value is padded on
the left with zeros rather than blanks. If the  0  and - flags both
appear, the 0 flag is ignored.  If a precision is given with a numeric
conversion (d, i, o, u, x, and X), the 0 flag is ignored. For other
conversions, the behavior is undefined.

-	The  converted  value  is  to  be left adjusted on the field boundary.
(The default is right justification.)  The converted value is padded
on the right with  blanks,  rather than on the left with blanks or zeros.
A - overrides a 0 if both are given.

' '	(a space) A blank should be left before a positive number (or empty
string) produced by a signed conversion.

+	A sign (+ or -) should always be placed before a number produced by
a  signed  conversion. By default, a sign is used only for negative numbers.
A + overrides a space if both are used.
*/
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	*ptr;

	if (argc < 2)
		return (1);
	printf("\n%d", ft_printf(argv[1], &ptr));
	printf("\n%d", printf("\n%p", &ptr));
	return (0);
}

/*
1) We must receive a string.
2) We count how many times the symbol "%" is followed by a valid flag.
3) That will be our counter to control the loop
*/
int	ft_printf(const char *str, ...)
{
	static int	count_char;
	int			i;
	va_list		args;
	char		*flags;

	i = -1;
	va_start(args, str);
	count_char = 0;
	flags = ft_strdup("cspdiuxX%");
	while (str[++i])
	{
		if (str[i + 1] == '\0')
			return (0);
		else if (str[i] == '%')
		{
			count_char += ft_flag_selector(str[i + 1], &args);
			i++;
		}
		else
			count_char++;
	}
	va_end(args);
	return (count_char);
}

/*
static int	ft_count_occr_percent(const char *str)
{
	size_t	i;
	size_t	count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[++i]))
			count++;
	}
	return (count);
}
 */

static int	ft_flag_selector(char flag, va_list *args)
{
	char	*str;

	if (flag == 's')
	{
		return (ft_printf_s(&str, &args));
	}
	else if (flag == 'i' || flag == 'd')
	{
		return (ft_printf_id(&str, &args));
	}
	else if (flag == 'c')
		ft_putchar_fd(va_arg(*args, int), 1);
	else if (flag == '%')
		ft_putchar_fd('%', 1);
	else if (flag == 'p')
		return (ft_printf_p(&args));
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 02:46:00 by restevez          #+#    #+#             */
/*   Updated: 2025/01/10 04:10:59 by restevez         ###   ########.fr       */
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
[x] %c Prints a single character.
[x] %s Prints a string (as defined by the common C convention).
[x] %p The void * pointer argument has to be printed in hexadecimal format.
[x] %d Prints a decimal (base 10) number.
[x] %i Prints an integer in base 10.
[x] %u Prints an unsigned decimal (base 10) number.
[] %x Prints a number in hexadecimal (base 16) lowercase format.
[] %X Prints a number in hexadecimal (base 16) uppercase format.
[x] %% Prints a percent sign.

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

Compile: ccs utils.c ft_printf.c libft.a
*/
/*
	./a "" "Char: %c, String: %s, Pointer: %p, Decimal: %d,
		Integer: %i, hex: %x, HEX: %X" "O" "Alfabeto" "a" 42 10 12 42
*/
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	*ptr;

	if (argc < 2)
		return (1);
	if (ft_memcmp(argv[1], "TP", 2) == 0)
	{
		printf("Teste %%p: \n");
		printf("\n42 Return: %d\n\n", ft_printf(argv[2], &ptr));
		printf("\nPrintf Return: %d\n", printf("%p", &ptr));
	}
	else if (ft_memcmp(argv[1], "TN", 2) == 0)
	{
		printf("Teste %%d: \n");
		printf("\n42 Return: %d\n\n", ft_printf(argv[2], 1));
		printf("\nPrintf Return: %d", printf("%d", 1));
	}
	else if (ft_memcmp(argv[1], "PTSD", 4) == 0)
	{
		if (!argv[3] && !argv[4])
			return (1);
		printf("%%p Teste %%s %%d: \n");
		printf("\n42 Return: %d\n\n", ft_printf(argv[2], argv[3],
				argv[3], ft_atoi(argv[4])));
		printf("\nPrintf Return: %d", printf(argv[2], argv[3],
				argv[3], ft_atoi(argv[4])));
	}
	else if (ft_memcmp(argv[1], "TSD", 3) == 0)
	{
		if (!argv[3] && !argv[4])
			return (1);
		printf("Teste %%s %%d: \n");
		printf("\n42 Return: %d\n\n", ft_printf(argv[2], argv[3],
				ft_atoi(argv[4])));
		printf("\nPrintf Return: %d", printf(argv[2], argv[3],
				ft_atoi(argv[4])));
	}
	else if (ft_memcmp(argv[1], "TSS", 3) == 0)
	{
		if (!argv[3] && !argv[4])
			return (1);
		printf("Teste %%s %%s: \n");
		printf("\n42 Return: %d\n\n", ft_printf(argv[2], argv[3], argv[4]));
		printf("\nPrintf Return: %d", printf(argv[2], argv[3], argv[4]));
	}
	else if (ft_memcmp(argv[1], "TS", 2) == 0)
	{
		if (!argv[3])
			return (1);
		printf("Teste %%s: \n");
		printf("\n42 Return: %d\n\n", ft_printf(argv[2], argv[3]));
		printf("\nPrintf Return: %d", printf(argv[2], argv[3]));
	}
	else
	{
		printf("Teste %%c %%s %%p %%d %%i %%x %%X: \n");
		printf("\n42 Return: %d\n\n", ft_printf(argv[2],
				argv[3][0], argv[4], argv[5], ft_atoi(argv[6]),
				ft_atoi(argv[7]), ft_atoi(argv[8]), ft_atoi(argv[9])));
		printf("\nPrintf Return: %d", printf(argv[2],
				argv[3][0], argv[4], argv[5], ft_atoi(argv[6]),
				ft_atoi(argv[7]), ft_atoi(argv[8]), ft_atoi(argv[9])));
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	static int	count_char;
	int			i;
	va_list		args;

	i = -1;
	va_start(args, str);
	count_char = 0;
	while (str[++i])
	{
		if (str[i + 1] == '\0' && ++count_char)
			ft_putchar_fd(str[i], 1);
		else if (str[i] == '%')
			count_char += ft_flag_selector(str[++i], &args);
		else
		{
			ft_putchar_fd(str[i], 1);
			count_char++;
		}
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
	char	*flags;

	flags = ft_strdup("cspdiuxX%");
	if (!ft_strchr(flags, flag))
		flag = '%';
	if (flag == 's')
		return (ft_printf_s(&str, &args));
	else if (flag == 'i' || flag == 'd')
		return (ft_printf_id(&str, &args));
	else if (flag == 'c')
		ft_putchar_fd(va_arg(*args, int), 1);
	else if (flag == '%')
		ft_putchar_fd('%', 1);
	else if (flag == 'p')
		return (ft_printf_p(&args));
	else if (flag == 'u')
		return (ft_printf_u(&args));
	else if (flag == 'x')
		return (ft_printf_x(&args, "0123456789abcdef"));
	else if (flag == 'X')
		return (ft_printf_x(&args, "0123456789ABCDEF"));
	return (1);
}

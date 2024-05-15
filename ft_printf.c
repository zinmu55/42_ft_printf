/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohtake <skohtake@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 08:10:02 by skohtake          #+#    #+#             */
/*   Updated: 2024/05/15 14:58:43 by skohtake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	my_print_base_lower(int n, int fd, int base)	// cf:ft_putnbr

// {
// 	long long int lln;

// 	lln = (long long int)n;
// 	if (lln < 0)
// 	{
// 		ft_putchar_fd('-', fd);
// 		lln = -lln;
// 	}
// 	if (lln >= 10)
// 		ft_putnbr_fd(lln / 10, fd);
// 	ft_putchar_fd((lln % 10) + '0', fd);
// }

int	my_write_free(char **str)
{
	int	res;

	if (*str == NULL)
		return (write(1, "(null)", 6));
	res = write(1, *str, ft_strlen(*str));
	free(*str);
	return (res);
}

// char	*my_itohex_lower(int i, int sign, int hex_len, char **str)
char	*my_itohex_lower(int i, int sign, int hex_len)
{
	char	*res;

	res = (char *)ft_calloc(hex_len-- + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	if (sign == 1)
	{
		while (hex_len >= 0)
		{
			if (i % 16 < 10)
				res[hex_len--] = '0' + i % 16;
			if (i % 16 >= 10)
				res[hex_len--] = 'a' + i % 16 - 10;
			i /= 16;
		}
	}
	if (sign == -1)
	{
		i -= INT_MIN;
		while (hex_len >= 1)
		{
			if (i % 16 < 10)
				res[hex_len--] = '0' + i % 16;
			if (i % 16 >= 10)
				res[hex_len--] = 'a' + i % 16 - 10;
			i /= 16;
		}
		if (i % 16 + 8 < 10)
			res[hex_len--] = '0' + i % 16 + 8;
		if (i % 16 + 8 >= 10)
			res[hex_len--] = 'a' + i % 16 + 8 - 10;
	}
	return (res);
}

int	my_print_hex_lower(int i)
{
	int		tmp;
	int		hex_len;
	char	*str;

	hex_len = 0;
	tmp = i;
	if (i == 0)
		return (write(1, "0", 1));
	else if (i > 0)
	{
		while (tmp > 0)
		{
			tmp /= 16;
			hex_len++;
		}
		str = my_itohex_lower(i, 1, hex_len);
	}
	else
	{
		hex_len = 8;
		str = my_itohex_lower(i, -1, hex_len);
	}
	return (my_write_free(&str));
}

char	*sub_uitoa(char *res, long long int lln, int digits)
{
	if (lln < 0)
	{
		res[0] = '-';
		lln = -lln;
	}
	res[digits--] = '\0';
	while (lln != 0)
	{
		res[digits] = (lln % 10) + '0';
		lln /= 10;
		digits--;
	}
	return (res);
}

char	*my_uitoa(unsigned int n)
{
	long long int	lln;
	int				digits;
	char			*res;

	if (n == 0)
		return (ft_strdup("0"));
	lln = (long long int)n;
	digits = 1;
	while (lln / 10 != 0)
	{
		digits++;
		lln /= 10;
	}
	lln = (long long int)n;
	if (lln < 0)
		digits++;
	res = (char *)malloc(sizeof(char) * digits + 1);
	if (res == NULL)
		return (NULL);
	res = sub_uitoa(res, lln, digits);
	return (res);
}

int	my_print_uint(unsigned int ui)
{
	char	*str;
	int		res;

	str = my_uitoa(ui);
	if (str == NULL)
		return (0);
	res = write(1, str, ft_strlen(str));
	free(str);
	return (res);
}

int	my_print_int(int i)
{
	char	*str;

	str = ft_itoa(i);
	if (str == NULL)
		return (0);
	i = write(1, str, ft_strlen(str));
	free(str);
	return (i);
}

int	my_print_str(char *str)
{
	if (str == NULL)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	my_print_char(char c)
{
	return (write(1, &c, 1));
}

// decide process according identifier
int	my_process_id(char id, va_list *list)
{
	int	res;

	long tmp; // this needs removing
	res = 0;
	tmp = 0;
	if (id == 'c')
	{
		res = my_print_char((char)va_arg(*list, int));
		// printf("\nchar_printf:%c\n", id);
	}
	if (id == 's')
	{
		res = my_print_str((char *)va_arg(*list, char *));
	}
	// if (id == 'p')
	// {
	// }
	if (id == 'd')
	{
		res = my_print_int((int)va_arg(*list, int));
	}
	if (id == 'i')
	{
		res = my_print_int((int)va_arg(*list, int));
	}
	if (id == 'u')
	{
		res = my_print_uint((unsigned int)va_arg(*list, unsigned int));
	}
	if (id == 'x')
	{
		res = my_print_hex_lower((int)va_arg(*list, int));
	}
	// if (id == 'X')
	// {
	// }
	if (id == '%')
	{
		res = my_print_char('%');
	}
	return (res);
}

//
int	my_count_res(char *format, va_list *list)
{
	int	res;
	int	index;

	res = 0;
	index = 0;
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			index++;
			res += my_process_id(format[index], list);
		}
		else if (format[index] != '\0')
		{
			res += write(1, format + index, 1);
		}
		index++;
	}
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	char	*dup;
	int		res_len;

	dup = ft_strdup(format);
	if (dup == NULL)
		return (0);
	va_start(list, format);
	res_len = my_count_res(dup, &list);
	va_end(list);
	free(dup);
	return (res_len);
}

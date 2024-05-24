/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_print_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohtake <skohtake@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:26:11 by skohtake          #+#    #+#             */
/*   Updated: 2024/05/24 11:01:03 by skohtake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// //cf:ft_putnbr,youcan use unsigned long long
// int	my_print_base_lower(int n, int fd,int base)

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

char	*my_itohex_upper(int i, int sign, int hex_len)
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
				res[hex_len--] = 'A' + i % 16 - 10;
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
				res[hex_len--] = 'A' + i % 16 - 10;
			i /= 16;
		}
		if (i % 16 + 8 < 10)
			res[hex_len--] = '0' + i % 16 + 8;
		if (i % 16 + 8 >= 10)
			res[hex_len--] = 'A' + i % 16 + 8 - 10;
	}
	return (res);
}

int	my_print_hex_upper(int i)
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
		str = my_itohex_upper(i, 1, hex_len);
	}
	else
	{
		hex_len = 8;
		str = my_itohex_upper(i, -1, hex_len);
	}
	return (my_write_free(&str));
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

char	*my_uitobase_lowercase(unsigned int ui, int base)
{
	char			*res;
	long long int	lln;
	int				digits;

	lln = (long long int)ui;
	digits = 1;
	while (lln /= base)
		digits++;
	lln = (long long int)ui;
	
	return (res);
}

int	my_print_hex_lower(unsigned int ui)
{
	char	*str;
	int		res;

	str = my_uitobase_lowercase(ui, 16);
	if (str == NULL)
		return (0);
	res = write(1, str, ft_strlen(str));
	free(str);
	return (res);
}

int	my_print_pointer(void *ptr)
{
	int	res;

	res = 0;
	res += write(1, "0x", 2);
	if (ptr == NULL)
		res += write(1, "0", 1);
	else
		res += my_print_hex_lower((long long unsigned int)ptr);
	return (res);
}

////////////////////////////////////////////////////////////////////
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohtake <skohtake@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:09:20 by skohtake          #+#    #+#             */
/*   Updated: 2024/06/11 11:34:26 by skohtake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

// char	*my_itohex_lower(int i, int sign, int hex_len)
// {
// 	char	*res;

// 	res = (char *)ft_calloc(hex_len-- + 1, sizeof(char));
// 	if (res == NULL)
// 		return (NULL);
// 	if (sign == 1)
// 	{
// 		while (hex_len >= 0)
// 		{
// 			if (i % 16 < 10)
// 				res[hex_len--] = '0' + i % 16;
// 			if (i % 16 >= 10)
// 				res[hex_len--] = 'a' + i % 16 - 10;
// 			i /= 16;
// 		}
// 	}
// 	if (sign == -1)
// 	{
// 		i -= INT_MIN;
// 		while (hex_len >= 1)
// 		{
// 			if (i % 16 < 10)
// 				res[hex_len--] = '0' + i % 16;
// 			if (i % 16 >= 10)
// 				res[hex_len--] = 'a' + i % 16 - 10;
// 			i /= 16;
// 		}
// 		if (i % 16 + 8 < 10)
// 			res[hex_len--] = '0' + i % 16 + 8;
// 		if (i % 16 + 8 >= 10)
// 			res[hex_len--] = 'a' + i % 16 + 8 - 10;
// 	}
// 	return (res);
// }

// int	my_print_hex_lower(int i)
// {
// 	int		tmp;
// 	int		hex_len;
// 	char	*str;

// 	hex_len = 0;
// 	tmp = i;
// 	if (i == 0)
// 		return (write(1, "0", 1));
// 	else if (i > 0)
// 	{
// 		while (tmp > 0)
// 		{
// 			tmp /= 16;
// 			hex_len++;
// 		}
// 		str = my_itohex_lower(i, 1, hex_len);
// 	}
// 	else
// 	{
// 		hex_len = 8;
// 		str = my_itohex_lower(i, -1, hex_len);
// 	}
// 	return (my_write_free(&str));
// }

char	*my_uitohex_lower(unsigned int ui, int sign, int hex_len)
{
	char	*res;

	res = (char *)ft_calloc(hex_len-- + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	if (sign == 1)
	{
		while (hex_len >= 0)
		{
			if (ui % 16 < 10)
				res[hex_len--] = '0' + ui % 16;
			if (ui % 16 >= 10)
				res[hex_len--] = 'a' + ui % 16 - 10;
			ui /= 16;
		}
	}
	// if (sign == -1)
	// {
	// 	i -= INT_MIN;
	// 	while (hex_len >= 1)
	// 	{
	// 		if (i % 16 < 10)
	// 			res[hex_len--] = '0' + i % 16;
	// 		if (i % 16 >= 10)
	// 			res[hex_len--] = 'a' + i % 16 - 10;
	// 		i /= 16;
	// 	}
	// 	if (i % 16 + 8 < 10)
	// 		res[hex_len--] = '0' + i % 16 + 8;
	// 	if (i % 16 + 8 >= 10)
	// 		res[hex_len--] = 'a' + i % 16 + 8 - 10;
	// }
	return (res);
}

int	my_print_hex_lower(int i)
{
	long long int	tmp;
	int				hex_len;
	char			*str;

	hex_len = 0;
	tmp = (unsigned int)i;
	if (i == 0)
		return (write(1, "0", 1));
	while (tmp > 0)
	{
		tmp /= 16;
		hex_len++;
	}
	str = my_uitohex_lower((unsigned int)i, 1, hex_len);
	if (str == NULL)
		return (write(1, "(null)", 6));
	tmp = write(1, str, ft_strlen(str));
	free(str);
	return (tmp);
}

// int	main(void)
// {
// 	my_print_hex_lower(-1);
// 	printf("\n");
// 	printf("%x\n", -1);
// 	return (0);
// }

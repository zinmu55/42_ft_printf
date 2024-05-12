/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohtake <skohtake@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 08:10:02 by skohtake          #+#    #+#             */
/*   Updated: 2024/05/12 14:54:58 by skohtake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// decide process according identifier
int	my_process_id(char id, va_list list)
{
	int	res;

	res = 0;
	if (id == 'c')
	{
		res = my_print_char()
	}
	if (id == 's')
	{
	}
	if (id == 'p')
	{
	}
	if (id == 'd')
	{
	}
	if (id == 'i')
	{
	}
	if (id == '%')
	{
	}
	return (res);
}

//
int	my_count_res(char *format, va_list list)
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
	int		index;
	int		res_len;

	dup = ft_strdup(format);
	if (dup == NULL)
		return (0);
	va_start(list, format);
	res_len = my_count_res(dup, list);
	va_end(list);
	free(dup);
	return (res_len);
}

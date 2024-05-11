/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohtake <skohtake@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 08:10:02 by skohtake          #+#    #+#             */
/*   Updated: 2024/05/11 14:52:33 by skohtake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *input, ...)
{
	va_list	ap;
	char	*save;
	char	*tmp;
	int		i;

	save = ft_strdup(input);
	va_start(ap, input);
	i = 1;
	while (i--)
	{
		tmp = save;
		save = ft_strjoin(save, (char *)va_arg(ap, char *));
		write(1, "\n", 1);
		ft_putstr_fd(save, 1);
	}
	va_end(ap);
	return (0);
}

/*
・引数の数
・引数の型
を指定してあげる必要がある。
->第一引数から計算しておく必要がある。
※引数の数が多いのは問題ないが、引数の数が少ないとエラーになる。
*/


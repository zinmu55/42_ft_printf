/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohtake <skohtake@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:54:36 by skohtake          #+#    #+#             */
/*   Updated: 2024/05/10 14:00:37 by skohtake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	ft_putstr_fd("Now, main.c is working!", 1);
	write(1, "\n", 1);
	return (0);
}

/* execute "ccw main.c libft libft/libft.a" to compile */

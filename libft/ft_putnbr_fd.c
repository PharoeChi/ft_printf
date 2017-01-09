/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:47:38 by lbogar            #+#    #+#             */
/*   Updated: 2016/11/09 20:47:39 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long s;

	s = (long)n;
	if (s < 0)
	{
		ft_putchar_fd('-', fd);
		s = -s;
	}
	if (s >= 10)
	{
		ft_putnbr_fd((s / 10), fd);
		ft_putnbr_fd((s % 10), fd);
	}
	else
		ft_putchar_fd((s + '0'), fd);
}

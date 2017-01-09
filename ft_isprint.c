/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:48:46 by lbogar            #+#    #+#             */
/*   Updated: 2016/11/07 18:48:47 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isprint(int c)
{
	char *characters;

	characters = " !\"#$%&\'()*+,-./:;<=>\?@[\\]^_`{|}~";
	if (ft_isalnum(c))
		return (1);
	while (*characters && *characters != c)
		++characters;
	if (*characters == '\0')
		return (0);
	else
		return (1);
}

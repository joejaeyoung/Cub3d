/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajo < jajo@student.42gyeongsan.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:26:14 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/24 21:47:06 by jajo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*destcpy;
	const char	*srccpy;

	destcpy = (char *)dest;
	srccpy = (const char *)src;
	if (dest <= src)
		while (n--)
			*destcpy++ = *srccpy++;
	else
	{
		destcpy += n;
		srccpy += n;
		while (n--)
			*--destcpy = *--srccpy;
	}
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajo < jajo@student.42gyeongsan.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:54:58 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/24 21:47:48 by jajo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*u1;
	const unsigned char	*u2;

	if (n == 0)
		return (0);
	u1 = (const unsigned char *)s1;
	u2 = (const unsigned char *)s2;
	while (n-- > 1 && *u1 && *u1 == *u2)
	{
		u1++;
		u2++;
	}
	return (*u1 - *u2);
}

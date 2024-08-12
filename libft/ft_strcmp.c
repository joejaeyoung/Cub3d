/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajo < jajo@student.42gyeongsan.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:50:09 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/24 21:47:35 by jajo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char	*u1;
	const unsigned char	*u2;

	if (!s1 || !s2)
		return (1);
	u1 = (const unsigned char *)s1;
	u2 = (const unsigned char *)s2;
	while (*u1 && *u1 == *u2)
	{
		u1++;
		u2++;
	}
	return (*u1 - *u2);
}

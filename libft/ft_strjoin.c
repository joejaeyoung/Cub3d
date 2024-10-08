/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajo < jajo@student.42gyeongsan.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:09:21 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/24 21:47:40 by jajo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	m;

	dest = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!dest)
		return (0);
	m = 0;
	while (*s1)
		dest[m++] = *s1++;
	while (*s2)
		dest[m++] = *s2++;
	dest[m] = '\0';
	return (dest);
}

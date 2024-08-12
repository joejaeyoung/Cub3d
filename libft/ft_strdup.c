/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajo < jajo@student.42gyeongsan.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:16:51 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/28 18:34:00 by jajo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*dest;
	size_t		m;

	if (!s)
		return (NULL);
	m = ft_strlen(s);
	dest = (char *)malloc((m + 1) * sizeof(char));
	if (!dest)
		return (0);
	ft_strlcpy(dest, s, m + 1);
	return (dest);
}

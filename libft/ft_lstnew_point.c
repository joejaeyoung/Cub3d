/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajo < jajo@student.42gyeongsan.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:01:45 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/24 22:12:06 by jajo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_point	*ft_lstnew_point(int height, char *str)
{
	int	len;
	t_point	*line;
	int	idx;

	idx = -1;
	len = ft_strlen(str);
	line = (t_point *)malloc(sizeof(t_point) * len);
	if (!line)
		return (NULL);
	
	while(++idx < len)
	{
		line[idx].height = height;
		line[idx].width = idx;
		if (str[idx] == ' ')
			line[idx].value = -1;
		else if (str[idx] == 'N' || str[idx] == 'S' || str[idx] == 'W' || str[idx] == 'E')
		{
			line[idx].direction = str[idx];
			line[idx].value = 2;
		}
		else
			line[idx].value = ft_atoi_one(str[idx]);
	}
	return (line);
}

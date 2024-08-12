/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajo < jajo@student.42gyeongsan.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:24:51 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/24 21:00:10 by jajo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_point	*ft_realloc(t_point *memblock, int memblock_size, int result_size)
{
	t_point	*tmp;
	int		i;
	int		height;

	i = -1;
	height = memblock[0].height;
	tmp = (t_point *)malloc(sizeof(t_point) * (result_size));
	if (!tmp)
		return (NULL);

	while(++i < result_size)
	{
		if (i < memblock_size)
		{
			tmp[i].width = memblock[i].width;
			tmp[i].height = memblock[i].height;
			tmp[i].value = memblock[i].value;
			tmp[i].direction = memblock[i].direction;
		}
		else
		{
			tmp[i].width = i;
			tmp[i].height = height;
			tmp[i].value = -1;
			tmp[i].direction = '0';
		}
	}
	free(memblock);
	memblock = NULL;
	return (tmp);
}

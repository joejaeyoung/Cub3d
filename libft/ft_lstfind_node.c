/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajo < jajo@student.42gyeongsan.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:29:32 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/22 21:26:11 by jajo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_field	*ft_lstfind_node(t_field *lst, int height)
{
	t_field	*cur;

	cur = lst;
	while (cur)
	{
		if (cur->height == height)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

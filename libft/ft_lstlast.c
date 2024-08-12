/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajo < jajo@student.42gyeongsan.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:27:22 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/22 21:24:24 by jajo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_field	*ft_lstlast(t_field *lst)
{
	t_field	*cur;

	if (!lst)
		return (0);
	cur = lst;
	while (cur->next)
		cur = cur->next;
	return (cur);
}

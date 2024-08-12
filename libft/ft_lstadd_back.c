/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajo < jajo@student.42gyeongsan.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:28:51 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/24 21:46:53 by jajo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstadd_back(t_field **lst, t_field *new)
{
	t_field	*back;

	if (lst == NULL || new == NULL)
		return (1);
	back = ft_lstlast(*lst);
	if (back)
		back->next = new;
	else
		*lst = new;
	return (0);
}

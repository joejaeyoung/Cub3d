/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajo < jajo@student.42gyeongsan.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:29:10 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/22 21:25:24 by jajo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_node(t_field **lst, t_field *prev, t_field *cur)
{
	if (prev)
		prev->next = cur->next;
	else
		*lst = cur->next;
	free(cur->line);
	free(cur);
}

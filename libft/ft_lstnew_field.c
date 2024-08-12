/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_field.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajo < jajo@student.42gyeongsan.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:01:45 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/22 21:39:15 by jajo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_field *ft_lstnew_field(int height, char *str)
{
	t_field *field;

	field = (t_field *)malloc(sizeof(t_field));
	field->line_num = ft_strlen(str);
	field->height = height;
	field->next = NULL;
	field->line = ft_lstnew_point(height, str);
	return (field);
}

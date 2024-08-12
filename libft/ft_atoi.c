/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajo < jajo@student.42gyeongsan.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:50:37 by jajo              #+#    #+#             */
/*   Updated: 2024/07/24 21:46:31 by jajo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_plus(const char *str, int *idx)
{
	int	sign;

	sign = 1;
	if (ft_issign(str[*idx]))
	{
		if (str[*idx] == '-')
			sign *= -1;
		(*idx)++;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	unsigned long long	result;
	int					idx;
	int					sign;

	idx = 0;
	result = 0;
	while ((str[idx] >= 9 && str[idx] <= 13) || str[idx] == 32)
		idx++;
	sign = get_plus(str, &idx);
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		result *= 10;
		result += str[idx] - '0';
		idx++;
		if ((result >= 10000000000000000 && str[idx] \
			&& str[idx + 1] && str[idx + 2]) || (result \
			>= 922337203685477580 && (str[idx] > ('7' + (sign < 0)))))
		{
			ft_putstr_fd("bash: exit: ", STDERR_FILENO);
			ft_putstr_fd((char *)str, STDERR_FILENO);
			ft_putendl_fd(": numeric argument required", STDERR_FILENO);
			return (2);
		}
	}
	return ((result * sign));
}

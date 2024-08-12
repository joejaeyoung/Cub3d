/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajo < jajo@student.42gyeongsan.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:37:55 by jajo              #+#    #+#             */
/*   Updated: 2024/07/24 21:45:48 by jajo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	if (charset[i] == '\0')
		return (0);
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	get_total_word_num(char *str, char *sep)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && is_charset(str[i], sep))
			i++;
		if (str[i] && !is_charset(str[i], sep))
			count++;
		while (str[i] && !is_charset(str[i], sep))
			i++;
	}
	return (count);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*fill_argv_fills(char *str, int st, int la)
{
	char	*tmp;

	tmp = (char *)malloc(1 * (la - st + 2));
	ft_strncpy(tmp, &str[st], la - st + 1);
	tmp[la - st + 1] = '\0';
	return (tmp);
}

char	**ft_split_str(char *str, char *charset)
{
	int		total;
	char	**result;
	int		i;
	int		st;
	int		la;

	i = 0;
	total = get_total_word_num(str, charset);
	result = (char **)malloc(sizeof(char *) * (total + 1));
	total = 0;
	while (str[i])
	{
		while (str[i] && is_charset(str[i], charset))
			i++;
		if (str[i] && !is_charset(str[i], charset))
			st = i;
		while (str[i] && !is_charset(str[i], charset))
			la = i++;
		if (la == i - 1)
			result[total++] = fill_argv_fills(str, st, la);
	}
	result[total] = NULL;
	return (result);
}

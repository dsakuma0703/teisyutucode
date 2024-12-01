/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsakuma  <dsakuma@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 23:20:51 by dsakuma           #+#    #+#             */
/*   Updated: 2024/08/25 23:20:51 by dsakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	put_str(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

char	*get_low_num(char **dict, char **str, int length, int j)
{
	char	*dest;
	char	*low_num;
	int		l;

	if (j == 0)
	{
		l = length % 3;
		if (length % 3 == 0)
			l = 3;
		dest = ft_strndup(*str, l);
		*str += l;
		low_num = int_to_str(dict, ft_atoi(dest));
		free(dest);
	}
	else
	{
		dest = ft_strndup(*str, 3);
		*str += 3;
		low_num = int_to_str(dict, ft_atoi(dest));
		free(dest);
	}
	return (low_num);
}

void	put_numbers(char **dict_low_num, char **dict_high_num, char **str,
		int length)
{
	int		j;
	int		roop_num;
	char	*low_num;

	j = 0;
	roop_num = (length - 1) / 3;
	while (roop_num)
	{
		low_num = get_low_num(dict_low_num, str, length, j);
		if (ft_strcmp(low_num, "zero") != 0)
		{
			put_str(low_num);
			put_str(" ");
			free(low_num);
			put_str(get_dict_value(dict_high_num, roop_num - 1));
			put_str(" ");
		}
		j++;
		roop_num--;
	}
}

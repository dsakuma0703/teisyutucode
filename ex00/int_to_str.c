/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsakuma <dsakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 23:20:17 by dsakuma           #+#    #+#             */
/*   Updated: 2024/08/25 23:20:18 by dsakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	hundle_hundreds_place(char *res, char **dict, int nb, int pos)
{
	int	hundreds_place;

	hundreds_place = nb / 100;
	set_str(res, dict[hundreds_place]);
	pos += str_len(dict[hundreds_place]);
	res[pos++] = '-';
	set_str(res + pos, dict[100]);
	pos += str_len(dict[100]);
	res[pos++] = ' ';
	if (nb % 100 != 0)
	{
		set_str(res + pos, "and ");
		pos += str_len("and ");
	}
	return (pos);
}

int	hundle_tens_place(char *res, char **dict, int nb, int pos)
{
	int	tens_place;

	if (nb % 100 <= 20)
	{
		set_str(res + pos, dict[nb % 100]);
		pos += str_len(dict[nb % 100]);
	}
	else
	{
		tens_place = (nb % 100) / 10 * 10;
		set_str(res + pos, dict[tens_place]);
		pos += str_len(dict[tens_place]);
		if (nb % 10 != 0)
		{
			res[pos++] = '-';
			set_str(res + pos, dict[nb % 10]);
			pos += str_len(dict[nb % 10]);
		}
	}
	return (pos);
}

char	*int_to_str(char **dict, int nb)
{
	int		i;
	char	*res;

	res = (char *)malloc(100 * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	if (nb >= 1000)
	{
		free(res);
		return ("invalid number");
	}
	if (nb == 0)
	{
		set_str(res, dict[0]);
		return (res);
	}
	if (nb >= 100)
		i = hundle_hundreds_place(res, dict, nb, i);
	if (nb % 100 == 0)
		return (res);
	i = hundle_tens_place(res, dict, nb, i);
	res[i] = '\0';
	return (res);
}

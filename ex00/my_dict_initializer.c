/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_dict_initializer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsakuma  <dsakuma@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 23:20:45 by dsakuma           #+#    #+#             */
/*   Updated: 2024/08/25 23:20:46 by dsakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	set_dict(char **dict, int index, char *str)
{
	dict[index] = (char *)malloc(str_len(str) * sizeof(char));
	if (!dict[index])
	{
		return ;
	}
	set_str(dict[index], str);
}

char	**initialize_dict_high_num(void)
{
	char	**dict_high_num;

	dict_high_num = (char **)malloc(12 * sizeof(char *));
	if (!dict_high_num)
	{
		return (0);
	}
	set_dict(dict_high_num, 0, "thousand");
	set_dict(dict_high_num, 1, "million");
	set_dict(dict_high_num, 2, "billion");
	set_dict(dict_high_num, 3, "trillion");
	set_dict(dict_high_num, 4, "quadrillion");
	set_dict(dict_high_num, 5, "quintillion");
	set_dict(dict_high_num, 6, "sextillion");
	set_dict(dict_high_num, 7, "septillion");
	set_dict(dict_high_num, 8, "octillion");
	set_dict(dict_high_num, 9, "nonillion");
	set_dict(dict_high_num, 10, "decillion");
	set_dict(dict_high_num, 11, "undecillion");
	return (dict_high_num);
}

void	initialize_dict_low_num_from_one_to_nineteen(char **dict)
{
	set_dict(dict, 0, "zero");
	set_dict(dict, 1, "one");
	set_dict(dict, 2, "two");
	set_dict(dict, 3, "three");
	set_dict(dict, 4, "four");
	set_dict(dict, 5, "five");
	set_dict(dict, 6, "six");
	set_dict(dict, 7, "seven");
	set_dict(dict, 8, "eight");
	set_dict(dict, 9, "nine");
	set_dict(dict, 10, "ten");
	set_dict(dict, 11, "eleven");
	set_dict(dict, 12, "twelve");
	set_dict(dict, 13, "thirteen");
	set_dict(dict, 14, "fourteen");
	set_dict(dict, 15, "fifteen");
	set_dict(dict, 16, "sixteen");
	set_dict(dict, 17, "seventeen");
	set_dict(dict, 18, "eighteen");
	set_dict(dict, 19, "nineteen");
}

void	initialize_dict_low_num_from_twenty_to_hundred(char **dict)
{
	set_dict(dict, 20, "twenty");
	set_dict(dict, 30, "thirty");
	set_dict(dict, 40, "forty");
	set_dict(dict, 50, "fifty");
	set_dict(dict, 60, "sixty");
	set_dict(dict, 70, "seventy");
	set_dict(dict, 80, "eighty");
	set_dict(dict, 90, "ninety");
	set_dict(dict, 100, "hundred");
}

char	**initialize_dict_low_num(void)
{
	char	**dict_low_num;

	dict_low_num = (char **)malloc(101 * sizeof(char *));
	if (!dict_low_num)
	{
		return (0);
	}
	initialize_dict_low_num_from_one_to_nineteen(dict_low_num);
	initialize_dict_low_num_from_twenty_to_hundred(dict_low_num);
	return (dict_low_num);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_given_dict.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsakuma  <dsakuma@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 23:21:11 by dsakuma           #+#    #+#             */
/*   Updated: 2024/08/25 23:21:12 by dsakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	use_given_dict(char *str, int pos, char *file_name)
{
	char	**dict_high_num;
	char	**dict_low_num;
	int		length;

	dict_low_num = small_num_dic_from_file(file_name);
	dict_high_num = large_num_dic_from_file(file_name);
	length = str_len(str) - pos;
	str += pos;
	if (length >= 40)
	{
		write(1, &"Dict Error\n", 12);
		return ;
	}
	if (ft_strcmp(str, "0") == 0 || ft_strcmp(str, "00") == 0)
	{
		put_str(dict_low_num[0]);
		write(1, &"\n", 1);
		return ;
	}
	put_numbers(dict_low_num, dict_high_num, &str, length);
	if (ft_strcmp(str, "000") != 0)
		put_str(int_to_str(dict_low_num, ft_atoi(str)));
	put_str("\n");
	free(dict_high_num);
	free(dict_low_num);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsakuma <yumasuda@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 23:20:22 by dsakuma           #+#    #+#             */
/*   Updated: 2024/08/25 23:20:22 by dsakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	check_sign(char *str, int *ptr_i)
{
	int	sign;
	int	i;

	sign = 1;
	i = *ptr_i;
	while ((str[i] != '\0') && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	*ptr_i = i;
	return (sign);
}

void	skip_whitespace(char *str, int *ptr_i)
{
	int	count;
	int	i;

	i = 0;
	count = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	*ptr_i = i;
}

int	validate_input(char *str, int *pos)
{
	int	sign;
	int	i;

	skip_whitespace(str, pos);
	sign = check_sign(str, pos);
	i = 0;
	if (sign == -1)
	{
		return (0);
	}
	while (str[*pos + i])
	{
		if (str[*pos + i] < '0' || str[*pos + i] > '9')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	*str;
	int		pos;
	char	*file_name;

	if (argc == 1 || argc >= 4)
	{
		write(1, &,"Error\n" 6);
		return (0);
	}
	str = argv[1];
	pos = 0;
	if (!validate_input(str, &pos) || str_len(str) == 0)
	{
		write(1, &"Error\n", 6);
		return (0);
	}
	if (argc == 2)
		use_default_dict(str, pos);
	else
	{
		file_name = argv[2];
		use_given_dict(str, pos, file_name);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dic_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsakuma <dsakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 23:19:58 by dsakuma           #+#    #+#             */
/*   Updated: 2024/08/25 23:19:58 by dsakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rush02.h"
#include <fcntl.h>

void	dict_err(void)
{
	write(2, "Dict Error\n", 12);
}

// RDWR can kick directories
size_t	read_dict(char *dict_name, t_str_str_dic *raw_dict[])
{
	char	buff[10240];
	int		fd;
	size_t	read_cnt;
	int		head_raw_dict;
	size_t	cnt;

	cnt = 0;
	fd = open(dict_name, O_RDWR);
	if (fd == -1)
		return (0);
	read_cnt = read(fd, buff, 10240);
	head_raw_dict = 0;
	while (cnt < read_cnt)
	{
		raw_dict[head_raw_dict] = parse_line(buff, &cnt);
		head_raw_dict++;
	}
	close(fd);
	raw_dict[head_raw_dict] = malloc(sizeof(t_str_str_dic));
	raw_dict[head_raw_dict]->key = NULL;
	raw_dict[head_raw_dict]->word = NULL;
	return (head_raw_dict);
}

size_t	len_raw_dict(t_str_str_dic *raw_dict[])
{
	size_t	cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	while (raw_dict[i]->key != NULL)
	{
		if (4 <= raw_dict[i]->len)
			cnt++;
		i++;
	}
	return (cnt);
}

char	**large_num_dic_from_file(char *path)
{
	t_str_str_dic	*raw_dict[200];
	size_t			i;
	size_t			cnt_l;
	char			**dict_large_to_ret;

	read_dict(path, raw_dict);
	cnt_l = len_raw_dict(raw_dict) + 1;
	dict_large_to_ret = (char **)malloc(sizeof(char **) * cnt_l);
	if (dict_large_to_ret == NULL)
		return (false);
	i = 0;
	while (raw_dict[i]->key != NULL)
	{
		if (4 <= raw_dict[i]->len)
		{
			dict_large_to_ret[(raw_dict[i]->len - 1) / 3
				- 1] = raw_dict[i]->word;
		}
		i++;
	}
	return (dict_large_to_ret);
}

char	**small_num_dic_from_file(char *path)
{
	t_str_str_dic	*raw_dict[200];
	size_t			i;
	size_t			cnt_s;
	char			**dict_small_to_ret;

	read_dict(path, raw_dict);
	cnt_s = len_raw_dict(raw_dict) + 1;
	dict_small_to_ret = (char **)malloc(sizeof(char **) * cnt_s);
	if (dict_small_to_ret == NULL)
		return (NULL);
	i = 0;
	while (i < cnt_s && raw_dict[i]->key != NULL)
	{
		if (raw_dict[i]->len < 4)
			dict_small_to_ret[ft_atoi(raw_dict[i]->key)] = raw_dict[i]->word;
		i++;
	}
	return (dict_small_to_ret);
}

// int	main(void)
// {
// 	char	**dict_large_num;
// 	char	**dict_small_num;
// 	int		i;

// 	i = 0;
// 	dict_small_num = small_num_dic_from_file("numbers.dict");
// 	dict_large_num = large_num_dic_from_file("numbers.dict");
// 	while (i < 10)
// 	{
// 		printf(" main s: %d:%s\n", i, dict_small_num[i]);
// 		free(dict_small_num[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < 100 && dict_large_num[i] != NULL)
// 	{
// 		printf("main l: %d:%s\n", i, dict_large_num[i]);
// 		free(dict_large_num[i]);
// 		i++;
// 	}
// 	return (0);
// }

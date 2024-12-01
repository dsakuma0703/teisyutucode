/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsakuma <dsakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 23:19:58 by dsakuma           #+#    #+#             */
/*   Updated: 2024/08/25 23:19:58 by dsakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	skip_until(char *str, char end, size_t *cnt)
{
	while (str[*cnt] != end)
		*cnt += 1;
}

void	skip_white_spaces(char *str, size_t *cnt)
{
	while (ft_isspace(str[*cnt]))
		*cnt += 1;
}

char	*ft_strdup_num(char *src, size_t *cnt)
{
	char	*dst;
	size_t	len;
	size_t	i;

	len = 0;
	while ('0' <= src[*cnt + len] && src[*cnt + len] <= '9')
		len++;
	len += 1;
	dst = malloc(sizeof(char) * len);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < len - 1)
	{
		dst[i] = src[*cnt + i];
		i++;
	}
	dst[i] = '\0';
	*cnt += len;
	return (dst);
}

char	*ft_strdup_visible(char *src, size_t *cnt)
{
	char	*dst;
	size_t	len;
	size_t	i;

	len = 0;
	while (' ' <= src[*cnt + len] && src[*cnt + len] <= '~')
		len++;
	len += 1;
	dst = malloc(sizeof(char) * len);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < len - 1)
	{
		dst[i] = src[*cnt];
		i++;
		*cnt += 1;
	}
	dst[i] = '\0';
	return (dst);
}

t_str_str_dic	*parse_line(char *str, size_t *cnt)
{
	t_str_str_dic	*raw_dict;

	raw_dict = malloc(sizeof(t_str_str_dic));
	skip_white_spaces(str, cnt);
	raw_dict->key = ft_strdup_num(str, cnt);
	raw_dict->len = str_len(raw_dict->key);
	skip_white_spaces(str, cnt);
	if (str[*cnt] == ':')
		*cnt += 1;
	skip_white_spaces(str, cnt);
	raw_dict->word = ft_strdup_visible(str, cnt);
	skip_white_spaces(str, cnt);
	return (raw_dict);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsakuma  <dsakuma@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 23:20:57 by dsakuma           #+#    #+#             */
/*   Updated: 2024/08/25 23:20:58 by dsakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <errno.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_str_str_dic
{
	char			*key;
	char			*word;
	int				key_int;
	unsigned long	len;
}					t_str_str_dic;

// extern int		errno;
unsigned long		ft_strlen(char *str);
unsigned long		ft_strlen(char *str);
char				*ft_strdup(char *src);
void				ft_put_errstr(char *str);
char				*get_low_num(char **dict, char **str, int length, int j);
void				put_numbers(char **dict_low_num, char **dict_high_num,
						char **str, int length);
void				put_str(char *str);
char				*int_to_str(char **dict, int nb);
int					ft_atoi(char *str);
int					str_len(char *str);
int					ft_strcmp(char *s1, char *s2);
void				set_str(char *dest, char *src);
char				**initialize_dict_high_num(void);
char				**initialize_dict_low_num(void);
char				*get_dict_value(char **dict, int index);
char				*ft_strndup(char *src, int n);
void				use_default_dict(char *str, int pos);
void				use_given_dict(char *str, int pos, char *file_name);
bool				ft_isspace(char c);
t_str_str_dic		*parse_line(char *str, unsigned long *cnt);
void				dict_err(void);
unsigned long		read_dict(char *dict_name, t_str_str_dic *raw_dict[]);
bool				ft_isspace(char c);
t_str_str_dic		*parse_line(char *str, unsigned long *cnt);
void				dict_err(void);
unsigned long		read_dict(char *dict_name, t_str_str_dic *raw_dict[]);
char				**small_num_dic_from_file(char *path);
char				**large_num_dic_from_file(char *path);
#endif
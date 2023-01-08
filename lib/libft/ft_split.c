/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:08:37 by dmin              #+#    #+#             */
/*   Updated: 2022/11/07 11:08:46 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int	word_cnt(char const *str, char c)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str != '\0')
			cnt++;
		while (*str && *str != c)
			str++;
	}
	return (cnt);
}

static char	*get_word2(char **arr, int cnt, char const *str, int len)
{
	char	*tmp;

	tmp = ft_substr(str, 0, len);
	if (!tmp)
	{
		while (cnt--)
			free(arr[cnt]);
		return ((char *) NULL);
	}
	return (tmp);
}

static char	**get_word(char **arr, char const *str, char c)
{
	int		cnt;
	int		len;
	char	*tmp;

	cnt = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str != '\0')
		{
			len = 0;
			while (*str && *str != c)
			{
				str++;
				len++;
			}
			tmp = get_word2(arr, cnt, str - len, len);
			if (!tmp)
				return ((char **) NULL);
			arr[cnt++] = tmp;
		}
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**ret_arr;
	int		w_cnt;
	int		str_len;

	str_len = ft_strlen(s);
	w_cnt = word_cnt(s, c);
	ret_arr = (char **)malloc((w_cnt + 1) * sizeof(char *));
	if (!ret_arr)
		return ((void *) NULL);
	ret_arr[w_cnt] = (void *) NULL;
	ret_arr = get_word(ret_arr, s, c);
	return (ret_arr);
}
/*
#include	<stdio.h>
void   check_leak(void)
{
		system("leaks a.out");
}
int	main(void)
{
	//char **arr0;
	char **arr1;
	//char **arr2;
	//char **arr3;
	//char **arr6;
	//char **arr7;
	//char **arr8;
	//char **arr9;
	//char **arr10;
	int 	i;

	atexit(check_leak);
	//arr0 = ft_split("hello!", ' ');
	arr1 = ft_split("hello!", 'x');
	//arr2 = ft_split("hello!zzzzzzzz", 'z');
	//arr3 = ft_split("\t\t\t\thello!\t\t\t\t", '\t');
	//arr6 = ft_split("^^^1^^2a,^^^^3^^^^--h^^^^", '^');
	//arr7 = ft_split("  gh  ", ' ');
	//arr8 = ft_split("pJLJXYeCm8Iewr59mpFBvUXZqk0FmfqQGJTp", 'p');
	//arr9 = ft_split("    WouHiTxB", 'B');
	//arr10 = ft_split("I09GW", '9');
	i = 0;
	
	while (arr1[i] != 0)
	{
		printf("%s\n", arr1[i]);
		free(arr1[i]); 
		i++;
	}
	free(arr1);
	return (0);
}
*/
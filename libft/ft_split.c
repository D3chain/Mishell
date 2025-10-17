/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:50:14 by echatela          #+#    #+#             */
/*   Updated: 2025/04/27 15:07:27 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	word_count;
	size_t	i;

	word_count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			word_count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (word_count);
}

static void	*free_all(char **res, size_t j)
{
	while (j > 0)
		free(res[--j]);
	free(res);
	return (NULL);
}

static char	*malloc_word(const char *s, size_t start, size_t end)
{
	char	*word;
	size_t	len;

	len = end - start;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_memcpy(word, &s[start], len);
	word[len] = '\0';
	return (word);
}

static int	fill_words(const char *s, char c, char **res)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			res[j] = malloc_word(s, start, i);
			if (!res[j++])
				return (free_all(res, j), 1);
		}
	}
	res[j] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	res = malloc(sizeof(char *) * (word_count + 1));
	if (!res)
		return (NULL);
	if (fill_words(s, c, res))
		return (NULL);
	return (res);
}

// int main(int ac, char **av)
// {
//     (void)ac;
//     char    **res = ft_split(av[1], av[2][0]);
//     while (*res != NULL)
//         printf("%s\n", *res++);
// }

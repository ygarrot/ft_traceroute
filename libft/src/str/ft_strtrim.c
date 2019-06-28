/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:46:15 by ygarrot           #+#    #+#             */
/*   Updated: 2017/11/14 17:50:04 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*cpy(int i, int end, char *fresh, char const *s)
{
	int b;

	b = 0;
	while (i < end)
	{
		fresh[b] = s[i];
		b++;
		i++;
	}
	fresh[b] = '\0';
	return (fresh);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		end;
	char	*fresh;

	i = 0;
	end = 0;
	if (!s)
		return (NULL);
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	while (s[end])
		end++;
	while (i != end && (s[end - 1] == ' ' ||
				s[end - 1] == '\n' || s[end - 1] == '\t') && s)
		end--;
	if ((fresh = (char*)malloc((end - i) + 1 * sizeof(char))) == NULL)
		return (NULL);
	return (cpy(i, end, fresh, s));
}

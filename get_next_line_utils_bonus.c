/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:05:28 by cdapurif          #+#    #+#             */
/*   Updated: 2019/11/08 14:15:35 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list		*ft_lstfoa(t_list **begin_list, int fd)
{
	t_list	*new;
	t_list	*ptr;

	ptr = *begin_list;
	while (ptr)
	{
		if (ptr->fd == fd)
			return (ptr);
		ptr = ptr->next;
	}
	if ((new = malloc(sizeof(t_list) * 1)) == NULL)
		return (NULL);
	new->fd = fd;
	new->buff[0] = '\0';
	new->next = NULL;
	ptr = *begin_list;
	if (!ptr)
	{
		*begin_list = new;
		return (new);
	}
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
	return (new);
}

void		ft_lstremove(t_list **begin_list, int fd)
{
	t_list *prev;
	t_list *next;
	t_list *ptr;

	prev = NULL;
	ptr = *begin_list;
	while (ptr)
	{
		next = ptr->next;
		if (ptr->fd == fd)
		{
			free(ptr);
			if (!prev)
				*begin_list = next;
			else
				prev->next = next;
		}
		else
			prev = ptr;
		ptr = next;
	}
}

char		*ft_strjoin(char *s1, char *s2, int lib)
{
	int		i;
	int		a;
	char	*ret;

	i = 0;
	if (s1)
		i = ft_strlen(s1);
	if ((ret = malloc(i + ft_strlen(s2) + 1)) == 0)
		return (NULL);
	if (s1)
	{
		i = -1;
		while (s1[++i])
			ret[i] = s1[i];
	}
	a = -1;
	while (s2[++a])
		ret[i + a] = s2[a];
	ret[i + a] = '\0';
	if (s1)
		free(s1);
	if (lib)
		free(s2);
	return (ret);
}

char		*ft_substr(char *s, int start, int len, int set)
{
	int		i;
	int		size;
	char	*ret;

	if (!s[0] || start > ft_strlen(s) - 1)
	{
		if ((ret = malloc(1)) == NULL)
			return (NULL);
		ret[0] = '\0';
		return (ret);
	}
	i = start;
	while (i - start < len && s[i])
		i++;
	size = i - start;
	if ((ret = malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	ret[size] = '\0';
	i = -1;
	while (++i < size)
		ret[i] = s[start + i];
	if (set)
		s = NULL;
	return (ret);
}

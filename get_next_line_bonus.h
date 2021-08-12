/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:30:44 by cdapurif          #+#    #+#             */
/*   Updated: 2019/11/08 13:01:41 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list
{
	int				fd;
	char			buff[BUFFER_SIZE + 1];
	struct s_list	*next;
}				t_list;

int				get_next_line(int fd, char **line);
int				ft_strlen(char *str);
char			*ft_substr(char *s, int start, int len, int set);
char			*ft_strjoin(char *s1, char *s2, int free);
t_list			*ft_lstfoa(t_list **begin_list, int fd);
void			ft_lstremove(t_list **begin_list, int fd);

#endif

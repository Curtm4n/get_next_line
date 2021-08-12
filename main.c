/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:55:48 by cdapurif          #+#    #+#             */
/*   Updated: 2019/11/08 14:16:28 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int		main(void)
{
	int		ret;
	int		fd;
	int		fd1;
	char	*line;

	if ((fd = open("Mr_Robot.txt", O_RDONLY)) == -1)
		return (42);
	if ((fd1 = open("lorem_ipsum.txt", O_RDONLY)) == -1)
		return (42);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		printf("%d\n", ret);
		free(line);
		ret = get_next_line(fd1, &line);
			printf("%s\n", line);
			printf("%d\n", ret);
			free(line);
	}
	printf("%s\n", line);
	free(line);
	printf("%d\n", ret);
	close(fd);
	return (0);
}

__attribute__((destructor))void sdfuhsufygw(void)
{
	while (1);
}

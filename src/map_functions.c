/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbayra <sozbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:58:04 by sozbayra          #+#    #+#             */
/*   Updated: 2023/06/19 19:33:00 by sozbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	ft_allocate_memory(t_checker *checker)
{
	checker->map = (char **)malloc(checker->rows * sizeof(char *));
	checker->temp_map = (char **)malloc(checker->rows * sizeof(char *));
}

void	ft_read_next_line(t_checker *checker, int fd, t_temp *temp)
{
	temp->string = get_next_line(fd);
	if (temp->string != 0)
	{
		checker->map[temp->m_i] = (char *)malloc(checker->rectangle
				* sizeof(char));
		checker->temp_map[temp->m_i] = (char *)malloc(checker->rectangle
				* sizeof(char));
		temp->m_j = 0;
		while (temp->string[temp->m_j] && temp->string[temp->m_j] != '\n')
		{
			checker->map[temp->m_i][temp->m_j] = temp->string[temp->m_j];
			checker->temp_map[temp->m_i][temp->m_j] = temp->string[temp->m_j];
			temp->m_j++;
		}
		checker->map[temp->m_i][temp->m_j] = '\0';
		checker->temp_map[temp->m_i][temp->m_j] = '\0';
		temp->m_i++;
	}
	else
	{
		temp->control = 1;
	}
	free(temp->string);
}

void	ft_convert_to_matrix(int fd, t_checker *checker)
{
	t_temp	temp;

	temp.control = 0;
	temp.m_i = 0;
	ft_allocate_memory(checker);
	while (temp.control != 1)
	{
		ft_read_next_line(checker, fd, &temp);
	}
}

void	ft_update_rectangle(t_checker *checker, int length, int i)
{
	if (i == 0)
		checker->rectangle = length;
	else if (checker->rectangle != length)
		checker->rectangle = -1;
}

void	ft_read_map(int fd, t_checker *checker)
{
	char	*c;
	int		length;
	int		j;
	int		control;
	int		i;

	i = 0;
	control = 0;
	length = 0;
	while (control != 1)
	{
		j = 0;
		checker->rows++;
		c = get_next_line(fd);
		if (c != 0)
		{
            //j++ ayrı olarak yazılıydı, düzeltme yapıldı.
			while (c[j] && c[j++] != '\n')
			length = j;
			ft_update_rectangle(checker, length, i);
			i++;
		}
		else
			control = 1;
		free(c);
	}
}

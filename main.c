/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wned <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 14:12:47 by wned              #+#    #+#             */
/*   Updated: 2018/12/27 19:37:39 by wned             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define N 4
#include <string.h>

void printSolution(int field[N][N])
{
	int			i;
	int			j;
	static int  k = 1;

	i = 0;
	printf("%d-\n", k++);
    while (i < N)
    {
		j = 0;
	    while (j < N)
		{
	        printf(" %d ", field[i][j]);
			j++;
		}
		i++;
	    printf("\n");
	}
    printf("\n");
}

int		is_safe(int field[N][N], int row, int col)
{
	int i;
	int j;

	i = 0;
	while (i < col)
	{
		if (field[row][i])
			return (0);
		i++;
	}
	i = row;
	j = col;
	if (i == row && j == col)
	{
		while (i >= 0 && j >= 0)
		{
			if (field[i][j])
				return (0);
			i--;
			j--;
		}
	}
	i = row;
	j = col;
	if (i == row && j == col)
	{
		while (i < N && j >= 0)
		{
			if (field[i][j])
				return (0);
			i++;
			j--;
		}
	}
	return (1);
}

int		solveNQField(int field[N][N], int col)
{
	int i;

	if (col == N)
	{
		printSolution(field);
		return (1);
	}
	i = 0;
	while (i < N)
	{
		if (is_safe(field, i, col))
		{
			field[i][col] = 1;
			solveNQField(field, col + 1);
				//return (1);
			field[i][col] = 0;
		}
		i++;
	}
	return (0);
}

void	solveNQ()
{
	int field[N][N];
	memset(field, 0, sizeof(field));
	solveNQField(field, 0);
	return ;
}

int		main()
{
	solveNQ();
	return (0);
}

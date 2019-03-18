/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroland- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:54:27 by mroland-          #+#    #+#             */
/*   Updated: 2019/03/02 17:54:29 by mroland-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void    plotLineHigh(t_fdf *t)
{
	t->dx = t->X1 - t->X0;
	t->dy = t->Y1 - t->Y0;
	t->xi = 1;
	if (t->dx < 0)
	{
		t->xi = -1;
		t->dx = -t->dx;
	}
    t->D = 2 * t->dx - t->dy;
	t->x = t->X0;
	t->y = t->Y0;
	while (t->y <= t->Y1)
	{
		mlx_pixel_put(t->mlx_ptr, t->win_ptr, t->x, t->y, t->ccolor);
		if (t->D > 0)
		{
			t->x = t->x + t->xi;
			t->D = t->D - 2 * t->dy;
		}
		t->D = t->D + 2 * t->dx;
		t->y++;
	}
}

void    plotLineLow(t_fdf *t)
{
    t->dx = t->X1 - t->X0;
    t->dy = t->Y1 - t->Y0;
    t->yi = 1;
    if (t->dy < 0)
    {
        t->yi = -1;
        t->dy = -t->dy;
    }
    t->D = 2 * t->dy - t->dx;
    t->y = t->Y0;
    t->x = t->X0;
    while (t->x <= t->X1)
    {
        mlx_pixel_put(t->mlx_ptr, t->win_ptr, t->x, t->y, t->ccolor);
        if (t->D > 0)
        {
            t->y = t->y + t->yi;
            t->D = t->D - 2 * t->dx;
        }
        t->D = t->D + 2 * t->dy;
		t->x++;
    }
}

t_fdf *swap_t(t_fdf *t, int flag)
{
    if (flag == 0)
    {
        t->X0 = t->x1;
        t->Y0 = t->y1;
        t->X1 = t->x0;
        t->Y1 = t->y0;
    }
    if (flag == 1)
    {
        t->X0 = t->x0;
        t->Y0 = t->y0;
        t->X1 = t->x1;
        t->Y1 = t->y1;        
    }
	return (t);
}

void    plotLine(t_fdf *t)
{
  if (ABS(t->y1 - t->y0) < ABS(t->x1 - t->x0))
  {
    if (t->x0 > t->x1)
        plotLineLow(swap_t(t, 0));
    else
        plotLineLow(swap_t(t, 1));
  }
  else
  {
    if (t->y0 > t->y1)
    	plotLineHigh(swap_t(t, 0));
    else
		plotLineHigh(swap_t(t, 1));
  }
}

void	input_point(int i, int j, t_fdf *t, int flag)
{
	if (flag == 0)
	{
		t->x0 = t->p[i][j - 1].x * t->scale + t->centerX;
        t->y0 = t->p[i][j - 1].y * t->scale + t->centerY;
        t->x1 = t->p[i][j].x * t->scale + t->centerX;
        t->y1 = t->p[i][j].y * t->scale + t->centerY;
        t->ccolor = t->p[i][j - 1].color;
	}
	if (flag == 1)
	{
		t->x0 = t->p[i - 1][j].x * t->scale + t->centerX;
        t->y0 = t->p[i - 1][j].y * t->scale + t->centerY;
        t->x1 = t->p[i][j].x * t->scale + t->centerX;
        t->y1 = t->p[i][j].y * t->scale + t->centerY;
        t->ccolor = t->p[i - 1][j].color;
	}
}

void print_table(t_fdf *t)
{
	int i;
	int j;

	i = 0;
	while (i < t->height)
    {
        j = 0;
        while (j < t->width)
        {
            if (j > 0)
            {
				input_point(i, j, t, 0);
                plotLine(t);
            }          
            if (i > 0)
            {
                input_point(i, j, t, 1);
				plotLine(t);
            }
            j++;
        }
        i++;
    }
}

int     main(int argc, char **argv)
{
    t_fdf   *t;
    int     fd;
    char    buff[BUFF_SIZE];
    char    **line_y;
    int     y;
    int     x;
    int     count;
    char    **line_x;
    char    *temp_color;
    int     white;
    int     k;
    int     len;
    int     ret;
	
	if (argc != 2)
    {
        ft_putstr("usage: fdf [map_file]\n");
        exit (0);
    }
    else
    {
        //ft_open(argv, 0, 0, &t);
       // void    ft_open(char **argv, int len, int ret)
        if ((fd = open(argv[1], O_RDONLY)) < 0)
            E(1);
        ret = read(fd, buff, BUFF_SIZE);//                          потом сделать цикл, чтобы читать большие мар
        buff[ret] = '\0';
        line_y = ft_strsplit(buff, '\n');//                         поделили мар на строки
        len = 0;
        while (line_y[len] != NULL)//                               посчитали количество "точек" на строке
            len++;
   //t = ft_valid(line, i);
        t = (t_fdf*)malloc(sizeof(t_fdf));//                   выделяем память под большую структуру
        t->p = (t_mfdf**)malloc(sizeof(t_mfdf) * len);//    выделяем память под двойной массив
        y = 0;
        count = ft_count_word(line_y[y], ' ');
        t->width = count;
        t->height = len;
        while (y < t->height)
        {
            line_x = ft_strsplit(line_y[y], ' ');
            t->p[y] = (t_mfdf*)malloc(sizeof(t_mfdf) * count);
            white = ft_atoi_base("FFFFFF", 16);
            x = 0;
            while (x < t->width)
            {
                t->p[y][x].x = x;
                t->p[y][x].y = y; 
                t->p[y][x].z = ft_atoi(line_x[x]);
                t->p[y][x].color = white;
                k = 0;
                while (line_x[x][k] != '\0')
                {
                    if (line_x[x][k] == 'x')
                    {
                        temp_color = ft_strsub(line_x[x], k + 1, (ft_strlen(line_x[x]) - (k + 1)));
                        t->p[y][x].color = ft_atoi_base(temp_color, 16);
                    }
                    k++;
                }
 //               printf("%f, %f, %f, %d\t", t->p[y][x].x, t->p[y][x].y, t->p[y][x].z, t->p[y][x].color);
                x++;
            }
            printf("\n");
            free(line_x);
            y++;
        }
        close(fd);
 //   return (t);
		t->h = 300;
		t->w = 500;
		t->mlx_ptr = mlx_init();
	    t->win_ptr = mlx_new_window(t->mlx_ptr, t->w, t->h, "mlx 42");
        /* масштаб от величины открытого окна */
		t->scale = ((t->h > t->w) ? ((t->w / 100) * 80) / (t->width - 1) : ((t->h / 100) * 80) / (t->height - 1));
        /* центровка */ /* по оси Х */
		t->centerX = ((t->w / 2) - (t->p[t->height - 1][t->width - 1].x * t->scale) / 2);
		/* центровка */ /* по оси Y */
		t->centerY = ((t->h / 2) - (t->p[t->height - 1][t->width - 1].y * t->scale) / 2);
		print_table(t);
        mlx_loop(t->mlx_ptr);
    }

    exit (0);
}
	/* от Вити: */
	// po->mlx = mlx_init();
    // po->win = mlx_new_window(po->mlx, SWIN, SWIN, "FDF");
    // po->nim = mlx_new_image(po->mlx, SWIN, SWIN);
    // po->data = (int*)mlx_get_data_addr(po->nim, &po->bpp,
    //     &po->line_size, &po->endian);
    // centermap(po);
    // ft_draw(po);
    // mlx_put_image_to_window(po->mlx, po->win, po->nim, 0, 0);

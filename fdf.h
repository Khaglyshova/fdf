/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroland- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:03:15 by mroland-          #+#    #+#             */
/*   Updated: 2019/03/02 18:03:18 by mroland-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

//# define BUFF_SIZE 9000

# include "mlx.h"
# include "libft/libft.h"
# define E(p) if (p) { ft_putstr("error\n"); exit(0);}
# define ABS(number) ((number) > 0 ? (number):-(number))

typedef struct  s_mfdf
{
    double      x;
    double      y;
    double      z;
    int         color;
}               t_mfdf;

typedef struct  s_fdf 
{

    t_mfdf      **p;
    int         x0;/* plotLine */
    int         y0;/* plotLine */
    int         x1;/* plotLine */
    int         y1;/* plotLine */
    int         ccolor;
    int         h;
    int         w;
    int         width;
    int         height;
    int         scale;
    int         centerX;
    int         centerY;
    void        *mlx_ptr;
    void        *win_ptr;
    int         X0;
    int         Y0;
    int         X1;
    int         Y1;
    int         dx;/* plotLineLow, plotLineLow */
    int         dy;/* plotLineLow, plotLineLow */
    int			xi;/* plotLineLow, plotLineLow */
    int			yi;/* plotLineLow, plotLineLow */
    int			D;/* plotLineLow, plotLineLow */
	int			x;/* plotLineLow, plotLineLow */
	int			y;/* plotLineLow, plotLineLow */
        
}               t_fdf;
#endif
# include "mlx.h"
# include <stdlib.h>
# define ABS(number) ((number) > 0 ? (number):-(number))

typedef struct  s_fdf 
{
    void        *mlx_ptr;
    void        *win_ptr;    
}               t_fdf;

void    plotLineHigh(int x0, int y0, int x1, int y1, t_fdf *table)
{
    int dx;
    int dy;
    int xi;
    int D;
	int x;
	int y;

	dx = x1 - x0;
	dy = y1 - y0;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
    D = 2 * dx - dy;
	x = x0;
	y = y0;
	while (y <= y1)
	{
		mlx_pixel_put(table->mlx_ptr, table->win_ptr, x, y, 0xFFFFFF);
		if (D > 0)
		{
			x = x + xi;
			D = D - 2 * dy;
		}
		D = D + 2 * dx;
		y++;
	}
}

void    plotLineLow(int x0, int y0, int x1, int y1, t_fdf *table)
{
    int dx;
    int dy;
    int yi;
    int D;
	int x;
	int y;

    dx = x1 - x0;
    dy = y1 - y0;
    yi = 1;
    if (dy < 0)
    {
        yi = -1;
        dy = -dy;
    }
    D = 2 * dy - dx;
    y = y0;
    x = x0;
    while (x <= x1)
    {
        mlx_pixel_put(table->mlx_ptr, table->win_ptr, x, y, 0xFFFFFF);
        if (D > 0)
        {
            y = y + yi;
            D = D - 2 * dx;
        }
        D = D + 2 * dy;
		x++;
    }
}

void    plotLine(int x0, int y0, int x1, int y1, t_fdf *table)
{
  if (ABS(y1 - y0) < ABS(x1 - x0))
  {
    if (x0 > x1)
        plotLineLow(x1, y1, x0, y0, table);
    else
        plotLineLow(x0, y0, x1, y1, table);
  }
  else
  {
    if (y0 > y1)
        plotLineHigh(x1, y1, x0, y0, table);
    else
      plotLineHigh(x0, y0, x1, y1, table);
  }
}

void BresenhamCircle(int x0, int y0, int radius, t_fdf *table)
{
    int x = radius;
    int y = 0;
    int radiusError = 1 - x;
    while (x >= y)
    {
		plotLine(x0, y0, x + x0, y + y0, table);
        plotLine(x0, y0, y + x0, x + y0, table);
        plotLine(x0, y0, -x + x0, y + y0, table);
        plotLine(x0, y0, -y + x0, x + y0, table);
        plotLine(x0, y0, -x + x0, -y + y0, table);
        plotLine(x0, y0, -y + x0, -x + y0, table);
        plotLine(x0, y0, x + x0, -y + y0, table);
        plotLine(x0, y0, y + x0, -x + y0, table);
        y++;
        if (radiusError < 0)
        {
            radiusError = radiusError + (2 * y + 1);
        }
        else
        {
            x--;
            radiusError = radiusError + (2 * (y - x + 1));
        }
    }
}

int     main()
{
	int 	x0 = 600;
	int 	y0 = 600;
	int		radius = 500;
	t_fdf   *table;

    table = (t_fdf*)malloc(sizeof(t_fdf));
	table->mlx_ptr = mlx_init();
	table->win_ptr = mlx_new_window(table->mlx_ptr, 1200, 1200, "BresenhamCircle");
	BresenhamCircle(x0, y0, radius, table);
	mlx_loop(table->mlx_ptr);
	return (0);	
}
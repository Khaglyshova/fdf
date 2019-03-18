# include "mlx.h"

void BresenhamCircle(int x0, int y0, int radius, void **mlx_ptr, void **win_ptr)
{
    int x = radius;
    int y = 0;
    int radiusError = 1 - x;
    while (x >= y)
    {
		mlx_pixel_put(*mlx_ptr, *win_ptr, x + x0, y + y0, 0xFFFFFF);
        mlx_pixel_put(*mlx_ptr, *win_ptr, y + x0, x + y0, 0xFFFFFF);
        mlx_pixel_put(*mlx_ptr, *win_ptr, -x + x0, y + y0, 0xFFFFFF);
        mlx_pixel_put(*mlx_ptr, *win_ptr, -y + x0, x + y0, 0xFFFFFF);
        mlx_pixel_put(*mlx_ptr, *win_ptr, -x + x0, -y + y0, 0xFFFFFF);
        mlx_pixel_put(*mlx_ptr, *win_ptr, -y + x0, -x + y0, 0xFFFFFF);
        mlx_pixel_put(*mlx_ptr, *win_ptr, x + x0, -y + y0, 0xFFFFFF);
        mlx_pixel_put(*mlx_ptr, *win_ptr, y + x0, -x + y0, 0xFFFFFF);
        y++;
        if (radiusError < 0)
        {
            radiusError += 2 * y + 1;
        }
        else
        {
            x--;
            radiusError += 2 * (y - x + 1);
        }
    }
}

int main()
{
	int 	x0 = 250;
	int 	y0 = 250;
	int		radius = 50;
	void	*mlx_ptr;
    void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "BresenhamCircle");
	BresenhamCircle(x0, y0, radius, &mlx_ptr, &win_ptr);
	mlx_loop(mlx_ptr);
	return (0);	
}
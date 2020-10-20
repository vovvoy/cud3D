#include <mlx.h>
#include <unistd.h>


typedef struct  s_vars {
    void        *mlx;
    void        *win;
    int         w;
    int         h;
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
    int         side;
    double      posX;
    double      posY;
    double      dirX;
    double      dirY;
    double      planeX;
    double      planeY;
    double      cameraX;
    double      rayDirX;
}               t_vars;

void            my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void            square(t_vars *mlx)
{

    for (int i = 0; i < 1920; i++)
        for (int j = 0; j < 1080; j++)
        {
            if ((i < mlx->w + mlx->side / 2 && i >= mlx->w - mlx->side / 2) &&
                (j < mlx->h + mlx->side / 2 && j >= mlx->h - mlx->side / 2))
                my_mlx_pixel_put(mlx, i, j, 0x00FF0000 / 2);
            else
                {
                    if (j > 1080 / 2)
                        my_mlx_pixel_put(mlx, i, j, 0x00000000);
                    else
                        my_mlx_pixel_put(mlx, i, j, 0x00FFFFFF);
                }
        }
    mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);

}

int            move(int keycode, t_vars *mlx)
{
    if (keycode == 126)
        mlx->side -= 5;
    if (keycode == 125)
        mlx->side += 5;
    if (keycode == 123)
        if (mlx->w > mlx->side / 2)
            mlx->w -= 10;
    if (keycode == 124)
        if (mlx->w < 1920 - mlx->side / 2)
            mlx->w += 10;
    square(mlx);
    return 1;
}

int             main(void)
{
    t_vars mlx;

    mlx.w = 1920/2;
    mlx.h = 1080/2;
    mlx.side = 100;
    mlx.mlx = mlx_init();
    mlx.win = mlx_new_window(mlx.mlx, 1920, 1080, "Hello world!");
    mlx.img = mlx_new_image(mlx.mlx, 1920, 1080);
    mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length,
                                 &mlx.endian);
    square(&mlx);
    mlx_hook(mlx.win, 2, 0, move, &mlx);
    mlx_loop(mlx.mlx);
}
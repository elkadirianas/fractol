#include "fractol.h"

static void ERROR(){
    exit(1); 
}

void data_init(t_fractal *fractal){
    fractal->escape_value = 4 ; 
    fractal->iterations=42; 
}

void fractal_init(t_fractal *fractal){
    fractal->mlx_connection = mlx_init(); 
    if(!fractal->mlx_connection)
        ERROR(); 
    fractal->mlx_window = mlx_new_window(fractal->mlx_connection, W, H , fractal->name); 
    if(!fractal->mlx_window){
        free(fractal->mlx_connection); 
        free(fractal->mlx_window); 
        ERROR(); 
    }
    fractal->img.img_ptr=mlx_new_image(fractal->mlx_connection,W,H); 
    if(!fractal->img.img_ptr){
        mlx_destroy_window(fractal->mlx_connection,fractal->mlx_window); 
        free(fractal->mlx_connection); 
        free(fractal->mlx_window); 
        ERROR(); 
    }
    fractal->img.pixel=mlx_get_data_addr(fractal->img.img_ptr,&fractal->img.bits_per_pixel,
                                        &fractal->img.line_length,&fractal->img.endian); 
    data_init(fractal); 
}
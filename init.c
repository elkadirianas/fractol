#include "fractol.h"

static void ERROR(){
    exit(1); 
}

static void data_init(t_fractal *fractal){
    fractal->escape_value = 4 ; 
    fractal->iterations=42; 
    fractal->shift_x=0.0; 
    fractal->shift_y=0.0; 
}

static void event_init(t_fractal *fractal){
    mlx_hook(fractal->mlx_window,KeyPress,0,
                key_handle, fractal);
   	// mlx_hook(fractal->mlx_window,ButtonPress,0,
    //             mouse_handle, fractal);
    // mlx_hook(fractal->mlx_window,DestroyNotify,0,
    //             close_handle, fractal);
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
    event_init(fractal); 
    data_init(fractal); 
}
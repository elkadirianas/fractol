#include "fractol.h"

void close_f(t_fractal *fractal){
    mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr); 
    mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window); 
    exit(0); 
}

int key_handle(int keycode, t_fractal *fractal){
    if(keycode==escape) 
        close_f(fractal); 
    else if(keycode==plus)
        fractal->iterations+=10; 
    else if(keycode==minus)
        fractal->iterations-=10; 
    else if(keycode==left)
        fractal->shift_x+=0.5; 
    else if(keycode==right)
        fractal->shift_x -=0.5;
    else if(keycode==up)
        fractal->shift_y-=0.5; 
    else if(keycode==down)
        fractal->shift_y +=0.5; 
    render(fractal); 
    return 0 ; 
}
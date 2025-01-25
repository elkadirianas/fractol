#include "fractol.h"

static void my_pixel_put(int x , int y , t_img *img , int color){
    int offset ; 
    offset=(y*img->line_length)+(x*(img->bits_per_pixel/8));
    *(unsigned int *)(img->pixel+offset)=color; 
}

void handle_pixel(int x , int y , t_fractal *fractal){
    t_complex z; 
    t_complex c ; 
    int i ; 
    int color ; 

    i=0; 
    z.r=0.0; 
    z.i=0.0; 

    c.r=scale(x, -2,2, 0 , W)+fractal->shift_x; 
    c.i=scale(y,  2,-2, 0 , H)+fractal->shift_y;
    while(i<fractal->iterations){
        z=sum_complex(square_complex(z),c); 
        if(((z.r*z.r)+(z.i*z.i))>fractal->escape_value){
            //color = scale(i,BLACK,0xFF030507,0,fractal->iterations); 
            color = 0x000F0000* i;
            my_pixel_put(x,y,&fractal->img,color); 
            return ; 
        }
        i++; 
    }
    my_pixel_put(x,y,&fractal->img,BLACK); 
}

void render(t_fractal *fractal){
    int x ; 
    int y ; 
    y=0 ; 
    while(y<H){
        x=0; 
        while(x<W){
            handle_pixel(x,y,fractal); 
            x++; 
        }
        y++; 
    }
    mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,fractal->img.img_ptr,
				0,0);
}
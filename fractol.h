#ifndef FRACTOL_H
#define FRACTOL_H

#include "stdio.h"
#include "mlx.h"
#include "unistd.h"
#include "stdlib.h"

#define W 800 
#define H 800


#define BLACK       0x000000  // RGB(0, 0, 0)
#define WHITE       0xFFFFFF  // RGB(255, 255, 255)
#define RED         0xFF0000  // RGB(255, 0, 0)
#define GREEN       0x00FF00  // RGB(0, 255, 0)
#define BLUE        0x0000FF  // RGB(0, 0, 255)
#define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
#define LIME_SHOCK      0xCCFF00  // A blinding lime
#define NEON_ORANGE     0xFF6600  // A blazing neon orange
#define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
#define AQUA_DREAM      0x33CCCC  // A bright turquoise
#define HOT_PINK        0xFF66B2  // As the name suggests!
#define ELECTRIC_BLUE   0x0066FF  // A radiant blue
#define LAVA_RED        0xFF3300  // A bright, molten red



typedef struct s_complex{
	double r ; 
	double i ; 
}	t_complex; 

typedef struct	s_img {
	void	*img_ptr;
	char	*pixel;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_fractal{
	char * name ; 
    void *mlx_connection; 
    void *mlx_window; 
    t_img img ; 
	double escape_value ; 
	int iterations; 
}   t_fractal; 


int	ft_strncmp(const char *s1, const char *s2, size_t n);
double scale(double number , double n_min, double n_max, double o_min , double o_max); 
void fractal_init(t_fractal *fractal); 
t_complex sum_complex(t_complex num_1 , t_complex num_2);
t_complex square_complex(t_complex num);
void handle_pixel(int x , int y , t_fractal *fractal); 
void render(t_fractal *fractal); 

#endif

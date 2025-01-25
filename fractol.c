
#include "fractol.h"

void f(){
    system("leaks app"); 
}

int main(int argc , char **argv){
    atexit(f); 
    t_fractal fractal ; 
    if(((argc==2 && !ft_strncmp(argv[1],"mandelbort",10)) || (argc==4 && !ft_strncmp(argv[1],"julia",5)))){
        fractal.name=argv[1]; 
        fractal_init(&fractal); 
        render(&fractal); 
        mlx_loop(fractal.mlx_connection);
        printf("good"); 
    }
    else{
        printf("issa hh"); 
    }
    return 0 ; 
}
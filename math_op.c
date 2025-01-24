#include "fractol.h"


double scale(double number , double n_min, double n_max, double o_min , double o_max){
    return (n_max -n_min)*(number-o_min)/(o_max-o_min)+n_min; 
}

t_complex sum_complex(t_complex num_1 , t_complex num_2){
    t_complex result ; 
    result.r=num_1.r+num_2.r; 
    result.i=num_1.i+num_2.i; 
    return result; 
}

t_complex square_complex(t_complex num){
    t_complex result ; 
    result.r=num.r*num.r-num.i*num.i; 
    result.i=2*num.r*num.i; 
    return result ; 
}
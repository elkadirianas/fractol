/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkadir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:02:25 by aelkadir          #+#    #+#             */
/*   Updated: 2025/01/25 20:02:29 by aelkadir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "mlx.h"
# include "stdlib.h"
# include "unistd.h"

# define KEYPRESS 2
# define BUTTONPRESS 4
# define DESTROYNOTIFY 17

# define MOUSE_UP 4
# define MOUSE_DOWN 5

# define ESCAPE 53
# define PLUS 69
# define MINUS 78
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define W 800
# define H 800

# define BLACK 0x000000
# define WHITE 0xFFFFFF

typedef struct s_complex
{
	double	r;
	double	i;
}			t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixel;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iterations;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}			t_fractal;
size_t		ft_strlen(const char *s);
double		ft_atodouble(char *str);
int			is_valid(char *str);
void		ft_putstr_fd(char *s, int fd);
int			ft_strcmp(const char *s1, const char *s2);
double		scale(double number, double n_min, double n_max, double o_max);
void		fractal_init(t_fractal *fractal);
t_complex	sum_complex(t_complex num_1, t_complex num_2);
t_complex	square_complex(t_complex num);
void		handle_pixel(int x, int y, t_fractal *fractal);
void		render(t_fractal *fractal);
int			key_handle(int keysym, t_fractal *fractal);
int			close_f(void);
int			mouse_handle(int button, int x, int y, t_fractal *fractal);
double		atodbl(char *s);
#endif
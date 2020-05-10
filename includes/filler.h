//
// Created by Ринат Мирзагаламов on 2020-05-07.
//

#ifndef FILLER_FILLER_H
#define FILLER_FILLER_H

# include "libft/headers/libft.h"
# include "libft/headers/ft_printf.h"

# define SHIFT_LEFT 55

typedef struct	s_map
{
	int			**figure;
	int			**map;
	int			vz;
	int			my_num;
	int			hor_size;
	int			ver_size;
	int			my_x;
	int			my_y;
	int			f_ver;
	int			f_width;
	int			ver_shift;
	int			right_shift;
}				t_map;



#endif //FILLER_FILLER_H

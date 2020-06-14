/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <bglinda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 21:56:54 by bglinda           #+#    #+#             */
/*   Updated: 2020/05/24 21:58:32 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_FILLER_H
# define FILLER_FILLER_H

# include "libft/headers/libft.h"
# include "libft/headers/ft_printf.h"
# include <stdio.h>

# define A 65
# define MAX 1000000

typedef struct	s_struct
{
	int			**figure;
	int			**map;
	int			my_num;
	int			hor_size;
	int			ver_size;
	int			my_x;
	int			my_y;
	int			f_ver;
	int			f_width;
}				t_struct;

int				update_heatmap(t_struct *map, int find_to, int weight);
int				create_map(t_struct *map);
void			find_place(t_struct *map);
int				fresh(int return_val, t_struct *map);
void			clear_map(t_struct *map);
int				update_map(t_struct *map, int size);
int				skip_str(int line_count);
void			*free_map(void **mas);
void			fillna(int *s, int n);
int				define_figure(t_struct *map);
int				change_values(t_struct *map, int i, int j, int count);
int				solver(t_struct *map);
int				ft_len_arr(char **arr);
int				valid_map(t_struct *map, char *buf, int gnl);
int				valid_player(t_struct *map);
int				valid_shape(t_struct *map);
int				valid_shape_fig(char *piece, t_struct *map);
int				valid_figure(t_struct *map, char *ptr, int gnl);
void			get_shape_map(t_struct *map, char **arr);

#endif

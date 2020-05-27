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
# include <ncurses.h>
# include <locale.h>

# define SHIFT 50
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
	int			ver_shift;
	int			right_shift;
}				t_struct;

typedef struct	s_bonus
{
	char		*name_1;
	char		*name_2;
	int			o_score;
	int			x_score;
}				t_bonus;

int				update_heatmap(t_struct *map, int find_to, int cost);
int				create_map(t_struct *map);
void			find_place(t_struct *map);
int				fresh(int return_val, t_struct *map);
void			clear_map(t_struct *map);
int				refresh_map(t_struct *map, int size);
int				skip_str(int line_count);
int				size_num(int num);
void			*free_map(void **mas);
void			fillna(int *s, int n);
int				define_figure(char *piece, t_struct *map);
int				change_values(t_struct *map, int i, int j, int count);
int				solver(t_struct *map);
char			*find_str_from_name(int fd, char *name);
void			curs_start(void);
void			printw_color(char *str, int pair_num);
void			create_header(int hor, t_bonus *viz);
void			output_score(int hor, int ver, t_bonus *viz);

#endif

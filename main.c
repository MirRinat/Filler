//
// Created by Ринат Мирзагаламов on 2020-05-07.
//

#include "includes/filler.h"

int ft_size_num(int num)
{
	int size;

	size = 0;
	while(num > 0)
	{
		num /= 10;
		size++;
	}
	return (size);
}

void	ft_bzero_for_filler(int *s, int n)
{
	int i;

	i = 0;
	while (i < n)
		s[i++] = 200;
}

int			skip_strings(int line_count)
{
	char	*ptr;
	int		size;

	size = 0;
	ptr = NULL;
	while (size < line_count)
	{
		if (get_next_line(0, &ptr) == -1)
			return (-1);
		free(ptr);
		size++;
	}
	return (1);
}

void print_map(t_map *map)
{
	int i = 0;
	int j;
	while (i < map->ver_size)
	{
		j = 0;
		while (j < map->hor_size)
		{
			printf("%c", map->map[i][j]);
			j++;
		}
		i++;
	}
}



void		*free_doub_lvl_mass(void **mas)
{
	char	**ptr;
	int		i;

	i = 0;
	if (!mas)
		return (NULL);
	ptr = (char**)mas;
	while (ptr[i] != NULL)
		free(ptr[i++]);
	free(ptr);
	return (NULL);
}

static int	free_all(int return_val, t_map *map)
{
	free_doub_lvl_mass((void**)map->map);
	free_doub_lvl_mass((void**)map->figure);
	return (return_val);
}

static void	clear_map(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (j < map->hor_size)
		{
			map->map[i][j] = 200;
			j++;
		}
		i++;
	}
	free_doub_lvl_mass((void**)map->figure);
}



//###################################################################

//#################### 			Create map
static void	cut_hor_and_ver(t_map *map)
{
	int		i;
	int		j;

	i = map->f_ver - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < map->f_width && map->figure[i][j] == 200)
			j++;
		if (j != map->f_width)
			break ;
		(map->ver_shift)++;
		i--;
	}
	j = map->f_width - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < map->f_ver && map->figure[i][j] == 200)
			i++;
		if (i != map->f_ver)
			return ;
		(map->right_shift)++;
		j--;
	}
}

static int	memfigure(char *piece, t_map *map)
{
	int		i;

	i = 0;
	map->f_width = ft_atoi(&(piece[8]));
	map->f_ver = ft_atoi(&(piece[6]));
	free(piece);
	map->ver_shift = 0;
	if (!(map->figure = (int**)malloc(sizeof(int*) * (map->f_ver + 1))))
		return (-1);
	while (i < map->f_ver)
	{
		if (!(map->figure[i++] = (int*)malloc(sizeof(int) * map->f_width)))
		{
			free_doub_lvl_mass((void**)map->figure);
			return (-1);
		}
	}
	map->figure[map->f_ver] = NULL;
	return (1);
}

static int	create_figure(t_map *map)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	while (i < map->f_ver)
	{
		j = 0;
		if (!get_next_line(0, &ptr))
		{
			free_doub_lvl_mass((void**)map->figure);
			free_doub_lvl_mass((void**)map->map);
			return (-1);
		}
		while (ptr[j] != '\0')
		{
			map->figure[i][j] = (ptr[j] == '*') ? -1 : 200;
			j++;
		}
		free(ptr);
		i++;
	}
	return (1);
}

int			define_figure(char *piece, t_map *map)
{
	if (memfigure(piece, map) == -1)
		return (-1);
	if (!create_figure(map))
		return (-1);
	map->ver_shift = 0;
	map->right_shift = 0;
	cut_hor_and_ver(map);
	return (0);
}

static int	map_change(t_map *map, int size)
{
	char	*time_buf;
	int		str_cheked;
	int		i;

	str_cheked = 0;
	while (str_cheked < size)
	{
		if (get_next_line(0, &time_buf) == -1)
		{
			free_doub_lvl_mass((void**)map->map);
			return (-1);
		}
		i = 0;
		while (i < map->hor_size)
		{
			if (ft_memchr("oO", time_buf[i + 4], 2))
				map->map[str_cheked][i] = (map->my_num == 1) ? -1 : 0;
			else if (ft_memchr("xX", time_buf[i + 4], 2))
				map->map[str_cheked][i] = (map->my_num == 1) ? 0 : -1;
			i++;
		}
		free(time_buf);
		str_cheked++;
	}
	return (1);
}

int			refresh_map(t_map *map, int size)
{
	char	*time_buf;

	if (map_change(map, size) == -1)
		return (-1);
	if (get_next_line(0, &time_buf) == -1)
	{
		free_doub_lvl_mass((void**)map->map);
		return (-1);
	}
	if (define_figure(time_buf, map) == -1)
		return (-1);
	return (1);
}




int def_shape(t_map *map)//define map's shapes
{
	char *ptr;


	//some function
	if (get_next_line(0,&ptr) == -1)
		return (-1);
	map->my_num = ptr[10] - 48;
	//printf("ptr[10] = %c", ptr[10]);
	//

	free(ptr);
	if (get_next_line(0,&ptr) == -1)
		return (-1);
	map->ver_size = (int)ft_atoi(&(ptr[8]));
	map->hor_size = (int)ft_atoi(&(ptr[8 + ft_size_num(map->ver_size) + 1]));
	if (!(map->map = (int**)malloc(sizeof(int*) * (map->ver_size + 1))))
		return (-1);
	map->map[map->ver_size] = NULL;
	free(ptr);
	return (0);
}


int create_map(t_map *map)
{
	int size;

	size = 0;
	def_shape(map);
	while (size < map->ver_size)
	{
		if (!(map->map[size] = (int*)malloc(sizeof(int) * map->hor_size)))
		{
			free_doub_lvl_mass((void**)map->map);//clear map
			return (-1);
		}
		ft_bzero_for_filler(map->map[size++], map->hor_size);//fillna all map
	}
//	print_map(map);
	if (!skip_strings(1))
		return (-1);
	refresh_map(map,map->ver_size);
	return (0);

}
//######################			solver/filler

int	weight_diagonals(t_map *map, int i, int j, int cost)
{
	int		count;

	count = 0;
	if (i - 1 >= 0 && j + 1 < map->hor_size && map->map[i - 1][j + 1] == 200)
	{
		map->map[i - 1][j + 1] = cost;
		count++;
	}
	if (i - 1 >= 0 && j - 1 >= 0 && map->map[i - 1][j - 1] == 200)
	{
		map->map[i - 1][j - 1] = cost;
		count++;
	}
	if (i + 1 < map->ver_size && j + 1 < map->hor_size
		&& map->map[i + 1][j + 1] == 200)
	{
		map->map[i + 1][j + 1] = cost;
		count++;
	}
	if (i + 1 < map->ver_size && j - 1 >= 0 && map->map[i + 1][j - 1] == 200)
	{
		map->map[i + 1][j - 1] = cost;
		count++;
	}
	return (count);
}

int	check_weight(t_map *map, int cost, int i, int j)
{
	int		count;

	count = 0;
	if (j + 1 < map->hor_size && map->map[i][j + 1] == 200)
	{
		map->map[i][j + 1] = cost;
		count++;
	}
	if (j - 1 >= 0 && map->map[i][j - 1] == 200)
	{
		map->map[i][j - 1] = cost;
		count++;
	}
	if (i + 1 < map->ver_size && map->map[i + 1][j] == 200)
	{
		map->map[i + 1][j] = cost;
		count++;
	}
	if (i - 1 >= 0 && map->map[i - 1][j] == 200)
	{
		map->map[i - 1][j] = cost;
		count++;
	}
	count += weight_diagonals(map, i, j, cost);
	return (count);
}

int			update_weight(t_map *map, int find_to, int cost)
{
	int		count;
	int		i;
	int		j;

	count = 1;
	while (count > 0)
	{
		i = 0;
		count = 0;
		while (i < map->ver_size)
		{
			j = 0;
			while (j < map->hor_size)
			{
				if (map->map[i][j] == find_to)
					count += check_weight(map, cost, i, j);
				j++;
			}
			i++;
		}
		find_to++;
		cost++;
	}
	return (find_to);
}



static int	check_z(int map_value, int figure_value, int *intersection,
					  int *count)
{
	if (map_value == -1 && figure_value == -1)
		(*intersection)++;
	if (map_value == 0 && figure_value == -1)
		return (-1);
	if (*intersection > 1)
		return (-1);
	if (map_value > 0 && figure_value == -1)
		(*count) += map_value;
	return (1);
}


int set_figure(t_map *map, int i, int j, int *intersection)
{
	int count;
	int ptr_j;
	int x;
	int y;

	y = 0;
	count = 0;
	*intersection = 0;
	ptr_j = j;
	while (i < map->ver_size && y < map->f_ver)
	{
		x = 0;
		j = ptr_j;
		while (x < map->f_width && j < map->hor_size)
		{
			if (check_z(map->map[i][j], map->figure[y][x],intersection, &count) == -1)
				return (-1);
			j++;
			x++;
		}
		i++;
		y++;
	}
	return (count);
}


static int	change_values(t_map *map, int i, int j, int count)
{
	map->my_x = j;
	map->my_y = i;
	return (count);
}

void find_place(t_map *map)
{
	int i;
	int j;
	int count;
	int current;
	int intersection;

	current = 1000000;
	i = 0;
	while (i < map->ver_size)
	{
		j = 0;
		while (j < map->hor_size)
		{
			if (((i + map->f_ver - map->ver_shift - 1) < map->ver_size)
			&& (j + map->f_width - map->right_shift - 1 < map->hor_size))
			{
				count = set_figure(map, i, j, &intersection);
				if (count > 0 && intersection > 0 && count < current)
				{
					current = change_values(map, i, j, count);
				}

			}
			j++;
		}
		i++;
	}
}


int filler(t_map *map)
{
	char	*x;
	char	*y;

	while (1)
	{
		update_weight(map, 0, 1);
		find_place(map);
		x = ft_itoa(map->my_x);
		y = ft_itoa(map->my_y);
		if (!(x && y))
			return (free_all(-1, map));
		ft_printf("%s %s\n", y, x);
		free(x);
		free(y);
		if (map->my_x < 0 || map->my_y < 0)
			break ;
		if (!skip_strings(2))
			return (free_all(-1, map));
		clear_map(map);
		if (refresh_map(map, map->ver_size) == -1)
			return (-1);
		map->my_x = -1;
		map->my_x = -1;
	}
	return (free_all(0, map));

}


int main()
{
	t_map map;

	if (create_map(&map) == -1)
		return (-1);
//	print_map(&map);
	filler(&map);
	return (0);
}
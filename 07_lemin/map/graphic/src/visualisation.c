/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:02:20 by dmorar            #+#    #+#             */
/*   Updated: 2019/04/17 17:02:22 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	horizontal(t_lem *fo)
{
	int dy;
	int yi;
	int	d;
	int dx;

	dy = fo->y2 - fo->y1;
	dx = fo->x2 - fo->x1;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	d = 2 * dy - dx;
	while (fo->x1++ != fo->x2)
	{
		if (fo->x1 >= 0 && fo->y1 >= 0 && fo->y1 < WID && fo->x1 < WID)
			fo->img_data[fo->x1 + fo->y1 * WID] = fo->color;
		if (d > 0)
		{
			fo->y1 = fo->y1 + yi;
			d = d - 2 * dx;
		}
		d = d + 2 * dy;
	}
}

void	vertical(t_lem *fdf)
{
	int		dx;
	int		xi;
	int		dy;
	int		d;

	dx = fdf->x2 - fdf->x1;
	dy = fdf->y2 - fdf->y1;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	d = 2 * dx - dy;
	while (fdf->y1++ != fdf->y2)
	{
		if (fdf->x1 >= 0 && fdf->y1 >= 0 && fdf->y1 < WID && fdf->x1 < WID)
			fdf->img_data[fdf->x1 + fdf->y1 * WID] = 0;
		if (d > 0)
		{
			fdf->x1 = fdf->x1 + xi;
			d = d - 2 * dy;
		}
		d = d + 2 * dx;
	}
}


void	swapint(t_lem *fdf)
{
	int		buf;

	buf = fdf->x1;
	fdf->x1 = fdf->x2;
	fdf->x2 = buf;
	buf = fdf->y1;
	fdf->y1 = fdf->y2;
	fdf->y2 = buf;
}

void	bresenham(t_lem *fdf)
{
	if (abs(fdf->y2 - fdf->y1) < abs(fdf->x2 - fdf->x1))
	{
		if (fdf->x1 > fdf->x2)
		{
			swapint(fdf);
			horizontal(fdf);
		}
		else
			horizontal(fdf);
	}
	else
	{
		if (fdf->y1 > fdf->y2)
		{
			swapint(fdf);
			vertical(fdf);
		}
		else
			vertical(fdf);
	}
}

int		closemap(void *fo)
{
	(void)fo;
	exit(0);
}

void		rooms(t_lem *fo, int x, int y, int color)
{
	int radius;
	int x1;
	int y1;
	int err;

	radius = 5;
	x1 = -radius;
	y1 = 0;
	err = 2 - 2 * radius;
	fo->color = color;
	while (x1 <= 0)
	{
		fo->x1 = x + x1;
		fo->y1 = y + y1;
		fo->x2 = x - x1;
		fo->y2 = y + y1;
		horizontal(fo);
		fo->x1 = x + x1;
		fo->y1 = y - y1;
		fo->x2 = x - x1;
		fo->y2 = y - y1;
		horizontal(fo);
		radius = err;
		if(radius <= y1)
			err += ++y1 * 2 + 2;
		if(radius > x1 || err > y1)
			err += ++x1 * 2 + 1;
	}
}


void		justdraw(t_lem *fo, t_lst *lst)
{
	int color;
	t_lst *head;

	head = lst;
	while (lst != NULL)
    {
		if (lst->conn != NULL)
		{
			int i = 0;
			while (i < lst->sizeconn && lst->conn[i] != NULL)
			{
				fo->color = 0x0;
				fo->x1 = lst->corname_x * fo->scale;
				fo->x2 = lst->conn[i]->corname_x * fo->scale;
				fo->y1 = lst->corname_y * fo->scale;
				fo->y2 = lst->conn[i]->corname_y * fo->scale;
				bresenham(fo);
				i++;
			}
		}
        lst = lst->next;
    }
	lst = head;
	while (lst != NULL)
	{
		color = 0x9D7243;
		if (lst->end == 1)
			color = 0x0;  //green
		else if(lst->start == 1)
			color = 0xFFFFFF;  //red
		rooms(fo, lst->corname_x * fo->scale, lst->corname_y * fo->scale, color);
		lst = lst->next;
	}
}

int		key_release(int key, t_lem *fo)
{
	if (key == 49)
//	{
//		if (checkorder(fo->ara, fo->lenar) == 1 && fo->lenar == fo->len)
//		{
//			mlx_clear_window(fo->mlx_ptr, fo->win_ptr);
//			ft_bzero(fo->img_data, WID * WID * 4);
//			justdraw(fo, "OK");
//			ft_printf("OK\n");
//		}
//		else
//			make_vis_comands(fo);
//	}
	fo->img_data[0] = 0;
	if (key == 53)
		exit(0);
	return (0);
}

int		mouse_release(int button, int x, int y, t_lem *fo)
{
	(void)x;
	(void)y;
	if (button == 5)
		fo->scale += 5;
	if (button == 4)
		if (fo->scale - 5 > 0)
			fo->scale = fo->scale - 5;
	mlx_clear_window(fo->mlx_ptr, fo->win_ptr);
	ft_bzero(fo->img_data, WID * WID * 4);
	return (1);
}

void		visualit(t_lem *fo, t_lst *lst)
{
	int		x;

	x = -1;
	fo->mlx_ptr = mlx_init();
	fo->win_ptr = mlx_new_window(fo->mlx_ptr, WID, WID, "LEM-IN");
	fo->img_ptr = mlx_new_image(fo->mlx_ptr, WID, WID);
	fo->img_data = (int*)mlx_get_data_addr(fo->img_ptr, &fo->bpp,
										   &fo->line_size, &fo->endian);
	while (++x < WID * WID)
		fo->img_data[x] = 0x4A6A10;
	fo->scale = 50;
	justdraw(fo, lst);
	mlx_put_image_to_window(fo->mlx_ptr, fo->win_ptr, fo->img_ptr, 0, 0);
	mlx_hook(fo->win_ptr, 2, 0, key_release, fo);
	if(mlx_mouse_hook(fo->win_ptr, mouse_release, fo) == 1)
		justdraw(fo, lst);
	mlx_hook(fo->win_ptr, 17, 0, closemap, lst);
	mlx_loop(fo->mlx_ptr);
}


//# include "libft.h"
//# include <sys/types.h>
//# include <sys/stat.h>
//# include <fcntl.h>
//# include "mlx.h"
//# define WID 1300
//
//typedef struct		s_lem
//{
//	int             num_ants;
//	int             line;
//	int             check_start;
//	int             check_end;
//	char            *command;
//	void		*mlx_ptr;
//	void		*win_ptr;
//	void		*img_ptr;
//	int			*img_data;
//	int			bpp;
//	int			line_size;
//	int			endian;
//	int x1;
//	int x2;
//	int y1;
//	int y2;
//	int color;
//	int scale;
//}					t_lem;

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:10:53 by tmann             #+#    #+#             */
/*   Updated: 2019/04/21 16:03:42 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "mlx.h"
# define WID 1300

typedef struct		s_lem
{
    int             num_ants;
    int             line;
	int             check_start;
	int             check_end;
	char            *command;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*img_data;
	int			bpp;
	int			line_size;
	int			endian;
	int x1;
	int x2;
	int y1;
	int y2;
	int color;
	int scale;
}					t_lem;

typedef struct		s_lst
{
	int             is_first;
	char            *name_s;
	int             corname_x;
	int             corname_y;
	int             start;
	int             end;
	int             ant;
	int             sizeconn;
	struct s_lst	**conn;
	struct s_lst	*next;
}					t_lst;

t_lem				*scan_param(t_lem *po, t_lst *lst);
void				ft_struct_zero(t_lem *po);
void				ft_lst_zero(t_lst *lst);
t_lst				*creat_list(void);
void				readparam(char *line, t_lem *po, t_lst *lst);
void				val_param(char *str, t_lem *po, t_lst *lst, t_lst *head);
void				check_line2(t_lem *po, t_lst *lst, char *str);
void				check_line3(t_lem *po, t_lst *lst, char *str, char **arr);
void				re_write(t_lst *lst);
void				check_start_end(t_lst *lst, int cs, int ce);
void				check_double_line_conn(t_lst *lst);
int					count_2d_len(char **arr);
int					count_otr_len(char *str);
void				check_double_name(t_lst *lst);
void				check_double_cor(t_lst *lst);
void				check_conn(t_lst *lst, t_lst *head);
void		visualit(t_lem *fo, t_lst *lst);

#endif
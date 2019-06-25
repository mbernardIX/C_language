/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:50:03 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"

typedef struct		s_lem
{
	int				num_ants;
	int				line;
	int				check_start;
	int				check_end;
	int				val_start;
	int				val_end;
	char			*command;
	int				min_way;
	int				bfs_count;
	int				size_con_end;
	int				size_con_start;
	struct s_lst	**here;
	int				count_way;
	struct s_lst	**ways;
	int				run_num_ants;
}					t_lem;

typedef struct		s_lst
{
	int				ant;
	int				green;
	int				is_first;
	char			*name_s;
	int				corname_x;
	int				corname_y;
	int				visited;
	int				start;
	int				end;
	int				sizeconn;
	struct s_lst	*parent;
	struct s_lst	**conn;
	struct s_lst	*next;
	struct s_lst	**par;
	int				sizepar;
	struct s_lst	*go;
	struct s_lst	*quick;
	int				bfs_lvl;
	int				dead_end;
	struct s_lst	**output;
	int				sizeoutput;
	int				alone;
	int				len_way;
	int				i;
	int				is_linked_with_start;
}					t_lst;

typedef	struct		s_queue
{
	struct s_lst	*name;
	struct s_queue	*next;
}					t_queue;

t_lem				*scan_param(t_lem *po, t_lst *lst);
void				ft_struct_zero(t_lem *po);
void				ft_lst_zero(t_lst *lst);
t_lst				*creat_list(void);
void				readparam(char *line, t_lem *po, t_lst *lst);
void				val_param(char *str, t_lem *po, t_lst *lst, t_lst *head);
void				check_line2(t_lem *po, t_lst *lst, char *str);
void				check_line3(t_lem *po, t_lst *lst, char *str, char **arr);
void				re_write(t_lst *lst);
void				check_double_line_conn(t_lst *lst);
int					count_2d_len(char **arr);
int					count_otr_len(char *str);
void				check_conn(t_lst *lst, t_lst *head);
t_lst				*ft_sort_list(t_lst *lst);
void				check_double_param(t_lst *lst, char *str);
void				*creat_queue(void);
void				ft_zero_queue(t_queue *qu);
t_queue				*ft_add_first_in_queue(t_queue *head,
						t_queue *qu, t_lst *lst);
t_queue				*ft_add_in_queue(t_queue *qu, t_lst *lst);
t_queue				*ft_delete_out_queue(t_queue *qu);
void				ft_bfs(t_lst *lst, t_lem *po);
void				*creat_way(void);
void				creat_ways(t_lst *lst, t_lem *po, t_lst *head);
void				creat_quick_way(t_lst *lst);
t_lst				*check_quick(int i, t_lst *tmp);
t_lst				*for_func_quick(int i, t_lst *tmp);
void				del_dead_end(t_lst *lst, int check);
void				start_end(t_lst *lst, t_lem *po);
t_lem				*sort_way(t_lem *po);
void				try_write_par(t_lst *lst);
int					is_or_not(t_lst *lst1, t_lst *lst2);
void				run_ways_from_end(t_lst *lst, t_lem *po,
						int i, int size_way);
void				re_output(t_lst *lst);
void				try_write_par(t_lst *lst);
void				create_par(t_lst *lst);
void				create_output(t_lst *lst);
void				ants_go_output(t_lem *po, t_lst *hl, int i, t_lst *end);
int					check_double_output(t_lst *p, t_lst *lst);
int					check_double_op(t_lst *lst);
int					check_par(t_lst *lst, int i, int check);
void				del_brother(t_lst *lst, char *brother);
int					check_par_dead_end(t_lst *lst, t_lst *par, int i, int res);
void				kill_cross(t_lst *lst);
t_lem				*creat_arr_ways(t_lem *po, t_lst *lst);
t_lem				*create_arr_ants(t_lem *po);
t_lem				*creat_way_for_ants(t_lst *lst, t_lem *po);
int					is_all_ants_in_end(t_lem *po);
void				count_ants_for_ways(t_lem *po, int num_ants);
void				create_ants_here(t_lem *po, int j, int i, int p);
void				ft_final();

#endif

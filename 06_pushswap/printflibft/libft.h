/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:55:00 by dspider-          #+#    #+#             */
/*   Updated: 2019/03/01 15:14:12 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_isprint(int c);
int				ft_isascii(int c);
int				ft_isalnum(int c);
int				ft_isdigit(int c);
int				ft_isalpha(int c);

int				ft_atoi(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strstr(const char *str1, const char *str2);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strcat(char *s, const char *q);
char			*ft_strncat(char *s, const char *q, size_t n);
char			*ft_strncpy(char *dest, const char *str, size_t n);
size_t			ft_strlcat(char *str1, const char *str2, size_t n);
char			*ft_strcpy(char *dest, const char *str);
char			*ft_strdup(const char *s);
size_t			ft_strlen(const char *s);
void			ft_strdel(char *as);

void			*ft_memset(void *b, int c, size_t l);
void			ft_bzero(void *b, size_t n);
void			*ft_memcpy(void *b, const void *c, size_t n);
void			*ft_memccpy(void *b, const void *s, int c, size_t n);
void			*ft_memmove(void *b, const void *src, size_t n);
void			*ft_memchr(const void *b, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

void			*ft_memalloc(size_t n);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t n);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t n);
char			*ft_strjoin(char *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			*ft_itoa(long n);
char			*ft_itoa_base(unsigned long n, int base, int t);

void			ft_putchar(char c);
void			ft_putchar_n(char c, int n);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int				ft_sqrt(int nb);
int				ft_is_prime(int nb);
int				ft_fibonacci(int index);
int				ft_count_if(char **tab, int (*f)(char*));
void			ft_print_params(int ac, char **av);
void			ft_sort_params(int ac, char **av);
void			ft_swap_char(char *s, char *d);
long			max(long a, long b);
long			min(long a, long b);
void			ft_bit(char *str, int *a, int j);
char			*rev_str(char *str, long len);

void			calc_strings(char *str, char *dest);

#endif
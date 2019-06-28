/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:23:29 by ygarrot           #+#    #+#             */
/*   Updated: 2019/05/16 13:06:29 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 300
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define WHITE "\x1b[37m"
# define RESET "\x1b[0m"

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <limits.h>
# include <wctype.h>
# include <stdarg.h>
# include <stdbool.h>
# include <wchar.h>
# include <limits.h>
# include <sys/ioctl.h>
# include "ft_printf.h"
# include "get_next_line.h"
# include "ft_btree.h"

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

char			**ft_init_double_tab(int size, int size2);
char			**ft_strnsplit(const char *str, char c, int row);
char			**ft_strsplit(char const *s, char c);
char			**ft_strmsplit(char const *s, char *c);
char			*ft_imaxtoabase(intmax_t value, int base);
char			*ft_implode(char *glue, const char *str, const char *str2);
char			*ft_itoa(int n);
char			*ft_itoabase(int value, int base);

char			*ft_strcat(char *dest, const char *src);
char			*ft_strchr(const char *s, int c);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strdup(const char *src);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_str_tabjoin(char const **s2);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmap2(char *s, char (*f)(char*));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *dest, const char *src, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strndup(char *todup, size_t siz);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *s1, const char *s2, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
int				ft_strrlento(char *str, char lim);
int				ft_charchr(char c, char *str);
int				ft_mcharchr(char *c, char *str);

char			*ft_uimaxtoabase(uintmax_t value, int base);
int				**ft_init_char_tab(int size, int size2);
int				**ft_initdbl_int_tab(size_t size1, size_t size2);
int				*ft_init_int_tab(int size);
int				ft_abs(int value);
int				ft_atoi(const char *str);
int				ft_atoi_base(const char *str, int base);

int				ft_uint_isin(unsigned int tofind, unsigned int *tab, int size);
int				ft_int_isin(int tofind, int *tab, int size);
int				ft_isalnum(int c);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isbase(int c, int base);
int				ft_isdigit(int c);
int				ft_isin(char c, char *str);
int				ft_ismax(int i, int i2);
int				ft_ismin(int i, int i2);
int				ft_isprint(int c);

int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_occiter(char *str, int base, int (*f)(int, int));
int				ft_search_char(char *str, char c, int end);
int				ft_str_isdigit(char *str);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strisin(char *tofind, char *str);
int				ft_strisin_tab(char *str, char **tab, int option);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_tablen(char **tab);
int				ft_tolower(int c);
int				ft_toupper(int c);

size_t			ft_sizeof_tab(char **tab);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str1);
size_t			ft_strnlen(const char *str1, size_t maxsize);

t_list			*ft_lstnew(void const *content, size_t content_size);
t_list			*ft_lstnewc(void const *content, size_t content_size);
void			ft_lstdelone(t_list	**alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *n);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstiter_s(t_list *lst, void *env, void (*f)(t_list *elem, void *env));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstpushfront(void *content, size_t content_size, t_list *b);
void			ft_lstpushback(t_list **left, t_list *right);
void			ft_lstfree(void *s, size_t t);
t_list			*ft_lstremoveif(t_list **begin, int (*cmp)(void *c, size_t t),
		void (*del)(void *, size_t));
t_list			*ft_lstreverse(t_list **begin);
t_list			*ft_lstsort(t_list *lst, int (*cmp)(void *, void *));
t_list			*ft_lstat(t_list *begin, size_t t);
void			ft_lstvoid(void *content, size_t t);
size_t			ft_lstsize(t_list *lst);
char			*ft_lsttostr(t_list *lst);
int				ft_lstpushsort(t_list **l, t_list *n, int (*c)(void *, void*));
void			ft_lstfusion(t_list **l, t_list *r, int (*c)(void *, void *),
		void (*del)(void*, size_t));

void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_realloc(void *str, size_t size);
void			ft_bzero(void *s, size_t n);
void			ft_capitalize(char *str);
void			ft_free_dblechar_tab(char **tab);
void			ft_free_dblint_tab(int **tab, int size);

void			ft_memdel(void **ap);
void			ft_print_chartab(char **tab, int fd);
void			ft_print_dbl_inttab(int **tab, size_t size1, size_t size2);
void			ft_print_inttab(int *tab, int size);
void			ft_putchar(char c);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr_recc(int nbr);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_strclr(char *s);
void			ft_strdel(char **as);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_strswap(char *str, char *str2);

char			**ft_strtabdup(char **tabl);
char			*ft_strdupto(char *str, char to);
int				ft_indexmin(int *tabl, size_t len);
double			ft_sqrt(double n);
int				ft_gotmod(size_t nb, int i);
int				ft_writenchar(char c, int n);
int				ft_strlenin(char *str, char *lim);
int				ft_strlento(char *str, char c);
int				ft_strlento_rev(char *str, int size, char *lim);
int				ft_strnocc(char *str, char c, int n);
int				ft_max(int n, int m);
int				ft_min(int n, int m);
int				ft_divideby(int nb, int div);
int				ft_insert(char **str, char *in, size_t to, size_t size);
int				ft_addtofd(char *str, int fd);
void			ft_strrev(char *str);
void			ft_replace(char *str, char *n);
int				ft_strinstr(char *str, char *pattern);
int				ft_strprefix(char *pref, char *str);
void			ft_intswap(int *i, int *j);
int				ft_power(int nb, int pow);
int				ft_dblstr_add(char ***t, char *str);
int				ft_cpy(char *filefrom, char *fileto);

int				ft_lenchar_r(char *str, int pos);
int				ft_lenchar_l(char *str, int pos);
int				ft_isin_unicode(char *str, char *pattern);

int				is_directory(int fd);
int				is_directory_str(char *name);
int				is_regular_file(int fd);
int				ft_swap_int(int num);
int				ft_getopt(int ac, char *av[], const char *optst, int *nb);
int				ft_getoptvalue(int ac, char *av[],
								const char *optst, char **opts);
int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_exit(char *str, int code);

double			ft_std(double *array, int len);
double			ft_mean(double *array, int len);

t_list	*ft_lstfilter(t_list *lst, void *struc, t_list *(*f)(t_list *elem, void *struc));
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajo < jajo@student.42gyeongsan.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:55:05 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/24 21:00:21 by jajo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

# define MAX_SIZE 1025

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_point {
	int		width;
	int		height;
	int		value;
	char	direction;
}	t_point;

typedef struct s_field {
	t_point	*line;
	int		line_num;
	int		height;
	struct s_field *next;
}	t_field;

char	*ft_itoa(int c);
int		ft_atoi_one(const char c);
int		ft_atoi(const char *str);

int		ft_issign(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isspace(int c);
int		ft_isrgb(int c);

char	*get_next_line(int fd);

char	**ft_split(char const *s, char c);
char	**ft_split_str(char *str, char *charset);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
t_point	*ft_realloc(t_point *memblock, int memblock_size, int result_size);


void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

int		ft_lstadd_back(t_field **lst, t_field *new);
void	ft_lstadd_front(t_field **lst, t_field *new);
void	ft_lstclear(t_field **lst);
void	ft_lstdel_node(t_field **lst, t_field *prev, t_field *cur);
t_field	*ft_lstfind_node(t_field *lst, int height);
t_field	*ft_lstlast(t_field *lst);
t_field *ft_lstnew_field(int height, char *str);
t_point	*ft_lstnew_point(int height, char *str);
int		ft_lstsize(t_field *lst);




#endif

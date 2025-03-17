/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:56:55 by srussame          #+#    #+#             */
/*   Updated: 2024/11/05 08:26:26 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *nptr);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putchar_fd(char c, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// ft_printf function

int		ft_printf(const char *str, ...);
int		ft_putchar_count(char c, int *count);
int		ft_putstr_count(char *str, int *count);
int		ft_putnbr_count(int num, int *count);
int		ft_putuint_count(unsigned int num, int *count);
int		ft_putaddress_count(void *ptr, int *count);
int		ft_puthex_small_count(unsigned int num, int *count);
int		ft_puthex_big_count(unsigned int num, int *count);

// get_next_line funct

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

typedef struct s_gnl_data
{
	int		cl_ret;
	char	*return_line;
	char	*read_buffer;

}				t_gnl_data;

typedef struct s_check_leftover_data
{
	size_t	old_l;
	size_t	new_l;
	char	*new_leftover;
}				t_check_leftover_data;

typedef struct s_goread_data
{
	long long	read_ret;
	size_t		checkline_ret;
	char		*readcat;
}				t_goread_data;

typedef struct s_buffjoin_data
{
	size_t	old_len;
	size_t	new_len;
	char	*new_dest;
}				t_buffjoin_data;

typedef struct s_putleft_data
{
	size_t	new_len;
	size_t	new_i;
}				t_putleft_data;

char	*get_next_line(int fd);
int		check_leftover(char **leftover, t_gnl_data *gnl);
size_t	check_newline(char *buffer);
int		put_leftover(t_goread_data *gr, char **leftover,
			t_gnl_data *gnl);

#endif

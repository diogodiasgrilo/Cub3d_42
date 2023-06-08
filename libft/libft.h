/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:44:30 by diogpere          #+#    #+#             */
/*   Updated: 2023/05/05 19:08:00 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define HEX_UPPER "0123456789ABCDEF"
# define HEX_LOWER "0123456789abcdef"

int					ft_printf(const char *str, ...);
void				ft_putstr(char *s, long int *counter);
void				ft_putchar(char c, long int *counter);
void				ft_putnbr(long int n, long int *counter);
void				ft_hex_printer(unsigned long long int n, int gate,
						long int *counter, int up_down);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
int					ft_tidy(char *buffer);
int					ft_strlen(const char *str);
void				ft_fixer_mover(char *buffer, int gate, int i);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000

# endif

char				*ft_itoa(int n);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isalnum(char c);
char				*ft_strdup(char *src);
int					ft_lstsize(t_list *lst);
int					ft_atoi(const char *str);
int					ft_strlen(const char *s);
void				ft_bzero(char *s, int n);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(void *content);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
int					ft_strlen_gnl(const char *str);
void				*ft_calloc(int count, int size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				**ft_split(char const *s, char c);
int					ft_countchar(const char *s, int c);
void				*ft_memset(void *b, int c, int len);
char				*ft_strjoin_gnl(char *s1, char *s2);
char				*ft_strenlarge(char *str1, char *str2);
void				*ft_memchr(const void *s, int c, int n);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstadd_front(t_list **lst, t_list *new);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
void				*ft_memcpy(void *dst, const void *src, int n);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
int					ft_memcmp(const void *s1, const void *s2, int n);
void				*ft_memmove(void *dst, const void *src, int len);
int					ft_strncmp(const char *s1, const char *s2, int n);
int					ft_strlcat(char *dst, const char *src, int dstsize);
int					ft_strlcat(char *dst, const char *src, int dstsize);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_substr(char const *s, unsigned int start, int len);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
unsigned long int	ft_strlcpy(char *dst, const char *src,
						unsigned long int dstsize);
char				*ft_strnstr(const char *haystack, const char *needle,
						int len);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

#endif

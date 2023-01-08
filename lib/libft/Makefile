SRC		:=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_toupper.c ft_tolower.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
		ft_memcmp.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_printf_c.c ft_printf_d.c ft_printf_p.c ft_printf_s.c ft_printf_u.c \
		ft_uitoa.c ft_printf_x.c ft_printf.c ft_write_hex.c \
		get_next_line.c get_next_line_utils.c

OBJ		:=	$(SRC:.c=.o)

SRC_B	:=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ_B	:=	$(SRC_B:.c=.o)

CFLAGS	:=	-Wall -Wextra -Werror

NAME	:=	libft.a

ifdef W_B
	OBJECTS = $(OBJ) $(OBJ_B)
else
	OBJECTS = $(OBJ)
endif

all:		$(NAME)
	
$(NAME):	$(OBJECTS)
	ar -rc $@ $^

bonus:
	make W_B=1 all

*.o:		*.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJ_B)

fclean:		clean
	@rm -f $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re
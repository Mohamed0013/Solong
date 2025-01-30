NAME = so_long

SRCDIR = libft

SRCS =  so_long.c  ft_check_map.c  ft_free.c ft_init_map.c \
        ft_rendergame.c   ft_render_map.c \
		perror_fct.c \
    	get_next_line.c ft_utils.c \
        
LIBFTSRCS = $(wildcard $(SRCDIR)/*.c)

OBJS = ${SRCS:.c=.o}
OBJS2 = ${LIBFTSRCS:.c=.o}
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g3


all: ${NAME}

$(NAME): $(OBJS) $(OBJS2)
		$(CC) ${CFLAGS} $(OBJS) $(OBJS2) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) 
 
clean:
	@${RM} ${OBJS} ${OBJS2}

fclean:
	@${RM} ${NAME}
	@${RM} ${OBJS} ${OBJS2}

re: fclean all

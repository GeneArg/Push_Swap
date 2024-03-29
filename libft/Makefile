SRC =	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_isdigit.c \
		get_next_line.c

SRCS = $(addprefix $(SRCS_DIR), $(SRC))

OBJS = ${SRCS:.c=.o}

SRCS_DEBUG = $(addprefix d_, $(SRC))

OBJS_DEBUG = ${SRCS_DEBUG:.c=.o}

HEADER_DIR = ./

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

AR = ar

ARFLAGS = -rcs

all : ${NAME} Makefile #incase makefile changes.

${NAME} : ${OBJS}
	${AR} ${ARFLAGS} ${NAME} ${OBJS}

%.o : %.c libft.h #incase libft.h changes
	${CC} ${CFLAGS} -c $< -o $@

d_%.o : %.c
	${CC} ${CFLAGS} -g -c $< -o $@

debug : fclean ${OBJS_DEBUG}
	${AR} ${ARFLAGS} ${NAME} ${OBJS_DEBUG}

debugging : debug

bonus : ${OBJS_BONUS} #need to double check to not relink.
	${AR} ${ARFLAGS} ${NAME} ${OBJS_BONUS}

so :
	${CC} -shared -o libft.so ${OBJS}

sobonus :
	${CC} -shared -o libft.so ${OBJS_BONUS}

soclean : clean
	rem -f libft.so

clean :
	@for file in ${OBJS} ${OBJS_DEBUG} ${OBJS_BONUS}; do \
		if [ -f "$$file" ]; then \
			rm -f "$$file"; \
		fi \
	done

fclean : clean
	@if [ -f "${NAME}" ]; then \
		rm -f ${NAME}; \
	fi

re : fclean all

.PHONY : all clean fclean re debug debugging so bonus

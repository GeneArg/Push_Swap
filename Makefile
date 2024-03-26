# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eagranat <eagranat@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 15:28:12 by eagranat          #+#    #+#              #
#    Updated: 2024/03/26 15:28:37 by eagranat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := push_swap
CC        := cc
FLAGS    := -Wall -Wextra -Werror
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      check.c \
                          case_ba.c \
                          rotate_push.c \
                          sort.c \
                          libft/ft_strnstr.c \
                          libft/ft_isdigit.c \
                          libft/ft_putstr_fd.c \
                          libft/ft_strlcpy.c \
                          libft/ft_strlen.c \
                          libft/ft_memcmp.c \
                          libft/ft_putnbr_fd.c \
                          libft/ft_strchr.c \
                          libft/ft_striteri.c \
                          libft/ft_bzero.c \
                          libft/ft_strjoin.c \
                          libft/ft_memcpy.c \
                          libft/ft_putendl_fd.c \
                          libft/ft_toupper.c \
                          libft/ft_split.c \
                          libft/ft_strrchr.c \
                          libft/ft_memchr.c \
                          libft/ft_putchar_fd.c \
                          libft/ft_memset.c \
                          libft/ft_substr.c \
                          libft/ft_strncmp.c \
                          libft/ft_strmapi.c \
                          libft/ft_strtrim.c \
                          libft/ft_memmove.c \
                          libft/ft_strlcat.c \
                          libft/ft_calloc.c \
                          libft/ft_strdup.c \
                          libft/ft_atoi.c \
                          libft/ft_itoa.c \
                          libft/ft_tolower.c \
                          stack_utils.c \
                          rotate_type.c \
                          free.c \
                          error_print.c \
                          push_swap.c \
                          reverse_rotate.c \
                          swap.c \
                          parse.c \
                          check_error.c \
                          push_rrr.c \
                          case_ab.c \

OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re



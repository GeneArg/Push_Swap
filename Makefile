# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eagranat <eagranat@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 15:28:12 by eagranat          #+#    #+#              #
#    Updated: 2024/03/28 14:04:58 by eagranat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft/
OBJ_DIR = obj/
BONUS = checker
SRC_DIR = srcs/
HDR_FILES = $(wildcard srcs/push_swap/*.h)

SRC_1 = srcs/push_swap/push_swap.c \

SRC_2 =	srcs/push_swap/case_ab.c \
		srcs/push_swap/case_ba.c \
		srcs/push_swap/check_error.c \
		srcs/push_swap/check.c \
		srcs/push_swap/error_print.c \
		srcs/push_swap/free.c \
		srcs/push_swap/parse.c \
		srcs/push_swap/push_rrr.c \
		srcs/push_swap/reverse_rotate.c \
		srcs/push_swap/rotate_push.c \
		srcs/push_swap/rotate_type.c \
		srcs/push_swap/sort.c \
		srcs/push_swap/stack_utils.c \
		srcs/push_swap/swap.c \
		srcs/push_swap/process.c \

BONUS_SRC = srcs/checker/checker.c \

OBJ_1 = ${SRC_1:.c=.o}
OBJ_2 = ${SRC_2:.c=.o}

BONUS_OBJ =${BONUS_SRC:.c=.o}

INCLUDE = -L ./libft -lft

.c.o:
	${CC} -c $< -o ${<:.c=.o}

CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m



${NAME}: ${OBJ_1} ${OBJ_2} ${HDR_FILES}
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${OBJ_1} ${OBJ_2} -o ${NAME} ${INCLUDE}
	@echo "$(GREEN)$(NAME) created[0m ✔️"

${BONUS}: ${OBJ_2} ${BONUS_OBJ}
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${BONUS_OBJ} ${OBJ_2} -o ${BONUS} ${INCLUDE}
	@echo "$(GREEN)$(BONUS) created[0m ✔️"

all: ${NAME} ${BONUS}

bonus: ${BONUS}

clean:
	@for file in ${OBJ_1} ${OBJ_2} ${BONUS_OBJ} ${NAME} ${BONUS}; do \
		if [ -f "$$file" ]; then \
			rm -f "$$file"; \
		fi \
	done
	@cd $(LIBFTDIR) && $(MAKE) clean
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean: clean
	${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re: clean all

.PHONY: all clean fclean re bonus

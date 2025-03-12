SRC_FILE	= main.c

SRC_OBJ		= ${addprefix ${SRC_DIR}, ${SRC_FILE}}

OBJ			= ${addprefix ${OBJ_DIR}, ${SRC_FILE:.c=.o}}

#Directories

SRC_DIR		= src/

OBJ_DIR		= obj/

LFT_DIR		= libft/

MLX_DIR		= minilibx-linux/

#lib

LIBFT	= ${LFT_DIR}libft.a

MLX		= ${MLX_DIR}libmlx_Linux.a

#name

NAME	= so_long

CC		= cc

FLAG	= -Wall -Wextra -Werror

LINK	= -L${MLX_DIR} -lmlx_Linux -L${LFT_DIR} -lft -lX11 -lXext
all: ${NAME}

${NAME}: ${OBJ} ${LIBFT} ${MLX}
	${CC} ${FLAG} ${OBJ} ${LINK} -o ${NAME}

${OBJ_DIR}:
	mkdir -p ${OBJ_DIR}

${OBJ_DIR}%.o: ${SRC_DIR}%.c | ${OBJ_DIR}
	${CC} ${FLAG} -c -I./include/ -I./${LFT_DIR}include/ -I./${MLX_DIR} $< -o $@

${LIBFT}:
	make -C ${LFT_DIR}

${MLX}:
	make -C ${MLX_DIR}

clean:
	rm -f ${OBJ}
	make fclean -C ${LFT_DIR}
	make clean -C ${MLX_DIR}

fclean: clean
	rm -f ${NAME}

re: fclean all


.PHONY: clean fclean re all
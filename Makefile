MAIN_SRC_FILE	=	main.c \

SO_LONG_SRC_FILE		=	create_so_long_1.c \
							create_window_1.c \

IMAGE_HANDLE_SRC_FILE	=	image_utils_1.c \
							image_utils_2.c \
							img_scaling_1.c \
							img_scaling_2.c \
							get_texture_list_1.c \
							get_texture_1.c

MAP_PROCESS_SRC_FILE	=	map_read_1.c \
							map_check_1.c \
							map_check_2.c \
							map_data_1.c \
							map_data_2.c \
							map_data_3.c \
							map_check_path_1.c \
							map_check_path_2.c \
							map_link_img_1.c \
							map_paint_1.c \

UTILS_SRC_FILE			=	so_long_utils_1.c \
							so_long_utils_2.c \

HOOKS_SRC_FILE			=	exit_hooks.c \
							control_hooks.c \

SRC		=	${addprefix ${SRC_DIR}${MAIN_SRC_DIR}, ${MAIN_SRC_FILE}} \
			${addprefix ${SRC_DIR}${IMAGE_HANDLE_SRC_DIR}, ${IMAGE_HANDLE_SRC_FILE}} \
			${addprefix ${SRC_DIR}${MAP_PROCESS_SRC_DIR}, ${MAP_PROCESS_SRC_FILE}} \
			${addprefix ${SRC_DIR}${UTILS_SRC_DIR}, ${UTILS_SRC_FILE}} \
			${addprefix ${SRC_DIR}${HOOKS_SRC_DIR}, ${HOOKS_SRC_FILE}} \
			${addprefix ${SRC_DIR}${SO_LONG_SRC_DIR}, ${SO_LONG_SRC_FILE}}

OBJ			= 	${patsubst ${SRC_DIR}%.c, ${OBJ_DIR}%.o, ${SRC}}

#Directories

SO_LONG_SRC_DIR = solong/

HOOKS_SRC_DIR = hooks/

MAIN_SRC_DIR = main/

IMAGE_HANDLE_SRC_DIR = image_handle/

MAP_PROCESS_SRC_DIR = map_process/

UTILS_SRC_DIR = utils/

SRC_DIR		= src/

OBJ_DIR		= obj/

LFT_DIR		= libft/

MLX_DIR		= minilibx-linux/

#lib

LIBFT	= ${LFT_DIR}libft.a

MLX		= ${MLX_DIR}libmlx_Darwin.a

#name

NAME	= so_long

CC		= cc

FLAG	= -Wall -Wextra -Werror

LINK	= -L${MLX_DIR} -lmlx_Darwin -L${LFT_DIR} -lft -lX11 -lXext -lm
all: ${NAME}

${NAME}: ${OBJ} ${LIBFT} ${MLX}
	@${CC} ${FLAG} ${OBJ} ${LINK} -o ${NAME}
	@echo "built ${NAME} complete"

${OBJ_DIR}:
	@mkdir -p ${OBJ_DIR}

${OBJ_DIR}%.o: ${SRC_DIR}%.c | ${OBJ_DIR}
	@mkdir -p $(dir $@)
	@${CC} ${FLAG} -c -I./include/ -I./${LFT_DIR}include/ -I./${MLX_DIR} $< -o $@

${LIBFT}:
	@echo "Building LIBFT"
	@make -C ${LFT_DIR}
	@echo "Built LIBFT SUCCESS"

${MLX}:
	@echo "Building MLX"
	@make -C ${MLX_DIR}
	@echo "Built MLX SUCCESS"

clean:
	@rm -f ${OBJ}
	@make fclean -C ${LFT_DIR}
	@make clean -C ${MLX_DIR}
	@echo "Cleaned Project."

fclean: clean
	@rm -f ${NAME}
	@echo "remove executable ${NAME}"

re: fclean all


.PHONY: clean fclean re all

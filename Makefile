# **************************************************************************** #
#                                  VARIABLES                                   #
# **************************************************************************** #

# --- Source Files and Directories ---
MAIN_SRC_FILE	=	main.c \

SO_LONG_SRC_FILE		=	create_so_long_1.c \
							create_window_1.c \
							player_move_1.c \
							paint_map_to_window_1.c \

IMAGE_HANDLE_SRC_FILE	=	image_utils_1.c \
							image_utils_2.c \
							img_scaling_1.c \
							img_scaling_2.c \
							get_texture_list_1.c \
							get_texture_1.c

MAP_PROCESS_SRC_FILE	=	map_read_1.c \
							map_read_2.c \
							map_check_1.c \
							map_check_2.c \
							map_data_1.c \
							map_data_2.c \
							map_data_3.c \
							map_check_path_1.c \
							map_check_path_2.c \
							map_check_path_3.c \
							map_link_img_1.c \

UTILS_SRC_FILE			=	so_long_utils_1.c \
							so_long_utils_2.c \
							so_long_utils_3.c \

HOOKS_SRC_FILE			=	exit_hooks.c \
							control_hooks.c \
							expose_hook.c\

SRC		=	${addprefix ${SRC_DIR}${MAIN_SRC_DIR}, ${MAIN_SRC_FILE}} \
			${addprefix ${SRC_DIR}${IMAGE_HANDLE_SRC_DIR}, ${IMAGE_HANDLE_SRC_FILE}} \
			${addprefix ${SRC_DIR}${MAP_PROCESS_SRC_DIR}, ${MAP_PROCESS_SRC_FILE}} \
			${addprefix ${SRC_DIR}${UTILS_SRC_DIR}, ${UTILS_SRC_FILE}} \
			${addprefix ${SRC_DIR}${HOOKS_SRC_DIR}, ${HOOKS_SRC_FILE}} \
			${addprefix ${SRC_DIR}${SO_LONG_SRC_DIR}, ${SO_LONG_SRC_FILE}}

OBJ			= 	${patsubst ${SRC_DIR}%.c, ${OBJ_DIR}%.o, ${SRC}}

DEP			= ${OBJ:.o=.d}

HEADERS = $(wildcard include/*.h)

# Directories
SO_LONG_SRC_DIR = solong/
HOOKS_SRC_DIR = hooks/
MAIN_SRC_DIR = main/
IMAGE_HANDLE_SRC_DIR = image_handle/
MAP_PROCESS_SRC_DIR = map_process/
UTILS_SRC_DIR = utils/
SRC_DIR		= src/
OBJ_DIR		= obj/
LFT_DIR		= libft/

# --- MiniLibX Settings ---
# Local (fallback) MiniLibX directory
LOCAL_MLX_DIR = minilibx-linux/

# Check for a system-installed MiniLibX library (search in /usr/local/lib and /usr/lib)
MLX_SYS_LIB_LOCAL = $(wildcard /usr/local/lib/libmlx*.a)
MLX_SYS_LIB       = $(wildcard /usr/lib/libmlx*.a)

ifeq ($(strip $(MLX_SYS_LIB_LOCAL)),)
    ifeq ($(strip $(MLX_SYS_LIB)),)
        $(info No system-installed MiniLibX library found. Using local MiniLibX copy.)
        MLX_LIB_PATH   = $(LOCAL_MLX_DIR)
        MLX_LIB        = $(LOCAL_MLX_DIR)libmlx_Linux.a
        MLX_LINK_FLAGS = -L$(LOCAL_MLX_DIR) -lmlx_Linux
    else
        $(info Found MiniLibX library in /usr/lib.)
        MLX_LIB_PATH   = /usr/lib
        MLX_LIB        = $(firstword $(wildcard /usr/lib/libmlx*.a))
        MLX_LINK_FLAGS = -L/usr/lib -lmlx_Linux
    endif
else
    $(info Found MiniLibX library in /usr/local/lib.)
    MLX_LIB_PATH   = /usr/local/lib
    MLX_LIB        = $(firstword $(wildcard /usr/local/lib/libmlx*.a))
    MLX_LINK_FLAGS = -L/usr/local/lib -lmlx_Linux
endif

# Check for MiniLibX header (search in /usr/local/include and /usr/include)
MLX_SYS_INC_LOCAL = $(wildcard /usr/local/include/mlx.h)
MLX_SYS_INC       = $(wildcard /usr/include/mlx.h)

ifeq ($(strip $(MLX_SYS_INC_LOCAL)),)
    ifeq ($(strip $(MLX_SYS_INC)),)
        $(info No system-installed MiniLibX header found. Using local MiniLibX copy.)
        MLX_INCLUDE_FLAG = -I$(LOCAL_MLX_DIR)
    else
        $(info Found MiniLibX header in /usr/include.)
        MLX_INCLUDE_FLAG = -I/usr/include
    endif
else
    $(info Found MiniLibX header in /usr/local/include.)
    MLX_INCLUDE_FLAG = -I/usr/local/include
endif

# --- Other Libraries and Executable ---
LIBFT	= ${LFT_DIR}libft.a
NAME	= so_long

# **************************************************************************** #
#                          COMPILER FLAGS & LINKING                            #
# **************************************************************************** #
CC		= cc
FLAG	= -Wall -Wextra -Werror -I./include/ -I./${LFT_DIR}include/ $(MLX_INCLUDE_FLAG) -MMD -MP 
LINK	= $(MLX_LINK_FLAGS) -L${LFT_DIR} -lft -lX11 -lXext -lm

# **************************************************************************** #
#                                  RULES                                     #
# **************************************************************************** #

all: ${NAME}

${NAME}: ${OBJ} ${LIBFT} ${MLX} Makefile
	@$(CC) $(FLAG) $(OBJ) $(LINK) -o ${NAME}
	@echo "built ${NAME} complete"

${OBJ_DIR}:
	@mkdir -p ${OBJ_DIR}

${OBJ_DIR}%.o: ${SRC_DIR}%.c ${HEADERS} | ${OBJ_DIR}
	@mkdir -p $(dir $@)
	@$(CC) $(FLAG) -c $< -o $@

${LIBFT}:
	@echo "Building LIBFT"
	@make -C ${LFT_DIR}
	@echo "Built LIBFT SUCCESS"

# --- MiniLibX Build Rule ---
# Use the local build only if system MLX was not found.
ifeq ($(MLX_LIB_PATH),$(LOCAL_MLX_DIR))
    # Check if local MiniLibX directory exists.
    ifneq ($(wildcard $(LOCAL_MLX_DIR)),)
$(MLX):
	@echo "Building local MiniLibX..."
	@make -C $(LOCAL_MLX_DIR)
	@echo "Built MiniLibX SUCCESS"
    else
$(MLX):
	@echo "Error: Local MiniLibX directory '$(LOCAL_MLX_DIR)' not found!" >&2
	@echo "Please clone MiniLibX from https://github.com/42Paris/minilibx-linux into '$(LOCAL_MLX_DIR)'." >&2
    endif
else
$(MLX):
	@echo "Using system-installed MiniLibX."
endif

-include $(DEP)

clean:
	@rm -f ${DEP}
	@rm -f ${OBJ}
	@make fclean -C ${LFT_DIR}
	@if [ -d "$(LOCAL_MLX_DIR)" ]; then make clean -C $(LOCAL_MLX_DIR); fi
	@echo "Cleaned Project."

fclean: clean
	@rm -f ${NAME}
	@echo "Removed executable ${NAME}"

re: fclean all

.PHONY: clean fclean re all


###COMMANDS
CC	=		cc
RM	=		rm -rf
MKDIR	=	mkdir -p
#

###EXECUTABLE
NAME		=	pipex
NAME_BONUS	=	pipex_bonus
#

###DIRECTORIES
SRC_DIR			=	src
OBJ_DIR			=	obj
INC_DIR			=	include

SRC_BONUS_DIR	=	src_bonus

LIBFT_DIR		=	libft
LIBFT_INC_DIR	=	libft
#

###LIBRARIES
LIBFT_A = libft.a
LIBFT_A := $(addprefix $(LIBFT_DIR)/, $(LIBFT_A))

LIBFT_HEADER = libft
#

###SOURCES

SRCS = $(addprefix utils/,				\
				$(addprefix get_next_line/,		\
					get_next_line.c				\
					get_next_line_utils.c		\
					get_next_line_close.c		\
				)								\
				$(addprefix string/,			\
					ft_strcpy.c					\
				)								\
				$(addprefix exec/,				\
					ft_execvpe.c				\
				)								\
				$(addprefix path/,				\
					path_utils.c				\
					get_command_path.c			\
				)								\
				$(addprefix structs/,			\
					command.c					\
					input.c						\
					output.c					\
				)								\
				$(addprefix parsing/,			\
					parsing.c					\
				)								\
				$(addprefix heredoc/,			\
					heredoc.c					\
					heredoc_pipe.c				\
					heredoc_file.c				\
				)								\
				$(addprefix files/,				\
					safe_close.c				\
				)								\
			)									\
			$(addprefix core/,					\
				childs.c						\
				files.c							\
				core.c							\
			)									\
		main.c

SRCS_BONUS = $(addprefix utils/,				\
				$(addprefix get_next_line/,		\
					get_next_line.c				\
					get_next_line_utils.c		\
					get_next_line_close.c		\
				)								\
				$(addprefix string/,			\
					ft_strcpy.c					\
				)								\
				$(addprefix exec/,				\
					ft_execvpe.c				\
				)								\
				$(addprefix path/,				\
					path_utils.c				\
					get_command_path.c			\
				)								\
				$(addprefix structs/,			\
					command.c					\
					input.c						\
					output.c					\
				)								\
				$(addprefix parsing/,			\
					parsing.c					\
				)								\
				$(addprefix heredoc/,			\
					heredoc.c					\
					heredoc_pipe.c				\
					heredoc_file.c				\
				)								\
				$(addprefix files/,				\
					safe_close.c				\
				)								\
			)									\
			$(addprefix core/,					\
				childs.c						\
				files.c							\
				core.c							\
			)									\
		main.c

SRCS := $(SRCS:%=$(SRC_DIR)/%)

SRCS_BONUS := $(SRCS_BONUS:%=$(SRC_BONUS_DIR)/%)
#

###OBJECTS
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

OBJS_BONUS = $(SRCS_BONUS:%.c=$(OBJ_DIR)/%.o)
#

###FLAGS
CFLAGS = -Wall -Wextra -Werror -g
CFLAGS += -I$(LIBFT_INC_DIR)
CFLAGS += -I$(INC_DIR)

LDFLAGS	=	-L${LIBFT_DIR} -l:libft.a
#

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(LIBFT_A) $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)
	$(info CREATED $@)

$(NAME_BONUS): $(LIBFT_A) $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) $(LDFLAGS) -o $(NAME_BONUS)
	$(info CREATED $@)

$(OBJ_DIR)/%.o: %.c
	$(MKDIR) $(@D)
	$(CC) -c $(CFLAGS) -o $@ $<
	$(info CREATED $@)

clean:
	$(MAKE) clean -sC $(LIBFT_DIR)
	$(RM) $(OBJ_DIR) $(OBJ_BONUS_DIR)

fclean: clean
	$(MAKE) fclean -sC $(LIBFT_DIR)
	$(RM) $(NAME) $(NAME_BONUS)

re:
	$(MAKE) fclean
	$(MAKE) all

$(LIBFT_A):
	$(MAKE) -sC $(LIBFT_DIR)

.PHONY: all clean fclean re bonus

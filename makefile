###COMMANDS
CC	=		cc
RM	=		rm -rf
MKDIR	=	mkdir -p
#

###EXECUTABLE
NAME	=	pipex
#

###DIRECTORIES
SRC_DIR			=	src
OBJ_DIR			=	obj
INC_DIR			=	include

LIBFT_DIR		=	libft
LIBFT_INC_DIR	=	libft
#

###LIBRARIES
LIBFT_A = libft.a
LIBFT_A := $(addprefix $(LIBFT_DIR)/, $(LIBFT_A))

LIBFT_HEADER = libft
#

###SOURCES
SRCS = main.c
SRCS := $(SRCS:%=$(SRC_DIR)/%)
#

###OBJECTS
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
#

###FLAGS
CFLAGS = -Wall -Wextra -Werror -v
CFLAGS += -I$(INC_DIR)
CFLAGS += -I$(LIBFT_INC_DIR)

LDFLAGS	=	-L${LIBFT_DIR} -l:libft.a
#

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)
	$(info CREATED $@)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(MKDIR) $(@D)
	$(CC) -c $(CFLAGS) -o $@ $<
	$(info CREATED $@)

clean:
	$(MAKE) clean -sC $(LIBFT_DIR)
	$(RM) $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -sC $(LIBFT_DIR)
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

$(LIBFT_A):
	$(MAKE) -sC $(LIBFT_DIR)

.PHONY: all clean fclean re

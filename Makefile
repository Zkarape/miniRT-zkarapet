NAME	= miniRT

HEAD	= includes

SRCDIR	= srcs

OBJS_DIR = obj

LIB		= lib

FILES	=	$(wildcard $(SRCDIR)/*.c)

OBJS			=	$(patsubst $(SRCDIR)/%.c, $(OBJS_DIR)/%.o, $(FILES))
MK	=	mkdir -p
CC		= cc

RM		= rm -rf


CFLAGS	= -Wall -Wextra -Werror -I $(HEAD) -D NUM_THREADS=$(NUM_THREADS)

FLAGS = -L $(LIB)/libft -lft

MACOS_MACRO = -D MACOS

LINUX_MACRO = -D LINUX


MACOS_FLAGS	= -L $(LIB)/minilibx_opengl -lmlx -framework OpenGL -framework AppKit 

LINUX_FLAGS = -L $(LIB)/minilibx-linux -lmlx -lm -lX11 -lXext -lpthread

CLEAN_RULE = 

COMPILE_LIBS = 

UNAME := $(shell uname)

ifeq ($(UNAME),Darwin)
	NUM_THREADS = $(shell sysctl -n hw.ncpu)
	CFLAGS += $(MACOS_MACRO)
	FLAGS += $(MACOS_FLAGS)
	CLEAN_RULE += $(MAKE) -C $(LIB)/minilibx_opengl
endif
ifeq ($(UNAME),Linux)
	NUM_THREADS = $(shell nproc --all)
	CFLAGS += $(LINUX_MACRO)
	FLAGS += $(LINUX_FLAGS)
	COMPILE_LIBS += $(MAKE) -C $(LIB)/minilibx-linux
endif

.DEFAULT_GOAL = all

$(OBJS_DIR): $(SRCDIR)
	$(MK) $@

$(OBJS_DIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

${NAME}:	${OBJS}
			$(COMPILE_LIBS)
			$(MAKE) -C $(LIB)/libft
			${CC} ${CFLAGS} $(OBJS) $(FLAGS) -o ${NAME} 

all:		$(OBJS_DIR) ${NAME}

clean:
			$(MAKE) clean -C $(LIB)/libft
			${RM} ${OBJS_DIR}

fclean:		clean
			$(COMPILE_LIBS) $(CLEAN_RULE)
			$(MAKE) fclean -C $(LIB)/libft
			${RM} ${NAME}

re:			fclean all

PHONY:		all clean fclean re
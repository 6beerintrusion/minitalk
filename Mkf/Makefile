NAME			=	client

NAME_BONUS		=	server

LIBFT			=	libft.a

CLIENT			=	.

SERVER			=	.

DIR_OBJS		=	objs

SRCS_NAMES		=	client.c

SRCS_NAMES_B	=	server.c

OBJS_NAMES		=	${SRCS_NAMES:.c=.o}

OBJS_NAMES_B	=	${SRCS_NAMES_B:.c=.o}

SRCS			=	$(addprefix $(CLIENT)/,$(SRCS_NAMES))

SRCS_B			=	$(addprefix $(SERVER)/,$(SRCS_NAMES_B))

OBJS			=	$(addprefix $(DIR_OBJS)/,$(OBJS_NAMES))

OBJS_B			=	$(addprefix $(DIR_OBJS)/,$(OBJS_NAMES_B))

HEAD			=	-Iincludes/ -Ilibft

CC				=	cc

CFLAGS			=	-g3 -Wall -Werror -Wextra

# MAKEFLAGS		=	--no-print-directory

all				:	${NAME}

$(NAME): $(OBJS)
	make -C libft
	mv libft/libft.a .
	$(CC) $(CFLAGS) $(OBJS) ${LIBFT} -o $(NAME)
	@echo "\033[34;5mclient\033[0m"

$(OBJS) : $(DIR_OBJS)/%.o : $(CLIENT)/%.c | $(DIR_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)


server: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_B)
	make -C libft
	mv libft/libft.a .
	$(CC) $(CFLAGS) $(SRCS_B) ${HEAD} ${LIBFT} -o $(NAME_BONUS)
	@echo "\033[31;5mserver\033[0m"

$(OBJS_B) : $(DIR_OBJS)/%.o : $(SERVER)/%.c | $(DIR_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)

clean:
	make clean -C libft
	rm -rf ${DIR_OBJS}
	rm -rf ${OBJS}

fclean:	clean
	make fclean -C libft
	rm -rf ${LIBFT}
	rm -rf ${NAME}
	rm -rf ${NAME_BONUS}

re:	fclean all

stop:
	rm ${NAME}

.PHONY:	all clean fclean re bonus
# .SILENT:
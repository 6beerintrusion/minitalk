NAME			=	client
NAME_BONUS		=	server
LIBFT			=	libft.a
DIR_OBJS		=	objs
SRCS_NAMES		=	client.c
SRCS_NAMES_B	=	server.c
OBJS_NAMES		=	${SRCS_NAMES:.c=.o}
OBJS_NAMES_B	=	${SRCS_NAMES_B:.c=.o}
SRCS			=	$(SRCS_NAMES)
SRCS_B			=	$(SRCS_NAMES_B)
OBJS			=	$(addprefix $(DIR_OBJS)/,$(OBJS_NAMES))
OBJS_B			=	$(addprefix $(DIR_OBJS)/,$(OBJS_NAMES_B))
HEAD			=	-Iincludes/ -Ilibft
CC				=	cc
CFLAGS			=	-g3 -Wall -Werror -Wextra

CLIENT_FLAGS	=	-DCOMPILE_CLIENT
SERVER_FLAGS	=	-DCOMPILE_SERVER

all				:	${NAME} ${NAME_BONUS}

$(NAME): $(OBJS)
	make -C libft
	mv libft/$(LIBFT) .
	$(CC) $(CFLAGS) $(CLIENT_FLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "\033[34;5mclient\033[0m"

$(OBJS) : $(DIR_OBJS)/%.o : %.c | $(DIR_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_FLAGS) -c $< -o $@ $(HEAD)

$(NAME_BONUS): $(OBJS_B)
	make -C libft
	mv libft/$(LIBFT) .
	$(CC) $(CFLAGS) $(SERVER_FLAGS) $(OBJS_B) $(LIBFT) -o $(NAME_BONUS)
	@echo "\033[31;5mserver\033[0m"

$(OBJS_B) : $(DIR_OBJS)/%.o : %.c | $(DIR_OBJS)
	$(CC) $(CFLAGS) $(SERVER_FLAGS) -c $< -o $@ $(HEAD)

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)

clean:
	make clean -C libft
	rm -rf $(DIR_OBJS)

fclean:	clean
	make fclean -C libft
	rm -f $(LIBFT)
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re:	fclean all

.PHONY:	all clean fclean re

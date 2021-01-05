NAME = libftprintf.a

SRCS = ft_printf.c \
		handle_d.c \
		handle_p.c \
		handle_s.c \
		handle_x.c \
		handle_u.c \
		utils.c

FLAGS = -Wall -Werror -Wextra -I./libft/
OBJS = $(SRCS:.c=.o)
NORME = norminette

LIBS = ./libft/libft.a
#LDLIBS = $(addprefix -l, $(LIBS))
CC = @clang -c -g $(FLAGS)


all : $(NAME)
	@echo "Your $(NAME) is ready."

complib:
	@make -C libft/

message:
	@echo "krr Your $(NAME) files are compiling..."

$(NAME): complib $(SRCS) $(OBJS)
	@echo "Your $(NAME) files are compiling..."
	@cp ./libft/libft.a $(NAME)
	@$(CC) $(SRCS) -I$(LIBS)
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)

norme:
	@$(NORME) $(SRCS) $(BONUS)

test:
	@clang -c -g $(FLAGS) main.c -I.libftprintf.a -o a.out

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)
	@make clean -C libft/
	@echo "[ $(NAME) ] Your .o files have been deleted."

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft/
	@echo "Your $(NAME) have been deleted."

re: fclean all

.PHONY: all clean re norme bonus normebonus

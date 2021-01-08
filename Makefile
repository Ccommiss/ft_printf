NAME = libftprintf.a

SRCS = ft_printf.c \
		parser.c \
		handle_d.c \
		handle_p.c \
		handle_s.c \
		handle_x.c \
		handle_u.c \
		handle_c.c \
		handle_n.c \
		display.c \
		utils.c

FLAGS = -Wall -Werror -Wextra -I./libft/
OBJS = $(SRCS:.c=.o)
NORME = norminette
LIBS = ./libft/libft.a
CC = @clang -c -g $(FLAGS)


# This is a minimal set of ANSI/VT100 color codes
_END=$'\x1b[0m
_BOLD=$'\x1b[1m
_UNDER=$'\x1b[4m
_REV=$'\x1b[7m

# Colors
_GREY=$'\x1b[30m
_RED=$'\x1b[31m
_GREEN=$'\x1b[32m
_YELLOW=$'\x1b[33m
_BLUE=$'\x1b[34m
_PURPLE=$'\x1b[35m
_CYAN=$'\x1b[36m
_WHITE=$'\x1b[37m

all : $(NAME)
	@printf "%-30s $(_GREEN)%s$(_END)\n" [$(NAME)] "Your $(NAME) is ready."
	@printf "\360\237\246\204  \360\200\242\204  \U0001F615 \x0\x01\xF6\x15   \360\201\260\242   \x1f615 \U1F615 \U23F0 By ccommiss, with \U2764 \125\053\061\106\064\070\103"
complib:
	@make -C libft/

message:
	@printf "%-30s %s\n" [$(NAME)] "krr Your $(NAME) files are compiling..."

$(NAME): $(SRCS) $(OBJS)
	@make -C libft/
	@printf "%-30s $(_GREEN)%s\n" [$(NAME)]  "Your $(NAME) files are compiling..."
	@cp ./libft/libft.a $(NAME)
	$(CC) $(SRCS) -I$(LIBS)
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)

norme:
	@$(NORME) $(SRCS) $(BONUS)

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)
	@make clean -C libft/
	@printf "%-30s %s\n" [$(NAME)] "Your .o files have been deleted."

cleanup:
	@make fclean -C libft/
	@rm -f $(OBJS) $(OBJS_BONUS)
	@printf "%-30s %s\n" [$(NAME)] "Your .o files have been deleted."

fclean:
	@make fclean -C libft/
	@rm -f $(OBJS) $(OBJS_BONUS)
	@printf "%-30s %s\n" [$(NAME)] "Your .o files have been deleted."
	@rm -f $(NAME)
	@printf "%-30s %s\n" [$(NAME)] "Your $(NAME) have been deleted."


re: fclean all

.PHONY: all clean re norme bonus normebonus

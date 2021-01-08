NAME = libftprintf.a

SRCS = ft_printf.c \
		parser.c \
		handle_d.c \
		handle_p.c \
		handle_s.c \
		handle_x.c \
		handle_u.c \
		handle_c.c \
		display.c \
		utils.c

BONUS = handle_n_bonus.c \

FLAGS = -Wall -Werror -Wextra -I./libft/
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(BONUS:.c=.o)
NORME = norminette
LIBS = ./libft/libft.a
CC = @clang -c -g $(FLAGS)
WP = `pwd | sed 's!.*/!!'`


# This is a minimal set of ANSI/VT100 color codes
_END=$'\x1b[0m
_BOLD=$'\x1b[1m
_UNDER=$'\x1b[4m
_REV=$'\x1b[7m
_LIGHT=$'\x1b[2m

# Colors
_GREY=$'\x1b[30m
_RED=$'\x1b[31m
_GREEN=$'\x1b[32m
_YELLOW=$'\x1b[33m
_BLUE=$'\x1b[34m
_PURPLE=$'\x1b[35m
_CYAN=$'\x1b[36m
_WHITE=$'\x1b[37m
_LBLUE=$'\x1b[94m
_ORANGE=$'\x1b[38;5;215m
_PINK=$'\x1b[38;5;95m
_GRASS=$'\x1b[38;5;119m
_UNICORN= $'\360\237\246\204 
_UNIC=$'🦄
_LETTER = $'💌 
LC_ALL=C.UTF-8

all : $(NAME)
	@printf "$(_BOLD)$(_PINK)%-30s$(_END) $(_GRASS)$(_BOLD)%s$(_END)\n" [$(WP)] "✅	Your $(NAME) is ready."
	@echo "\n $(_UNIC)	By $(_PURPLE)$(_BOLD)ccommiss$(_END), with $(_LETTER)"

$(NAME): $(SRCS) $(OBJS)
	@make -C libft/
	@printf "$(_BOLD)$(_PINK)%-30s$(_END) $(_WHITE)$(_LIGHT)%s\n$(_END)" [$(WP)]  "Your $(WP) files are compiling..."
	@cp ./libft/libft.a $(NAME)
	$(CC) $(SRCS) -I$(LIBS)
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)

bonus : all $(BONUS) $(OBJS_BONUS)
	@ar -rc $(NAME) $(OBJS_BONUS)
	@ranlib $(NAME)
	@printf "$(_BOLD)$(_PINK)\n%-30s$(_END) $(_BOLD)$(_GRASS)%s$(_END)\n" [$(WP)] " 🏆	Your $(NAME) is ready, bonuses included."

norme:
	@$(NORME) $(SRCS) $(BONUS)

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)
	@make clean -C libft/
	@printf "$(_BOLD)$(_PINK)%-30s$(_END) $(_LIGHT)%s\n$(_END)" [$(WP)] "Your .o files have been deleted."

cleanup:
	@make fclean -C libft/
	@rm -f $(OBJS) $(OBJS_BONUS)
	@printf "$(_BOLD)$(_PINK)%-30s$(_END) %s\n" [$(WP)] "Your .o files have been deleted."

fclean:
	@make fclean -C libft/
	@rm -f $(OBJS) $(OBJS_BONUS)
	@printf "$(_BOLD)$(_PINK)%-30s$(_END) $(_LIGHT)%s\n$(_END)" [$(WP)] "Your .o files have been deleted."
	@rm -f $(NAME)
	@printf "$(_BOLD)$(_PINK)%-30s$(_END) $(_BOLD)%s$(_END)\n" [$(WP)] "🗑️	Your $(NAME) have been deleted."



re: fclean all

.PHONY: all clean re norme bonus normebonus

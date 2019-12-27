NAME = ft_select

CC = gcc

CFLAGS = -Wall -Wextra -Werror

_lCYAN = \x1b[96m
_lYELLOW = \x1b[93m
_lGREEN = \x1b[92m
_lBLUE = \x1b[94m
_RED = \x1b[31m
_BOLD = \x1b[1m
_END = \x1b[0m

LIB = libft/libft.a

FILE = select_color.c\
		select.c\
		select_generateur.c\
		select_generateur2.c\
		select_historique.c\
		select_keybord.c\
		select_main.c\
		select_signal.c\

OFILE =	select_color.o\
		select.o\
		select_generateur.o\
		select_generateur2.o\
		select_historique.o\
		select_keybord.o\
		select_main.o\
		select_signal.o\
		
all: $(NAME)

$(NAME): $(OFILE) select.h
		@make -C libft
		@$(CC) -o $(NAME) -ltermcap $(LIB) $(OFILE)
		@echo "\n$(_lGREEN) -> The Programme was completed <-\n$(_END)"

clean:
	@make -C libft clean
	@rm -rf $(OFILE)
	@echo "$(_lGREEN) > make clean $(_END)"

fclean : clean
	@make -C libft fclean
	@rm -rf $(NAME)
	@echo "$(_lGREEN) > make fclean $(_END)"

re: fclean all
	@echo "$(_lGREEN) > make re $(_END)"

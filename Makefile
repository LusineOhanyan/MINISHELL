NAME		=	minishell
CC			=	cc
SRCS		=	$(wildcard ./src/*.c)
OBJS		=	$(patsubst ./src/%.c, ./$(OBJECTFOLDER)/%.o, $(SRCS))
CFLAGS		=	-I./include  -Wall -Wextra -Werror
LINKER		=	-L ./Lusine/lib -lreadline
RM			=	rm -rf
LIBFT       =   libs/libft/libft.a
PRINTF      =   libs/printf/libftprintf.a

LIBFT_DIR  = libs/libft
PRINTF_DIR = libs/printf
OBJECTFOLDER = temp
MKDIR = mkdir
HEADER = $(wildcard ./include/*)

./$(OBJECTFOLDER)/%.o: ./src/%.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME):$(OBJECTFOLDER) $(LIBFT) $(PRINTF) $(OBJS) 
	$(CC) $(CFLAGS) $(LINKER) $(OBJS) $(LIBFT) $(PRINTF)  -o $(NAME)

$(OBJECTFOLDER) :
	mkdir $(OBJECTFOLDER)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

clean:
	make clean -C $(PRINTF_DIR)
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS) 
	$(RM) $(OBJECTFOLDER) 

fclean: clean
	make fclean -C $(PRINTF_DIR)
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re:fclean all

.PHONY: all clean bonus fclean re


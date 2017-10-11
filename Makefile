NAME		= fdf

RM			= rm -rf
CC			= gcc
MKDIR		= mkdir -p
MAKE		= make
CFLAGS		= -Wall -Werror -Wextra
CFLAGS		+= -I includes -I src/libft/includes
LDFLAGS		+= -L src/libft/ -lft -L src/libmlx/ -lmlx -framework OpenGL -framework AppKit

DLIBFT	:= src/libft
LIBFT	:= src/libft/libft.a
DLIBMLX	:= src/libmlx
LIBMLX	:= src/libmlx/libmlx.a

DSRC	= ./src/src
DOBJF	= ./src/obj
DINC	= ./src/inc

SRC		:= $(shell ls -1 $(DSRC) | grep .c$$)
OBJF	:= $(SRC:.c=.o)
OBJF	:= $(addprefix $(DOBJF)/, $(OBJF))


all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(DLIBFT)
	@echo "\033[32m Compiled libft.a\033[0m"

$(LIBMLX):
	@$(MAKE) -C $(DLIBMLX)
	@echo "\033[32m Compiled liblmlx.a\033[0m"

$(DOBJF)/%.o: $(DSRC)/%.c $(DINC)
	@$(MKDIR) $(DOBJF)
	@$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(LIBFT) $(LIBMLX) $(OBJF)
	@$(CC) $(LDFLAGS) -o $@ $^
	@echo "\033[32m Compiled Executable\033[0m"

clean:
	@$(RM) $(OBJF)
	@$(MAKE) -C $(DLIBFT) clean
	@$(MAKE) -C $(DLIBMLX) clean
	@echo "\033[31m -- Object Files Removed --\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(DOBJF)
	@$(MAKE) -C $(DLIBFT) fclean
	@echo "\033[31m   -- libft.a Removed --\033[0m"
	@echo "\033[31m   -- $(NAME) Removed --\033[0m"

re: fclean all

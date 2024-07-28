NAME		= libftprintf.a

LIBFT		= ./libft/libft.a
LIBFTDIR	= ./libft

SRC			= ./functions

PRINTF_SRCS	= ft_printf.c ft_itoa_base.c print_char.c \
				print_str.c put_pointer.c \
				print_unsigned.c print_hexa.c \
				print_capital_hexa.c

OBJS		= $(PRINTF_SRCS:.c=.o)

CC			= cc
AR			= ar rcs
RM			= rm -rf
CFLAG		= -Wall -Wextra -Werror
CP			= cp

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJS)
				$(CP) $(LIBFT) $(NAME)
				@$(AR) $(NAME) $(OBJS)

$(LIBFT):	$(LIBFTDIR)
				@$(MAKE) -C $(LIBFTDIR)
							
%.o:		$(SRC)/%.c
				@$(CC) $(CFLAGS) -c $< -o $@
clean:
			@$(MAKE) clean -C $(LIBFTDIR)
			@$(RM) $(OBJS)

fclean:		clean
				@$(MAKE) fclean -C $(LIBFTDIR)
				@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

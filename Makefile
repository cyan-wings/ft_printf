###Header variables

HDR_DIR 	= includes/
HDR			= ft_printf.h
HDRS		= $(addprefix $(HDR_DIR), $(HDR))


###Source code variables

SRCDIR			= srcs/
SRC				= 	\
					putchar		\
					putstr		\
					strlen		\
					putnbr_base	\
					putaddr		\
					in			\
					printf		\

SRC_P			= $(addprefix ft_, $(SRC))
SRC_F			= $(addsuffix .c, $(SRC_P))
SRCS			= $(addprefix $(SRCDIR), $(SRC_F))

OBJDIR			= objs/
OBJ_F			= $(subst .c,.o,$(SRC_F))
OBJS			= $(addprefix $(OBJDIR), $(OBJ_F))


###Bonus variables

SRCDIR_BONUS	= bonus/
SRC_BONUS		=	\
					memset			\
					calloc			\
					atowp			\
					in				\
					strlen			\
					nbrlen_base		\
					printchar		\
					printstring		\
					printnbr		\
					buffer_utils	\
					format_addr		\
					format			\
					printf_bonus	\

SRC_BONUS_P		= $(addprefix ft_, $(SRC_BONUS))
SRC_BONUS_F		= $(addsuffix .c, $(SRC_BONUS_P))
SRCS_BONUS		= $(addprefix $(SRCDIR_BONUS), $(SRC_BONUS_F)


OBJDIR_BONUS	= objs_bonus/
OBJ_BONUS_F		= $(subst .c,.o,$(SRC_BONUS_F))
OBJS_BONUS		= $(addprefix $(OBJDIR_BONUS), $(OBJ_BONUS_F))

###Other variables

NAME			= libftprintf.a
IFLAGS			= -I $(HDRS)
CC				= cc
CW				= -Wall -Wextra -Werror
CFLAGS 			= $(CW) -c
AR				= ar -rcs
RM				= rm -rf

TESTNAME		= tests/main
TESTNAME_BONUS	= tests/bonus

###Rules

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(OBJS_BONUS) 
	$(AR) $(NAME) $(OBJS_BONUS)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) $(IFLAGS) $< -o $@

$(OBJDIR_BONUS)%.o: $(SRCDIR_BONUS)%.c
	$(CC) $(CFLAGS) $(IFLAGS) $< -o $@

main: re
	$(CC) $(CW) $(TESTNAME).c -o $(TESTNAME) -L. $(NAME)
	clear
	./$(TESTNAME)

b: rebonus
	$(CC) $(CW) $(TESTNAME_BONUS).c -o $(TESTNAME_BONUS) -L. $(NAME)
	clear
	./$(TESTNAME_BONUS)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re


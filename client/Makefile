##
## EPITECH PROJECT, 2021
## Project_2021
## File description:
## Project makefile
##

DSRC	=	./src/

SRC_FILES	=	main.c							\
				client/client.c					\
				shell/shell_client_init.c		\
				shell/shell_stop.c				\
				shell/send_shell_command.c		\
				daemon/daemon_init.c			\
				daemon/daemon_start.c			\
				utility/find_newline.c			\
				utility/is_empty.c				\
				utility/str_to_upper.c			\
				utility/strconcat.c				\
				utility/logger.c				\
				utility/is_command.c			\
				utility/signal_init.c			\

SRC	=	$(addprefix $(DSRC), $(SRC_FILES))

OBJ	=	$(SRC:.c=.o)

NAME	=	my_troyan

CFLAGS	+= -Wall -Wextra -W $(INCLUDE) #-Werror
LD_FLAGS += -lmysocket -L../lib/socket

INCLUDE = -I./include -I../lib/socket/include

all:  $(NAME)

debug: CFLAGS += -g
debug: all

$(NAME): $(OBJ)
	make -C ../lib/socket
	@$(CC) -o $(NAME) $(OBJ) $(LD_FLAGS) && \
		$(ECHO) $(BOLD_T)$(GREEN_C)"\n[✔] COMPILED:" $(DEFAULT)$(LIGHT_GREEN) "$(NAME)\n"$(DEFAULT) || \
		$(ECHO) $(BOLD_T)$(RED_C)"[✘] "$(UNDLN_T)"BUILD FAILED:" $(LIGHT_RED) "$(NAME)\n"$(DEFAULT)

clean:
	rm -f  $(OBJ)
	@rm -f *.gcda
	@rm -f *.gcno

fclean:	clean
	rm -f $(NAME)

re:	fclean all

#tests_run:
#	gcc -o $(NAME) $(SRC_UT) -I./include -lcriterion --coverage && ./$(NAME)

.PHONY :        clean fclean re

ECHO	=	/bin/echo -e
DEFAULT	=	"\e[0m"
BOLD_T	=	"\e[1m"
DIM_T	=	"\e[2m"
UNDLN_T	=	"\e[4m"
BLACK_C	=	"\e[30m"
RED_C	=	"\e[31m"
GREEN_C	=	"\e[32m"
YELLO_C	=	"\e[33m"
BLUE_C	=	"\e[34m"
MAGEN_C	=	"\e[35m"
CYAN_C	=	"\e[36m"
WHITE_C	=	"\e[97m"
DEFAULT_C	=	"\e[39m"
LINE_RETURN	=	$(ECHO) ""

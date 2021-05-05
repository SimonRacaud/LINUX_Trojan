##
## EPITECH PROJECT, 2021
## Project_2021
## File description:
## Project makefile
##

DSRC	=	./src/

SRC_FILES	=	main.c							\
				app/client/client_connect.c		\
				app/client/client_disconnect.c	\
				app/app_process_fd.c			\
				app/app_start.c					\
				utility/find_newline.c			\
				utility/is_empty.c				\
				utility/str_to_upper.c			\
				utility/strconcat.c				\
				utility/logger.c				\
				utility/is_command.c			\
				utility/signal_init.c			\
				gui/gui_create.c				\
				gui/gui_destroy.c				\
				gui/gui_print.c					\
				gui/gui_prompt.c				\
				gui/gui_reset_cursor_pos.c		\
				gui/gui_event_resize.c			\

SRC	=	$(addprefix $(DSRC), $(SRC_FILES))

OBJ	=	$(SRC:.c=.o)

NAME	=	my_troyan_cli

CFLAGS	+= -Wall -Wextra -W $(INCLUDE) #-Werror
LD_FLAGS += -lncurses -lmysocket -L../lib/socket

INCLUDE = -I./include -I../lib/socket/include

all:  $(NAME)

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

debug: CFLAGS += -g
debug: re

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

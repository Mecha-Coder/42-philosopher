#==============================================================
# DECLARATION
#==============================================================

NAME = philo
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=thread

#==============================================================
# FILES
#==============================================================

SRCS =	$(wildcard ./check/*.c) \
		$(wildcard ./logic/*.c) \
		$(wildcard ./routine/*.c) \
		$(wildcard ./utils/*.c) \
		philo.c

OBJS = $(SRCS:.c=.o)

#==============================================================
# BUILD COMMAND
#==============================================================

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) -o $@ $^
	
%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME) 

re: fclean all

.PHONY: all bonus clean fclean re
#==============================================================
# DECLARATION
#==============================================================

NAME = philo_bonus
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=thread

#==============================================================
# FILES
#==============================================================

SRCS =	$(wildcard ./logic/*.c) \
		$(wildcard ./routine/*.c) \
		$(wildcard ./utils/*.c) \
		philo_bonus.c
		
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
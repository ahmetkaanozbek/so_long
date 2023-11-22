NAME = libft.a
CODEDIRS=. 
INCDIRS=. # can be list

SOURCES = $(foreach D,$(CODEDIRS),$(wildcard $(D)/*.c))

OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(AR) -r $@ $?

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS) $(BOBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
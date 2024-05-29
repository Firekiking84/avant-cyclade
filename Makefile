NAME =			Avant-cyclade

SRC =			src/main.c			\
			$(wildcard ./src/*/*.c)		\

OBJS =			$(SRC:.c=.o)

LIB_OBJS =		$(LIB_SRC:.c=.o)

INCLUDE =		-I./include

CC =			bcc

FLAGS =			-Wall -Wextra -g -ggdb

LDFLAGS =		-L./ -rdynamic

all:$(NAME)

$(NAME):$(OBJS)
			$(CC) $(OBJS) -O0 $(LDFLAGS) -o $(NAME)
.c.o:
			$(CC) $(FLAGS) -O0 $(INCLUDE) -c $< -o $@
ar:$(OBJS)
			ar rc $(NAME).a $(OBJS)
g:
			gdb --arg ./$(NAME)
clean:
			rm -f $(shell find ./ -name "*.o")
			rm -f $(shell find ./ -name "*~")
			rm -f $(shell find ./ -name "*.gcda")
			rm -f $(shell find ./ -name "*.gcno")
			rm -f $(shell find ./ -name "*#")
			rm -f $(shell find ./ -name "*#")
fclean: clean
			rm -f $(NAME)
re: fclean all

test: fclean
			cd test/vector_test/ ; make report
			cd test/draw/ ; make report

tree: fclean
			tree

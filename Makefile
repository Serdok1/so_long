CC = gcc
CFLAGS = -Wall -Wextra -I./minilibx

LDFLAGS = -L./minilibx -lmlx -framework OpenGL -framework AppKit

TARGET = so_long

SRCS = main.c
OBJS = $(SRCS:.c=.o)
LIBMLX = ./minilibx/libmlx.a

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $(LIBMLX) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean $(TARGET)

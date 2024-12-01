SRCS = strlib.c main.c my_dict_initializer.c dic_read.c dict_parser.c util.c int_to_str.c use_default_dict.c use_given_dict.c get_dict_value.c output.c 
OBJS = $(SRCS:%.c=%.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I .
TARGET = rush-02

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SRCS)

all: $(TARGET)

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(TARGET)

re: fclean all
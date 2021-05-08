CC	?= gcc
RM	= rm -f

CFLAGS	+= -ansi -pedantic -pedantic-errors -Wall -Werror -Wextra -fpic -Iinc
LDFLAGS	+= 

TARGET	= cas

SRCS	= main.c
OBJS	= $(addprefix src/, $(SRCS:.c=.o))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	$(RM) $(OBJS)
	$(RM) $(TARGET)

re: clean all

.PHONY: all clean clean re

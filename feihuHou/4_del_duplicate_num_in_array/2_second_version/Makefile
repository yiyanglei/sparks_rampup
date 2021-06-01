
CFLAGS 	:= -Wall -O2 -c
CFLAGS  += -I$(PWD)/include


CC 	:= $(CROSSCOMPILE)gcc
LD 	:= $(CROSSCOMPILE)ld

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c = .o)


all: $(OBJS)
	$(CC) -o del_duplicate_num_in_array $^

clean:
	rm -f del_duplicate_num_in_array
	rm -f $(OBJS)

%.o:%.c
	$(CC) $(CFLAGS) -o $@ $<

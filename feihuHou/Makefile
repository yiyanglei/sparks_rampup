SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c = .o)
CC = gcc
CCFLAGS = -g -Wall -O0

addbinary_feihuHou : $(OBJS)
	$(CC) -o $@ $< 

%.o : %.c
	$(CC) -o  $@ $^ $(CCFLAGS)

clean:
	rm *.o addbinary_feihuHou

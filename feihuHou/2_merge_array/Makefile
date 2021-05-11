SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c = .o)
CC = gcc
CCFLAGS = -g -Wall -O0

merge_array_feihuHou : $(OBJS)
	$(CC) -o $@ $< 

%.o : %.c
	$(CC) -o  $@ $^ $(CCFLAGS)

clean:
	rm *.o merge_array_feihuHou

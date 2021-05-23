
CFLAGS 	:= -Wall -O2 -c
CFLAGS  += -I$(PWD)/include


CC 	:= $(CROSSCOMPILE)gcc
LD 	:= $(CROSSCOMPILE)ld

OBJS := twosum_feihuHou.o hash.o

all: $(OBJS)
	$(CC) -o twosum_feihuHou $^

clean:
	rm -f twosum_feihuHou
	rm -f $(OBJS)

%.o:%.c
	$(CC) $(CFLAGS) -o $@ $<

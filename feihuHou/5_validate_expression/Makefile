CFLAGS 	:= -Wall -O2 -c
CFLAGS  += -I$(PWD)/include


CC 	:= $(CROSSCOMPILE)gcc
LD 	:= $(CROSSCOMPILE)ld

OBJS := $(wildcard *.c)
OBJS := $(patsubst %.c,%.o, $(OBJS))
DEP_FILES := $(patsubst %,.%.d, $(OBJS))
DEP_FILES := $(wildcard $(DEP_FILES))




all: $(OBJS)
	$(CC) -o validate_expression $^

ifneq ($(DEP_FILES),)
include $(DEP_FILES)
endif


%.o:%.c
	gcc $(CFLAGS) -c -o $@ $< -MD -MF .$@.d

clean:
	rm -f validate_expression
	rm -f *.o




.PHONY: clean



	

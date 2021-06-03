#ifndef STACK_H
#define STACK_H

#include "typedef.h"


typedef struct Stack_s{
	char *data;
	int32_t top;
	int32_t max_len;
}Stack_t;



void stack_print(Stack_t* p_stack);
Stack_t* stack_new(uint32_t max_len);
uint8_t stack_delete(Stack_t* p_stack);
void stack_clear(Stack_t* p_stack);
uint8_t stack_is_empty(Stack_t* p_stack);
uint8_t stack_is_full(Stack_t* p_stack);
uint8_t stack_top(Stack_t* p_stack, char* c);
uint8_t stack_push(Stack_t* p_stack, char c);
uint8_t stack_pop(Stack_t* p_stack, char* c);
int32_t stack_len(Stack_t* p_stack);


#endif

#include "./include/stack.h"
#include "./include/typedef.h"


#include "stdio.h"
#include "stdlib.h"
#include "string.h"


#define PRINT_FORMAT  printf



void stack_print(Stack_t* p_stack) {
	int32_t i;
	if (p_stack->top == -1) {
		PRINT_FORMAT("栈空！\n");
		return;
	}
	for (i = p_stack->top; i >= 0; i--) {
		PRINT_FORMAT("%4c", p_stack->data[i]);
	}
	PRINT_FORMAT("\n");
}


Stack_t* stack_new(uint32_t max_len) {
	Stack_t* p_stack = (Stack_t*)malloc(sizeof(Stack_t));
	if (NULL == p_stack) {
		return NULL;
	}
	p_stack->data = (char*)malloc(sizeof(char)* max_len);
	if (NULL == p_stack->data) {
		free(p_stack);
		return NULL;
	}
	p_stack->top = -1;	
	p_stack->max_len = max_len;
	return p_stack;
}

uint8_t stack_delete(Stack_t* p_stack) {
	if (NULL != p_stack->data) {
		free(p_stack->data);
	}else {
		return 0;
	}
	if (NULL != p_stack) {
		free(p_stack);
	}else {
		return 0;
	}
	return 1;
}


void stack_clear(Stack_t* p_stack) {
	p_stack->top = -1;	
}


uint8_t stack_is_empty(Stack_t* p_stack) {
	if (p_stack->top == -1) {
		return 1;
	}else {
		return 0;
	}
}

uint8_t stack_is_full(Stack_t* p_stack) {
	if (p_stack->top == p_stack->max_len - 1) {
		return 1;
	}else {
		return 0;
	}
}

uint8_t stack_top(Stack_t* p_stack, char* c) {
	if (p_stack->top == p_stack->max_len -1) {
		return 0;
	}else {
		*c = p_stack->data[p_stack->top];
		return 1;
	}
}

uint8_t stack_push(Stack_t* p_stack, char c) {
	if (p_stack->top == p_stack->max_len - 1) {
		PRINT_FORMAT("stack is full！\n");
		return 0;
	}else {
		p_stack->top++;
		p_stack->data[p_stack->top] = c;
		return 1;
	}
}


uint8_t stack_pop(Stack_t* p_stack, char* c) {
	if (p_stack->top == -1) {
		PRINT_FORMAT("stack is full！\n");
		return 0;
	}else {
		*c = p_stack->data[p_stack->top];
		p_stack->top--;
		return 1;
	}
}

int stack_len(Stack_t* p_stack) {
	return p_stack->top + 1;
}

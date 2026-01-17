#ifndef STACK_H 
#define STACK_H

#include <stddef.h>  // size_t

typedef struct Stack{
	void* data_;
	size_t elem_size_;
	size_t capacity_;
	size_t top_;
	size_t curr_size_;
} Stack;

// Inicializálás
int initStack(Stack *s, size_t elem_size, size_t capacity);

// Stack tetejére tesz egy elemet
int push(Stack *s, void* value);

// Stackből kivesz egy elemet (out_value-ba másolja)
int pop(Stack *s, void* out_value);

// Stack tetejének lekérése (nem veszi ki)
int top(Stack s, void* out_value);

// Tele van?
int isFull(Stack s);

// Üres?
int isEmpty(Stack s);

// Kiürítés
int setEmpty(Stack *s);

// Debug print, print_fn a konkrét típus kiírására
void printStack(Stack s, void (*print_fn)(void*));

#endif


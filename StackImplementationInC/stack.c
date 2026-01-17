#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "stack.h"

int initStack(Stack *s, size_t elem_size, size_t capacity){
    if (!s || elem_size == 0 || capacity == 0)
        return 0;

    s->capacity_ = capacity;
    s->elem_size_ = elem_size;
    s->curr_size_ = 0;
    s->data_ = malloc(elem_size * capacity);

    return s->data_ != NULL;
}

int isEmpty(Stack s){
    return s.curr_size_ == 0;
}

int isFull(Stack s){
    return s.curr_size_ == s.capacity_;
}

int push(Stack *s, void *value){
    if (!s || isFull(*s))
        return 0;

    void* target =
        (char*)s->data_ + s->curr_size_ * s->elem_size_;

    memcpy(target, value, s->elem_size_);
    s->curr_size_++;
    return 1;
}
int top(Stack s, void* out_value) {
    if (isEmpty(s))
        return 0;

    void* source =
        (char*)s.data_ + (s.curr_size_ - 1) * s.elem_size_;

    memcpy(out_value, source, s.elem_size_);
    return 1;
}

int pop(Stack *s, void* out_value){
    if (!s || isEmpty(*s))
        return 0;

    s->curr_size_--;

    void* source =
        (char*)s->data_ + s->curr_size_ * s->elem_size_;

    memcpy(out_value, source, s->elem_size_);
    return 1;
}

int setEmpty(Stack *s){
    if (!s)
        return 0;

    s->curr_size_ = 0;
    return 1;
}
void printStack(Stack s, void (*print_fn)(void*)) {
    printf("[ ");
    for (size_t i = 0; i < s.curr_size_; i++) {
        void* elem = (char*)s.data_ + i * s.elem_size_;
        print_fn(elem);
        printf(" ");
    }
    printf("]\n");
}

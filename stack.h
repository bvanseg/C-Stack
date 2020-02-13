/*
 * MIT License
 *
 * Copyright (c) 2020 Boston Vanseghi
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdbool.h>
#include "linkedlist.h"

typedef struct stack {
    LinkedList * list;
    int elementSize;
    int size;
} Stack;

Stack * create_stack(int elementSize);
void resize_stack(Stack * stack);

bool push_stack(Stack * stack, void * data);
void pushAll_stack(Stack * stack, int size, ...);
void pop_stack(Stack * stack);
void * peek_stack(Stack * stack);
void clear_stack(Stack * stack);

int size_stack(Stack * stack);
bool isEmpty_stack(Stack * stack);

void destroy_stack(Stack * stack);

#endif // STACK_H_INCLUDED

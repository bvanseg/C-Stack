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
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>
#include "stack.h"
#include "linkedlist.h"

Stack* create_stack(int elementSize) {
    Stack* stack = malloc(sizeof(Stack));

    if (stack != NULL) {
        stack->elementSize = elementSize;
        stack->list = create_linkedList(elementSize);
    }
    return stack;
}

bool push_stack(Stack* stack, void* value) {
    if (stack == NULL || stack->list == NULL)
        return false;

    addAt_linkedList(stack->list, value, 0);

    return true;
}

void pushAll_stack(Stack* stack, int size, ...) {
    va_list params;
    va_start(params, size);
    void* arg = va_arg(params, void*);
    int i = 0;
    while (i < size) {
        push_stack(stack, arg);
        arg = va_arg(params, void*);
        i++;
    }
    va_end(params);
}

void pop_stack(Stack* stack) {
    remove_linkedList(stack->list, 0);
}

void* peek_stack(Stack* stack) {
    return stack->list->head->data;
}

void clear_stack(Stack* stack) {
    clear_linkedList(stack->list);
}

int size_stack(Stack* stack) {
    return stack->size;
}

bool isEmpty_stack(Stack* stack) {
    return stack == NULL || stack->list == NULL || stack->list->size == 0;
}

void destroy_stack(Stack* stack) {
    destroy_linkedList(stack->list);
    free(stack);
    stack = NULL;
}

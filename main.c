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
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int main()
{
    Stack* stack = create_stack(sizeof(int));

    int a = 0, b = 1, c = 2, d = 3;

    push_stack(stack, &a);
    printf("Stack Top Value: %d\n", *(int*)peek_stack(stack));
    push_stack(stack, &b);
    printf("Stack Top Value: %d\n", *(int*)peek_stack(stack));
    pop_stack(stack);
    printf("Is Empty: %d\n", isEmpty_stack(stack));
    push_stack(stack, &c);
    printf("Stack Top Value: %d\n", *(int*)peek_stack(stack));
    push_stack(stack, &d);
    printf("Stack Top Value: %d\n", *(int*)peek_stack(stack));
    pop_stack(stack);
    pop_stack(stack);
    pop_stack(stack);
    printf("Is Empty: %d\n", isEmpty_stack(stack));

    destroy_stack(stack);

    return 0;
}

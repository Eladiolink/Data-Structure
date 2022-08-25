#include <stdio.h>
#include <stdlib.h>

typedef int Element;
typedef struct Stack Stack;
typedef struct Node Node;

Stack *create_stack();
void destroy_stack(Stack *stk);
Node *create_node();
void destroy_node(Node *node);
int Push(Stack *stk, Element elm);
int Pop(Stack *stk, Element *elm);
int Top(Stack *stk, Element *elm);
int Is_empty(Stack *stk);

int main()
{
    Stack *stk = create_stack();

    Push(stk, 1);
    Push(stk, 2);

    Element x;
    Top(stk, &x);
    printf("Top: %d\n", x);

    Pop(stk, &x);
    printf("Pop: %d\n", x);

    Top(stk, &x);
    printf("Top: %d\n", x);

    destroy_stack(stk);
    return 0;
}

struct Node
{
    Element info;
    Node *prev;
};

struct Stack
{
    Node *top;
};

Node *create_node()
{
    Node *node = (Node *)malloc(sizeof(Node));

    if (node)
        return node;
    return NULL;
}

Stack *create_stack()
{
    Stack *stk = (Stack *)malloc(sizeof(Stack));

    if (stk)
    {
        stk->top = NULL;
        return stk;
    }
    return NULL;
}

int Push(Stack *stk, Element elm)
{
    if (stk)
    {
        Node *newElement = create_node();
        newElement->info = elm;

        if (stk->top == NULL)
        {
            newElement->prev = NULL;
        }
        else
        {
            newElement->prev = stk->top;
        }

        stk->top = newElement;
        return 1;
    }

    return 0;
}

int Pop(Stack *stk, Element *elm)
{
    if (stk && !Is_empty(stk))
    {
        Node *remove = stk->top;
        *elm = remove->info;
        stk->top = remove->prev;
        destroy_node(remove);
        return 1;
    }

    return 0;
}

int Top(Stack *stk, Element *elm)
{
    if (stk && !Is_empty(stk))
    {
        *elm = stk->top->info;
        return 1;
    }

    return 0;
}

int Is_empty(Stack *stk)
{
    if (stk->top == NULL)
    {
        return 1;
    }
    return 0;
}

void destroy_stack(Stack *stk)
{
    while (stk->top)
    {
        Node *remove = stk->top;
        stk->top = remove->prev;
        destroy_node(remove);
    }
}

void destroy_node(Node *node)
{
    free(node);
}
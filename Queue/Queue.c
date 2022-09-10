#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Element;
typedef struct Queue Queue;
typedef struct Node Node;

Queue *create_Queue();
void destroy_Queue(Queue *q);
Node *create_node();
void destroy_node(Node *node);

// Add an element to the end of the queue
int enqueue(Queue *q,Element elm);
// Remove an element from the front of the queue
int dequeue(Queue *q);
// Check if the queue is empty
bool isEmpty(Queue *q);
//Get the value of the front of the queue without removing it
int peek(Queue *q, Element *elm);

int main(){
    Queue *q = create_Queue();
    enqueue(q,12);
    enqueue(q,13);
    enqueue(q,14);

    Element x=24;
    
    peek(q,&x);
    printf("Elemento of peak: %i\n",x);
    
    dequeue(q);
    peek(q,&x);
    printf("Elemento of peak: %i\n",x);

    enqueue(q,15);

    dequeue(q);
    peek(q,&x);
    printf("Elemento of peak: %i\n",x);

    dequeue(q);
    peek(q,&x);
    printf("Elemento of peak: %i\n",x);

    dequeue(q);
    
    if(isEmpty(q)){
        printf("Queue is Empty!\n");
    }

    destroy_Queue(q);
    return 0;
}

struct Node
{
    Element info;
    Node *prev;
};

struct Queue
{
    Node *peak;
};

Node *create_node()
{
    Node *node = (Node *)malloc(sizeof(Node));

    if (node){
        node->prev = NULL;
        return node;
    }
    return NULL;
}

void destroy_node(Node *node)
{
    free(node);
}

Queue *create_Queue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));

    if (queue)
    {
        queue->peak = NULL;
        return queue;
    }
    return NULL;
}

void destroy_Queue(Queue *q){
    Node * elm;
    while (q->peak)
    {
        elm = q->peak;
        q->peak = elm->prev;
        destroy_node(elm);
    }

    free(q);
}

int enqueue(Queue *q, Element elm){
    if(q != NULL){
        Node * new = create_node();
        new->info = elm;

        if(q->peak == NULL){
                q->peak = new;
                return 1;
        }

        Node *p = q->peak;
        while (p->prev)
        {
            p = p->prev;
        }
        
        p->prev = new;

        return 1;
    }
    
    return 0;
}

int dequeue(Queue *q){
    if(q!=NULL && !isEmpty(q)){
        Node * remove = q->peak;
        q->peak = q->peak->prev;
        destroy_node(remove);
        return 1;
    }

    return 0;
}

bool isEmpty(Queue *q){
    if(q->peak == NULL)
        return true;
    return false;
}

int peek(Queue *q, Element *elm){
    if(q!=NULL && !isEmpty(q)){
        *elm = q->peak->info;
        return 1;
    }
    return 0;
}
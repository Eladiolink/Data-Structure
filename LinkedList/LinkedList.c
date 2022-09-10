#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Element;
typedef struct List List;
typedef struct Node Node;

List *create_List();
void destroy_List(List *l);
Node *create_node();
void destroy_node(Node *node);

// operations
int insert(List *l,Element elm);
int delete(List *l,Element elm);
int insertafter(List *l, int x, Element elm);
int list_removeafter(List *l, int x, Element *elm);

int main(){

    return 0;
}

struct Node
{
    Element info;
    Node *next;
};

struct List
{
    Node *list;
};

Node *create_node()
{
    Node *node = (Node *)malloc(sizeof(Node));

    if (node){
        node->next = NULL;
        return node;
    }
    return NULL;
}

void destroy_node(Node *node)
{
    free(node);
}

List *create_List(){
    List *list = (List *)malloc(sizeof(List));

    if (list)
    {
        list->list = NULL;
        return list;
    }
    return NULL;
}

void destroy_List(List *l){

}

// operations
int insert(List *l,Element elm);
int delete(List *l,Element elm);
int insertafter(List *l, int x, Element elm);
int list_removeafter(List *l, int x, Element *elm);
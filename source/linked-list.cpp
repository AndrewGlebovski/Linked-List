#include <stdio.h>
#include <stdlib.h>
#include "linked-list.hpp"


/// Returns error and prints message on condition fail
#define ASSERT(condition, message, error, ...)                                                      \
if (!(condition)) {                                                                                 \
    printf("%s(%i) in %s\n[%i] %s\n", __FILE__, __LINE__, __PRETTY_FUNCTION__, error, message);     \
    __VA_ARGS__;                                                                                    \
    return error;                                                                                   \
}


Node *create_node(void) {
    Node *node = (Node *) calloc(1, sizeof(Node));

    // if (!node) printf("Failed to allocate memory for node!");

    return node;
}


int insert(Node *node, int value) {
    ASSERT(node, "Invalid node pointer!", INVALID_ARG);

    Node *new_node = create_node();
    
    ASSERT(new_node, "Couldn't insert due node allocate fail!", ALLOC_FAIL);

    *new_node = {value, node -> next, node};

    if (node -> next)
        node -> next -> prev = new_node;

    node -> next = new_node;

    return 0;
}


int remove(Node *node) {
    ASSERT(node, "Invalid node pointer!", INVALID_ARG);

    node -> next -> prev = node -> prev;
    node -> prev -> next = node -> next;

    free(node);

    return 0;
}


int destruct(Node *list) {
    ASSERT(list, "Invalid node pointer!", INVALID_ARG);

    if (list -> next)
        destruct(list -> next);

    free(list);

    return 0;
}


int dump(Node *list, FILE *output) {
    ASSERT(list, "Invalid node pointer!", INVALID_ARG);
    ASSERT(output, "Invalid output file!", INVALID_ARG);

    fprintf(output, "%-16s   %-16s %-16s %-16s\n", "[Node]", "Data", "Next", "Prev");

    for(Node *ptr = list; ptr; ptr = ptr -> next)
        fprintf(output, "[%-16p] %-16i %-16p %-16p\n", ptr, ptr -> data, ptr -> next, ptr -> prev);

    return 0;
}


Node *get_node(Node *list, int index) {
    for(int i = 0; list && i < index; list = list -> next, i++);

    return list;
}


int get_size(Node *list) {
    int size = 0;
    
    for(; list; list = list -> next, size++);

    return size;
}

#include <stdio.h>
#include "linked-list.hpp"


int main() {
    Node *list = create_node();

    dump(list, stdout);

    destruct(list);

    printf("Linked List!\n");

    return 0;
}

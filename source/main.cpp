#include <stdio.h>
#include "linked-list.hpp"
#include "log.hpp"


int main() {
    Node *list = create_node();

    FILE *log = fopen("dump/log.html", "w");

    DUMP_IT(log, list, fprintf(log, "Constructor"));

    for(int i = 0; i < 12; i++) {
        insert(get_node(list, i), i + 1);

        DUMP_IT(log, list, fprintf(log, "Insert %i after %i", i + 1, i));
    }

    fclose(log);

    destruct(list);

    printf("Linked List!\n");

    return 0;
}

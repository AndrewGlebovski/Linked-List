/**
 * \file
 * \brief Graphical dump module source
*/

#include <stdio.h>
#include <stdlib.h>
#include "linked-list.hpp"
#include "log.hpp"


/// Writes structs associated with Nodes by following the logical order
void write_records(FILE *file, Node *from, Node *to, const char *fillcolor);


/// Writes index ranks
void write_ranks(FILE *file, int count);


/// Writes edge connecting Nodes 
void write_edges(FILE *file, Node *from, Node *to);


/// Writes hidden edges connecting Nodes to keep them in row
void write_hidden_edges(Node *list, FILE *file);




int generate_file(Node *list, FILE *file) {
    fprintf(file, "digraph G {\n");
    fprintf(file, "rankdir=LR\n");
    fprintf(file, "splines=ortho\n");
    fprintf(file, "nodesep=1\n");

    write_ranks(file, get_size(list));

    write_records(file, list, nullptr, "daf9f4");

    write_hidden_edges(list, file);

    fprintf(file, "edge[color=\"#019aa2\"];\n");

    int id = 0;
    for(Node *node = list; node; node = node -> next, id++)
        fprintf(file, "{ rank = same; \"%i\"; \"e%p\";}\n", id, node);

    write_edges(file, list, nullptr);

    fprintf(file, "}\n");

    return 0;
}


void write_ranks(FILE *file, int count) {
    fprintf(file, "{\n");
    fprintf(file, "    node[shape=plaintext, fontcolor=white];\n");
    fprintf(file, "    edge[color=white]\n");

    fprintf(file, "    ");

    for(int i = 0; i < count - 1; i++)
        fprintf(file, "\"%i\" -> ", i);
    
    fprintf(file, "\"%i\";\n", count - 1);

    fprintf(file, "}\n");
}


void write_records(FILE *file, Node *from, Node *to, const char *fillcolor) {
    fprintf(file, "{\n");

    fprintf(file, "    node[shape=record, color=\"#355250\", fontsize=14, fontcolor=\"#355250\", style=\"filled\", fillcolor=\"#%s\"];\n", fillcolor);

    for(Node *node = from; node != to; node = node -> next)
        fprintf(file, "    \"e%p\"[label=\"<index> %-p | %i |  {<prev> %-p | <next> %-p}\"];\n", node, node, node -> data, node -> prev, node -> next);

    fprintf(file, "}\n");
}


void write_edges(FILE *file, Node *from, Node *to) {
    for(Node *node = from; node != to; node = node -> next) {
        if (node -> next != 0)
            fprintf(file, "\"e%p\" -> \"e%p\";\n", node, node -> next);

        if (node -> prev != 0)
            fprintf(file, "\"e%p\" -> \"e%p\";\n", node, node -> prev);
    }
}


void write_hidden_edges(Node *list, FILE *file) {
    fprintf(file, "{\n");

    fprintf(file, "    edge[color=white, weight = 1000];\n");

    for(Node *node = list; node -> next; node = node -> next)
        fprintf(file, "    \"e%p\" -> \"e%p\";\n", node, node -> next);
    
    fprintf(file, "}\n");
}


int generate_image(const char *input, const char *output) {
    char cmd[20 + 2 * _MAX_PATH] = "";

    sprintf(cmd, "dot %s -o %s -Tpng", input, output);

    return system(cmd);
}


int show_image(const char *filepath) {
    char cmd[10 + _MAX_PATH] = "";

    sprintf(cmd, "start %s", filepath);

    system(cmd);

    return system("pause");
}


int graphic_dump(Node *list, FILE *log) {
    static int i = 0;

    char dot[FILENAME_MAX] = "", img[FILENAME_MAX] = "";

    sprintf(dot, "dump/graph%i.txt", i);
    sprintf(img, "dump/graph%i.png", i);

    FILE *file = fopen(dot, "w");

    generate_file(list, file);

    fclose(file);

    generate_image(dot, img);

    fprintf(log, "<img src=\"graph%i.png\" alt=\"WTF\" style=\"width: auto\">\n", i);

    i++;

    return 0;
}

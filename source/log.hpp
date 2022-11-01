/**
 * \file
 * \brief Graphical dump module header
*/


int graphic_dump(Node *list, FILE *log);


int generate_file(Node *list, FILE *file);


int generate_image(const char *input, const char *output);


int show_image(const char *filepath);


#define DUMP_IT(log, list, title, ...)                                                 \
do {                                                                                   \
    if (log) {                                                                         \
        fprintf(log, "<div style=\"width:95%%\">\n");                                  \
        fprintf(log, "<h1>");                                                          \
        title;                                                                         \
        fprintf(log, "</h1>\n");                                                       \
        fprintf(log, "<xmp style=\"font-size: auto\">\n");                             \
        fprintf(log, "%s(%i) in %s\n", __FILE__, __LINE__, __PRETTY_FUNCTION__);       \
        dump(list, log);                                                               \
        fprintf(log, "</xmp>\n");                                                      \
        graphic_dump(list, log);                                                       \
        __VA_ARGS__;                                                                   \
        fprintf(log, "</div>\n");                                                      \
        fprintf(log, "<hr>\n");                                                        \
    }                                                                                  \
} while(0)

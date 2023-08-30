#include <cargs.h>
#include <stdio.h>
int main(int argc, const char** argv) {
    const char* val = NULL;
    cargs_option opts[] = {
        cargs_def_field('f', "file", true, STRING, REGULAR, &val)};

    cargs_parser parser;
    cargs_init(&parser, opts, 1, argc, argv);
    cargs_parse(&parser);

    if (val != NULL) {
        printf("value = %s\n", val);
    }

    return 0;
}

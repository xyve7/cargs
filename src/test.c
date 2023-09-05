#include <cargs.h>
#include <stdio.h>
int main(int argc, const char** argv) {
    const char* val = NULL;
    const char* output = NULL;
    cargs_option opts[] = {
        cargs_def_field("f", "file", true, STRING, REGULAR, &val),
        cargs_def_field("o", "output", true, STRING, REGULAR, &output)
    };

    cargs_parser parser;
    cargs_init(&parser, opts, 2, argc, argv);
    cargs_parse(&parser);

    if (val != NULL && output != NULL) {
        // NOTE: This is only here for testing if the argument passed in was received and there were no parsing errors
        FILE* fp = fopen(val, "rb");
        FILE* out = fopen(output, "wb");
        fseek(fp, 0, SEEK_END);
        long size = ftell(fp);
        fseek(fp, 0, SEEK_SET);

        char* buffer = malloc(size + 1);
        fread(buffer, size, 1, fp);
        buffer[size] = '\0';

        fputs(buffer, out);

        free(buffer);

        fclose(fp);
        fclose(out);
    }

    return 0;
}

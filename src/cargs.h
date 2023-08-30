#ifndef CARGS_H
#define CARGS_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    CHAR,
    SHORT,
    INT,
    LONG,
    UCHAR,
    USHORT,
    UINT,
    ULONG,
    STRING,
    BOOL
} cargs_type;

typedef enum {
    REGULAR,
    ARRAY
} cargs_specifier;

typedef struct {
    const char short_opt;
    const char* long_opt;
    bool required;
    cargs_type type;
    cargs_specifier specifier;
    void* out;
    bool found;
} cargs_option;

typedef struct {
    int argc;
    const char** argv;
    cargs_option* options;
    size_t len;
} cargs_parser;

void cargs_init(cargs_parser* parser, cargs_option* options, size_t no, int argc, const char** argv);
void cargs_parse(cargs_parser* parser);

#define cargs_def_field(short_opt, long_opt, required, type, specifier, out) \
    { short_opt, long_opt, required, type, specifier, out, false }

#endif

// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2021 TTG <prs.ttg+genstone@pm.me>

#include <gencommon.h>
#include <genstring.h>

GEN_ERRORABLE cio_line_from_offset(const size_t offset, size_t* const restrict out_line, const char* const restrict source, const size_t source_length);
GEN_ERRORABLE cio_column_from_offset(const size_t offset, size_t* const restrict out_column, const char* const restrict source, const size_t source_length);

typedef enum {
    CIO_TOKEN_IDENTIFIER,
    CIO_TOKEN_BLOCK,
    CIO_TOKEN_NUMBER
} cio_token_type_t;

typedef struct {
    cio_token_type_t type;
    size_t offset;
    size_t length;
} cio_token_t;

GEN_ERRORABLE cio_tokenize(const char* const restrict source, const size_t source_length, cio_token_t** const restrict out_tokens, size_t* const restrict out_tokens_length);

typedef struct {
    char* identifier;
    size_t parameters_length;
    size_t* parameters;

    const cio_token_t* token;
} cio_call_t;

typedef struct {
    char* identifier;
    size_t parameters;
    size_t calls_length;
    cio_call_t* calls;
    bool external;

    const cio_token_t* token;
} cio_routine_t;

typedef struct {
    size_t routines_length;
    cio_routine_t* routines;
} cio_program_t;

GEN_ERRORABLE cio_parse(const cio_token_t* const restrict tokens, const size_t tokens_length, cio_program_t* const restrict out_program, const char* const restrict source, const size_t source_length, const char* const restrict source_file, const size_t source_file_length);
GEN_ERRORABLE cio_free_program(cio_program_t* const restrict program);

GEN_ERRORABLE cio_emit_bytecode(const cio_program_t* const restrict program, unsigned char** const restrict out_bytecode, size_t* const restrict out_bytecode_length, const char* const restrict source, const size_t source_length, const char* const restrict source_file, const size_t source_file_length);

typedef struct {
    size_t base;
    bool reserve : 1;
    size_t height : (CHAR_BIT * sizeof(size_t)) - 1;
} cio_frame_t;

typedef struct {
    size_t* stack;
    cio_frame_t* frames;
} cio_vm_t;

GEN_ERRORABLE cio_execute_bytecode(const unsigned char* const restrict bytecode);

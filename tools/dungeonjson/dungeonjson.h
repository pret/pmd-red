// dungeonjson.h

#ifndef DUNGEONJSON_H
#define DUNGEONJSON_H

#include <cstdio>
using std::fprintf; using std::exit;

#include <cstdlib>

#ifdef _MSC_VER

#define FATAL_ERROR(format, ...)          \
do                                        \
{                                         \
    fprintf(stderr, format, __VA_ARGS__); \
    exit(1);                              \
} while (0)

#else

#define FATAL_ERROR(format, ...)            \
do                                          \
{                                           \
    fprintf(stderr, format, ##__VA_ARGS__); \
    exit(1);                                \
} while (0)

#endif // _MSC_VER

#endif // DUNGEONJSON_H

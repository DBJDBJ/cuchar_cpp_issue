#ifndef C_VERSION_DETECT_H
#define C_VERSION_DETECT_H

/* Check if we're being compiled by a C++ compiler */
#ifdef __cplusplus
#define IS_CPP 1
#define CPP_VERSION __cplusplus
#else
#define IS_CPP 0
#define CPP_VERSION 0
#endif

/* Detect C Standard Version */
#if defined(__STDC_VERSION__)
#if __STDC_VERSION__ >= 202311L
#define C_VERSION 23 /* C23 */
#define C_VERSION_STRING "C23"
#elif __STDC_VERSION__ >= 201710L
#define C_VERSION 17 /* C17 */
#define C_VERSION_STRING "C17"
#elif __STDC_VERSION__ >= 201112L
#define C_VERSION 11 /* C11 */
#define C_VERSION_STRING "C11"
#elif __STDC_VERSION__ >= 199901L
#define C_VERSION 99 /* C99 */
#define C_VERSION_STRING "C99"
#elif __STDC_VERSION__ >= 199409L
#define C_VERSION 94 /* C94 */
#define C_VERSION_STRING "C94"
#else
#define C_VERSION 90 /* C90/C89 */
#define C_VERSION_STRING "C90"
#endif
#else
#ifdef __STDC__
#define C_VERSION 89 /* C89 */
#define C_VERSION_STRING "C89"
#else
#define C_VERSION 0 /* Pre-Standard C */
#define C_VERSION_STRING "K&R C"
#endif
#endif

#ifdef C_VERSION_DETECT_USER

#include <stdio.h>

/* Print version info function */

#ifdef __cplusplus
extern "C" inline void print_start_info(const char argv_0[])
#else
inline void print_start_info(const char argv_0[static 0xFF])
#endif
{

#define DBJ_VT_RESET "\033[0m"
#define DBJ_VT_BOLD "\033[01m"
#define DBJ_VT_GREEN DBJ_VT_BOLD "\033[32m"
#define DBJ_VT_RED "\033[31m"

    printf(DBJ_VT_RESET);

    printf("\n%s , compiled with: ", argv_0);

/* OS and compiler detection */
#ifdef __linux__
    printf("\nLinux like OS,");
#endif

#ifdef __GNUC__
    printf(" GNUC %d\n", __GNUC__);
#elif defined(__clang_version__)
    printf(" clang %s\n", __clang_version__);
#elif defined(_MSC_VER)
    printf(" CL %d.%d\n", _MSC_VER, _MSC_BUILD);
#else
    printf(" Unknown compiler\n");
#endif
    printf("\n" DBJ_VT_GREEN);
#ifdef __cplusplus
    printf("Compiled as C++, version: %ld\n", CPP_VERSION);
#else
    printf("Compiled as %s\n", C_VERSION_STRING);
    printf("__STDC_VERSION__ = %ldL\n", (long)__STDC_VERSION__);
#endif

    printf("\n" DBJ_VT_RESET);
}
#endif /* C_VERSION_DETECT_USER */

#endif /* C_VERSION_DETECT_H */
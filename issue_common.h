#ifndef ISSUE_COMMON_H_
#define ISSUE_COMMON_H_

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <limits.h>
#include <stddef.h>
#include <uchar.h>
#include <wchar.h>

#define C_VERSION_DETECT_USER
#include "version_detect.h"

/* Forward declarations */
void u32sample(const char32_t *str32);
void u8sample_compat(const char *str8);

/* UTF-32 handling */
void u32sample(const char32_t *str32)
{
#ifdef __cplusplus
    mbstate_t state = {};
#else
    mbstate_t state = {0};
#endif
    char out[MB_LEN_MAX] = {0};

    while (*str32)
    {
#if defined(_MSC_VER)
        size_t rc = c32rtomb(out, *str32, &state);
        if (rc > 0)
            printf("%s", out);
#else
        /* Some older C compilers might need wcrtomb instead of c32rtomb */
        size_t rc = wcrtomb(out, (wchar_t)*str32, &state);
        if (rc > 0)
            printf("%s", out);
#endif
        str32++;
    }
}

/* C17 compatible UTF-8 handling */
void u8sample_compat(const char *str8)
{
    while (*str8)
    {
        printf("%c", *str8);
        str8++;
    }
}

/* Helper macro for UTF-8 string literals */
#if defined(_MSC_VER)
#define U8_STRING(x) (const char *)u8##x
#else
#define U8_STRING(x) u8##x
#endif

int issue_common_main(const int args, const char *argv[static args])
{
    setlocale(LC_ALL, "en_US.utf8");

    print_start_info(argv[0]);

    /* UTF-32 demonstration */
    printf("\nchar32_t *, Converting to 'char *', and then printing --> ");
    u32sample(U"ひらがな");

    /* UTF-8 demonstration using C17 compatible approach */
    printf("\nUTF-8 string literal, printing directly --> ");
    u8sample_compat(U8_STRING("ひらがな"));

    printf("\n\nDone ...\n");

    return 42;
}

#endif // ISSUE_COMMON_H_

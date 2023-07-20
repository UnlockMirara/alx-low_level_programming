#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

void print_all(const char * const format, ...)
{
    va_list args;
    char c;
    int i;
    float f;
    char *s;
    int flag = 0;

    va_start(args, format);

    while (format && format[flag])
    {
        c = format[flag];
        flag++;

        if (flag > 1)
            printf(", ");

        if (c == 'c')
        {
            i = va_arg(args, int);
            printf("%c", i);
        }
        else if (c == 'i')
        {
            i = va_arg(args, int);
            printf("%d", i);
        }
        else if (c == 'f')
        {
            f = va_arg(args, double);
            printf("%f", f);
        }
        else if (c == 's')
        {
            s = va_arg(args, char*);
            if (s == NULL)
                printf("(nil)");
            else
                printf("%s", s);
        }
    }

    va_end(args);
    printf("\n");
}

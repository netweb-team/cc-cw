#include <stdio.h>

int write(int x)
{
    if ((int) x == x)
        printf("%d", (int) x);
    else
        printf("%lf", x);
    return 0;
}

int writeln(int x)
{
    write(x);
    printf("\n");
    return 0;
}

int swrite(char *x)
{
    printf("%s", x);
    return 0;
}

int swriteln(char *x)
{
    swrite(x);
    printf("\n");
    return 0;
}

int read(int *x)
{
    scanf("%d", x);
    return 0;
}

int readln(int *x)
{
    read(x);
    printf("\n");
    return 0;
}

int sread(char *x)
{
    scanf("%s", x);
    return 0;
}

int sreadln(char *x)
{
    sread(x);
    printf("\n");
    return 0;
}

int inc(int *x)
{
    return ++*x;
}

int dec(int *x)
{
    return --*x;
}

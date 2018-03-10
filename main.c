#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#define BUFSIZE 50
#define POTATOES "potatoes"

int dump_buf(const char *buf)
{
    char *str = malloc(BUFSIZE+1);

    if (str == NULL)
    {
        printf("Unable to allocate dump string. Out of memory?\n");
        return 127;
    }

    strncpy(str, buf, BUFSIZE);
    str[BUFSIZE] = '\0';

    printf("%s\n", str);

    free(str);
    return 0;
}

int reset_buf(char *buf)
{
    for (int i = 0; i < BUFSIZE; i++)
        buf[i] = ' ';
    return 0;
}

int potatoes(char *buf)
{
    if (reset_buf(buf) != 0)
    {
        printf("Unable to reset buffer\n");
        return 127;
    }

    int pos, num_chars;

    for (int i = 0; i < 10; i++)
    {
        pos = rand() % BUFSIZE;
        num_chars = pos + strlen(POTATOES) > BUFSIZE
            ? BUFSIZE - pos
            : strlen(POTATOES);

        memcpy(&buf[pos], "potatoes", num_chars);
    }
    
    return 0;
}

int main()
{
    int exit_code = 0;

    // seed PRNG

    time_t t;
    srand((unsigned) time(&t));

    // allocate and set up buffer

    char *buf = malloc(BUFSIZE);

    if (buf == NULL)
    {
        printf("Unable to allocate buffer. Out of memory?\n");
        return 127;
    }

    // potatoes

    for (int i = 0; i < BUFSIZE / 2; i++)
    {
        exit_code = potatoes(buf);
        if (exit_code != 0) break;

        exit_code = dump_buf(buf);
        if (exit_code != 0) break;
    }

    // clean up

    free(buf);
    return exit_code;
}

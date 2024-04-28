#include "Cleaner.h"
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Необходимо указать путь в качестве аргумента командной строки.\n");
        return 1;
    }

    Cleaning(argv[1]);

    return 0;
}
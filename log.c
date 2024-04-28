#include "log.h"
void log_message(const char *format, ...)
{
    FILE *logfile = fopen("log.txt", "a");
    if (logfile != NULL)
    {
        va_list args;
        va_start(args, format);

        char buffer[1024];
        vsprintf(buffer, format, args);

        fprintf(logfile, "%s\n", buffer);
        fclose(logfile);

        va_end(args);
    }
    else
    {
        fprintf(stderr, "Ошибка открытия файла лога\n");
    }
}
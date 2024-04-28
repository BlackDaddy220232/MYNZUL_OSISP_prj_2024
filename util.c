#include "util.h"
int hardLinkReplace(char *existinfFile, char *newLink)
{
    int result = link(existinfFile, newLink);
    if (result == 0)
    {
        log_message("\nЖесткая ссылка %s на файл %s создана успешно.\n", newLink, existinfFile);
    }
    else
    {
        log_message("\nОшибка при создании жесткой ссылки");
        return 0;
    }
    return 1;
}
int DeleteFile(char *path)
{
    struct stat fileInfo;
    int result = stat(path, &fileInfo);
    if (result != 0)
    {
        log_message("Ошибка при получении информации о файле");
        return 1;
    }

    if (S_ISREG(fileInfo.st_mode))
    {
        result = remove(path);
        if (result == 0)
        {
            log_message("Файл %s успешно удален.\n", path);
        }
        else
        {
            log_message("Ошибка при удалении файла");
            return 0;
        }
    }
    else
    {
        log_message("Указанный путь не является файлом.\n");
        return 0;
    }

    return 1;
}
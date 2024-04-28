#include "Cleaner.h"
counter = 0;
void Cleaning(char *path)
{
    HashTable *table = create_table(CAPACITY);
    process_directory(path, table);
    log_message("%d файлов просканированно", counter);
}
void process_directory(char *path, HashTable *table)
{
    DIR *dir = opendir(path);
    if (dir == NULL)
    {
        perror("Ошибка открытия директории");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }
        if (entry->d_name[0] == '.')
        {
            continue;
        }
        char entry_path[1024];
        snprintf(entry_path, sizeof(entry_path), "%s/%s", path, entry->d_name);

        struct stat entry_stat;
        if (lstat(entry_path, &entry_stat) == -1)
        {
            perror("Ошибка получения информации о файле");
            continue;
        }

        if (S_ISDIR(entry_stat.st_mode))
        {
            process_directory(entry_path, table);
        }
        else if (S_ISREG(entry_stat.st_mode))
        {
            process_file(entry_path, table);
        }
    }
    closedir(dir);
}
void process_file(char *file_path, HashTable *table)
{
    MainBlock *fileContent = mainBlockInit();
    FILE *file = fopen(file_path, "rb");
    if (file == NULL)
    {
        perror("Ошибка открытия файла");
        return;
    }
    fileContent->path = file_path;
    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    size_t total_bytes_read = 0;

    // Определение размера файла
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    int sizeofCach = 0;
    // Проверка на пустой файл
    if (file_size == 0)
    {
        DeleteFile(file_path);
        return;
    }
    // Считывание по частям размером в один килобайт
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)) > 0)
    {
        total_bytes_read += bytes_read;
        sizeofCach = bytes_read;
        fileContent->fileChain = addelem(fileContent->fileChain, SHA256(buffer, sizeofCach));
    }
    if (total_bytes_read != file_size)
    {
        fprintf(stderr, "\nОшибка чтения файла: неправильное количество прочитанных байтов\n");
    }
    char *chainHash = combineHash(fileContent->fileChain);
    char *mainHash = SHA256(chainHash, strlen(chainHash));
    ht_insert(table, mainHash, fileContent->path);
    free(fileContent);
    fclose(file);
    counter++;
}
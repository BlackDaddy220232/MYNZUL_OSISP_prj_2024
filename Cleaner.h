#pragma once
#include "HashMap.h"
#include "BlockChain.h"
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include "SHA256.h"
#define BUFFER_SIZE 1024
int counter;
void process_directory(char *path, HashTable *table);
void Cleaning(char *path);
void process_file(char *file_path, HashTable *table);

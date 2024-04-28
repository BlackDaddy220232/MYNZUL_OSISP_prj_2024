#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct BlockChain
{
    char *hashKey;          // поле данных
    struct BlockChain *ptr; // указатель на следующий элемент
} BlockChain;
typedef struct MainBlock
{
    char *path;
    BlockChain *fileChain;
} MainBlock;
BlockChain *init(char *hash);
BlockChain *addelem(BlockChain *lst, char *hash);
void deleteBlockChain(BlockChain *head);
MainBlock *mainBlockInit();
void listprint(BlockChain *lst);
char *combineHash(BlockChain *chain);
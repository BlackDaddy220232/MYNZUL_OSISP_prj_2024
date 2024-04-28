#include "BlockChain.h"
BlockChain *init(char *hash)
{
    BlockChain *lst = (BlockChain *)malloc(sizeof(BlockChain));
    lst->hashKey = (char *)malloc(65 * sizeof(char));
    strcpy(lst->hashKey, hash);
    lst->hashKey[64] = '\0';
    lst->ptr = NULL;
    return lst;
}

BlockChain *addelem(BlockChain *lst, char *hash)
{
    if (lst == NULL)
    {
        lst = init(hash);
        return lst;
    }
    BlockChain *node = (BlockChain *)malloc(sizeof(BlockChain));
    node->hashKey = (char *)malloc(65 * sizeof(char));
    strcpy(node->hashKey, hash);
    node->hashKey[64] = '\0';
    node->ptr = lst;
    return node;
}

void deleteBlockChain(BlockChain *head)
{
    while (head != NULL)
    {
        BlockChain *current = head;
        head = head->ptr;
        free(current->hashKey);
        free(current);
    }
}

MainBlock *mainBlockInit()
{
    MainBlock *lst = (MainBlock *)malloc(sizeof(MainBlock));
    lst->path = (char *)malloc(256 * sizeof(char));
    lst->fileChain = NULL;
    return lst;
}

void listprint(BlockChain *lst)
{
    BlockChain *p = lst;
    int counter = 0;
    while (p != NULL)
    {
        counter++;
        p = p->ptr;
    }
    printf("\nCounter : %d\n", counter);
}
char *combineHash(BlockChain *chain)
{
    BlockChain *tmp = chain;
    char *combainHash = NULL;
    long size = 0;
    while (tmp != NULL)
    {
        size += strlen(tmp->hashKey);
        combainHash = (char *)realloc(combainHash, (size + 1) * sizeof(char));
        strcat(combainHash, tmp->hashKey);
        tmp = tmp->ptr;
    }
    return combainHash;
}

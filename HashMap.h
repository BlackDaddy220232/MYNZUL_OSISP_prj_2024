#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#define CAPACITY 50000 // Size of the HashTable.
// Defines the HashTable item.
// Defines the HashTable item.
typedef struct Ht_item
{
    char *key;
    char *value;
} Ht_item;

// Defines the LinkedList.
typedef struct LinkedList
{
    Ht_item *item;
    struct LinkedList *next;
} LinkedList;

// Defines the HashTable.
typedef struct HashTable
{
    // Contains an array of pointers to items.
    Ht_item **items;
    LinkedList **overflow_buckets;
    int size;
    int count;
} HashTable;
unsigned long hash_function(const unsigned char *hash);
LinkedList *allocate_list();
LinkedList *linkedlist_insert(LinkedList *list, Ht_item *item);
Ht_item *linkedlist_remove(LinkedList *list);
void free_linkedlist(LinkedList *list);
LinkedList **create_overflow_buckets(HashTable *table);
void free_overflow_buckets(HashTable *table);
Ht_item *create_item(char *key, char *value);
HashTable *create_table(int size);
void free_item(Ht_item *item);
void free_table(HashTable *table);
void handle_collision(HashTable *table, unsigned long index, Ht_item *item);
void ht_insert(HashTable *table, char *key, char *value);
char *ht_search(HashTable *table, char *key);
void ht_delete(HashTable *table, char *key);
void print_search(HashTable *table, char *key);
void print_table(HashTable *table);

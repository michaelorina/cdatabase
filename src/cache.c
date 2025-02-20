#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/cache.h"

#define HASH_SIZE 100

typedef struct KeyValue {
    char key[50];
    char value[100];
    struct KeyValue *next;
} KeyValue;

KeyValue *hash_table[HASH_SIZE];

unsigned int hash(const char *key) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash * 31) + *key;
        key++;
    }
    return hash % HASH_SIZE;
}

void cache_set(const char *key, const char *value) {
    unsigned int index = hash(key);
    KeyValue *new_pair = malloc(sizeof(KeyValue));
    if (!new_pair) return;

    strcpy(new_pair->key, key);
    strcpy(new_pair->value, value);
    new_pair->next = hash_table[index];
    hash_table[index] = new_pair;
}

char *cache_get(const char *key) {
    unsigned int index = hash(key);
    KeyValue *pair = hash_table[index];
    while (pair) {
        if (strcmp(pair->key, key) == 0) {
            return pair->value;
        }
        pair = pair->next;
    }
    return NULL;
}

void cache_delete(const char *key) {
    unsigned int index = hash(key);
    KeyValue *pair = hash_table[index], *prev = NULL;
    while (pair) {
        if (strcmp(pair->key, key) == 0) {
            if (prev) prev->next = pair->next;
            else hash_table[index] = pair->next;
            free(pair);
            return;
        }
        prev = pair;
        pair = pair->next;
    }
}
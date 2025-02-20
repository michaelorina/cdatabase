#include <stdio.h>
#include <pthread.h>
#include "../include/db.h"
#include "../include/cache.h"

pthread_mutex_t db_mutex = PTHREAD_MUTEX_INITIALIZER;

void set(const char *key, const char *value) {
    pthread_mutex_lock(&db_mutex);
    cache_set(key, value);

    FILE *file = fopen("database.txt", "a");
    if (file) {
        fprintf(file, "%s=%s\n", key, value);
        fclose(file);
    }
    pthread_mutex_unlock(&db_mutex);
}

char *get(const char *key) {
    pthread_mutex_lock(&db_mutex);
    char *result = cache_get(key);
    pthread_mutex_unlock(&db_mutex);
    return result;
}

void delete_entry(const char *key) {
    pthread_mutex_lock(&db_mutex);
    cache_delete(key);
    pthread_mutex_unlock(&db_mutex);
}

void load_from_file() {
    pthread_mutex_lock(&db_mutex);
    FILE *file = fopen("database.txt", "r");
    if (!file) {
        pthread_mutex_unlock(&db_mutex);
        return;
    }

    char key[50], value[100];
    while (fscanf(file, "%49[^=]=%99[^\n]\n", key, value) == 2) {
        cache_set(key, value);
    }

    fclose(file);
    pthread_mutex_unlock(&db_mutex);
}

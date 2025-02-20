#ifndef DB_H 
#define DB_H

#include <pthread.h>

void set(const char *key, const char *value);
char *get(const char *key);
void delete_entry(const char *key);
void load_from_file();
void save_to_file(const char *key, const char *value);

#endif
#ifndef CACHE_H
#define CACHE_H

void cache_set(const char *key, const char *value);
char *cache_get(const char *key);
void cache_delete(const char *key);

#endif
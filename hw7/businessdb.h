#pragma once

#include <stddef.h>  // for size_t
#include <stdbool.h> // for bool

typedef struct Customer {
    char *email;
    char *name;
    int shoe_size;
    char *favorite_food;
    struct Customer *next;
} Customer;

typedef struct {
    Customer **buckets;   
    size_t n_buckets;     
} HashTable;

HashTable *create_table(size_t n_buckets);

size_t hash_key(const char *email, size_t n_buckets);

bool add_customer(HashTable *ht,
                  const char *email,
                  const char *name,
                  int shoe_size,
                  const char *favorite_food);
void load_database(HashTable *ht, const char *filename);

Customer *find_customer(const HashTable *ht, const char *email);

bool delete_customer(HashTable *ht, const char *email);

void list_table(const HashTable *ht);

void save_data(const HashTable *ht, const char *filename);

void free_data(HashTable *ht);

#define UNUSED(x) (void)(x)


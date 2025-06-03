#include "businessdb.h"

#include <stdio.h>    
#include <stdlib.h>  
#include <string.h>     
#include <ctype.h>      

HashTable *create_table(size_t n_buckets) {
    HashTable *data = malloc(sizeof(HashTable));
    if (!data) {
        return NULL; 
    }
    data->n_buckets = n_buckets;

    data->buckets = calloc(n_buckets, sizeof(Customer *));
    if (!data->buckets) {
        free(data);
        return NULL;
    }

    return data;
}


size_t hash_key(const char *email, size_t n_buckets) {
    unsigned long hv = 0;
    unsigned long base = 31;
    for (const char *p = email; *p; p++) {
        hv = (hv * base + (unsigned char)(*p)) % (n_buckets * 13 + 1);
    }
    return hv % n_buckets;
}


static Customer *create_customer(const char *email, const char *name,
                                 int shoe_size, const char *food) {
    Customer *cust = malloc(sizeof(Customer));
    if (!cust) {
        return NULL;
    }
    cust->email = strdup(email);
    cust->name = strdup(name);
    cust->shoe_size = shoe_size;
    cust->favorite_food = strdup(food);
    cust->next = NULL;
    return cust;
}


bool add_customer(HashTable *data,
                  const char *email,
                  const char *name,
                  int shoe_size,
                  const char *favorite_food)
{
    if (!data || !email) return false;

    size_t index = hash_key(email, data->n_buckets);
    Customer *head = data->buckets[index];
    Customer *curr = head;

    while (curr) {
        if (strcmp(curr->email, email) == 0) {
            free(curr->name);
            free(curr->favorite_food);
            curr->name = strdup(name);
            curr->shoe_size = shoe_size;
            curr->favorite_food = strdup(favorite_food);
            return true;
        }
        curr = curr->next;
    }

    Customer *newCust = create_customer(email, name, shoe_size, favorite_food);
    if (!newCust) return false;

    newCust->next = head;
    data->buckets[index] = newCust;
    return true;
}


void load_database(HashTable *data, const char *filename) {
    if (!data || !filename) return;

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        return;
    }

    char line[512];
    while (fgets(line, sizeof(line), fp)) {
        char *nl = strchr(line, '\n');
        if (nl) {
            *nl = '\0';
        }

        char *email = strtok(line, "\t");
        char *name = strtok(NULL, "\t");
        char *shoe_str = strtok(NULL, "\t");
        char *food = strtok(NULL, "\t");

        if (!email || !name || !shoe_str || !food) {
            continue;
        }
        int shoe_size = atoi(shoe_str);

        add_customer(data, email, name, shoe_size, food);
    }

    fclose(fp);
}

Customer *find_customer(const HashTable *data, const char *email) {
    if (!data || !email) return NULL;

    size_t index = hash_key(email, data->n_buckets);
    Customer *curr = data->buckets[index];

    while (curr) {
        if (strcmp(curr->email, email) == 0) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

bool delete_customer(HashTable *data, const char *email) {
    if (!data || !email) return false;

    size_t index = hash_key(email, data->n_buckets);
    Customer *curr = data->buckets[index];
    Customer *prev = NULL;

    while (curr) {
        if (strcmp(curr->email, email) == 0) {
  
            if (prev) {
                prev->next = curr->next;
            } else {
                data->buckets[index] = curr->next;
            }
        
            free(curr->email);
            free(curr->name);
            free(curr->favorite_food);
            free(curr);
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;
}


void list_table(const HashTable *data) {
    if (!data) return;

    for (size_t i = 0; i < data->n_buckets; i++) {
        Customer *curr = data->buckets[i];
        while (curr) {
            printf("Email: %s, Name: %s, Shoe Size: %d, Food: %s\n",
                   curr->email, curr->name, curr->shoe_size, curr->favorite_food);
            curr = curr->next;
        }
    }
}


void save_data(const HashTable *data, const char *filename) {
    if (!data || !filename) return;

    FILE *fp = fopen(filename, "w");
    if (!fp) {
        return;
    }

    for (size_t i = 0; i < data->n_buckets; i++) {
        Customer *curr = data->buckets[i];
        while (curr) {
            fprintf(fp, "%s\t%s\t%d\t%s\n",
                    curr->email, curr->name, curr->shoe_size, curr->favorite_food);
            curr = curr->next;
        }
    }

    fclose(fp);
}

void free_data(HashTable *data) {
    if (!data) return;

    for (size_t i = 0; i < data->n_buckets; i++) {
        Customer *curr = data->buckets[i];
        while (curr) {
            Customer *tmp = curr;
            curr = curr->next;
            free(tmp->email);
            free(tmp->name);
            free(tmp->favorite_food);
            free(tmp);
        }
    }
    free(data->buckets);
    free(data);
}

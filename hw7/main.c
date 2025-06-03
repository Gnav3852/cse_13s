#include "businessdb.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 256

int contains_tab(const char *str) {
    return strchr(str, '\t') != NULL;
}

void read_In(char *buffer, size_t size) {
    if (fgets(buffer, size, stdin)) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0'; 
        }
    }
}

int main(void) {
    HashTable *db = create_table(50);  
    load_database(db, "customers.tsv");  

    char command[MAX_INPUT];
    while (1) {
        printf("Enter command (add, lookup, delete, list, save, quit): ");
        read_In(command, MAX_INPUT);

        if (strcmp(command, "add") == 0) {
            char email[MAX_INPUT], name[MAX_INPUT], food[MAX_INPUT];
            int shoe_size;
            
            printf("Enter email: ");
            read_In(email, MAX_INPUT);
            if (strchr(email, ' ')) {
                printf("Invalid email. Email should not contain spaces.\n");
                continue;
            }
            if (contains_tab(email)) {
                printf("Invalid input. Email should not contain tab characters.\n");
                continue;
            }

            printf("Enter name: ");
            read_In(name, MAX_INPUT);
            if (contains_tab(name)) {
                printf("Invalid input. Name should not contain tab characters.\n");
                continue;
            }

            printf("Enter shoe size: ");
            if (scanf("%d", &shoe_size) != 1 || shoe_size <= 0) {
                printf("Invalid size. Please enter a positive number.\n");
                while (getchar() != '\n');  
                continue;
            }
            while (getchar() != '\n'); 

            printf("Enter favorite food: ");
            read_In(food, MAX_INPUT);
            if (contains_tab(food)) {
                printf("Invalid input. Food should not contain tab characters.\n");
                continue;
            }

            add_customer(db, email, name, shoe_size, food);
        } 
        else if (strcmp(command, "lookup") == 0) {
            char email[MAX_INPUT];
            printf("Enter email to lookup: ");
            read_In(email, MAX_INPUT);
            Customer *customer = find_customer(db, email);
            if (customer) {
                printf("Customer found: %s, %s, %d, %s\n", customer->email, customer->name, customer->shoe_size, customer->favorite_food);
            } else {
                printf("Customer not found.\n");
            }
        } 
        else if (strcmp(command, "delete") == 0) {
            char email[MAX_INPUT];
            printf("Enter email to delete: ");

            read_In(email, MAX_INPUT);
            delete_customer(db, email);
        } 
        else if (strcmp(command, "list") == 0) {
            list_table(db);
        } 
        else if (strcmp(command, "save") == 0) {
            save_data(db, "customers.tsv");
        } 
        else if (strcmp(command, "quit") == 0) {
            break;
        } 
        else {
            printf("Unknown command.\n");
        }
    }

    save_data(db, "customers.tsv");
    free_data(db);
    return 0;
}

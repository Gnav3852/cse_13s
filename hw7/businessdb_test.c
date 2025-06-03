#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "businessdb.h"


static void checkRes(const char *message, bool condition) {
    printf("%s: %s\n", message, condition ? "SUCCESS" : "FAILURE");
}

int main(void) {
    printf("Starting businessdb tests...\n\n");

    HashTable *ht = create_table(5);
    checkRes("Created table with 5 buckets", (ht != NULL && ht->n_buckets == 5));

    bool added = add_customer(ht, "alice@example.com", "Alice", 7, "pasta");
    checkRes("Added 'alice@example.com' to table", added);

    Customer *c = find_customer(ht, "alice@example.com");
    checkRes("Found 'alice@example.com' after adding", (c != NULL));

    if (c) {
        checkRes("Check name is 'Alice'", (strcmp(c->name, "Alice") == 0));
        checkRes("Check shoe size is 7", (c->shoe_size == 7));
        checkRes("Check favorite_food is 'pasta'", (strcmp(c->favorite_food, "pasta") == 0));
    }

    added = add_customer(ht, "alice@example.com", "Alice B", 8, "noodles");
    checkRes("Overwrote existing customer email", added);

    c = find_customer(ht, "alice@example.com");
    checkRes("Found overwritten 'alice@example.com'", (c != NULL));
    if (c) {
        checkRes("Check name is now 'Alice B'", (strcmp(c->name, "Alice B") == 0));
        checkRes("Check shoe size is now 8", (c->shoe_size == 8));
        checkRes("Check favorite_food is 'noodles'", (strcmp(c->favorite_food, "noodles") == 0));
    }

    add_customer(ht, "bob@example.com", "Bob", 10, "pizza");
    add_customer(ht, "charlie@example.com", "Charlie", 9, "sushi");

    checkRes("Found 'bob@example.com'", find_customer(ht, "bob@example.com") != NULL);
    checkRes("Found 'charlie@example.com'", find_customer(ht, "charlie@example.com") != NULL);

    bool deleted = delete_customer(ht, "bob@example.com");
    checkRes("Deleted 'bob@example.com' successfully", deleted);
    checkRes("'bob@example.com' no longer found", find_customer(ht, "bob@example.com") == NULL);

    deleted = delete_customer(ht, "nobody@example.com");
    checkRes("Deleting unknown email returns false", (deleted == false));

    
    const char *output = "output.tsv";
    save_data(ht, output);
    printf("Saved to '%s'\n", output);


    printf("\nListing current table contents:\n");
    list_table(ht);

    free_data(ht);

    printf("\nAll tests finished.\n");
    return 0;
}

# Homework 7: Design Document

  * **Author:** Gandharva Naveen  
  * **Date:** March 2025  

## Introduction

For this homework, I will create nine functions (plus the required helper functions) to implement a hash table type database for storing customer data. Each record has an email, name, shoe size, and favorite food. The email will be the unique key which will be hashing using a rolling hash method. The program will load from a file and can perfrom all CRUD (Create, Read, Update, Delete) applications while also dealing with memory management.

## Function 1: create_table 

The function `create_table` creates the hash table used by the database. It allocates an array or structure representing the buckets, with each bucket set to `NULL` to be an empty list. It determines the number of buckets either from a fixed value. The function returns a pointer to this new table so that other functions can use the DB.

## Function 2: hash_key

The function `hash_key` takes an email and computes an integer index using the rolling hash formula. By summing characters in a polynomial expression, we generate a hash value and modulo by the # of buckets to get the index.

## Function 3: add_customer

The function `add_customer` inserts or updates a customer record. It calls `hash_key` on the email to identify the relevant bucket. If an existing record with that `email` is found, the function updates it by removed old data. If no person is found, the function allocates a new `node` and adds it to the front of the list. This makes it so a single record is maintained for each email.

## Function 4: load_database

The function `load_database` reads customer records from a file. It opens the file, reads the lines, and splits lines and tabs to separate the email, name, shoe size, and favorite food. After converting the shoe size to an integer, it creates a new `customer` and inserts it into the hash table by calling `add_customer`.

## Function 5: find_customer

The function `find_customer` looks up a customer by email. It uses `hash_key` to figure out which bucket to check, loops the linked list in that bucket, and returns the matching customer if found. If no matching person is found, it returns `NULL`. 

## Function 6: delete_customer

The function `delete_customer` removes a record from the database by `email`. It determines the correct bucket using `hash_key` and loops the linked list. If it finds a matching person, it unlinks and frees that node, with any strings stored in it. If no matching person is found, the function says that nothing is deleted.

## Function 7: list_table

The function `list_table` prints out every record in the database. It loops over all buckets, looks at each linked list, and displays the email, name, shoe size, and favorite food. The order is based the hashing distribution.

## Function 8: save_data

The function `save_data` writes all records back to the given fule. It opens the file in write mode, loops through each bucket, and prints one line per customer with everything separated by tabs. After printing all records, it closes the file, saving the changes.

## Function 9: free_data

The function `free_data` ensures that all memory used by the database is freed. It visits each bucket, loops the linked list, and frees the email, name, and favorite food strings first. Then the nodes themselves. It then frees the array of buckets. This function makes sure there are no memory leaks


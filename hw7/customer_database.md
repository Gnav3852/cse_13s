# homework 7: Hash tables, I/O and strings

**Due date: Friday, 14 March 2024, 11:59pm**

# introduction

We spoke with several *very* expensive consultants, and now we're convinced that
the future isn't building solvers for Wordle anymore. The world has moved on,
and we're going to the next big thing, which is of course e-commerce businesses
that sell both snacks and shoes, using hash tables. This is going to be great.

Our task for this homework is to both *design* and *implement* a simple database
that will allow us to keep track of our customers, and all the information that
we know about them.

We will build a simple interface around this database, and from this interface,
we'll have the ability to read a database file from the disk, add customers,
delete customers, and save the database back to the file.

This homework will require a bit more planning on your part -- you're given
less of the framework to start with -- so *get planning*! You may wish to start
with [the code that we wrote in
class](https://git.ucsc.edu/ajrudnic/cse-13s-demos-winter-2025/-/blob/main/hashtables/hashtable.c)
when we did a similar "recipes" database, although keep in mind that this
homework is about keeping track of *Customers* rather than particular items.

You may also want to use the included `businessdb.py` as a reference for the
intended behavior for this program.

## What we know about a customer

Every customer in our database has an email address (a string), a name (a
string), a shoe size (an integer) and a favorite food (a string).

How should we keep this information? How do you store **struct**ured information
like this in C, usually?

## the main interaction loop

When the program loads up, it will read `customers.tsv` and store all the
customers in the hash table. Then, it will repeatedly prompt the user for a
command. The commands you should support are as follows.

  * `add`: if the user types `add`, the program will additionally prompt the
    user for an email address, a display name, a shoe size, and a favorite food.
    This Customer (with their associated data) will then be added to the hash
    table. If that email address is already present in the hash table, then
    replace the data that was already in the hash table with the new entry
    (don't just add another node into the table!), making sure to free up any
    memory that's no longer necessary.
  * `lookup`: prompt the user for an email address, then go find that entry in
    the hash table! If the specified Customer is not found (nobody has that
    email address) then display a nice message that the Customer was not found.
    If the specified Customer has been found, then display all the information
    we have about that Customer in a nicely formatted way.
  * `delete`: prompt the user for an email address, then go find that entry in
    the hash table (and delete it from the linked list in the bucket). Again, if
    the specified Customer is not found (nobody has that email address) then
    display a nice message that the customer was not found.
  * `list`: display every user in the database, in whatever order is convenient.
    Format each user the same way we do in `lookup`.
  * `save`: write the current state of the database back to `customers.tsv`.
  * `quit`: clean up all of our memory and exit the program.

## loading the customer database from a file

We will keep our customer database in a file called `customers.tsv`, where each
line of that file will contain a customer's email address (the key -- every
customer has a unique email address), their display name, their shoe size, and
their favorite food.

It might look like this.

```
sammy@ucsc.edu	Sammy The Slug	27	bananas
bimmy@ucsc.edu	bimmy	4	vegan jerky
```

Note that every line in the file has its fields separated by tabs (the `'\t'`
character), and it ends with a newline character (`'\n'`). Individual fields can
contain spaces, but not tabs. *The only tabs in the file are for separating
fields*. You might be wondering, what if the user inputs some text that contains
a tab? You should plan for this possibility -- what will you do? Write about
this in your design doc.

Some valid options are complaining at the user and making them re-enter the
string, or just removing the tabs yourself and replacing them with something
else. *In any case, if the user types a tab character, you should not store it
in the file*.

You can expect, by construction, that the `customers.tsv` file will never
contain tabs that are not meant to separate fields -- it's your job as a
programmer to never save invalid TSV files (eg, files with too many tabs, or
otherwise misformatted lines).

You may want to use the `strtok` function (see `man 3 strtok) to split apart a
string on its tab boundaries during loading.

How are you going to read each line of the file, one line at a time? Once you've
read a line, how are you going to extract those fields out of the line of text?
Also note that the customer database could be somewhat long, potentially
thousands of entries!

Once you've extracted the fields, what are you going to do with the information?
(you've got to put it in a hash table -- how, exactly?)

## storing customers in a hash table
Our customers are uniquely identified by their email addresses, so we want to be
able to look them up by email address.

Very similarly to [the demo we did in
class](https://git.ucsc.edu/ajrudnic/cse-13s-demos-winter-2025/-/blob/main/hashtables/hashtable.c),
we will establish a hash table containing a bunch of *buckets*, where each
bucket has a linked list of Customers. So essentially the hash table contains an
array of linked lists.

How do you figure out the appropriate bucket for a given customer? Take the hash
of their email address and then modulo by the number of buckets! How many
buckets do you want to use?

## saving the customer database file

When you do the `save` command, you'll open the `customers.tsv` file for writing
and store the current state of the hash table into that file. It should be in
the same format, as described above, but it will likely be in a different order.
That's fine!

How will you open a file for writing? How will you write structured data into
it? (consider using `fprintf` for this?)

## Cleaning up our messes

For this homework, we are allocating various dynamic data structures (possibly
several of them), with `malloc`, `calloc`, and `realloc`.

You need to make sure that we have a plan for `free`-ing all the memory we
allocate. Which parts of the code will allocate? How can you make sure every
allocated pointer gets `free`d?

In order to find out whether your code is cleaning up its messes, you should use
a tool called Valgrind.

If you have not yet installed Valgrind on your Linux system, you can install it
like so:
```
sudo apt install valgrind
```

You can run Valgrind to find out whether your program is leaking memory with the
following command:

```
valgrind --leak-check=full  ./businessdb
```

Valgrind will then tell you whether you are successfully cleaning up all of the
allocated memory, or whether your program has leaks.

## The structure of your program

You should separate out your program into a main C file, at least one library C
file with its own header *and tests*. You might decide that hash tables are one
library, and maybe linked lists are a separate library? Perhaps file I/O goes
into its own library? Up to you!

## Grading rubric
  * 2 points for a DESIGN.md that reasonably discusses all of the problems
    you're going to have to face, and provides some prose descriptions of your
    plans, and/or some pseudocode. (Submit this by Wednesday, in the separate
    Canvas assignment!)
  * +2 points for separating your program into a main C file and at least one
    library (more libraries might be reasonable!)
  * +2 points for good tests
  * +1 point for building the interface and displaying query results
  * +1 point for being able to load and parse customer information from the file
  * +1 point for correctly storing customers in the hash table & linked list
  * +1 point for adding/overwriting and deleting customers correctly
  * +1 point for saving your updated hash table to a file
  * +1 point for not leaking memory.
  * +1 point for writing a good Makefile and compiling with the required class
    CFLAGS.

## deliverables

All of your deliverables for this homework should be checked in to a directory
called `hw7` in your CSE13s gitlab repository. Remember -- *add, commit, push*.

Make sure your executable file is called `businessdb`, but you can divide up
your code into however many source and header files you like.

The resources you need are available in this directory, but remember, this is
mostly on you!

  * By **Wednesday, 12 March 2025**, you should have written your `DESIGN.md`,
    containing your thoughts and plans and pseudocode for this assignment. You
    can change this after the fact, but get planning! This is a separate Canvas
    assignment.
  * All of your code!
  * Makefile -- make sure that you use the standard flags for the class in your
    Makefile.

## reading

You should read...
  * _The C Programming Language_ by Kernighan & Ritchie, Chapter 6 (for some
    background on hash tables)
  * _The C Programming Language_ by Kernighan & Ritchie, Chapter 7 (to
    understand the I/O happening here).
  * _The C Programming Language_ by Kernighan & Ritchie, Chapter 8 (more
    discussion of I/O, also an explanation of realloc).

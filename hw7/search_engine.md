# homework 7: Hash tables, I/O and strings

**Due date: Friday, 14 March 2024, 11:59pm**

# introduction

You know what used to work really well? [Search
engines](https://en.wikipedia.org/wiki/Search_engine). They seemed magical. The
idea that you could type a query into a search box and find documents, either in
some specific database, or on the [world wide
web](https://en.wikipedia.org/wiki/World_Wide_Web), that contained the search
terms that you had specified, was really exciting.

Let's build a tiny one!

# Moving parts

## Loading the documents

When your program starts up, it will read a collection of *documents* into
memory. Exactly which documents you want to work with is up to you, but if you
don't have a specific idea, we've provided you with a collection of
Shakespeare's sonnets, in a simplified format, for easy loading. This is a
stripped-down version of [the Project Gutenberg text, available
here](https://www.gutenberg.org/ebooks/1041).

What you should collect, for every document, is its title (in the case of a
sonnet, this is just its number in roman numerals) and the entirety of its text.

You're going to need to get a little creative here -- how will you know when
you've reached a new sonnet?

In any case, you should design a data structure that can contain all of the
documents, with their title and text, for quick access. I might suggest a
*struct* to hold the information about a single document, and having a big array
of these structs that you can `realloc` as it grows.

Every document's ID number will be its *index* in that array -- or at least, you
need some way to have each document get its own unique ID number.

## Indexing the documents

After you've loaded all of the documents into memory, it's time to build our
*search index* -- this is the data structure, like an index at the back of a
book, that contains a mapping from each *word type* that you have encountered to
a *set* of the document ID numbers, for the documents that contain this word
type.

So for example, if documents 15 and 97 contain the word "lively" (in fact there
are two sonnets in the given collection with "lively" in them), then your
*index* will contain the mapping:

```
  "lively" : {15, 97}
```

How will you build this data structure? This should be a hash table mapping from
word types to sets of document IDs. You can use whatever representation you like
for sets, but I might suggest something simple like a linked list of numbers --
you could get fancy and do bitwise operations like we did in class, but keep in
mind that we're going to have potentially many more than 64 items in our sets.

How will you actually fill in this data structure? Here is some pseudocode to
get you started with the idea...

  * For each document we've loaded, give it the next available ID number
  * Now for each document...
      * split the text of the document into *tokens* -- find all of the sequences of
        numbers and letters (ie, consider whitespace and punctuation to be word
        boundaries), perhaps using regular expressions, and consider what you find
        to be "words".
      * For each word we find...
        * Add the current document ID to the set of document IDs for the current
          word.

At this point, you have built an index mapping from every word type to the set
of documents containing that word.


## Queries

This search engine will offer two different querying modes, `AND` queries and
`OR` queries. In either case, the user can enter as many query terms as they
like.

If we are doing an `AND` query, then we will return and print only the documents
that contain *all* of the given search terms -- this is equivalent to taking the
*intersection* of the sets stored in the index.

If we are doing an `OR` query, then we will return and print the documents that
contain *any* of the given search terms -- this is equivalent to taking the
*union* of the sets stored in the index.

## Main interaction loop

On startup, your program should load the documents into memory and build the
search index, as described above. Then, you should prompt the user to enter a
command. The commands are as follows...

  * `and` -- switch to "and" mode, doing set intersection on search results
  * `or` -- switch to "or" mode, doing set union on search results
  * `search` -- prompt the user for a query, split the query by whitespace, and
    return and print out the appropriate documents that match the given search
    query.
  * `quit` -- exit the program

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
valgrind --leak-check=full  ./search
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
    plans, and/or some pseudocode. (Submit this by Wednesday in the separate
    Canvas assignment)
  * +2 points for separating your program into a main C file and at least one
    library (more libraries might be reasonable!)
  * +2 points for good tests
  * +1 point for building the interface and displaying query results
  * +2 points for being able to load and parse the documents
  * +2 points for sensibly storing documents
  * +1 point for not leaking memory.
  * +1 point for writing a good Makefile and compiling with the required class
    CFLAGS.

## deliverables

All of your deliverables for this homework should be checked in to a directory
called `hw7` in your CSE13s gitlab repository. Remember -- *add, commit, push*.

Make sure your executable file is called `search`, but you can divide up
your code into however many source and header files you like, as long as you
have at least one separate library with its own tests and a Makefile.

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

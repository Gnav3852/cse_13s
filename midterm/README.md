# CSE 13s, Winter 2025 -- Midterm Exam

**HOWTO do this midterm** -- this is a take-home exam, to be done by just you,
with your notes, with the reading materials, and with your ability to read man
pages and search the web. Do not consult with other students, and do not ask
people other than the course staff for help!

The exam is due in 24 hours (+ accommodations), and turned in the same way
that we turn in homeworks. You must check in your materials into your
course git repository *and* upload the relevant commit ID on Canvas by then.
For most students, this is due at *2:40pm on Thursday 13 February 2025*. 

So make sure you check in *at least* these files into a directory called
`midterm` in your git repository:
  * your completed `honesty.md` (sign that you're doing this solo; use your name)
  * your completed `answers.txt` (answers to the multiple choice questions)
  * your completed `one.c`
  * your completed `two.c`
  * your completed `three.c`
  * your completed `four.c`
  * the provided `midterm.h` (you won't have to change this)
  * your `Makefile` for compiling the code (you won't have to change this)

For the multiple choice questions, put the corresponding letter for each
problem. For the programming problems, *your code will be checked
automatically*, so make sure to put your code in the correct file (ie, `one.c`,
`two.c`, and so on).

## getting started

In your gitlab repository, which you likely checked out into your home directory
on your Linux system, so it might be the directory `~/cse13s_sammytheslug` (if
you are Sammy The Slug), make a new directory called `hw4`.

```
$ cd ~/cse13s_sammytheslug
$ mkdir midterm
$ cd midterm
```

Then copy the following files into that directory, using `cp` (these are present
in the [cse-13s-resources-winter-2025
repository](https://git.ucsc.edu/ajrudnic/cse-13s-resources-winter-2025/), which
you should probably check out onto your computer) -- these files are in the
`midterm` directory in that resources repository:
  * `honesty.md`
  * all of the C files (`one.c`, `one_test.c` and so on)
  * `midterm.h`
  * `Makefile`
  * `check_multiple_choice.py`

If you have already checked out the `cse-13s-resources-winter-2025` repository,
you can get the latest files in it by going into that directory and doing a `git
pull`.


# multiple choice questions: 10 points

Please use the provided answer file, and check it in to your `midterm`
directory.
You can make sure that your `answers.txt` will be parsed correctly by running
the following command, since you have copied `check_multiple_choice.py` into
your directory:

```
$ python3 check_multiple_choice.py
```

Note that if your `answers.txt` does not parse correctly with the provided
`check_multiple_choice.py`, you won't get credit for your multiple choice
answers, so make sure the formatting is right!

1. **When you are building a C program out of many C source files, which of the
   following are true?**
  - A: You can't call functions in other C files unless they were defined in a
    common header file.
  - B: You can have only a single `main` function, and if you try to have more
    than one, this is an error.
  - C: You can define which `main` function you want to call as a compile-time
    option, specified in your Makefile.
  - D: Each C file can have its own `main` function as long as they have
    distinct return values.
2. **What happens if you free a pointer and then dereference it?**
  - A: The pointer still points to valid memory, so you can safely access it.
  - B: The program is guaranteed to crash immediately.
  - C: The behavior is undefined; it may crash, work normally, or cause subtle bugs.
  - D: The pointer is automatically set to NULL, preventing further issues.
3. **Which of the following are true, about map and reduce?**
  - A: Map as an operation takes a collection of data and applies a function to condense it down into a single result.
  - B: Map and reduce can often make operations that would usually take many computers go faster on a single computer.
  - C: Map takes a function pointer as an argument, but reduce does not.
  - D: Map and reduce can be applied to arrays, linked lists, or other collections.
4. **If you declare a variable `int x = 12;` in your main function, where has that variable been allocated?**
  - A: On the heap.
  - B: On the stack.
  - C: It might be on the stack or the heap, depending on our chip.
  - D: Neither; it is only in a register.
5. **Which of the following are good reasons to take the address of a variable on the stack?**
  - A: You can do this to allow other functions to change those variables, emulating pass-by-reference.
  - B: This is helpful if you need to migrate a variable from the stack to the heap.
  - C: It's never a good idea; this will result in a segmentation fault.
  - D: You can do this to use those variables after their function has returned.
6. **How many integers are there in mathematics, and how many numbers of type `int` are there in C?**
  - A: countably infinitely many; a finite number
  - B: uncountably infinitely many; about four billion (depending on the
    architecture)
  - C: countably infinitely many; countably infinitely many
  - D: countably infinitely many; uncountably infinitely many
7. **When deleting a node (other than the head) from a (singly) linked list, what do you typically need?**
  - A: Only a pointer to the node to delete.
  - B: A pointer to the previous node so you can adjust that node's next pointer to skip the node being deleted.
  - C: A pointer to the head node is sufficient in all cases.
  - D: You cannot delete any node except the head in a singly linked list; you need a doubly linked list to delete other nodes.
8. **Suppose we have a 32-bit int, `int x = 0x12345678`, and it happens to be stored at memory at address `&x` = 100.  In little-endian memory ordering, which byte would be at address 100, the lowest memory address?**
  - A: 0x78
  - B: 0x12
  - C: 0x34
  - D: 0x56
9. **Which of these is typically not true when comparing the performance of a linked list to an array, containing the same elements?**
  - A: An array uses less memory than a linked list.
  - B: If you have a pointer to an arbitrary element, it's faster to insert a new element after it in an array than a linked list.
  - C: Accessing an element at an arbitrary position is faster in an array than a linked list.
  - D: It is very fast to look up the first element in an array and a linked list.
10. **malloc and calloc return pointers to the heap, of type `void *`. Why don't they return the type that you requested?**
  - A: They can't, since C does not have support for functions that return multiple different types.
  - B: They could, but they don't for performance reasons.
  - C: They can't, since there's no way to return pointers to functions, and you might want to allocate a function.
  - D: They could, but it would make the API more awkward since you would have to pass the desired type as a parameter.


# programming problems: 20 points
Each of these problems is worth 5 points. They are to be implemented in their
own separate C files, and some tests are given in the corresponding test C
files. They'll be graded with different (but similar) automatic tests.

You don't have to check in the test files, but you can if you want to. Feel free
to change the tests -- but make sure you pass the ones that are given! Also,
don't worry about memory leaks right now, although *morally* you should free
memory in question 2.

It is OK, and encouraged, to add helper functions as you need them, and feel
free to reference code that you wrote from your homeworks, or that we wrote
together in the in-class demos.

## one

Write a function `long long *factorial_numbers(size_t n)` that returns the first
*n* factorial numbers (starting with factorial of 0), in a dynamically allocated
array of type `long long`. Recall that factorial(n) is the product of 1 * 2 *
... * n and factorial(0) is defined as 1.

It's your job to allocate the array and fill it up. It's not your job to free
the memory!

Should this be done iteratively or recursively? This is up to you!

See `one_test.c` for examples of how this might be called.

## two

For this function, you are given a linked list of floats. Your task is to
delete all numbers within a given range \[start, end\] (inclusive) from the
linked list. The list might be empty (i.e., it could be NULL), or it could be of
any positive length that fits in memory. If none of the numbers in the list are
in the specified range, then the linked list should remain unchanged.

Function Signature: `ll_float *delete_range(ll_float* head, float start, float end);`

Note that this function will return *the new head of the linked list* (since the
head might change due to being deleted), but nodes that are not deleted should
be left in place -- we're not making a new copy of the linked list. We're
modifying it to delete the entries that we want to delete.

An example would be something like this:

  * Input 1.0 → 2.0 → 3.0 → 4.0 → 5.0
  * Range: [2.0, 4.0]
  * Output: 1.0 → 5.0

See `two_test.c` for examples of how this might be called.

## three

In problem three, you'll write a function
`size_t count_strings_with_property(bool (*property)(char *), char **strings, size_t len)` ,
which takes a *property*, a function that takes a string and returns either true
or false, and an array of strings, along with that array's length. This function
returns the *count* of the strings in the string array for which the specified
function returns true. The array of strings is guaranteed to not be NULL, and
each of the entries is guaranteed to not be a NULL pointer, although it might be
an empty string.

See `three_test.c` for examples of how this might be called.

## four

[Bubble sort](https://en.wikipedia.org/wiki/Bubble_sort) is a simple (but
relatively inefficient) sorting algorithm that works by comparing elements in an
array and swapping them if they are in the incorrect order.

The pseudocode looks like:

* keep doing this...
  * for every element x of my input array
    * for every *other* element y of my input array
      * if x should go before y but does not, swap x and y's position in the
        array
* stop if I did not perform any swaps

Imagine that we are working at an online shoe retailer, and we want to sort our
customers by how many purchases they have made.

Implement a function for bubble sorting procedure that sorts customers by number
of purchases, ascending -- *so the customers who made the smallest number of
purchases will go first*.

There are a few variants of bubble sort, so if your exact procedure is not
exactly like the pseudocode, that is OK as long as you do (a) sort the array as
requested and (b) sort by repeatedly swapping elements that are out of order.


See `four_test.c` for an example of how this might be called.

----

# finally

Thanks a bunch! You got this. Thanks for showing up and being interested and
asking good questions in class. Alex et al will be around on the discord to give
*clarifications*, but not hints.

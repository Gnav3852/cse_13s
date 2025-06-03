# CSE 13s, Winter 2025 -- Final Exam

**HOWTO do this final** -- this is a take-home exam, to be done by just you,
with your notes, with the reading materials, and with your ability to read man
pages and search the web. Do not consult with other students, and do not ask
people other than the course staff for help!

The exam is due in 24 hours (+ accommodations), and turned in the same way
that we turn in homeworks. You must check in your materials into your
course git repository *and* upload the relevant commit ID on Canvas by then.
For most students, this is due at *noon on Wednesday 19 March 2025*. 

So make sure you check in *at least* these files into a directory called
`final` in your git repository:

  * your completed `honesty.md` (sign that you're doing this solo; use your name)
  * your completed `answers.txt` (answers to the multiple choice questions)
  * your completed `one.c`
  * your completed `two.c`
  * your completed `three.c`
  * your completed `four.c`
  * your completed `five.c`
  * the provided `final.h` (you won't have to change this)
  * your `Makefile` for compiling the code (you won't have to change this)

For the multiple choice questions, put the corresponding letter for each
problem. For the programming problems, *your code will be checked
automatically*, so make sure to put your code in the correct file (ie, `one.c`,
`two.c`, and so on).

**Two things to note**
  * your directory in your repository must be called `final`
  * turn in your git commit id (40 hexadecimal characters) on Canvas
  * thanks!

# multiple choice questions: 15 points

Please use the provided answer file, filled in with your own answers, and check
it in to your `final` directory. You can make sure that your `answers.txt` will
be parsed correctly by running the following command, if you copy
`check_multiple_choice.py` into your directory:

```
$ python3 check_multiple_choice.py
```

1. **What does the #include directive do in C?**
  - A: It includes a header file, which can contain function prototypes and constants
  - B: It directly links object files to the program
  - C: It runs a preprocessor command to modify the source code
  - D: It compiles the included files into the program
2. **Suppose an 8‑bit unsigned integer myset represents a set, where each bit corresponds to an element either being present in the set (on) or not present (off); which expression correctly checks if a specific element n is in the set?**
  - A: `myset | (1 << n)`
  - B: `myset & (1 << n)`
  - C: `myset ^ (1 << n)`
  - D: `myset & ~(1 << n)`
3. **Which of the following operations in a C program running on Linux do not require doing a system call?**
  - A: writing a file to the filesystem
  - B: ejecting the CD tray
  - C: calling `strcmp` to compare strings allocated on the heap
  - D: opening a network connection
4. **Which property of regular hash functions makes them unsuitable for encrypting data?**
  - A: They are too slow for practical use
  - B: They are one-way functions designed not to be reversible
  - C: They produce too large of an output
  - D: They require too much processing power
5. **What is the primary purpose of a linker in the C compilation process?**
  - A: To translate C source code into machine code
  - B: To check the syntax of C programs
  - C: To combine object files and resolve external references
  - D: To optimize code for better performance
6. **What will happen if you try to dereference a null pointer in C?**
  - A: The program will crash with a segmentation fault
  - B: It will result in undefined behavior, potentially causing data corruption
  - C: It will return NULL as a valid pointer value
  - D: It will automatically allocate memory at the address 0x0
7. **If** `int *p = &a` and `int a = 20;` , **what would the value of** `*(p + 2)`
   **be?**
  - A. The value of `a`
  - B. It depends on the type of pointer
  - C. Undefined behavior due to pointer arithmetic
  - D. The value stored at the memory address of `a + 2 * sizeof(int)`, which may not exist
8. **Say we wanted to run the BAD programming language inside a web browser. What would help us do this?**
  - A: We need a compiler to translate BAD programs into machine code for every different kind of computer that we want to support
  - B: The best way will be to petition web browser vendors to include support for the BAD language soon
  - C: We could write a compiler that would translate BAD programs to JavaScript programs
  - D: This actually cannot be done, since the BAD programming language depends on an interpreter written in Python
9. **What's the difference between breadth-first and depth-first search over a graph?**
  - A: BFS is implemented iteratively (with a while loop), while DFS is implemented recursively.
  - B: With BFS, we use a stack and radiate outward from the initial point, but with DFS we use a queue and go as far as we can down each individual path, first.
  - C: With BFS, we use a queue and radiate outward from the initial point, but with DFS we use a stack and go as far as we can down each individual path, first.
  - D: Depth-first search is useful on *directed* graphs like trees, whereas breadth-first search is useful on the more general case of *undirected graphs*.
10. **Which of the following are good reasons to take the address of a variable on the stack?**
  - A: It's never a good idea; this will result in a segmentation fault.
  - B: You can do this to use those variables after their function has returned.
  - C: You can do this to allow other functions to change those variables, emulating pass-by-reference.
  - D: This is helpful if you need to migrate a variable from the stack to the heap.
11. **How would you go about writing a function `size_t number_of_numbers(int* numbers)` , to determine the size of a dynamically-allocated array of ints?**
  - A: Every array carries its size, so you can just return `numbers->size`.
  - B: You can use sizeof() to find the size of an array.
  - C: Start at the beginning of the array and walk through the elements until you find a null element.
  - D: You can't do that, since C passes arrays as pointers to the initial element of the array.
12. **Which of these things can you do with regular expressions?**
  - A: Compactly describe any set of strings.
  - B: Define a context-free grammar to describe the syntax of a programming language
  - C: Write a regular expression for matching any number of the letter 'A', followed by *the same number* of the letter 'B'.
  - D: Compactly describe nondeterministic finite-state automata for matching strings
13. **When you call calloc, what does it return?**
  - A: a pointer to memory on the heap
  - B: it depends on the type of variable you are trying to allocate
  - C: a pointer to memory on the stack that has been set to 0
  - D: it depends on your operating system
14. **Which of the following are true about pipes (the | operator) in UNIX?**
  - A: pipes are a mechanism for protecting each users' virtual memory from other users' processes
  - B: you can use pipes to connect the standard output of one process to the standard input of another process
  - C: pipes make sure that the first process completes successfully before running a second process.
  - D: pipes are the only way you can use grep on UNIX.
15. **When you're building a new application, which of the following is a good way to store your users' passwords?**
  - A: Don't store the passwords directly; store hashed versions of them along with their cryptographic salt.
  - B: Store the passwords in a hash table, for quick lookup.
  - C: Store your application's users' passwords in /etc/shadow.
  - D: Encrypt each one with a one-time pad and store the OTPs separately.

# programming problems: 25 points
Each of these problems is worth 5 points. They are to be implemented in their
own separate C files, and some tests are given in the corresponding test C
files. They'll be graded with different (similar, but more comprehensive)
automatic tests.

You don't have to check in the test files, but you can if you want to. Feel free
to change the tests -- but make sure you pass the ones that are given! Also,
don't worry about memory leaks right now.

It is OK, and encouraged, to add helper functions as you need them, and feel
free to reference code that you wrote from your homeworks, or that we wrote
together in the in-class demos. You can also add more includes at the top of
your C file if you feel you need them, but you may not change the Makefile to
add additional libraries at link time.

Note that if your code crashes on any of the tests, you will probably not
receive partial credit for the problem -- the test program has to get to the end
(even if some of the results are wrong!) for you to get credit for that
particular problem.

## one

For this problem, write a function: `size_t count_increasing_columns(int
**matrix, size_t rows, size_t cols)`, which counts how many of the columns in
the specified matrix are *strictly increasing*.

You are given a dynamically allocated 2D array (matrix), with `rows` rows and
`cols` columns. A column is said to be strictly increasing if each element in
that column is strictly greater than the element above it (no ties allowed).
Return how many columns satisfy that property.

For example! If `matrix` (4×3) is:

```
  1   3   2
  2   4   2
  3   5   3
  4   6   5
```

  * Column 0: [1, 2, 3, 4] is strictly increasing (1 < 2 < 3 < 4).
  * Column 1: [3, 4, 5, 6] is also strictly increasing.
  * Column 2: [2, 2, 3, 5] is not strictly increasing (2 == 2 at the top).

Hence, `count_increasing_columns(matrix, 4, 3)` returns 2.

See `one_test.c` for examples of how this might be called.

## two

Write a function `char *remove_characters(char *text, char *toremove)`,
which, given an input string `text` and an input string `toremove`, allocates a
new string that is the same as the input `text` except that all of the
characters that are present in `toremove` have been removed (and not replaced),
even if they occur many times.

So for example, given the input `text` `"Sphinx of black quartz, judge my vow"`
and the `toremove` string `"aeiou"`, this function would allocate a new string
`"Sphnx f blck qrtz, jdg my vw"`.

If the `toremove` string is empty (or none of the characters that are to be
removed are present in the string `text), then the output string will be a
*copy* of the input string -- you should always allocate a new output string.

See `two_test.c` for examples of how this might be called.

## three
Write a function `int apply_many_times(int (*func)(int), int x, size_t n)` that,
given a function pointer to a function that takes an `int` and returns an `int`,
repeatedly runs that function on the number `x`, `n` times.

So for example, if you are asked to apply a function to x three times, your
return value would be equal to: `func(func(func(x)))`. If you are asked to apply
the function 0 times, just return x.

You're guaranteed (by the type system!) that `n` will be 0 or greater. You could
write this function either iteratively or recursively, and both would be very
reasonable.

See `three_test.c` for examples of how this might be called.

## four
Write a function `int sum_values_at_max_depth(BinaryTree *tree)`, in which
you'll search a binary tree of integers and you'll return the sum of the nodes
that occur at that tree's *maximum depth*. Note that this is not the same as the
leaves of the tree, since some leaves are not at the maximum depth.

If you're given an empty tree, return 0.

For a visual example, consider this tree:

```
         1
       /   \
      2      3
     /      / \
    4      5   6
   /      /  
  8      7 
```

So here, 8 and 7 are at the maximum depth (3 steps from the root node), but the
leaf node 6 is not at that maximum depth. So we would return 8 + 7 = 15.

See `four_test.c` for examples of how this might be called.

## five
For this function, you'll be working with a kind of binary search tree called a
`WordCountTree`, which we might use if we were doing some linguistics, say
counting up the number of occurrences of a particular word in a document. A
`WordCountTree` maps from each word type that we have seen to the number of
times that it has occurred, allowing us to look up those word counts quickly. It
is ordered in standard lexicographic sort order, just by whatever `strcmp` (see
`man 3 strcmp`) returns.

Here you'll write a function `WordCountTree *merge_trees(WordCountTree *tree1,
WordCountTree *tree2)` that *merges* two of these trees, creating a new output
tree that you'll need to build.

This works as follows:

  * Any word that was present in either of the trees will be present in a
    completely new output tree that you create.
  * If that word only occurs in one of the input trees, then it will be mapped
    to the count from the one tree that it appeared in.
  * If a word appears in both input trees, then its associated count in the
    output tree is the sum of its counts in the two input trees.

See `five_test.c` for examples of how this might be called.

----

# finally

Thanks a bunch! You got this. Thanks for showing up and being interested and
asking good questions in class. Alex will be around on the discord to give
*clarifications*, but not hints.

You've all been a joy. Hope to see you in future classes on your CS journey, and
let's keep building fun programs!

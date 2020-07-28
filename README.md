# Hackerank practice files

I will try to insert my own annotations here as well

# hackerrank style.

I suspect hackerrank is more python and new language oriented because certainly its C template code
does not take care to free() certain variables during input.

This is a bad habit, but for one time input reading, it's not a big deal. 

## input treatment in C and C++

Hackerank input handling is based on interactive user input. This is an old paradigm which Big Data scientists 
will find unsuitable, but nevertheless if you are operating in the hackerrank system you need to abide by it.

Now having said that you can also redirect input into the program using <.

Both methods should work.

If you arrive at hackerank for the first time wanting to code in C or C++, you will probably encounter trouble with input output.

Alot stems from the use of an unconventional environment variable which they call "OUTPUT_PATH". Why? Well because:

* This very often does not exist by default (on a base Linux system).
* It is not a path (ie. folder or directory) but actually a file).

It's covered in this stack overflow post:

https://stackoverflow.com/questions/52170367/what-does-this-code-mean-ofstream-foutgetenvoutput-path

# input reading style

the customer readline() function operates so that multiple lines can read. When each line is known to have more than one element
the splitline function is also called

## Input naming style

As usual, input is first seen as a string, so the first value is attached to the t_str -named variable. Thisis passed to strtol()
to give "t". I presume this means "total" as in,t he number of subproblems, i.e. the number fo times the outer loop should be run.

Overall, there's a sense that the boilerplate code for C is neglected when updating, and naming is very lax, so that a name like
arr_count is used for the actual size of an array.

# Contents

## couinv0.c
This actually is a rationalisation and annotation of hackerrank's input handling functions.


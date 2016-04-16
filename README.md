# CPlusPlus
Stock C++ code for the Language Library Design of C++ with Bjarne Stroustrup.

#### The purpose of this assignment is to find that for which *N* is it better to use a linked list than a vector (or an array) to represent the sequence?

Sorting program:
- Program generates N random integers and inserts them into a sequence so that each is inserted in its proper position in the numerical order.

  For example 5 1 4 2 gives:

  5

  1 5

  1 4 5

  1 2 4 5

- We then remove elements one at a time by picking a random position in the sequence and remove the element there.

For example positions 1 2 0 0 gives:

1 2 4 5

1 4 5

1 4

4

- The sequence grows incrementally. 


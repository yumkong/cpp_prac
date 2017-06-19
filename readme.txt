#0612
./previous_prac
(1) work2_1st.cpp
==> derivative class and basic class: derivative class has implict member vars and funcs of the basic class
(2) work2_2nd.cpp
==> oridinary member func and viritual member func
(3) work2_3rd.cpp
==> set destructor func as virtual
==> so that when deleting a dynamically allocated derived obj, it can call both the derived destructor and the base destructor
(4) work2_4th.cpp
==> further illustration of virtual member fun in Father-Child-Grandchild relation

#0613
(5) work3_1st.cpp
==> direct and copy constructor
(6) work3_2nd.cpp
==> use a template class object as a predicate (a param of a standard library function)

#0614
./previous_prac
(7) work5_new
==> try best to encapsulate all funcs and properties to a class
    work5_old: the same functionality written last year, less encapsulated
(8) work7_1st: 2d array class
    work7_2nd: 3d array class
./cc
(9) cc1_1: 
==> create an array as hash table to check uniqueness
(10) cc1_2:
==> swap string elements between head and tail
(11) cc1_3 (both _me and _other):
==> during the for loop check of string, change the string content simutaneously

#0616
./cc
(12) cc1_4: check isAnagram
method1: use a hashtable to count char occurances
method2: sort and directly compare string
(13) cc1_5: replace a char in string with a substr
(14) cc1_6: rotate an image by 90 degrees (use a little math)
(15) cc1_7: use two sets to record row/col indices where 0 occurs
(16) cc1_8: a smart way to check rotated string

#0617
./cc
(17) linklist.cpp:  a warm up file for linklist: create/destroy a linklist, insert/delete a node from a linklist
(18) cc2_1: delete duplicated data from linklist using set
(19) cc2_2: find nth last element from a linklist
(20) cc2_3: rewrite linklist myself. Remove a certain node from linklist, given only access to that node.
(21) cc2_4: add two linklists like the sum of 2 integers
(22) cc2_5: detect loop of a link list with map container

#0618
./cc
(23) cc3_1: use an array to hold 3 stacks
(24) cc3_2: let stack output min() func in O(1) time
(25) cc3_3: set of stacks
(26) hanoi: solve classic hanoi tower with recursion
(26_2) cc3_4: hanoi tower with iteration (using stack)
(27) cc3_5: implements a queue with 2 stacks
(28) cc3_6: sort a stack (inplace or save to another stack)

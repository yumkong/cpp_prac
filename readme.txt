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


#0619
./cc
(29) cc4_1: check if a tree is balanced
(30) cc4_2: check whether there is a path between 2 nodes in a directed graph
(31) cc4_3: create a binary tree with minimal height given sorted array
(32) cc4_4: create a linklist for each tree level
(33) cc4_5: find the successor of a given node in a binary search tree
(34) cc4_6: find the frist ancestor of two nodes in a tree
(35) cc4_7: check if a tree is another tree's subtree
(36) cc4_8: find all tree paths where the sum of the node on the path equals to a certain number
./cpp_primer
(37) cpp16_1: template function to get absolute of a value
(38) cpp16_2: template function to print out to different streams (file, screen(cout), and memory(stringstream))
(39) cpp16_5: template function to get the max of two vals
(40) cpp16_9: template function using different vectors' iterator as arguments
(41) cpp16_12: get the maximal occurence element of a container
(42) cpp16_13: print container's elements
(43) cpp16_14: same as (42)
(44) cpp16_15: template func with non-type template parameter: return an array's length
(45) cpp16_16: template func with non-type template parameter: print a container's elements

#0620
./cc
(46) cc5_1: use a binary segment to replace a sub-segment of an int
(47) cc5_2: represent a decimal in binary
(48) cc5_3: given an integer, print the next smallest and next largest nmber that have the same number of "1" bits
(49) cc5_5: count how many bits need to be flipped to convert (int a) to (int b)
(50) cc5_6: swap odd and even bits in a integer with as few instructions as possible.
(51) cc5_7: check which number is missing from a set of n numbers (0,1,2,...,n). Each integer is only accessible in one bit at a time.
(52) recursion: Fibonacci series

./cpp_primer
(53) cpp16_25: data type casting and explicit template argument when using function template
(54) cpp16_27.cpp, cpp16_27_median.cpp and cpp16_27_median.hpp: how to divide function implementation and declarition
(55) cpp16_32: self-defined Queue class template
(56) cpp16_34: self-defined List class template (find a bug of the solution book)


#0621
./cpp_primer
(57) cpp16_52: count the number of occurences of an elment in a vector
(58) cpp12_13: extend the Screen class to include move(), set(), and display()

./cc
(59) cc8_2: count how many paths that a robot can go through a maze
     cc8_2_add:  what if there is "limit off" (obstacles)
(60) cc8_3: get all subsets of a set
(61) cc8_4: get all permutations of a string
(62) cc8_5: print all valid combinations of n-pairs of parentheses
(63) cc8_6: paint fill
(64) cc8_7: number of combinations of 25, 10,10, 5cents to get an arbitray n cents
(65) cc8_8: classis eight queen


#0622
./cc
(66) cc9_1: merge two sorted arrays
(67) cc9_2: sort an array of strings so that all anagrams are next to each other
(68) cc9_3: search a number in O(logn) on a sorted array after one time's back-forth rotation
(69) cc9_5: given a sorted array of strings which is interspersed with empty strings, find the location of a given string
(70) cc9_6: given a matrix in which each row and each column is sorted, find an element in it => do it in O(row + col)
(71) cc9_7: given height and weight of each person, compute the largest number of people in a tower (where the higher the tower, both the shorter and lighter the person is)
(72) cc10_4: implement -,*,/ with only +
(73) cc10_6: given a 2d graph with points on it, find a line that passes most number of points
(74) cc10_7: find the i-th integer whose only prime factors are 3,5,7


#0623
(75) cc12_3.cpp: given an input file with 4G (4 billion) integers, generate an integer which is not contained in the file (assume 1GB memory)
     cc12_3_add.cpp: same problem, but assume only 10M memory (the integers have no duplicates)
     cc12_3_add2.cpp: same problem, assume only 10M memory (the integers have duplicates)
(76) cc12_4.cpp: given an array with all numbers from 1 to N, where N at most 32,000 (2^15), the array may have duplicate entries and N is unknown. How to print all duplicate elements in the array?
(77) cc13_1.cpp: print the last K lines of an input file
(78) cc13_6.cpp: a toy program to show C++'s hiding name phenonmenon
(79) cc13_9.cpp: smart pointer
(80) cc16_5.cpp: find whether big endian or little endian of your machine
(81) cc16_10.cpp: write a function my2DAlloc which allocates a 2d array. It should minimize the number of calls to malloc and make sure the memory is accessible by arr[i][j]
(82) cc19_1: swap 2 numbers in place without temporary variables
(83) cc19_2: figure out if someone has won tic-tac-toe
(84) cc19_3: compute number of trailing zeros in n fractorial
(85) cc19_4: find the maximum of 2 numbers, not use if-else or comparison operator
(86) cc19_6: translate number to string


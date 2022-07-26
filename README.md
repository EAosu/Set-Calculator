# Set-Calculator

Intro: 
In this exercise we implemented a programable set calculator using recursive calls to one of the three basic operations:
Uni(on):  mathematical union between two groups A B will result the output of: (A U B)
Inter(section): Intersecting between two groups will result the output of: ( A ^ B )
Diff(erence): calculating the diff between A and B will be defined as: A – (A^B) 
(And printed as: A – B)
Using those three basic operations the user will be able to create more complex operations.

Main Classes used in the program:
Class set: This class is the basic data structure of the program; this class contains a private vector of integers which represents the given set by the user and some set-handling functions.
Class Operation: This is the base class for any in-program operation. The class contains the number of sets needed for the operation and some virtual functions.
Class AccOperation:  This is a middle class which connects between class "operation" and all the leaves which are the simple operations between two sets of the inheritance tree. Contains two shared_ptr's of operation which points to the two accumulated operations.
Class Id: This class oversees the identity operation which returns the set itself, kind of like the function: f(x) = x. 
Class Calculator: This class handles the interface of the program for example- creating more complex operations and handling the menu.
*This class contains a private vector of shared_ptr of operations. This vector will hold all the current operations (base ones and complicated ones which were created by the user).  
Class Comp: Composites between two operations. The way it works is that it calculates the first operation and inserts the result as the first input of the second operation.

Worth Mentioning data structures:
Vector of shared_ptrs which contain operation (and comp operations) to enable complex operations along with adding and removing current operations.
A binary tree of operations as displayed above in the picture and described in AccOperation. 
Worth Mentioning Algorithms:
None 

Known bugs:
if you enter a char instead of int as a set size or into a set itself it would result in an unexpected behavior.
Other notes:
None.

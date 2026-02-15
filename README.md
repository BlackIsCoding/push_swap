*This project has been created as part of the 42 curriculum by <akoudri>*



# Description :

Push Swap is a project where the goal is to sort a list of integers entered by the user through the command line in ascending order, using only a stack-based system and a limited set of operations. A stack is a linear data structure that follows the LIFO principle (Last In First Out), meaning the last element
pushed onto the stack is the first one to be removed.
In this project, we manipulate two stacks (stack A and stack B) and can only interact with the top element of each stack. The objective is to sort all the numbers in stack A using the smallest possible number of operations. The allowed operations include:
* sa, sb, ss – swap the top two elements of a stack
* pa, pb – push the top element from one stack to the other
* ra, rb, rr – rotate a stack upward
* rra, rrb, rrr – rotate a stack downward
The challenge of the project is not only to sort the numbers correctly, but to do so efficiently. The program is evaluated based on the total number of operations used, so simply sorting the list is not enough. The main focus of the project is algorithmic optimization and performance.


# Instructions :

To use the project, first compile it using the provided Makefile. After compilation, an executable program named push_swap will be created.
The program accepts a list of integers as input and outputs the sequence of operations required to sort them. You can test any combination of numbers, and the result will be a list of valid instructions that sorts the stack in ascending order.
The output of the program can be verified using the checker tool provided as part of the 42 project environment to ensure correctness.


# Resources :

Before starting this project, it is important to understand the concepts of stacks and linked lists. The following resources were especially helpful:
* NESO Academy (YouTube):
This channel provides excellent explanations about data structures, particularly stacks and linked lists. The clear tutorials helped me understand stack behavior and how to implement it effectively in code.
* ChatGPT:
ChatGPT was very useful for the algorithmic part of the project. It helped me understand different sorting strategies, suggested approaches to optimize the number of operations, and assisted in debugging and improving my logic.
These resources were used mainly for learning data structures, understanding stack manipulation, and exploring efficient algorithms for solving the Push Swap problem.

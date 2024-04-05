The Push swap project at 42 (École 42) is a programming challenge that involves sorting a stack of integers using a specific set of instructions efficiently. This project is designed to test a student's understanding of sorting algorithms, problem-solving skills, and ability to optimize code for a constrained environment.

Here's an overview of how the Push swap project typically works:

Objective: The main goal is to write a program that sorts a stack of integers using two stacks (referred to as Stack A and Stack B) and a specific set of operations.

Stacks and Operations:

Stack A: This is the initial stack that contains a random sequence of integers.
Stack B: This stack is initially empty and can be used as auxiliary storage.
Operations: You are allowed a specific set of operations to manipulate the stacks, such as:
sa: Swap the first two elements of stack A.
sb: Swap the first two elements of stack B.
ss: Perform sa and sb simultaneously.
pa: Push the first element of stack A onto stack B.
pb: Push the first element of stack B onto stack A.
ra: Rotate stack A upward (the first element becomes the last).
rb: Rotate stack B upward.
rr: Perform ra and rb simultaneously.
rra: Rotate stack A downward (the last element becomes the first).
rrb: Rotate stack B downward.
rrr: Perform rra and rrb simultaneously.
Sorting Requirement: Your task is to sort the integers in stack A in ascending order using the minimum number of operations.

Project Constraints:

Efficiency is crucial. The sorting algorithm should be optimized for speed and the number of operations used.
The project typically has constraints on memory usage and may impose a limit on the number of operations allowed.
Implementation and Optimization:

Students are expected to implement an efficient sorting algorithm that utilizes the provided operations creatively to minimize the number of steps required for sorting.
Various sorting algorithms can be explored and adapted to work with this stack-based model efficiently.
Evaluation:

The project is evaluated based on correctness (whether the stack is sorted correctly), efficiency (number of operations used), and code quality.

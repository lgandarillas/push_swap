# push_swap

## Project Overview

The **push_swap** project is part of the 42 School curriculum. The goal is to sort a list of integers using two stacks, `a` and `b`, with a limited set of operations, in the least amount of moves. 
<br><br>
This README provides a detailed explanation of the algorithm used, named the "Turk Algorithm", by [@ayogun](https://github.com/ayogun).
<br><br>
[Push Swap — A journey to find most efficient sorting algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

## Allowed Operations
- sa : Swap the first two elements at the top of stack a.
- sb : Swap the first two elements at the top of stack b.
- ss : Perform sa and sb simultaneously.
- pa : Push the top element from stack b to stack a.
- pb : Push the top element from stack a to stack b.
- ra : Rotate stack a (shift up all elements by 1).
- rb : Rotate stack b (shift up all elements by 1).
- rr : Perform ra and rb simultaneously.
- rra : Reverse rotate stack a (shift down all elements by 1).
- rrb : Reverse rotate stack b (shift down all elements by 1).
- rrr : Perform rra and rrb simultaneously.

## Getting Started
### Prerequisites
- A Unix-like operating system (Linux, macOS).
- GCC compiler.
1. Clone the repository.
```bash
git clone git@github.com:lgandarillas/push_swap.git
cd push_swap
```
2. Compile the project.
```bash
make
```
3. Usage
```bash
./push_swap 4 2 5 3 1
./push_swap "4 2 5 3 1"
```
4. Test
- To test the number of moves.
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```
- To test if the list is sorted.
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

## Algorithm Explanation
### Turk Algorithm
The Turk Algorithm involves the following steps:
1. Initial Setup
Start with two stacks, a (containing the input list) and b (empty).
2. Push Elements to Stack B
Push all elements from stack a to stack b in descending order. This ensures that when elements are pushed back to stack a, they are in ascending order.
3. Find the Cheapest Number
For each element in stack a, calculate the number of operations required to push it to its correct position in stack b. Choose the element with the least number of operations (cheapest).
4. Handle Special Cases
For stacks with three or fewer elements, sort directly with minimal operations.
For rotations, minimize the total number of operations by rotating both stacks simultaneously when possible.
5. Final Arrangement
Once all elements are in stack a, ensure the minimum element is at the top to complete the sorting.

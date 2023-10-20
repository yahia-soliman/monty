# Simple Monty Interpreter

This projects was made to learn the implementation of Stacks and Queues

## Description
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

### Monty byte code files
Files containing Monty byte codes usually have the ``.m`` extension in the subdir ``mfiles``, we use these files to testout if our monty is going to **behave** like it should be

```bash
zerobors@ubuntu:~/repo/monty$ cat -e mfiles/0.m 
   push     1$
 push    2$
   $
  push 3   anything after the instruction  is ignored   !!$
     pall$
$
#expected$
#3$
#2$
#1$
#$
zerobors@ubuntu:~/repo/monty$ 
````

## Content
Lets deep dive on the content of the repostiory
### 1- Makefile
Simply a make file with just 3 cases :
```bash
zerobors@ubuntu:~/repo/monty$ make monty 
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o monty
zerobors@ubuntu:~/repo/monty$ 
```
Compiling all of .c files in the repo with a spicified flags.
```bash
zerobors@ubuntu:~/repo/monty$ make clean
rm monty
zerobors@ubuntu:~/repo/monty$ 
```
Removing the compiled version
```bash
zerobors@ubuntu:~/repo/monty$ make 12
cat mfiles/12.m
push 1
push 2
push 3
push 4
push 0
push 110
push 0
push 108
push 111
push 111
push 104
push 99
push 83
pstr

#expected
#School
./monty mfiles/12.m
School
zerobors@ubuntu:~/repo/monty$ 
```
Displayes the content of the `.m` file, then excutes the program with that file, it is just a shortcut of not typing the while path of the file twice, we are lazy students uwu.
### 2- instrction.c
 The *Op_standard instructions* functions like pint, pall, ..etc 
 ```C
//  pall_op - Prints all the values on the stack
//  pint_op - Prints the value at the top of the stack, followed by a new line
//  pop_op - Removes the top element of the stack
//  swap_op - Swaps the top two elements of the stack
 ```
### 3- instrcton_math.c
The *Op_mathmatical instructions* functions like add, sub, mul, ..etc
```C
// add_op - Adds the top two elements.
// sub_op - Subtracts the top element of the stack from the second top element of the stack.
// mul_op - Multiplies the second top element of the stack with the top element of the stack.
// div_op - Divides the second top element of the stack by the top element of the stack.
// mod_op - Computes the rest of the division of the second top element of the stack by the top element of the stack.
```
### 4- get_word.c
Most important function of  the whole project, it takes a line of word and index then return that word of that spacific index.
### 5- error.c
Error handling functions

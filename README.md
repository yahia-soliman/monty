# Simple Monty Interpreter

This projects was made to learn the implementation of Stacks and Queues

## Description
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

### MontyMonty byte code files
Files containing Monty byte codes usually have the ``.m`` extension in the subdir ``mfiles``, Most of the industry uses this standard but it is not required by the specification of the language. 
### Example
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
made a set of tests to our monty project in subdir ``tests``, 3 days left untill the deadline and iam wasting my time writing this usless ``README.md`` so i gotta go now 

### Untill next time 
![Cheers](https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.pexels.com%2Fsearch%2Fnice%2F&psig=AOvVaw3iy1iLytjb4JMnUJmrQ9AD&ust=1697663929278000&source=images&cd=vfe&opi=89978449&ved=0CBEQjRxqFwoTCLjT342B_oEDFQAAAAAdAAAAABAE)

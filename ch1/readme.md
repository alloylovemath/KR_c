
# Reference books:  
* *The C Programming Language* (2nd, ANSI C), Brian W. Kernighan & Dennis
M. Ritchie;
* [CS 50, 2022](https://cs50.harvard.edu/x/2022/);
* *C Primer Plus*, (6th ed.), Stephen Prata.

# The Preface of KRC

## First Edition (1978)

**Characteristics of C**:
- general-purpose;
- not a "very high level" language.

## Second Edition

- 1983 American National Standard Institution (ANSI)-> ANSI standard of C (1988)
;

> C is not a big language, and it is not well served by a big book.

- pointers-the central to the C programming.

## Introduction of KRC

- **"system programming language"**-it is useful for writing compilers and
operating systems;
- **fundamental types**: characters, integers, floating-point numbers;
- **fundamental control flow**:  
	- statement grouping?
	- decision making-`if-else`;
	- selecting one of a set of possible cases-`switch`?
	- looping *with the termination test at the top*-`while, for`;
	- looping *with the termination test at the bottom*-`do`;
	- early loop exit-`break`

# The History of C Standards

## *K&R C* or *Classic C* (1978);

The book writen by K&R.

## ANSI C (ISO C)

Offically adopted in 1989 (1990 ISO)-*C89*, *C90*

**The Sprit of C**:
- Trust the programmer;
- Don’t prevent the programmer from doing what needs to be done;
- Keep the language small and simple;
- Provide only one way to do an operation;
- Make it fast, even if it is not guaranteed to be portable.  
	"an implementation should define a particular operation in terms of what
	works best for the target computer instead of trying to impose an abstract,
	uniform definition"

## C99

Starting revising in 1994;

**Three Points**:
- internationalization;
- correction of deficiencies;
- improvement of computational usefulness.

## C11

Starting revising in 2007;

"the “trust the programmer” goal should be tempered somewhat in the face of
contemporary concerns of programming security and safety"

---

# Chapter 1

There is a challenge when we want to run our C script, that we need a compiler
(and a debugger, maybe). 

## How to compile and run a C script

### WSL

In WSL, this can be down by following the instuction on
[this website](https://golas.blog/programming/ccpp/2021/02/05/vscode-wsl-c-cpp-development.html) or [this one](https://code.visualstudio.com/docs/cpp/config-wsl).
To compile the C script, we have two method (I know):  
1. press `ctrl + shift + B`, and click the menu showed in VS code.
By default, it will creat a file with the same name of you script.
For example, if you compile `hello.c`, you will get `hello` (use `ls` command
to see it). To run the program, just type `./<filename>` in your terminal
(you have to `cd` to the same folder);
2. type `cc <script name> -o <output name>` in terminal.
For example if we type `cc hello.c -o hello1`, it will creat a file named
`hello1`, and you can run it as we have discussed above. (This is the method
mentioned in the K&R's book);
3. type `gcc <script name> -o <output name>`...;
4. type `clang <script name> -o <output name>`...

### Windows

I don't know why, after I install VS code and the extension for C and C++,
it seems that I don't need any further work to compile and run C script.
I just write the code, and type `gcc <script name> -o <output name>` and it
works. For example, I tyep `gcc hello.c -o hello`, then type `./hello`, the
output will show in the terminal.

An interesting thing is that the procedure above will automatically create a
file with a `.exe` suffix. Although, you can specify that by typing
`gcc hello.c -o hello.exe`.

However, `clang` will not work in Windows (I don't know how to use it in
Windows, maybe).

## Examples in K&R C

OK, now head to the book. I will denote the examples with indice and their name.
For example, the first example in the book, which named helloC.c will be named
as `0helloC.c`. So you can open it in the correspondent folder for reference.

### 0helloC.c

There are only few things in it need to bring up.
- A C program must contain function(s) and variable(s);
- `int main(void)` is actually a special function, programs begings excuting at
the begining of `main`-every program must have a main function.
- escape sequence: for representing hard-to-type or invisible characters.
- `\n` is such a escape sequence, it means new line.

### 1temperature.c

- **comment**-two ways:  
	1. `// <comment>`-double slash, for one line comment;
	2. `/* <comment> */`-for multiple lines' comment.
- In C, declare variables before use them, define format:
`<type> <name> [<name1>, ...]`;
- There are several **types** in C:  
	1. `bool`-1 byte (8 bits);
	2. `char`-1 byte;
	3. `int`-4 bytes
	(So, smallest `int` is -2,147,483,648 ($-2^{31}$) while the biggest `int` is
	2,147,483,647 $2^{31}-1$, (2,147,483,648 possibilities,
	2,147,483,647 number)
	yet. And there is one bit for the sign i.e. $\pm$);  
	**Pay attention to the integer division truncates**
	4. `float`-4 bytes;
	5. `long`-8 bytes (long `int`);
	6. `double`-8 bytes (float);
- It might be suitable for us to use `float` more often unless we really need
`int`?
- `while`  
	1. single line-no need for the brace;
	2. multiple line-`{}`;
	3. indent-1 tab (usually 4 tabs);
- If an arithmetic operator has one floating-point operand and one integer
operand, however, the integer will be converted to floating point before the
operation is done
- `%6d`- at least 6 characters wide `int`, `%.2f`-2 characters after the
decimal point, `%6.2f`-at least 6 characters wide, 2 characters after the
decimal point; And it will round the number i.e. $0.666\dots$ will be 0.67 if
you use `%.2f`;

### 2temperature.c

- in any context where it is permissible to use the value of a variable of some
type, you can use a more complicated expression of that type;
- **For statemenet**:  
	within the parentheses following the `for`, there are **three parts**:  
	1. initialization;
	2. test or condition;
	3. the increment step (decrement also allowed).
	
	**The initialization, condition, and increment can be any expression**, i.e.
	not only the simple arithmetic operations.

### 3temperature.c

- meaningful number in the program (magic number?) shall be replaced with
meaningful name-symbolic constant (name);
- the way to define a symbolic constant: `#define NAME replacement text`,
**No semicolon at the end of a `#define` line!!!**
- convention: use uppercase letter with symbolic constants;

### Character Input and Output

General ideas:  
- text input and output-text stream-streams of characters;
- lines end with `\n`;
- `getchar()`-get and **return the next input character**, usually for keyboard
input;
- `putchar(c)`-c is usually an `int` not `char`;

#### 4copyFile.c

- `!=`-not equal to, its precedence is higher than `=`;
- why `int` rather `char`-we need dectect thins like `EOF` whose size is bigger
than `char`;
- `EOF`-end of file, a special "character";
- expressions have value -> assignments can appear at any where variable is
permitted.

Here, when we are dealing with ex1-6, we might wondering how to get `EOF`. The
problem is that there is no `EOF` on our keyboard. Fortunately, I found a
[solution](https://stackoverflow.com/questions/10720821/im-trying-to-understand-getchar-eof) (the answer of Antti Haapala --
Слава Україні). If you want to trigger `EOF` by keyboard, press `ctrl + D`
(Unix/Linux) or `ctrl + Z` (Windows). Else if (if-else in real life) you want
to trigger it by interacting with a file, you should wirte a, say `txt`, file,
and then type
```bash
cat <your file> | ./<your compiled program>
```
in the terminal.

#### 5charCount.c

- In the `while` solution part, which has been comment out, notice the `++nc`
it equals to `nc = nc + 1`. `++` actually can be either prefix or postfix, and
there are some difference between, we will discuss this in chapter 2;
- In the `for` part, notice the `;` in a single line. It's a *null statement*.

#### 6lineCount.c

- First, I revise the program, because the original version on KR_C might get
wrong (consider your file only have 1 line);
- `if` statement, brace-for multiple statement;
- `==`-test for equality (`=`-assignment);
- *character constant*  
	It turns out, character like `A` is also a "number" in computer. And there
	are some character set specify the correspondent value of things like `A`.
	For example, in **ASCII**, `A` is 65, `\n` is 10. You can try to run
	ascii.c (in folder 6lineCount) for some experience.

#### 7wordCount.c

- Pay attention to how we use `state` in the program;
- interpretation of `nl = nw = nc = 0;`, its actual form is:  
	```c
	nl = (nw = (nc = 0));
	```
	remember: expressions (here, the assignments) have value!
- `||`-OR, `&&`-AND. `&&`'s precedence is higher than `||`;
- expressions connected by `&&` or `||` are evaluated left to right. For example
, in
```c
c == ' ' || c == '\n' || c == '\t'
```
once the compiler knows that c is a blank i.e. `' '`, it won't test the two
remaining tests;
- `if-else if-...-(else)` structure.

### 8array.c

- **array**:  
	1. `int ndigits[10]`- an array can contain 10 integers, but notice that the
	index is begin at 0, i.e. the largest index is `ndigits[9]`;
- [recall](#6linecountc) that `char` is also an integer, this is the reason why
we can type:
```c
(c >= '0' || c <= '9')
```
and use `++ndigits[c - '0']`. And this works only if digits (i.e. `0`, `1`,
..., `9`) have consecutive increasing values, which, fortunately, is true
for all character sets;
- `if-else if-...-(else)`, the last `else` can be omitted. In that senario, if
no condition meets, anything inside the structure won't be excute.

### 9intPower.c

**function**:  
- I know we have learned about function in math classes, but there are some
minor differences between CS and math about function;
- In CS, functions provide a convenient way to **encapsulate** some
computation;
- ignore **how** a job is done; knowing **what** is done is sufficient;
- the definition of function:  
	```c
	<reture type> <func. name> (<parameter declarations, if any>)
	{
		<declarations>
		<statements>
	}
	```
- Function definitions can appear in any order, and in one source file or
several;
- The names used by a function is **local**;
- **formal argument**-**parameter**, **actual argument**-**argument**;
- **reture value**:  
	1. functions need not return a value;
	2. `return ;`-with no expression cause control, indicates the termination
	of the function;
	3. `main` function can also (*better*) return a value to indicate the status
	to the environment. `0` usually for normal termination, *non-zero* usually
	for unusual or erroneous termination;
- declarations before `main` are called **function prototype**, declaration and
definition and call of function must meet.

### 10intPower.c

- First look at the `for` loop, review [here](#2temperaturec)-**the
initialization, condition, and increment can be any expression**;
- All function arguments are passed "by value" i.e. **the called function is
given the values of its arguments in temporary variables rather than the
originals**. This means, in C, **the called function cannot directly alter a
variable in the calling function**. So, in the new `power` function, the `n`
decrease, while the original `n` outside the function won't change;
- If we want to change the original value, we must use a technology named
**pointer**-the address of the variable to be set, details in chapter 5.

### 11longestLine.c

- Exclude *pointer*, there is actually **another to modify the original value-
using arrays**. When we use a array as an argument, the value passed to the
function is the **address of the beginning of the array**. By subscripting,
the function can alter any element of the array.
- (Maybe) it's better to think about the outline before writing code;
- `char s[]` or `int number[]`, these are the way to use arrays as parameters
in a function;
- `void`-empty;
- In C, the **strings end with a special character-`'\0'`**;
- `%s`-placeholder for strings;

### 12externalVar.c

- In preceding programs, the variables inside a function are **local**-they
comes into existence only when the function called, and disappeared when the
function exited (known as *automatic variables*);
- **external** variables can be accessed by any function i.e. they are
**global**
- the external variables should be defined outside of any functions, and
**declared in each function that want to access it**;
- keyword `extern` can be omitted if their definition occurs in the source file
before its use in a particular function-so the common practice is to place all
definitions of external variables at the beginning of the source file;
- if there are multiple source file, common practice is to collect external
variables in a separate file (**header**), and add `external` if you use them;
- **definition** vs. **declaration**:  
	- definition: create variables and assign storage;
	- declaration: states and no storage is allocated.
- the disadvantage of relying too much on external variables:
	1. make the data connections of programs are not obvious-hard to modify or
	debug;
	2. destroy the versatility of the functions.

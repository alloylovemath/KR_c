
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
	2,147,483,647 $2^{31}-1$, I don't know why 2,147,483,648 is not include
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

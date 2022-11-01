# Character Input and Output

The main problem of code in chapter 1 is in section 1.5 which introduces the use
of `getchar()` and `putchar()`. However, it doesn't give a detailed explanation
on how to run those code.

For example, in exercise 1-7, we shall write a program to show the value of
`EOF`, one possible solution is:  

``` C
#include <stdio.h>

int main(void)
{
    printf("EOF: %i\n", EOF);

    return 0;
}
```

It will show you the value of `EOF`, but what we (or I) want is to show the
value in a more "real" scenario-when we really encounter the "end of file".
Maybe we can try this:  

``` C
#include <stdio.h>

int main(void)
{
    int c;
    while ((c = getchar()) != EOF)
    {
        putchar(c);
    }

    // the first '\n' will make the output looks better
    printf("\nEOF: %i\n", c);
    
    return 0;
}
```

The code works well, run the code and type something through you keyboard, you
will get a response. But, How can we type `EOF` using keyboard?

Fortunately, I find [a solution](https://stackoverflow.com/questions/10720821/im-trying-to-understand-getchar-eof) (the answer of Antti Haapala --
Слава Україні) on the internet. If you want to trigger `EOF` by typing with
keyboard, just press `ctrl + D` (Unix/Linux) or `ctrl + Z` (Windows). If you
want to interact with a file, you can compile the file, then type:  

```
cat <your file> | ./<your program>
```

in the terminal. Here, `<your file>` is literally a file writen by you
(eg: a .txt file). Then we get what we want.

Honestly speaking, `ex1-20.c` & `ex1-21.c` was not written by me. I copied the
code from the book *C Answer Book*. Why? Because I don't know how to do it or,
more specificly, I don't know what's the goal of the ex1-20 and ex1-21.

The reasons for that I don't get the intention of the author, I think, are:  
1. I'm not a native English speaker, so maybe my poor English lead to this;
2. More importantly, I suggest, is that I don't know **what is tab**, at least
the meaning of tab in the time K&R C published.

For me, I use `tab` mostly in coding. And no matter in Spyder or VS code, `tab`
is simply for indentation-1 `tab` = 4 `space`'s, that's all.
However, this is not true for ex1-20 and ex1-21.

# ex1-20

According to the script `ex1-20.c`, I guess that `tab`'s are for making
*columns*. For example, if we type:
```bash
1<tab>22<tab>333<tab>
```
what we want (at least according to `ex1-20.c`) is a 3-columns text:
```bash
1$$$$$$$22$$$$$$333$$$$$
```
(I subsitute `' '` to `'$'` for visualization.) A 3-columns right-justed text.

Now look the code in line 12:
```c
nb = TABINC - (pos - 1) % TABINC;
```
Let's consider that in position 12 we meet a `tab`. There are 11 preceding
characters, 8 of them blongs to preceding column, and 3 of them is the preceding
characters of this column. You see: 3 = (12 - 1) % 8 (`(pos - 1) % TABINC`), so
the number of blanks we need is 8 - 3 = 5 (`nb = TABINC - (pos - 1) % TABINC;`).

# ex1-21.c

If you understand `ex1-20.c`, then `ex1-21.c` is no big a deal. Let me give an
example. Suppose the text we are dealing with is:
```bash
ss <tab>bbb
```
when the program encounter `' '` at position 3, it will excute `++nb` and
terminate a round of iteration of the `for` loop in line 12, and the position
will be 4. Now it encounters the `tab` in position 4. Firstly, the program will
excute code in line 30-set `nb` to 0, then it will excute `putchar()` which
print a `tab` (notice that `tab` means create a column, not 4 space here).
Ok, the remaining question is will what is the position? If we do nothing it
will be 5 (4 + 1), but it's not true, since the next character is at position 9.
So, look at the code in line 41:
```c
pos = pos + (TABINC - (pos - 1) % TABINC) - 1;
```
We are at position 4, thus there are 3 preceding (`pos - 1`) i.e. 0 column
and 3 characters (`(pos - 1) % TABINC`), we put (8 - 3)
(`TABINC - (pos - 1) % TABINC`) blanks here, and the next position is
position + (8 - 3) = 4 + 5 = 9. But, wait a minute, the `for` loop in line 12
will add 1 to position automatically, so we subtract 1 from it, thus:
9 - 1 (`pos + (TABINC - (pos - 1) % TABINC) - 1`).

Phew~ hard to explan them.
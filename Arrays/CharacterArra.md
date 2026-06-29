# Character Arrays (C-Strings)

---

# 1. Characters (`char`)

A `char` stores a **single character**.

```cpp
char ch = 'A';
char digit = '7';
char symbol = '$';
```

## Memory

- A `char` occupies **1 byte**.
- 1 byte = **8 bits**.

```
1 byte
┌─┬─┬─┬─┬─┬─┬─┬─┐
│0│1│0│0│0│0│0│1│
└─┴─┴─┴─┴─┴─┴─┴─┘
```

---

# 2. ASCII

A computer does **not** store characters directly.

It stores an **integer code** for each character.

These codes are defined by the **ASCII (American Standard Code for Information Interchange)** table.

Example:

| Character | ASCII |
|-----------|------:|
| A | 65 |
| B | 66 |
| C | 67 |
| a | 97 |
| b | 98 |
| c | 99 |
| 0 | 48 |
| 1 | 49 |
| Space | 32 |

So

```cpp
char ch = 'A';
```

is actually stored as

```
01000001
```

which is decimal **65**.

---

# Why only 7 bits?

Originally, ASCII only defined **128 characters**.

```
2^7 = 128
```

This was enough for:

- English letters
- digits
- punctuation
- control characters

Since a byte has **8 bits**, the remaining bit was unused (later extended ASCII and Unicode used it).

Nowadays computers still store a `char` in **1 byte (8 bits)**.

---

# Printing the ASCII value

```cpp
char ch = 'A';

cout << int(ch);
```

Output

```
65
```

Another example

```cpp
char ch = 'a';

cout << int(ch);
```

Output

```
97
```

---

# Finding alphabet position

Instead of memorizing ASCII values:

```cpp
char ch = 'd';

cout << ch - 'a';
```

Output

```
3
```

because

```
'd' - 'a'

100 - 97 = 3
```

Similarly,

```cpp
char ch = 'D';

cout << ch - 'A';
```

Output

```
3
```

This is commonly used in interview problems.

---

# Character Arrays

A character array stores **multiple characters**.

```cpp
char arr[5] = {'a','b','c','d','e'};
```

Memory

```
Index

0   1   2   3   4

'a''b''c''d''e'
```

Printing individually

```cpp
cout << arr[0];
cout << arr[1];
```

works just like any other array.

---

# Why do we use character arrays?

Character arrays are used to store **strings (words/sentences).**

Example

```
Hello
Apple
Computer
```

A string is simply many characters stored one after another.

---

# C-Strings

A C-style string (C-string) is a character array that **ends with the null character**.

```
'\0'
```

This marks the **end of the string**.

Without it, the computer has no idea where the string ends.

---

# Null Character (`'\0'`)

```
'\0'
```

is **not** the character `'0'`.

It is a special character whose ASCII value is **0**.

```cpp
cout << int('\0');
```

Output

```
0
```

---

# Why is `'\0'` needed?

Suppose we have

```cpp
char word[] = {'c','o','d','e','\0'};
```

Memory

```
c
o
d
e
\0
```

When printing

```cpp
cout << word;
```

the computer prints

```
code
```

because it stops when it reaches `'\0'`.

---

# If there is no `'\0'`

```cpp
char word[4] = {'c','o','d','e'};
```

Memory

```
c
o
d
e
?
?
?
?
```

Now

```cpp
cout << word;
```

The computer keeps reading memory until it accidentally finds a `'\0'`.

Possible output

```
codeQ#@!^%$
```

or

```
code▒▒▒▒▒▒
```

This is **undefined behavior**.

---

# Difference from integer arrays

Consider

```cpp
int arr[5] = {1,2,3,4};
```

Memory

```
1
2
3
4
0
```

The last integer becomes **0** because missing values are zero-initialized.

Similarly,

```cpp
char arr[5] = {'c','o','d','e'};
```

becomes

```
c
o
d
e
'\0'
```

The remaining element is initialized to **0**, which for a `char` is the null character `'\0'`.

This is what makes it a valid C-string.

---

# Printing character arrays

Unlike integer arrays,

```cpp
char arr[] = {'c','o','d','e','\0'};

cout << arr;
```

prints

```
code
```

NOT

```
0x61ff2c
```

because `cout` has a special rule:

> If it sees a `char*` (or character array), it treats it as a C-string and prints characters until `'\0'`.

Compare:

```cpp
int arr[5];

cout << arr;
```

prints a memory address.

But

```cpp
char arr[] = "code";

cout << arr;
```

prints

```
code
```

---

# String Literals

A string literal is text written inside double quotes.

Examples

```cpp
"Hello"

"Apna College"

"C++"

"Programming"
```

These are called **string literals** because their value is fixed in the program.

---

# Character Array vs String Literal

Character array

```cpp
char word[] = {'c','o','d','e','\0'};
```

or

```cpp
char word[] = "code";
```

can be modified.

```cpp
word[0] = 'n';
```

Now

```
node
```

---

A string literal itself

```cpp
"code"
```

cannot be modified.

Its value is fixed.

---

# Creating Character Arrays

### Method 1

```cpp
char work[] = "code";
```

Compiler automatically adds

```
'\0'
```

Memory

```
c
o
d
e
\0
```

---

### Method 2

```cpp
char work[5] = "code";
```

Also becomes

```
c
o
d
e
\0
```

---

### Method 3

```cpp
char work[] = {'c','o','d','e','\0'};
```

---

### Method 4

```cpp
char work[50] = {'c','o','d','e','\0'};
```

Memory

```
c
o
d
e
\0
0
0
0
...
```

The remaining elements are initialized to **0**.

---

# Automatic `'\0'` with String Literals (Important)

When using a string literal

```cpp
char arr[] = "code";
```

the compiler **automatically appends** the null character.

Equivalent to

```cpp
char arr[] = {'c','o','d','e','\0'};
```

You do **not** have to write it yourself.

---

If you write

```cpp
char arr[10] = "code";
```

Memory

```
0 c
1 o
2 d
3 e
4 '\0'
5 0
6 0
7 0
8 0
9 0
```

The string ends at index **4**.

The remaining elements are simply zero-initialized.

---

# String Length

```cpp
strlen(arr)
```

returns the number of characters **before `'\0'`**.

Example

```cpp
char word[] = "hello";

cout << strlen(word);
```

Output

```
5
```

because

```
h e l l o \0
```

The null character is **not counted**.

---

# Inputting Character Arrays

Using

```cpp
cin >> word;
```

works only for a **single word**.

Example

Input

```
Apna College
```

Stored

```
Apna
```

Everything after the space is ignored.

---

# Reading an Entire Sentence

Use

```cpp
cin.getline()
```

Syntax

```cpp
cin.getline(array, size);
```

Example

```cpp
char sentence[50];

cin.getline(sentence, 50);
```

Input

```
Apna College is awesome
```

Stored

```
Apna College is awesome
```

including spaces.

The function automatically appends `'\0'`.

---

# `getline()` with a Delimiter

Syntax

```cpp
cin.getline(array, size, delimiter);
```

Parameters

```cpp
cin.getline(
    array,      // where to store the characters
    size,       // maximum characters to read
    delimiter   // optional: stop reading when this character is found
);
```

Example

```cpp
char sentence[50];

cin.getline(sentence, 50, '*');
```

Input

```
Hello World*Programming
```

Stored

```
Hello World
```

Reading stops when `*` is encountered.

The delimiter is **not stored**, and `'\0'` is automatically added at the end.

---

# Summary

- `char` stores one character (1 byte = 8 bits).
- Characters are stored using ASCII integer codes.
- `int(ch)` prints a character's ASCII value.
- `ch - 'a'` or `ch - 'A'` gives the alphabet index.
- A C-string is a character array ending with `'\0'`.
- `'\0'` has ASCII value **0** and marks the end of the string.
- Without `'\0'`, printing a character array can continue into random memory (undefined behavior).
- `cout << charArray` prints the whole string because `cout` stops at `'\0'`.
- String literals (`"code"`) automatically include the null character.
- `strlen()` counts characters before `'\0'`.
- `cin >> arr` reads only one word.
- `cin.getline(arr, size)` reads an entire line including spaces.
- `cin.getline(arr, size, delimiter)` stops reading when the delimiter is encountered.